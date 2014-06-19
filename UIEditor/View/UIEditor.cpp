#include "UIEditor.h"
#include <QPushButton>
#include <QToolBar>
#include <QDockWidget>
#include "Cocos2dxWidget.h"

UIEditor::UIEditor(QWidget *parent)
: QMainWindow(parent)
{
	m_pCxWidget = new Cocos2dxWidget();
	m_pCxWidget->initCocos2dx();
	this->setCentralWidget(m_pCxWidget);

	initToolBar();
	initDockWindow();
}

UIEditor::~UIEditor()
{

}

void UIEditor::initToolBar()
{
	QToolBar* toolBar = new QToolBar(tr("Font"));

	QPushButton* btn = new QPushButton("test", this);
	QObject::connect(btn, SIGNAL(clicked()), this, SLOT(onBtnTestClick()));

	toolBar->addWidget(btn);

	toolBar->setAllowedAreas(Qt::LeftToolBarArea);

	addToolBar(toolBar);
}

void UIEditor::initDockWindow()
{
	for (int i = 0; i < 2; ++i)
	{
		auto pDockWidget = new QDockWidget(this);
		pDockWidget->setWindowTitle("dock test");
	pDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);

	QWidget* pWidget = new QWidget();
	pWidget->setFixedSize(300, 200);
	pWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	pDockWidget->setWidget(pWidget);

	addDockWidget(Qt::LeftDockWidgetArea, pDockWidget);
	}

}
void UIEditor::onBtnTestClick()
{
	m_pCxWidget->setGLViewSize(1280, 766);
}

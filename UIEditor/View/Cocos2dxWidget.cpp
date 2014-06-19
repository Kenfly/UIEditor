#include "Cocos2dxWidget.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include <QTimer>
#include <QWidget>
#include <QMouseEvent>

USING_NS_CC;

Cocos2dxWidget::Cocos2dxWidget(QWidget* parent /* = 0 */)
: QWidget(parent, Qt::MSWindowsOwnDC | Qt::CustomizeWindowHint | Qt::FramelessWindowHint)
, m_pTimer(NULL)
{
}

void Cocos2dxWidget::initCocos2dx(int width,int height)
{ 
	m_width = width;
	m_height = height;
	//this->setFixedSize(m_width, m_height);
	AppDelegate app;
	m_pEGLView = CCEGLView::sharedOpenGLView((HWND)this->winId());
	m_pEGLView->setFrameSize(m_width, m_height);
	CCDirector::sharedDirector()->setOpenGLView(m_pEGLView);
	CCDirector::sharedDirector()->setDisplayStats(true);
	CCDirector::sharedDirector()->setAnimationInterval(1.0f / 60);
	CCDirector::sharedDirector()->runWithScene(HelloWorld::scene());
	
	m_pTimer = new QTimer(this);
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(update()));
	m_pTimer->start(1.0 * 1000 / 60.0f);

	//ShowWindow(CCEGLView::sharedOpenGLView()->getHWnd(), SW_SHOW);
}

void Cocos2dxWidget::update()
{
	CCDirector::sharedDirector()->mainLoop();
}

void Cocos2dxWidget::setGLViewSize(int width, int height)
{
	//m_width = width;
	//m_height = height;
	//m_pEGLView->resize(width, height);
	static float a = 1;
	m_pEGLView->setFrameZoomFactor(a -= 0.2f);
	CCSize size = m_pEGLView->getFrameSize();
	float factor = m_pEGLView->getFrameZoomFactor();
	this->setFixedSize(size.width * factor, size.height * factor);
}

void Cocos2dxWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
	{
		QPoint pos = event->pos();
		adjustTouchPos(pos); //调整输入的位置
		CCEGLView::sharedOpenGLView()->WindowProc(WM_LBUTTONDOWN, MK_LBUTTON, MAKELONG(pos.x(), pos.y()));
	}
}

void Cocos2dxWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
	{
		QPoint pos = event->pos();
		adjustTouchPos(pos);
		CCEGLView::sharedOpenGLView()->WindowProc(WM_LBUTTONUP, MK_LBUTTON, MAKELONG(pos.x(), pos.y()));
	}
}

void Cocos2dxWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
	{
		QPoint pos = event->pos();
		adjustTouchPos(pos);
		CCEGLView::sharedOpenGLView()->WindowProc(WM_MOUSEMOVE, MK_LBUTTON, MAKELONG(pos.x(), pos.y()));
	}
}

void Cocos2dxWidget::adjustTouchPos(QPoint& pos)
{
	pos.setY(m_pEGLView->getFrameSize().height * m_pEGLView->getFrameZoomFactor()- this->size().height() + pos.y());
}

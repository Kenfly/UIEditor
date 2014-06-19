#ifndef UIEDITOR_H
#define UIEDITOR_H

#include <QtWidgets/QMainWindow>

class Cocos2dxWidget;

class UIEditor : public QMainWindow
{
	Q_OBJECT

public:
	UIEditor(QWidget *parent = 0);
	~UIEditor();
private slots:
	void onBtnTestClick();
private:
	void initToolBar();
	void initDockWindow();
	Cocos2dxWidget* m_pCxWidget;
};

#endif // UIEDITOR_H

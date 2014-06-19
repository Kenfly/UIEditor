#ifndef  _QT_COCOS2DX_WIDGET_H_
#define  _QT_COCOS2DX_WIDGET_H_

#include <QWidget>

namespace cocos2d
{
	class CCEGLView;
}

class QTimer;

class Cocos2dxWidget : public QWidget
{
	Q_OBJECT
public:
	Cocos2dxWidget(QWidget* parent = 0);
	void initCocos2dx(int width = 960,int height = 640);
	void setGLViewSize(int width, int height);
private slots:
	void update();
protected:
	virtual void mousePressEvent(QMouseEvent *);
	virtual void mouseReleaseEvent(QMouseEvent *);
	virtual void mouseMoveEvent(QMouseEvent *);
private:
	void adjustTouchPos(QPoint& pos);
	cocos2d::CCEGLView* m_pEGLView;
	QTimer* m_pTimer;
	int m_width;
	int m_height;
};

#endif // _GL_WIDGET_H_

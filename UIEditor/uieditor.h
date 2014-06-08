#ifndef UIEDITOR_H
#define UIEDITOR_H

#include <QtWidgets/QMainWindow>
#include "ui_uieditor.h"

class UIEditor : public QMainWindow
{
	Q_OBJECT

public:
	UIEditor(QWidget *parent = 0);
	~UIEditor();

private:
	Ui::UIEditorClass ui;
};

#endif // UIEDITOR_H

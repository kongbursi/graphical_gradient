#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyWidget.h"

class MyWidget : public QMainWindow
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyWidgetClass ui;
};

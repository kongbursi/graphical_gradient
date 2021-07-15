#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include "paintarea.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include<QPushButton>
#include <QGridLayout>
class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
private:
	PaintArea *paintArea;
	QLabel *shapelabel;//ÐÎ×´
	QComboBox *shapeComboBox;
	QLabel *penWidthLable;//»­±Ê¿í¶È
	QSpinBox *penWidthSpinBox;
	QLabel *penColorLabel;//»­±ÊÑÕÉ«
	QFrame *penColorFrame;
	QPushButton *penColorbtn;//»­±ÊÑÕÉ«°´Å¥
	QLabel *penStyleLabel;
	QComboBox *penStyleComboBox;//»­±Ê·ç¸ñ
	QLabel *penCapLabel;
	QComboBox *penCapComboBox;
	QLabel *penJoinLabel;
	QComboBox *penJoinComboBox;
	QLabel *fillLabel;
	QComboBox *fillComboBox;
	QLabel *brushStyleLabel;
	QComboBox *brushStyleComboBox;
	QLabel *brushColorlabel;
	QFrame *brushColorFrame;
	QPushButton *brushColorbtn;
	QGridLayout *settingLayout;
	protected slots:
	void ShowShape(int);
	void ShowPenWidth(int);
	void ShowPenColor();
	void ShowPenStyle(int);
	void ShowPenCap(int);
	void ShowPenJoin(int);
	void ShowFill();
	void ShowBrushColor();
	void ShowBrush(int);
};
#endif // MAINWINDOW_H
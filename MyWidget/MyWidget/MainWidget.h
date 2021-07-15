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
	QLabel *shapelabel;//��״
	QComboBox *shapeComboBox;
	QLabel *penWidthLable;//���ʿ��
	QSpinBox *penWidthSpinBox;
	QLabel *penColorLabel;//������ɫ
	QFrame *penColorFrame;
	QPushButton *penColorbtn;//������ɫ��ť
	QLabel *penStyleLabel;
	QComboBox *penStyleComboBox;//���ʷ��
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
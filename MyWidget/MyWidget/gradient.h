#pragma once
#ifndef GRADIENT_TEST_H
#define GRADIENT_TEST_H
#include<QPainter>
#include<QStyleOption>
#include<QResizeEvent>
class gradient_test:public QWidget
{
	Q_OBJECT
public:
	explicit gradient_test(QWidget*parent = 0);
	virtual QSize sizeHint()const;
protected:
	void paintEvent(QPaintEvent*event);
	void resizeEvent(QResizeEvent*event);
private:
	QSize initSize;
	QImage wheel;
	void drawLine(const QSize &newSize);
};
#endif//GRADIENT_TEST_H
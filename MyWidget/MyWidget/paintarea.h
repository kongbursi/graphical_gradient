#pragma once
#ifndef PAINTAREA_H
#define PAINTAREA_H
#include <QWidget>
#include<QPen>
#include<QPaintEvent>
class PaintArea : public QWidget
{
	Q_OBJECT
public:
	enum Shape {
		Line, Rectangle, RoundRect, Ellipse, Polygon, Polyline, Points, Arc, Path, Text,
		Pixmap
	};
	PaintArea(QWidget * parent = 0);
	void setShape(Shape);       //������״
	void setPen(QPen);          //���û���
	void setBrush(QBrush);      //���û�ˢ
	void setFillRule(Qt::FillRule);//�������ģʽ
	void paintEvent(QPaintEvent *);//�ػ��¼�
private:
	Shape shape;
	QPen pen;
	QBrush brush;
	Qt::FillRule fillRule;
};
#endif // PAINTAREA_H
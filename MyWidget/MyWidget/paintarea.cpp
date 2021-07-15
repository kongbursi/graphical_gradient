#include "paintarea.h"
#include <QPainter>
PaintArea::PaintArea(QWidget *parent)
	:QWidget(parent)
{
	setPalette(QPalette(Qt::white)); //���ñ�����ɫ
	setAutoFillBackground(true);//�����Զ���䱳��ɫ
	setMinimumSize(400, 400);//���ô�����С��С
}
void PaintArea::setShape(Shape s)   //update()���´��ڲ���
{
	shape = s;
	update();
}
void PaintArea::setPen(QPen p)
{
	pen = p;
	update();
}
void PaintArea::setBrush(QBrush b)
{
	brush = b;
	update();
}
void PaintArea::setFillRule(Qt::FillRule rule)
{
	fillRule = rule;
	update();
}
//�ػ��¼�
void PaintArea::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setPen(pen);
	p.setBrush(brush);
	QRect rect(100, 100, 250, 200);//����һ������
	static const QPoint points[4] = {
		QPoint(100,100),
		QPoint(200,150),
		QPoint(300,250),
		QPoint(150,300)
	};//ȷ��Points���ĸ��������
	int startAngle = 60 * 16;
	int spanAngle = 180 * 16;  //Ϊ�����������ò�������
	QPainterPath path;     //QPainterPathΪQpainter���ṩ��һ���洢��������������˻������ݺͻ���˳��
	path.moveTo(50, 150);    //��ǰλ���ƶ�������50,150
	path.lineTo(350, 150);   //��ǰλ�ÿ�ʼ��ֱ�ߣ��յ�λ������350,150
	path.lineTo(100, 325);
	path.lineTo(200, 50);
	path.lineTo(300, 325);
	path.lineTo(50, 150);
	path.setFillRule(fillRule);  //�������ģʽ
	/*
	�����ʽ��һ��������
	ָ��ʹ����ż������������򡣸���������������ʹ�����·���ȷ��һ�����Ƿ�����״�ڡ�
	�ӵ㵽��״�ⲿ��λ�û���һ��ˮƽ�ߣ������㽻�������������������Ŀ����������õ�λ����״�ڲ�����ģʽΪĬ��ģʽ��
	Qt::OddEvenFill (default)
	ָ��ʹ�÷�����ƹ���������򡣸���������������ʹ�����·���ȷ��һ�����Ƿ�����״�ڡ�
	�ӵ㵽��״�ⲿ��λ�û���һ��ˮƽ�ߡ�ȷ��ÿ�����㴦��ֱ�߷��������ϻ������¡���������ͨ����ÿ������㷽��ĺ���ȷ���ġ�
	������ֲ�Ϊ�㣬���λ����״�ڲ����ڴ��������£������ģʽҲ���Ա���Ϊ�պ���״�Ľ��㡣
	Qt::WindingFill
	*/
	switch (shape)
	{
	case Line:       //ֱ��
		p.drawLine(rect.topLeft(), rect.bottomRight());  //����ֱ�ߡ����Ϊ�������ϵ㣬�յ�Ϊ�������µ�
		break;
	case Rectangle: //������
		p.drawRect(rect);
		break;
	case RoundRect:  //Բ�Ƿ���
		p.drawRoundRect(rect);
		break;
	case Ellipse:   //��Բ��
		p.drawEllipse(rect);
		break;
	case Polygon:   //�����
		p.drawPolygon(points, 4);  //����4����������
		break;
	case Polyline:  //�����
		p.drawPolyline(points, 4);
		break;
	case Points:    //��
		p.drawPoints(points, 4);
		break;
	case Arc:   //��
		p.drawArc(rect, startAngle, spanAngle);  //�������������ֱ�Ϊ ��ʼ�����Ƚ�
		break;
	case Path:  //����֮ǰ�Ѿ����õ�·��
		p.drawPath(path);
		break;
	case Text:  //����
		p.drawText(rect, Qt::AlignCenter, tr("Hello Qt!"));
		break;
	case Pixmap:    //ͼƬ
		p.drawPixmap(150, 150, QPixmap(":/image/D:/software/image1.jpeg"));//����һ��ͼ��
		break;
	default:
		break;
	}
}
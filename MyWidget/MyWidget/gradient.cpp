#include"gradient.h"
gradient_test::gradient_test(QWidget*parent)
	:QWidget(parent), initSize(300, 300)
{
	resize(650, 250);    //���ڴ�С
}
void gradient_test::drawLine(const QSize &newSize)
{
	QPainter painter(&wheel);   //wheel��Ϊ��ͼ����
	painter.setRenderHint(QPainter::Antialiasing);  //�������
	wheel.fill(Qt::white);
	//���Խ���
	QLinearGradient linearGradient(20, 20, 150, 150);
	//������һ��QLinearGradient����ʵ��������Ϊ�����յ����꣬����Ϊ��ɫ����ķ���
	//painter.setPen(Qt::NoPen);
	linearGradient.setColorAt(0.0, Qt::green);
	linearGradient.setColorAt(0.2, Qt::white);
	linearGradient.setColorAt(0.4, Qt::blue);
	linearGradient.setColorAt(0.6, Qt::red);
	linearGradient.setColorAt(1.0, Qt::yellow);
	painter.setBrush(QBrush(linearGradient));
	painter.drawEllipse(10, 10, 200, 200);
	//ǰ��Ϊ��ߣ�������������Ϊ���������,��������зֱ����ý������ɫ��·������

	//���佥��
	QRadialGradient radialGradient(310, 110, 100, 310, 110);
	//������һ��QRadialGradient����ʵ���������ֱ�Ϊ�������꣬�뾶���Ⱥͽ�������,�����Ҫ�Գ���ô��������ͽ�������Ҫһ��
	radialGradient.setColorAt(0, Qt::green);
	//radialGradient.setColorAt(0.2,Qt::white);
	radialGradient.setColorAt(0.4, Qt::blue);
	//radialGradient.setColorAt(0.6,Qt::red);
	radialGradient.setColorAt(1.0, Qt::yellow);
	painter.setBrush(QBrush(radialGradient));
	painter.drawEllipse(210, 10, 200, 200);//����Ӧ�����껭����
										   //���Ƚ���
	QConicalGradient conicalGradient(510, 110, 0);
	//������һ��QConicalGradient����ʵ���������ֱ�Ϊ��������ͳ�ʼ�Ƕ�
	conicalGradient.setColorAt(0, Qt::green);
	conicalGradient.setColorAt(0.2, Qt::white);
	conicalGradient.setColorAt(0.4, Qt::blue);
	conicalGradient.setColorAt(0.6, Qt::red);
	conicalGradient.setColorAt(0.8, Qt::yellow);
	conicalGradient.setColorAt(1.0, Qt::green);
	//���ý������ɫ��·������
	painter.setBrush(QBrush(conicalGradient));
	painter.drawEllipse(410, 10, 200, 200);//����Ӧ�����껭����
}
QSize gradient_test::sizeHint()const
{
	return QSize(height(), height());
}
void gradient_test::resizeEvent(QResizeEvent*event)
{
	wheel = QImage(event->size(), QImage::Format_ARGB32_Premultiplied);
	wheel.fill(palette().background().color());
	drawLine(event->size());
	update();
}
void gradient_test::paintEvent(QPaintEvent*event)
{
	QPainter painter(this);
	QStyleOption opt;
	opt.init(this);
	painter.drawImage(0, 0, wheel);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
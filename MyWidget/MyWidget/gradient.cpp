#include"gradient.h"
gradient_test::gradient_test(QWidget*parent)
	:QWidget(parent), initSize(300, 300)
{
	resize(650, 250);    //窗口大小
}
void gradient_test::drawLine(const QSize &newSize)
{
	QPainter painter(&wheel);   //wheel作为画图对象？
	painter.setRenderHint(QPainter::Antialiasing);  //消除锯齿
	wheel.fill(Qt::white);
	//线性渐变
	QLinearGradient linearGradient(20, 20, 150, 150);
	//创建了一个QLinearGradient对象实例，参数为起点和终点坐标，可作为颜色渐变的方向
	//painter.setPen(Qt::NoPen);
	linearGradient.setColorAt(0.0, Qt::green);
	linearGradient.setColorAt(0.2, Qt::white);
	linearGradient.setColorAt(0.4, Qt::blue);
	linearGradient.setColorAt(0.6, Qt::red);
	linearGradient.setColorAt(1.0, Qt::yellow);
	painter.setBrush(QBrush(linearGradient));
	painter.drawEllipse(10, 10, 200, 200);
	//前面为左边，后面两个参数为横轴和纵轴,上面的四行分别设置渐变的颜色和路径比例

	//辐射渐变
	QRadialGradient radialGradient(310, 110, 100, 310, 110);
	//创建了一个QRadialGradient对象实例，参数分别为中心坐标，半径长度和焦点坐标,如果需要对称那么中心坐标和焦点坐标要一致
	radialGradient.setColorAt(0, Qt::green);
	//radialGradient.setColorAt(0.2,Qt::white);
	radialGradient.setColorAt(0.4, Qt::blue);
	//radialGradient.setColorAt(0.6,Qt::red);
	radialGradient.setColorAt(1.0, Qt::yellow);
	painter.setBrush(QBrush(radialGradient));
	painter.drawEllipse(210, 10, 200, 200);//在相应的坐标画出来
										   //弧度渐变
	QConicalGradient conicalGradient(510, 110, 0);
	//创建了一个QConicalGradient对象实例，参数分别为中心坐标和初始角度
	conicalGradient.setColorAt(0, Qt::green);
	conicalGradient.setColorAt(0.2, Qt::white);
	conicalGradient.setColorAt(0.4, Qt::blue);
	conicalGradient.setColorAt(0.6, Qt::red);
	conicalGradient.setColorAt(0.8, Qt::yellow);
	conicalGradient.setColorAt(1.0, Qt::green);
	//设置渐变的颜色和路径比例
	painter.setBrush(QBrush(conicalGradient));
	painter.drawEllipse(410, 10, 200, 200);//在相应的坐标画出来
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
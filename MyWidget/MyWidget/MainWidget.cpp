#include "MainWidget.h"
#include "paintarea.h"
#include<QColorDialog>
#include <QTextCodec>
#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	paintArea = new PaintArea;
	shapelabel = new QLabel(QStringLiteral("��״��"));  //��״ѡ�������б��
	shapeComboBox = new QComboBox;
	shapeComboBox->addItem(tr("Line"), PaintArea::Line);
	shapeComboBox->addItem(tr("RoundRect"), PaintArea::RoundRect);
	shapeComboBox->addItem(tr("Ellipse"), PaintArea::Shape::Ellipse);
	shapeComboBox->addItem(tr("Polygon"), PaintArea::Polygon);
	shapeComboBox->addItem(tr("Polyline"), PaintArea::Polyline);
	shapeComboBox->addItem(tr("Points"), PaintArea::Points);
	shapeComboBox->addItem(tr("Arc"), PaintArea::Arc);
	shapeComboBox->addItem(tr("Rectangle"), PaintArea::Rectangle);
	shapeComboBox->addItem(tr("Path"), PaintArea::Path);
	shapeComboBox->addItem(tr("Text"), PaintArea::Text);
	shapeComboBox->addItem(tr("Pixmap"), PaintArea::Pixmap);
	connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(ShowShape(int)));
	penColorLabel = new QLabel(QStringLiteral("������ɫ��")); //������ɫѡ��ؼ�
	penColorFrame = new QFrame;
	penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);//Panel - QFrame��һ��ƽ��ʹ���ݿ�����͹����߰���,
																 //QFrame::Sunken - ��ܺ����ݿ��������� 
	penColorFrame->setAutoFillBackground(true);
	penColorFrame->setPalette(QPalette(Qt::blue));//����Ĭ����ɫΪ��ɫ
	penColorbtn = new QPushButton;
	connect(penColorbtn, SIGNAL(clicked()), this, SLOT(ShowPenColor()));


	penWidthLable = new QLabel(QStringLiteral("���ʿ�ȣ�"));//���ʿ��ѡ��ؼ�
	penWidthSpinBox = new QSpinBox;
	penWidthSpinBox->setRange(0, 20);//�����ֿ����ȡֵ��Χ
	connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ShowPenWidth(int)));


	penStyleLabel = new QLabel; //���ʷ��ѡ�������б��
	penStyleComboBox = new QComboBox;
	//penStyleComboBox->addItem()
	//penStyleComboBox->addItem(tr("SolidLine"), Qt::SolidLine);
	//penStyleComboBox->addItem(tr("DashLine"), Qt::DashLine);
	//penStyleComboBox->addItem(tr("DotLine"), Qt::DotLine);
	//penStyleComboBox->addItem(tr("DashDotLine"), Qt::DashDotLine);
	//penStyleComboBox->addItem(tr("DashDotDotLine"), Qt::DashDotDotLine);
	//penStyleComboBox->addItem(tr("CustomDashLine"), Qt::CustomDashLine);//�������������԰�addItem����Ĳ����û�Ϊint�������
	penStyleComboBox->addItem(tr("SolidLine"), 1);
	penStyleComboBox->addItem(tr("DashLine"), 2);
	penStyleComboBox->addItem(tr("DotLine"), 3);
	penStyleComboBox->addItem(tr("DashDotLine"), 4);
	penStyleComboBox->addItem(tr("DashDotDotLine"), 5);
	penStyleComboBox->addItem(tr("CustomDashLine"), 6);//�������������԰�addItem����Ĳ����û�Ϊint�������
	connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenStyle(int)));
	penCapLabel = new QLabel;  //�����˷��ѡ�������б��
	penCapComboBox = new QComboBox;
	penCapComboBox->addItem(tr("SquareCap"), Qt::SquareCap);
	penCapComboBox->addItem(tr("FlatCap"), Qt::FlatCap);
	penCapComboBox->addItem(tr("RoundCap"), Qt::RoundCap);
	connect(penCapComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenCap(int)));
	penJoinLabel = new QLabel;//�������ӵ���ѡ�������б��
	penJoinComboBox = new QComboBox;
	penJoinComboBox->addItem(tr("BevelJoin"), Qt::BevelJoin);
	penJoinComboBox->addItem(tr("MiterJoin"), Qt::MiterJoin);
	penJoinComboBox->addItem(tr("RoundJoin"), Qt::RoundJoin);
	fillLabel = new QLabel;//���ģʽѡ�������б��
	fillComboBox = new QComboBox;
	fillComboBox->addItem(tr("Odd Even"), Qt::OddEvenFill);
	fillComboBox->addItem(tr("Winding"), Qt::WindingFill);
	connect(fillComboBox, SIGNAL(activated(int)), this, SLOT(ShowFill()));
	brushColorlabel = new QLabel;//��ˢ���ѡ�������б��
	brushColorFrame = new QFrame;
	brushColorbtn = new QPushButton;
	brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	brushColorFrame->setAutoFillBackground(true);
	brushColorFrame->setPalette(QPalette(Qt::green));
	connect(brushColorbtn, SIGNAL(clicked()), this, SLOT(ShowBrushColor()));
	brushStyleLabel = new QLabel; //��ˢ���ѡ�������б��
	brushStyleComboBox = new QComboBox;
	brushStyleComboBox->addItem(tr("SolidPattern"), 1);
	brushStyleComboBox->addItem(tr("Dense1Pattern"), 2);
	brushStyleComboBox->addItem(tr("Dense2Pattern"), 3);
	brushStyleComboBox->addItem(tr("Dense3Pattern"), 4);
	brushStyleComboBox->addItem(tr("Dense4Pattern"), 5);
	brushStyleComboBox->addItem(tr("Dense5Pattern"), 6);
	brushStyleComboBox->addItem(tr("Dense6Pattern"), 7);
	brushStyleComboBox->addItem(tr("Dense7Pattern"), 8);
	brushStyleComboBox->addItem(tr("HorPattern"), 9);
	brushStyleComboBox->addItem(tr("VerPattern"), 10);
	brushStyleComboBox->addItem(tr("CrossPattern"), 11);
	brushStyleComboBox->addItem(tr("BDiagPattern"), 12);
	brushStyleComboBox->addItem(tr("FDiagPattern"), 13);
	brushStyleComboBox->addItem(tr("DiagCrossPattern"), 14);
	brushStyleComboBox->addItem(tr("LinearGradientPattern"), 15);
	brushStyleComboBox->addItem(tr("ConicalGradientPattern"), 16);
	brushStyleComboBox->addItem(tr("RadialGradientPattern"), 17);
	brushStyleComboBox->addItem(tr("TexturePattern"), 24);
	connect(brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowBrush(int)));
	settingLayout = new QGridLayout;//���岼��
	settingLayout->addWidget(shapelabel, 0, 0);
	settingLayout->addWidget(shapeComboBox, 0, 1);
	settingLayout->addWidget(penColorLabel, 0, 2);
	settingLayout->addWidget(penColorFrame, 0, 3);
	settingLayout->addWidget(penColorbtn, 0, 4);
	settingLayout->addWidget(penWidthLable, 1, 0);
	settingLayout->addWidget(penWidthSpinBox, 1, 1);
	settingLayout->addWidget(penStyleLabel, 1, 2);
	settingLayout->addWidget(penStyleComboBox, 1, 3);
	settingLayout->addWidget(penCapLabel, 2, 0);
	settingLayout->addWidget(penCapComboBox, 2, 1);
	settingLayout->addWidget(penJoinLabel, 2, 2);
	settingLayout->addWidget(penJoinComboBox, 2, 3);
	settingLayout->addWidget(fillLabel, 3, 0);
	settingLayout->addWidget(fillComboBox, 3, 1);
	settingLayout->addWidget(brushColorlabel, 3, 2);
	settingLayout->addWidget(brushColorFrame, 3, 3);
	settingLayout->addWidget(brushColorbtn, 3, 4);
	settingLayout->addWidget(brushStyleLabel, 4, 0);
	settingLayout->addWidget(brushStyleComboBox, 4, 1);
	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(settingLayout);
	mainLayout->addWidget(paintArea);
	ShowShape(shapeComboBox->currentIndex());
}
//���¾��Ǹ��ֲۺ�����
void MainWindow::ShowShape(int value)
{
	qDebug() << "ѡ�е���: " << value;
	PaintArea::Shape shape = PaintArea::Shape(shapeComboBox->itemData(value, Qt::UserRole).toInt());
	paintArea->setShape(shape);
}
void MainWindow::ShowPenWidth(int value)//���ʿ��
{
	QColor color = penColorFrame->palette().color(QPalette::Window);
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	paintArea->setPen(QPen(color, value, style, cap, join));
}
void MainWindow::ShowPenColor()//������ɫ
{
	QColor color = QColorDialog::getColor(Qt::blue);
	penColorFrame->setPalette(QPalette(color));
	int value = penWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	paintArea->setPen(QPen(color, value, style, cap, join));
}
void MainWindow::ShowPenStyle(int styleValue)//���ʷ��
{
	QColor color = penColorFrame->palette().color(QPalette::Window);
	int value = penWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(styleValue, Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	paintArea->setPen(QPen(color, value, style, cap, join));
}
void MainWindow::ShowPenCap(int capValue)//���˷��
{
	QColor color = penColorFrame->palette().color(QPalette::Window);
	int value = penWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(capValue, Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(), Qt::UserRole).toInt());
	paintArea->setPen(QPen(color, value, style, cap, join));
}
void MainWindow::ShowPenJoin(int joinValue)//�������ӵ���
{
	QColor color = penColorFrame->palette().color(QPalette::Window);
	int value = penWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(joinValue, Qt::UserRole).toInt());
	paintArea->setPen(QPen(color, value, style, cap, join));
}
void MainWindow::ShowFill()//���ģʽ
{
	Qt::FillRule fill = Qt::FillRule(fillComboBox->itemData(fillComboBox->currentIndex(), Qt::UserRole).toInt());
	paintArea->setFillRule(fill);
}
void MainWindow::ShowBrushColor()//��ˢ��ɫ
{
	QColor color = QColorDialog::getColor(Qt::blue);
	brushColorFrame->setPalette(QPalette(color));
	ShowBrush(brushStyleComboBox->currentIndex());
}
void MainWindow::ShowBrush(int value)//��ˢ���
{
	QColor color = brushColorFrame->palette().color(QPalette::Window);//��ˢ��ǰ����ɫ
	Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(value, Qt::UserRole).toInt());//��ȡ�û�ѡ��Ļ�ˢ���
	if (style == Qt::LinearGradientPattern)//���Խ���
	{
		QLinearGradient linearGradient(0, 0, 400, 400);//���Խ������ֹ��λ��
		linearGradient.setColorAt(0.0, Qt::white);//����Ⱥͽ�����ɫ
		linearGradient.setColorAt(0.2, color);
		linearGradient.setColorAt(1.0, Qt::black);
		paintArea->setBrush(linearGradient);
	}
	else if (style == Qt::RadialGradientPattern)//Բ�ν���
	{
		QRadialGradient radialGradient(200, 200, 150, 150, 100);//���ĵ㣬�뾶������
		radialGradient.setColorAt(0.0, Qt::white);
		radialGradient.setColorAt(0.2, color);
		radialGradient.setColorAt(1.0, Qt::black);
		paintArea->setBrush(radialGradient);
	}
	else if (style == Qt::ConicalGradientPattern)//׶�ν���
	{
		QConicalGradient conicalGradient(200, 200, 30);
		conicalGradient.setColorAt(0.0, Qt::white);
		conicalGradient.setColorAt(0.2, color);
		conicalGradient.setColorAt(1.0, Qt::black);
		paintArea->setBrush(conicalGradient);
	}
	else if (style == Qt::TexturePattern)
	{
		paintArea->setBrush(QBrush(QPixmap("2.png")));
	}
	else
	{
		paintArea->setBrush(QBrush(color, style));
	}
}
MainWindow::~MainWindow()
{
}
/*
"QVariant::QVariant(Qt::PenStyle)" (������ ��������:481�������ļ�:"f:\Qt\install\5.6.3\msvc2015_64\include\QtCore\qvariant.h") ���ɷ���	

*/

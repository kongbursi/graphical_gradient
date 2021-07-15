#include "MyWidget.h"
#include <QtWidgets/QApplication>
#include "MainWidget.h"
#include "gradient.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
	MainWindow m;
	gradient_test g;
	g.show();
	//m.show();
    //w.show();
    return a.exec();
}

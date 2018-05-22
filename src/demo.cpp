#include <QApplication>
#include "ui_demo.h"

namespace Ui
{
class DEMO;
}

class DEMO : public QWidget
{
	Q_OBJECT

public:
	explicit DEMO(QWidget *parent = 0)
	: QWidget(parent), ui(new Ui::DEMO)
	{
		ui->setupUi(this);
	}
	virtual ~DEMO()
	{
		delete ui;
	}
private:
	Ui::DEMO *ui;
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	DEMO demo;
	demo.show();

	return app.exec();
}

#include "demo.moc"

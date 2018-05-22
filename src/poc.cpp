#include <QApplication>
#include "ui_poc.h"

namespace Ui
{
class POC;
}

class POC : public QWidget
{
	Q_OBJECT

public:
	explicit POC(QWidget *parent = 0)
	: QWidget(parent), ui(new Ui::POC)
	{
		ui->setupUi(this);
	}
	virtual ~POC()
	{
		delete ui;
	}
private:
	Ui::POC *ui;
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	POC page;
	page.show();

	return app.exec();
}

#include "poc.moc"

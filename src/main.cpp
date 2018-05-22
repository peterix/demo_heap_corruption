#include <QApplication>
#include "WorldListPage.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	WorldListPage page;
	page.show();

	return app.exec();
}


#include "poc_heap_corruption.h"
#include "WorldListPage.h"
#include "ui_poc_heap_corruption.h"

poc_heap_corruption::poc_heap_corruption(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::poc_heap_corruption)
{
    ui->setupUi(this);
	auto page = new WorldListPage("worlds", "worlds", "Worlds");
	setCentralWidget(page);
}

poc_heap_corruption::~poc_heap_corruption()
{
    delete ui;
}

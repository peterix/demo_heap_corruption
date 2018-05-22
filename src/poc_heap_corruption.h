#ifndef POC_HEAP_CORRUPTION_H
#define POC_HEAP_CORRUPTION_H

#include <QMainWindow>

namespace Ui {
class poc_heap_corruption;
}

class poc_heap_corruption : public QMainWindow
{
    Q_OBJECT

public:
    explicit poc_heap_corruption(QWidget *parent = 0);
    ~poc_heap_corruption();

private:
    Ui::poc_heap_corruption *ui;
};

#endif // POC_HEAP_CORRUPTION_H

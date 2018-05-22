# Qt 5 heap corruption

You need Qt5 and CMake 3.0 or higher. Not all versions of Qt5 are affected.

```
mkdir build && cd build
cmake ..
make

valgrind ./demo_heap_corruption
```

Then close the window that pops up and watch the fireworks (invalid memory reads and writes).

On affected versions of Qt, you will get something like this:

```
==8087== Invalid write of size 8
==8087==    at 0x4FCBDC4: QWidget::~QWidget() (qwidget.cpp:1611)
==8087==    by 0x516A2F9: QToolButton::~QToolButton() (qtoolbutton.cpp:326)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x5145BB9: QTabBar::~QTabBar() (qtabbar.cpp:861)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x51657C9: QTabWidget::~QTabWidget() (qtabwidget.cpp:368)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x10F9E9: DEMO::~DEMO() (demo.cpp:20)
==8087==    by 0x10D4EE: main (demo.cpp:30)
==8087==  Address 0x1e0bd4b0 is 128 bytes inside a block of size 456 free'd
==8087==    at 0x4C2E60B: operator delete(void*) (vg_replace_malloc.c:576)
==8087==    by 0x60DA59E: cleanup (qscopedpointer.h:60)
==8087==    by 0x60DA59E: ~QScopedPointer (qscopedpointer.h:107)
==8087==    by 0x60DA59E: QObject::~QObject() (qobject.cpp:882)
==8087==    by 0x4FCC03B: QWidget::~QWidget() (qwidget.cpp:1564)
==8087==    by 0x4FCC1C9: QWidget::~QWidget() (qwidget.cpp:1727)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x524B829: QTreeView::~QTreeView() (qtreeview.cpp:207)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x4FCC1C9: QWidget::~QWidget() (qwidget.cpp:1727)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x5143689: QStackedWidget::~QStackedWidget() (qstackedwidget.cpp:147)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x51657C9: QTabWidget::~QTabWidget() (qtabwidget.cpp:368)
==8087==    by 0x60D11CA: QObjectPrivate::deleteChildren() (qobject.cpp:1993)
==8087==    by 0x4FCBFAA: QWidget::~QWidget() (qwidget.cpp:1703)
==8087==    by 0x10F9E9: DEMO::~DEMO() (demo.cpp:20)
==8087==    by 0x10D4EE: main (demo.cpp:30)
==8087==  Block was alloc'd at
==8087==    at 0x4C2D54F: operator new(unsigned long) (vg_replace_malloc.c:334)
==8087==    by 0x4FD292D: QWidget::QWidget(QWidget*, QFlags<Qt::WindowType>) (qwidget.cpp:1027)
==8087==    by 0x507E91F: QAbstractScrollAreaPrivate::init() (qabstractscrollarea.cpp:291)
==8087==    by 0x51E85F9: QAbstractItemView::QAbstractItemView(QAbstractItemViewPrivate&, QWidget*) (qabstractitemview.cpp:628)
==8087==    by 0x524E0E4: QTreeView::QTreeView(QWidget*) (qtreeview.cpp:186)
==8087==    by 0x10EEE6: Ui_DEMO::setupUi(QWidget*) (ui_demo.h:110)
==8087==    by 0x10F961: DEMO::DEMO(QWidget*) (demo.cpp:17)
==8087==    by 0x10D4CE: main (demo.cpp:30)
```

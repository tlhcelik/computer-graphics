#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img = new graphic(this);
    img->setGeometry(5,5,600,600);
    img->setFrameShape(QFrame::Box);
    img->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

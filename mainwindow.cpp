#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPdfDocument>
#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_document = new QPdfDocument(this);
    ui->pdfView->setDocument(m_document);

    setupConnections();

    //左半分に表示
    resize(960, 1080);
    move(0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


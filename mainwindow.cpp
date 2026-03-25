#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_document = new QPdfDocument(this);
    ui->pdfView->setDocument(m_document);
    ui->pdfView->setZoomMode(QPdfView::ZoomMode::FitInView);

    setupConnections();

    //左半分に表示
    resize(900, 1000);
    move(0,0);

    QDate today = QDate::currentDate();
    todate = today.toString("MMdd");
    qDebug() << "today is " << todate;
}

MainWindow::~MainWindow()
{
    delete ui;
}


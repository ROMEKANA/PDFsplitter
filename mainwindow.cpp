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

    connect(ui->openButton, &QPushButton::clicked, this, [this]() {

        QString filePath = QFileDialog::getOpenFileName(
            this,
            "PDFを開く",
            "",
            "PDF Files (*.pdf)"
            );

        if(filePath.isEmpty()) return;

        m_document->load(filePath);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


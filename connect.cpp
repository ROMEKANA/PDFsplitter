#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setupConnections(){
    connect(ui->openButton, &QPushButton::clicked, this, [this]() {

        filePath = QFileDialog::getOpenFileName(
            this,
            "PDFを開く",
            "",
            "PDF Files (*.pdf)"
            );

        if(filePath.isEmpty()) return;

        //qDebug() << filePath;
        //m_document->load(filePath);
        loadPDF();
    });


}

void MainWindow::loadPDF(){

    qDebug() << filePath;

    m_document->load(filePath);
}
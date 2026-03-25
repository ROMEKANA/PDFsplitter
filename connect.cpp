#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <filesystem>
#include <cstdlib>
//#include <iostream>

//using namespace std;

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
        qDebug() << filePath;

        m_document->load(filePath);

        pagecount = m_document->pageCount();


        qDebug() << "pagecount is " <<  QString::number(pagecount);


        splitPDF();
        loadPDF();
    });


}

void MainWindow::loadPDF(){


    QStringList list = filePath.split(".");


    for(int i = 0;i < pagecount; i++){
        QString number;
        if(pagecount < 10) number = QString::number(i+1);
        else number = QString("%1").arg(i+1, 2, 10, QChar('0'));
        filePaths[i] = list[0] + "-" + number +".pdf";
        qDebug() << filePaths[i];
    }

    qDebug() << filePaths[1];

    m_document->load(filePaths[1]);

}

void MainWindow::splitPDF(){
    QString command = "split " + filePath;
    qDebug() << command;
    system(command.toUtf8());
}
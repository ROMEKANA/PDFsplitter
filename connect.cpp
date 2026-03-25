#include "mainwindow.h"
#include "ui_mainwindow.h"

//using namespace std;

void MainWindow::setupConnections(){
    connect(ui->openButton, &QPushButton::clicked, this, [this]() {

        filePath = QFileDialog::getOpenFileName(
            this,
            "PDFを開く",
            "C:/SCAN",
            "PDF Files (*.pdf)"
            );

        if(filePath.isEmpty()) return;

        //qDebug() << filePath;
        //m_document->load(filePath);
        qDebug() << filePath;

        m_document->load(filePath);

        pagecount = m_document->pageCount();


        qDebug() << "pagecount is " <<  QString::number(pagecount);

        nowpage = 0;

        splitPDF();
        loadPDF();

    });

    connect(ui->Rename, &QPushButton::clicked, this, [this]() {
        QString name1 = ui->lineEdit1->text();
        QString name2 = ui->lineEdit2->text();

        if(name1.isEmpty() || name2.isEmpty()) return;

        ui->lineEdit2->setFocus();

       // ui->pdfView->setDocument(nullptr);  // ← 先に切る

       // m_document->close();
        //QThread::msleep(50);  // ちょい待つ


        QFileInfo info(filePaths[nowpage]);

        QString dir = info.absolutePath();
        QString newName = name1  + name2 + todate + ".pdf";
        QString newPath = dir + "/" + newName;


        QFile file(filePaths[nowpage]);
        file.close();


        qDebug() << "old:" << filePaths[nowpage];
        qDebug() << "new:" << newPath;

        loadPDF();

        //QThread::msleep(10000);  // ちょい待つ
        //if(file.rename(newPath)) {
        if(QFile::rename(filePaths[nowpage], newPath)) {
        //if(QFile::rename(filePath, newPath)) {
            qDebug() << "rename success:" << newPath;
        }
        else {
            qDebug() << "rename failed";
            qDebug() << file.errorString();
            nowpage--;
            loadPDF();
            return;
        }

        // 入力欄を空にする
        ui->lineEdit1->clear();
        //ui->lineEdit2->clear();

        /*auto nav = ui->pdfView->pageNavigator();

        int current = nav->currentPage();
        nav->setCurrentPage(current + 1);*/
        qDebug() << "now is " << nowpage;
        qDebug() << "now is " << ui->pdfView->pageNavigator()->currentPage();
        nowpage++;
        //ui->pdfView->setPage(nowpage + 1);
        //ui->pdfView->pageNavigator()->forward();
        ui->pdfView->pageNavigator()->jump(ui->pdfView->pageNavigator()->currentPage() + 1, {0, 0}, 1.0);

        qDebug() << "move";
        qDebug() << "now is " << nowpage;
        qDebug() << "now is " << ui->pdfView->pageNavigator()->currentPage();

        loadPDF();
        //*/
    });

    connect(ui->lineEdit1, &QLineEdit::returnPressed, ui->Rename, &QPushButton::click);
    connect(ui->lineEdit2, &QLineEdit::returnPressed, ui->Rename, &QPushButton::click);
}

void MainWindow::loadPDF(){

    //qDebug() << "open is " << filePaths[nowpage];

    //m_document->load(filePaths[nowpage]);

}

void MainWindow::splitPDF(){
    /*
    QString stri = R"(")";
    qDebug() << stri;
    QString command = "split " + stri + filePath + stri;
    qDebug() << command;



    QString command = "split " + filePath;
    qDebug() << command;

    system(command.toUtf8());

    */

    QProcess process;

    process.start("split.exe", { filePath });

    process.waitForFinished();

    qDebug() << process.readAllStandardOutput();
    qDebug() << process.readAllStandardError();


    QStringList list = filePath.split(".");


    for(int i = 0;i < pagecount; i++){
        QString number;
        if(pagecount < 10) number = QString::number(i+1);
        else number = QString("%1").arg(i+1, 2, 10, QChar('0'));
        filePaths[i] = list[0] + "-" + number +".pdf";
        //qDebug() << filePaths[i];
    }
}
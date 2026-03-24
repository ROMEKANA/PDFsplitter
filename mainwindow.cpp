#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    int width = screenGeometry.width() / 2;
    int height = screenGeometry.height();

    setGeometry(0, 0, width, height);  // 左半分

    m_document = new QPdfDocument(this);
    //ui->pdfView_1->setDocument(m_document);

    QHBoxLayout *layout = ui->container;

    for(int i = 0; i < 10; i++) {
        QLabel *label = new QLabel;

        label->setFixedSize(width/10, height);  // サイズ調整
        label->setStyleSheet("border: 1px solid black;");

        layout->addWidget(label);
        m_pages.push_back(label);
    }
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::renderPages()
{
    qDebug() << "render called";

    int pageCount = m_document->pageCount();

    for(int i = 0; i < 10; i++) {

        if(i < pageCount) {

            QSize labelSize = m_pages[i]->size();

            // 元ページサイズ取得
            QSizeF pageSize = m_document->pagePointSize(i);

            // スケール計算
            double scaleW = labelSize.width() / pageSize.width();
            double scaleH = labelSize.height() / pageSize.height();
            double scale = std::min(scaleW, scaleH);

            // 描画サイズ
            QSize renderSize(
                pageSize.width() * scale,
                pageSize.height() * scale
                );

            QImage image = m_document->render(i, renderSize);

            m_pages[i]->setPixmap(QPixmap::fromImage(image));
        }
        else {
            m_pages[i]->clear();
        }
    }
}

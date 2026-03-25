#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPdfDocument>
#include <QFile>
#include <QFileInfo>
#include <Qstring>
#include <QPushButton>
#include <qcoreapplication.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QPdfDocument *m_document;
    QString filePath;
    int pagecount;
    QString filePaths[30];
    void setupConnections();
    void loadPDF();
    void splitPDF();
    int nowpage;

};
#endif // MAINWINDOW_H

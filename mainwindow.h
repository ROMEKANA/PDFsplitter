#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPdfDocument>
#include <QLabel>
#include <QPdfDocument>
#include <QPushButton>
#include <QScreen>
#include <QGuiApplication>


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
    void renderPages();
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QPdfDocument *m_document;
    QVector<QLabel*> m_pages;
    void setupConnections();

};
#endif // MAINWINDOW_H

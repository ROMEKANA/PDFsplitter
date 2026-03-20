#include <QApplication>
#include <QWidget>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>

#include "program.h"

class Window : public QWidget {
public:
	Window(){
		setAcceptDrops(true);
		resize(400, 200);
		setWindowTitle("PDF Splitter");
	}

protected:
	void dragEnterEvent(QDragEnterEvent *event) override {
		if(event->mimeData()->hasUrls()){
			event->accept();
		}
	}

	void dropEvent(QDropEvent *event) override {
		auto urls = event->mimeData()->urls();

		for(auto url : urls){
			QString qpath = url.toLocalFile();
			std::string input = qpath.toStdString();

			splitPDF(input); 
		}
	}
};

int main(int argc, char *argv[]){
	QApplication app(argc, argv);

	Window w;
	w.show();

	return app.exec();
}
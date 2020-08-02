#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  _timer = new QTimer(this);
  connect(_timer, &QTimer::timeout, this, [this] {
    QScreen *screen = QGuiApplication::primaryScreen();
    ui->label->setPixmap(screen->grabWindow(0));
  });
  _timer->setInterval(70);
  _timer->start();
}

MainWindow::~MainWindow() { delete ui; }

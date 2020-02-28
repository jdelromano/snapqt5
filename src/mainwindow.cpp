#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Enter file path");
    ui->label->clear();
    ui->lblQtVersion->setText(QString("Current Qt Version: %1").arg(qVersion()));
    connect(ui->btnOpen, &QPushButton::clicked, [this](){
        QString fName = QFileDialog::getOpenFileName(this, "Select file", "~", "All files (*.*)");
        if(!fName.isEmpty()){
            ui->lineEdit->setText(fName);
        }
    });
    connect(ui->btnExec, &QPushButton::clicked, [this](){
        QUrl toOpen = QUrl::fromLocalFile(ui->lineEdit->text());
        ui->label->setText("openUrl: " + toOpen.toString());
        QDesktopServices::openUrl(toOpen);
    });

    connect(ui->btnXdg, &QPushButton::clicked, [this](){
        QUrl toOpen = QUrl::fromLocalFile(ui->lineEdit->text());
        QString command = QLatin1String(toOpen.toEncoded());
        command.prepend("xdg-open ");
        ui->label->setText(command.toLatin1());
        int res = ::system(command.toLatin1().data());
        ui->label->setText(command.toLatin1() + " -> res= " + QString::number(res));
    });

    connect(ui->btnGoogle, &QPushButton::clicked, [](){
        QUrl google("http://www.google.com");
        QDesktopServices::openUrl(google);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


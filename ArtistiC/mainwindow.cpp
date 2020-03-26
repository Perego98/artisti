#include<QLabel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "splitfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , list1()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_listWidget_Universal_Artist(const QString &path){


    //NOTA aggiungere "https://it.wikipedia.org" al link di wiki
    //NOTA non tutti i  nomi hanno un link
    QString downloadDirectory = QDir::currentPath();
    QString indirizzo = path;
    indirizzo.prepend(downloadDirectory + '/');
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;// ECCEZIONE?
    QTextStream in(&file);
    while (!in.atEnd()) {
       QString line = in.readLine();
       QLabel * myLabel = new QLabel();
       QString link = line.section('"', 1, 1);
       int dim = link.size();
       if(link!= "")
           link.prepend("https://it.wikipedia.org");

       QString name = line;
       name.remove(0,dim+3);

       //"<a href=\""+"\">Click Here!</a>"
       QString labelText = "<a href=\""+ link +"\">" + name + "</a>";

       myLabel->setText(labelText);
       myLabel->setTextFormat(Qt::RichText);
       myLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
       myLabel->setOpenExternalLinks(true);

       //ui->listWidget_Universal_Artist->addItem();
       QListWidgetItem * item = new QListWidgetItem(ui->listWidget_Universal_Artist);


       ui->listWidget_Universal_Artist->addItem(item);

       ui->listWidget_Universal_Artist->setItemWidget(item, myLabel);

    }
}


void MainWindow::set_LabelEtichetta_EMI_Artist(const QString &path){
    //NOTA aggiungere "https://it.wikipedia.org" al link di wiki
    //NOTA non tutti i  nomi hanno un link
    QString downloadDirectory = QDir::currentPath();
    QString indirizzo = path;
    indirizzo.prepend(downloadDirectory + '/');
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;// ECCEZIONE?
    QTextStream in(&file);
    while (!in.atEnd()) {
       QString line = in.readLine();
       QLabel * myLabel = new QLabel();
       QString link = line.section('"', 1, 1);
       int dim = link.size();
       if(link!= "")
           link.prepend("https://it.wikipedia.org");

       QString name = line;
       name.remove(0,dim+3);

       //"<a href=\""+"\">Click Here!</a>"
       QString labelText = "<a href=\""+ link +"\">" + name + "</a>";

       myLabel->setText(labelText);
       myLabel->setTextFormat(Qt::RichText);
       myLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
       myLabel->setOpenExternalLinks(true);

       //ui->listWidget_Universal_Artist->addItem();
       QListWidgetItem * item = new QListWidgetItem(ui->listWidget_EMI_Artist);


       ui->listWidget_EMI_Artist->addItem(item);

       ui->listWidget_EMI_Artist->setItemWidget(item, myLabel);

    }


}

#include<QLabel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "splitfile.h"
#include "grafici1.h"
#include "grafici2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , list1()
{
    ui->setupUi(this);
    //QObject::connect(ui->pushButtonGrafico1, SIGNAL(on_pushButtonGrafico1_clicked()), ui->setupUi(this), SIGNAL(opernGrafici1()));


    //File Name
    QString et1 = "List_of_EMI_artists.txt";
    QString et2 = "List_of_Universal_artists.txt";

     //url
     //QUrl etichetta1("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt");
     //QUrl etichetta2("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt");

     //string
     const QString etichetta1("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt");
     const QString etichetta2("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt");


     // download file
     try {
         manager = new downloadfiles(et1);
         manager->download(etichetta1);
     } catch (...) {
         delete manager;
         manager = nullptr;
     }


}

MainWindow::~MainWindow()
{
    delete manager;
    manager = nullptr;
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
       QLabel * myLabel;
       try {
           myLabel = new QLabel();
       } catch (...) {
           myLabel = nullptr;
       }

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
       QListWidgetItem * item;
       try {
           item = new QListWidgetItem(ui->listWidget_EMI_Artist);
       } catch (...) {
           item = nullptr;
       }

       ui->listWidget_EMI_Artist->addItem(item);

       ui->listWidget_EMI_Artist->setItemWidget(item, myLabel);

    }


}

void MainWindow::on_pushButtonGrafico1_clicked()
{
    grafici1 sec;
    sec.setModal(true);
    sec.exec();
}


void MainWindow::on_pushButton_grafico2_clicked()
{
    grafici2 sec;
    sec.setModal(true);
    sec.exec();
}


#include<QLabel>


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "grafico.h"
#include "grafico1.h"
#include "grafico2.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , list1()
{
    ui->setupUi(this);
}

void MainWindow::loadFileTXT(){
    QString et2 = "List_of_EMI_artists.txt";
     QString et1 = "List_of_Universal_artists.txt";
    set_listWidget_Universal_Artist(et2);
    set_LabelEtichetta_EMI_Artist(et1);
}

MainWindow::~MainWindow()
{

}

void MainWindow::set_listWidget_Universal_Artist(const QString &path){


    //NOTA aggiungere "https://it.wikipedia.org" al link di wiki
    //NOTA non tutti i  nomi hanno un link
    //NOTA non sempre esiste un nome ma esiste il link
    //NOTA il file è diviso per righe
    /*QString downloadDirectory = QDir::currentPath();
    QString indirizzo = path;
    indirizzo.prepend(downloadDirectory + '/');*/

    // creo un QFile per poter leggere Universal Artist
    QFile file(path);

    // se non è possibile aprire il file di testo in sola lettura interrompo con return;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;// ECCEZIONE?


    // leggo fino a che non finisco il file
    QTextStream in(&file);
    while (!in.atEnd()) {
        //leggo una riga per riga
       QString line = in.readLine();
       QLabel * myLabel = new QLabel();

       //estraggo il link contenuto nei " "
       QString link = line.section('"', 1, 1);
       int dim = link.size();

       //se il link è presente compongo il link in modo da poterlo aprire
       if(link!= "")
           link.prepend("https://it.wikipedia.org");


       QString name = line;
       //rimuovo la lunghezza del link piu i 3 caratteri
       //che comprendono "" e uno spazio, per avere il nome
       name.remove(0,dim+3);

       // se il nome non è presente metto un nome di default
       if(name=="")
           name = "404 name not found";

       //compongo il testo della label con html per inserire il link
       QString labelText = "<a href=\""+ link +"\">" + name + "</a>";

       // setto la Lable
       myLabel->setText(labelText);
       myLabel->setTextFormat(Qt::RichText);
       myLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
       myLabel->setOpenExternalLinks(true);

       //ui->listWidget_Universal_Artist->addItem();
       // creo un puntatore a un QListWidgetItem e lo collego alla QListWidget nella mainwindow.ui
       QListWidgetItem * item = new QListWidgetItem(ui->listWidget_Universal_Artist);

       // aggiungo l'item
       ui->listWidget_Universal_Artist->addItem(item);

       // riempio l'item con mylabel
       ui->listWidget_Universal_Artist->setItemWidget(item, myLabel);
    }
}


void MainWindow::set_LabelEtichetta_EMI_Artist(const QString &path){
    //NOTA aggiungere "https://it.wikipedia.org" al link di wiki
    //NOTA non tutti i  nomi hanno un link
    //NOTA non sempre esiste un nome ma esiste il link
    //NOTA il file è diviso per righe
    /*QString downloadDirectory = QDir::currentPath();
    QString indirizzo = path;
    indirizzo.prepend(downloadDirectory + '/');*/

    // creo un QFile per poter leggere EMI Artist
    QFile file(path);

     // se non è possibile aprire il file di testo in sola lettura interrompo con return;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;// ECCEZIONE?

     // leggo fino a che non finisco il file
    QTextStream in(&file);
    while (!in.atEnd()) {
        //leggo una riga per riga
       QString line = in.readLine();
       QLabel * myLabel;
       try {
           myLabel = new QLabel();
       } catch (...) {
           myLabel = nullptr;
       }

       //estraggo il link contenuto nei " "
       QString link = line.section('"', 1, 1);
       int dim = link.size();


       if(link!= "")
           link.prepend("https://it.wikipedia.org");

       QString name = line;

       //rimuovo la lunghezza del link piu i 3 caratteri
       //che comprendono "" e uno spazio, per avere il nome
       name.remove(0,dim+3);

       // se il nome non è presente metto un nome di default
       if(name=="")
           name = "404 name not found";

       //compongo il testo della label con html per inserire il link
       QString labelText = "<a href=\""+ link +"\">" + name + "</a>";

       // setto la Lable
       myLabel->setText(labelText);
       myLabel->setTextFormat(Qt::RichText);
       myLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
       myLabel->setOpenExternalLinks(true);

       // creo un puntatore a un QListWidgetItem e lo collego alla QListWidget nella mainwindow.ui
       QListWidgetItem * item = new QListWidgetItem(ui->listWidget_EMI_Artist);

         // aggiungo l'item
       ui->listWidget_EMI_Artist->addItem(item);

        // riempio l'item con mylabel
       ui->listWidget_EMI_Artist->setItemWidget(item, myLabel);
    }
}

void MainWindow::on_pushButtonGrafico1_clicked()
{
        grafico *grf;
        grf = new grafico();
        grf->show();
}


void MainWindow::on_pushButton_grafico2_clicked()
{
        grafico2 *grf2;
        grf2 = new grafico2();
        grf2->show();
}


void MainWindow::on_pushButtonGrafico2_clicked()
{
        grafico1 *grf1;
        grf1 = new grafico1();
        grf1->show();
}



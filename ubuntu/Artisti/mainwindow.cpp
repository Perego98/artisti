#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , emi(0)
    , universal(0)
{
    ui->setupUi(this);

    // inizializzo count_emi e count_universal;
        for (int i =0;i<27;i++){
            count_emi[i]=0;
            count_universal[i]=0;
        }


}

void MainWindow::loadFileTXT(){
    QString et2 = "List_of_EMI_artists.txt";
     QString et1 = "List_of_Universal_artists.txt";
    set_listWidget_Universal_Artist(et2);
    set_LabelEtichetta_EMI_Artist(et1);
    calcola_dati_emi();
    calcola_dati_universal();
    ui->emi_layout->addWidget(crea_emi());
    ui->universal_layout->addWidget(crea_universal());
    ui->number_layout->addWidget(crea_numeri());
    QMainWindow::showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcola_dati_universal(){
    QString et2 = "List_of_Universal_artists.txt";
        QFile file(et2);


        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            std::cout << "Non riesco ad aprire " << qPrintable(et2)
                      << " errore: "<< qPrintable(file.errorString()) << std::endl;
        }
        else{
            QTextStream in(&file);


        // fino a che non finisco il file leggo riga per riga
        while (!in.atEnd()) {
           QString line = in.readLine();
            universal++;
           // trovo la lunghezza del link
           QString link = line.section('"', 1, 1);
           int dim = link.size();

           // tolgo tutto ciò che non è il nome
           QString name = line;
           name.remove(0,dim+3);

            // se il nome è presente
           if(name.length()>0){

              // while(name.at(0) == ' ')
               //    name.remove(0,1);

               // prendo ilprimo carattere e richiamo conta
               QChar carattere = name.at(0);
               conta_universal(carattere);
           }
        }
     }
  }

void MainWindow::calcola_dati_emi(){
    QString et1 = "List_of_EMI_artists.txt";
        QFile file(et1);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            std::cout << "Non riesco ad aprire " << qPrintable(et1)
                      << " errore: "<< qPrintable(file.errorString()) << std::endl;
        }
        else{
            QTextStream in(&file);

            // fino a che non finisco il file leggo riga per riga
            while (!in.atEnd()) {
            QString line = in.readLine();
            emi++;

            // trovo la lunghezza del link
            QString link = line.section('"', 1, 1);
            int dim = link.size();

            // tolgo tutto ciò che non è il nome
            QString name = line;
            name.remove(0,dim+3);

            // se il nome è presente
            if(name.length()>0){

               // prendo ilprimo carattere e richiamo conta
               QChar carattere = name.at(0);
               conta_emi(carattere);
         }
      }
   }
}

void MainWindow::conta_emi(QChar &val){

    // trasformo il carattere in unicode e ne faccio il casting in intero
    int code = (int)val.unicode();

    // controllo che non sia nei range delle lettere minuscole e maiuscole
    // se non è li allora aumento il valore della prima cella che conta tutti i caratteri diversi dalle lettere
    if((code<65 || (code>90 && code<97) || code>122))
            count_emi[0]++;
    else if(code>=65 && code<=90)// conto cercando tra le lettere maiuscole
        count_emi[(code-64)]++;
    else if(code>=97 && code<=122) // conto cercando tra le lettere minuscole
        count_emi[(code-64-32)]++;
}

void MainWindow::conta_universal(QChar &val){

    // trasformo il carattere in unicode e ne faccio il casting in intero
    int code = (int)val.unicode();

    // controllo che non sia nei range delle lettere minuscole e maiuscole
    // se non è li allora aumento il valore della prima cella che conta tutti i caratteri diversi dalle lettere
    if((code<65 || (code>90 && code<97) || code>122))
            count_universal[0]++;
    else if(code>=65 && code<=90)// conto cercando tra le lettere maiuscole
        count_universal[(code-64)]++;
    else if(code>=97 && code<=122) // conto cercando tra le lettere minuscole
        count_universal[(code-64-32)]++;
}


void MainWindow::set_listWidget_Universal_Artist(const QString &path){


    //NOTA aggiungere "https://it.wikipedia.org" al link di wiki
    //non tutti i  nomi hanno un link
    //non sempre esiste un nome ma esiste il link
    //il file è diviso per righe

    // creo un QFile per poter leggere Universal Artist
    QFile file(path);

    // se non è possibile aprire il file di testo in sola lettura interrompo con return;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


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

    // creo un QFile per poter leggere EMI Artist
    QFile file(path);

     // se non è possibile aprire il file di testo in sola lettura interrompo con return;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

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

QChartView * MainWindow::crea_emi(){
    // lettera di partenza
     QChar let = 'a';

     // creo il set con nome lettere
     QBarSet *set = new QBarSet("lettere");

     // inserisco i valori per ogni lettera
     // in prima posizione in realtà ci sono tutti i carateri
     // che non sono lettere che chiamerò per semplicità, numeri
     for (int i =0;i<27;i++) {
         int value = count_emi[i];
         *set << value;
     }


     //creo le series
     QBarSeries *series = new QBarSeries();


     // aggiungo i numero sul grafico
     series->setLabelsVisible(true);
     series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
     set->setLabelColor(QColor(0,0,0));

     // aggiungo i set creati in precedenza
     series->append(set);

     // creo un chart
     QChart *chart = new QChart();

     // aggiongo il chart
     chart->addSeries(series);

     // Setto il titolo
     chart->setTitle("EMI Artist");


     // Definizione animazioni
     chart->setAnimationOptions(QChart::AllAnimations);

     // Holds the category titles
     QStringList categories;
     QChar cat;

     // inserisco i nomi di ogni barra
     categories << "Numeri";
     for (int i =1;i<27;i++) {
         cat = let.unicode()+(i-1);
         categories << cat;
     }

     // creo e setto gli assi
     QBarCategoryAxis *axis = new QBarCategoryAxis();
     axis->append(categories);
     chart->createDefaultAxes();

     chart->setAxisX(axis, series);

     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);

     // Used to display the chart
     //QChartView *chartView = new QChartView(chart);
     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     // cambio palette
     QPalette pal = qApp->palette();

     // cambio ilcolore attorno il chart e il testo
     pal.setColor(QPalette::Window, QRgb(0xffffff));
     pal.setColor(QPalette::WindowText, QRgb(0x404044));

     // applico i cambiamenti
     qApp->setPalette(pal);

     return chartView;
}

QChartView * MainWindow::crea_numeri(){

    // creo il grafico
       QBarSet *set = new QBarSet("numero artisti");
       *set << emi << universal;


       QBarSeries *series = new QBarSeries();

       // aggiungo i numero sul grafico
       series->setLabelsVisible(true);
       series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
       set->setLabelColor(QColor(0,0,0));

       series->append(set);
       QChart *chart = new QChart();

       // aggiungo chart
       chart->addSeries(series);

       // Setto il titolo
       chart->setTitle("Numero Artisti");


       // Definisco l'aimazione iniziale
       chart->setAnimationOptions(QChart::AllAnimations);

       QStringList categories;

       categories << "EMI Artist" << "Universal Artist";


       QBarCategoryAxis *axis = new QBarCategoryAxis();
       axis->append(categories);
       chart->createDefaultAxes();

       chart->setAxisX(axis, series);

       chart->legend()->setVisible(true);
       chart->legend()->setAlignment(Qt::AlignBottom);

       // lo uso per mostrare il chart
       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);


       // Used to change the palette
       QPalette pal = qApp->palette();

       // cambio il colore attorno al chart e del testo
       pal.setColor(QPalette::Window, QRgb(0xffffff));
       pal.setColor(QPalette::WindowText, QRgb(0x404044));

       // applico i cambiamenti
       qApp->setPalette(pal);

       return chartView;

}

QChartView * MainWindow::crea_universal(){

    // lettera di partenza
    QChar let = 'a';

    // creo il set con nome lettere
    QBarSet *set = new QBarSet("lettere");

    // inserisco i valori per ogni lettera
    // in prima posizione in realtà ci sono tutti i carateri
    // che non sono lettere che chiamerò per semplicità, numeri
    for (int i =0;i<27;i++) {
        int value = count_universal[i];
        *set << value;
    }


    //creo le series
    QBarSeries *series = new QBarSeries();

    // aggiungo i numero sul grafico
    series->setLabelsVisible(true);
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    set->setLabelColor(QColor(0,0,0));

    // aggiungo i set creati in precedenza
    series->append(set);

    // creo un chart
    QChart *chart = new QChart();

    // aggiongo il chart
    chart->addSeries(series);

    // Setto il titolo
    chart->setTitle("Universal Artist");


    // Definizione animazioni
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    QChar cat;

    // inserisco i nomi di ogni barra
    categories << "Numeri";
    for (int i =1;i<27;i++) {
        cat = let.unicode()+(i-1);
        categories << cat;
    }

    // creo e setto gli assi
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    chart->setAxisX(axis, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to display the chart
    //QChartView *chartView = new QChartView(chart);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // cambio palette
    QPalette pal = qApp->palette();

    // cambio ilcolore attorno il chart e il testo
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // applico i cambiamenti
    qApp->setPalette(pal);

    return chartView;
}


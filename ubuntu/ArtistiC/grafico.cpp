#include "grafico.h"
#include "ui_grafico.h"

#include <iostream>

grafico::grafico(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grafico)
{


    ui->setupUi(this);

    // inizializzo count;
    for (int i =0;i<27;i++)
        count[i]=0;


     setCentralWidget(createch());
     show();

}

// crea ilgrafico leggendo i dati dal file
QChartView * grafico::createch(){
    QString et1 = "List_of_EMI_artists.txt";
    QFile file(et1);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "Non riesco ad aprire " << qPrintable(et1)
                  << " errore: "<< qPrintable(file.errorString()) << std::endl;
        return nullptr;
    }


    QTextStream in(&file);

    // fino a che non finisco il file leggo riga per riga
    while (!in.atEnd()) {
       QString line = in.readLine();

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
           conta(carattere);
       }

    }

    // lettera di partenza
    QChar let = 'a';

    // creo il set con nome lettere
    QBarSet *set = new QBarSet("lettere");

    // inserisco i valori per ogni lettera
    // in prima posizione in realtà ci sono tutti i carateri
    // che non sono lettere che chiamerò per semplicità, numeri
    for (int i =0;i<27;i++) {
        int value = count[i];
        *set << value;
    }


    //creo le series
    QBarSeries *series = new QBarSeries();

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

void grafico::conta(QChar &val){

    // trasformo il carattere in unicode e ne faccio il casting in intero
    int code = (int)val.unicode();

    // controllo che non sia nei range delle lettere minuscole e maiuscole
    // se non è li allora aumento il valore della prima cella che conta tutti i caratteri diversi dalle lettere
    if((code<65 || (code>90 && code<97) || code>122))
            count[0]++;
    else if(code>=65 && code<=90)// conto cercando tra le lettere maiuscole
        count[(code-64)]++;
    else if(code>=97 && code<=122) // conto cercando tra le lettere minuscole
        count[(code-64-32)]++;
}

grafico::~grafico()
{
    delete ui;
}

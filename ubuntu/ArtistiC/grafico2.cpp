#include "grafico2.h"
#include "ui_grafico2.h"

#include <iostream>

grafico2::grafico2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grafico2)
{
    ui->setupUi(this);
    setCentralWidget(createch());
    show();
}

QChartView * grafico2::createch(){
    QString et2 = "List_of_Universal_artists.txt";
    QString et1 = "List_of_EMI_artists.txt";
    QFile file(et2);
    int EMI=0, Universal=0;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "Non riesco ad aprire " << qPrintable(et2)
                  << " errore: "<< qPrintable(file.errorString()) << std::endl;
        return nullptr;
    }

    // leggo e conto ogni riga di Universal artist
    QTextStream in(&file);
    while (!in.atEnd()) {
       QString line = in.readLine();
       Universal++;
    }

    QFile file2(et1);

    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "Non riesco ad aprire " << qPrintable(et1)
                  << " errore: "<< qPrintable(file.errorString()) << std::endl;
        return nullptr;
    }

        // leggo e conto ogni riga di EMI artist
    QTextStream in2(&file2);
    while (!in2.atEnd()) {
       QString line = in2.readLine();
       EMI++;
    }



    // creo il grafico
    QBarSet *set = new QBarSet("numero artisti");
    *set << EMI << Universal;


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
    chart->setTitle("test");


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


grafico2::~grafico2()
{
    delete ui;
}

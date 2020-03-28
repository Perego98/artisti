#include "grafico2.h"
#include "ui_grafico2.h"

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

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return nullptr;// ECCEZIONE?

    QTextStream in(&file);
    while (!in.atEnd()) {
       QString line = in.readLine();
       Universal++;
    }

    QFile file2(et1);
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
        return nullptr;// ECCEZIONE?

    QTextStream in2(&file2);
    while (!in2.atEnd()) {
       QString line = in2.readLine();
       EMI++;
    }



    QBarSet *set = new QBarSet("numero artisti");
    *set << EMI << Universal;




    QBarSeries *series = new QBarSeries();
    series->append(set);
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("test");


    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;

    categories << "EMI Artist" << "Universal Artist";


    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to display the chart
    //QChartView *chartView = new QChartView(chart);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // Apply palette changes to the application
    qApp->setPalette(pal);

    return chartView;

}


grafico2::~grafico2()
{
    delete ui;
}

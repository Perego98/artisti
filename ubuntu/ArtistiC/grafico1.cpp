#include "grafico1.h"
#include "ui_grafico1.h"

grafico1::grafico1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grafico1)
{
    ui->setupUi(this);

    // inizializzo count;
    for (int i =0;i<27;i++)
        count[i]=0;

    setCentralWidget(createch());
    show();
}


QChartView * grafico1::createch(){
    QString et2 = "List_of_Universal_artists.txt";
    QFile file(et2);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return nullptr;// ECCEZIONE?

    QTextStream in(&file);
    while (!in.atEnd()) {
       QString line = in.readLine();

       QString link = line.section('"', 1, 1);
       int dim = link.size();

       QString name = line;
       name.remove(0,dim+3);

       if(name.length()>0){
           QChar carattere = name.at(0);
           conta(carattere);
       }

    }

    QChar let = 'a';
    // popolo i set

    QBarSet *set = new QBarSet("lettere");

    for (int i =0;i<27;i++) {
        int value = count[i];
        *set << value;
    }



    QBarSeries *series = new QBarSeries();
    series->append(set);
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Universal Artist");


    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    QChar cat;

    categories << "Numeri";
    for (int i =1;i<27;i++) {
        cat = let.unicode()+(i-1);
        categories << cat;
    }

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

// valore piccolo posso passarlo per copia
void grafico1::conta(QChar val){
    int code = (int)val.unicode();
    if((code<65 || (code>90 && code<97) || code>122))
            count[0]++;
    else if(code>=65 && code<=90)
        count[(code-64)]++;
    else if(code>=97 && code<=122)
        count[(code-64-32)]++;
}

grafico1::~grafico1()
{
    delete ui;
}

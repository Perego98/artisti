#include<QLabel>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include<QtCharts>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "splitfile.h"
#include "grafico1.h"
#include "grafico2.h"
#include "grafico.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , list1()
    , bt1_pressed(false)
    , bt2_pressed(false)
    , bt3_pressed(false)
{
    ui->setupUi(this);
    //QObject::connect(ui->pushButtonGrafico1, SIGNAL(on_pushButtonGrafico1_clicked()), ui->setupUi(this), SIGNAL(opernGrafici1()));


    //File Name
    QString et1 = "List_of_EMI_artists.txt";
    QString et2 = "List_of_Universal_artists.txt";

     //url
     QUrl etichetta1("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt");
     QUrl etichetta2("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt");

     //string
     //const QString etichetta1("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt");
     //const QString etichetta2("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt");







     try {
         manager = new download();
         manager->setTarget(etichetta1);
         manager->setFileName(et1);
         manager->downloadstr();
     } catch (...) {
         delete manager;
         manager = nullptr;
     }


     try {
         manager2 = new download(et2);
         manager2->setTarget(etichetta2);
         //manager2->setFileName(et2);
         manager2->downloadstr();
     } catch (...) {
         delete manager2;
         manager2 = nullptr;
     }

     //QObject::connect(&dl, SIGNAL(done()), &app, SLOT(quit()));



}

MainWindow::~MainWindow()
{
    delete manager;
    manager = nullptr;
    delete manager2;
    manager2 = nullptr;
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
       if(name=="")
           name = "!name not found!";

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
    ui->listWidget_EMI_Artist->update();
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
       if(name=="")
           name = "!name not found!";

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
    /*grafici1 sec;
    sec.setModal(true);
    sec.exec();*/
        grafico *grf;
        grf = new grafico();
        grf->show();
        bt1_pressed = true;

    /*
    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinez");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("Trout");

    // Assign values for each bar
    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
    *set4 << 323 << 287 << 299 << 315 << 306 << 313;

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Batting Avg by Year");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart
    // chart->setAxisY(axis, series);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to display the chart
    //QChartView *chartView = new QChartView(chart);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->show();
    chartView->show();

    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // Apply palette changes to the application
    qApp->setPalette(pal);

    QWidget window;
    window.setMaximumSize(700, 700);
    window.setMinimumSize(700, 700);
            // Set the main window widget
    //window.setCentralWidget(chartView);
    //window.resize(420, 300);
    window.show();
    */


/*
    //![1]
        QBarSet *set0 = new QBarSet("Jane");
        QBarSet *set1 = new QBarSet("John");
        QBarSet *set2 = new QBarSet("Axel");
        QBarSet *set3 = new QBarSet("Mary");
        QBarSet *set4 = new QBarSet("Samantha");

        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,15);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]

    //![7]
        QMainWindow window;
        window.setCentralWidget(chartView);
        window.resize(420, 300);
        window.show();
    //![7]
    //! */
}


void MainWindow::on_pushButton_grafico2_clicked()
{
        grafico2 *grf2;
        grf2 = new grafico2();
        grf2->show();
        bt2_pressed = true;
}


void MainWindow::on_pushButtonGrafico2_clicked()
{
        grafico1 *grf1;
        grf1 = new grafico1();
        grf1->show();
        bt3_pressed = true;

}



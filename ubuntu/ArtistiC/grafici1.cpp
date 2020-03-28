#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
#include <QtCharts>

#include "grafici1.h"
#include "ui_grafici1.h"

grafici1::grafici1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grafici1)
{
    ui->setupUi(this);

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

                    // Set the main window widget
            //window.setCentralWidget(chartView);
            window.resize(420, 300);
            window.show();

}

grafici1::~grafici1()
{
    delete ui;
}

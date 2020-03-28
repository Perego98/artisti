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

#include "gradico_doppio.h"
#include "ui_gradico_doppio.h"

gradico_doppio::gradico_doppio(QWidget *parent) :
    QWidget(parent),
    m_listCount(3),
    m_valueMax(10),
    m_valueCount(7),
    m_dataTable(generateRandomData(m_listCount, m_valueMax, m_valueCount)),
    ui(new Ui::gradico_doppio)
{
    ui->setupUi(this);

    ui->setupUi(this);
        populateThemeBox();
        populateAnimationBox();
        populateLegendBox();

        //create charts

        QChartView *chartView;

        chartView = new QChartView(createAreaChart());
        ui->gridLayout->addWidget(chartView, 1, 0);
        m_charts << chartView;

        chartView = new QChartView(createPieChart());
        // Funny things happen if the pie slice labels do not fit the screen, so we ignore size policy
        chartView->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        ui->gridLayout->addWidget(chartView, 1, 1);
        m_charts << chartView;

        //![5]
        chartView = new QChartView(createLineChart());
        ui->gridLayout->addWidget(chartView, 1, 2);
        //![5]
        m_charts << chartView;

        chartView = new QChartView(createBarChart(m_valueCount));
        m_ui->gridLayout->addWidget(chartView, 2, 0);
        m_charts << chartView;

        chartView = new QChartView(createSplineChart());
        m_ui->gridLayout->addWidget(chartView, 2, 1);
        m_charts << chartView;

        chartView = new QChartView(createScatterChart());
        m_ui->gridLayout->addWidget(chartView, 2, 2);
        m_charts << chartView;

        // Set defaults
        m_ui->antialiasCheckBox->setChecked(true);

        // Set the colors from the light theme as default ones
        QPalette pal = qApp->palette();
        pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
        qApp->setPalette(pal);

        updateUI();


}

gradico_doppio::~gradico_doppio()
{
    delete ui;
}

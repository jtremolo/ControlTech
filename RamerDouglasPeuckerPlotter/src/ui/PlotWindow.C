
#include "PlotWindow.h"
#include <QDebug>
#include <QFile>


UI::PlotWindow::PlotWindow( QWidget* Parent )
  : QMainWindow( Parent ),
    m_chart( nullptr ),
    m_lineSeries( nullptr ),
    m_animationTimer( nullptr )
{
  initialize();
}


UI::PlotWindow::~PlotWindow()
{
  //! Stop any running animations
  stopAnimation();
}


void UI::PlotWindow::onLoadFile()
{
  //! Get data file path
  QString fileName = QFileDialog::getOpenFileName( this, tr( "Open File" ), QString(), tr( "Data File (*.csv)" ) );

  if( !fileName.isNull() )
  {
    //! Load file and set data
    bool loaded = loadFile( fileName );
    if( loaded )
    {
      //! Enable the epsilon options and reset the value
      m_epsilonLabel->setEnabled( true );
      m_epsilonSpinBox->setEnabled( true );
      m_animateButton->setEnabled( true );

      m_epsilonSpinBox->setValue( 0.0 );
    }
    else
    {
      //! Error if file unreadable
      QMessageBox::critical( this, tr( "File Error" ), tr( "Unable to load data file:\n%1" ).arg( fileName ) );
    }
  }
}


void UI::PlotWindow::onEpsilonChanged( double epsilon )
{
  //! Stop animation 
  stopAnimation();

  //! Run RDP algorithm
  Data::PlotData smoothedData( m_plotData );
  smoothedData.smoothWithRDP( epsilon );

  //! Update data series
  if( m_lineSeries != nullptr )
    m_lineSeries->replace( smoothedData.data().toList() );
}


void UI::PlotWindow::onAnimateClicked()
{
  if( m_animationTimer != nullptr )
  {
    //! Stop previous animation
    onEpsilonChanged( m_epsilonSpinBox->value() );
  }
  else
  {
    //! Start new animation
    startAnimation();
  }
}


void UI::PlotWindow::animateStep()
{
  //! Run RDP algorithm
  Data::PlotData smoothedData( m_plotData );
  smoothedData.smoothWithRDP( m_animationEpsilon );

  //! Update data series
  if( m_lineSeries != nullptr )
    m_lineSeries->replace( smoothedData.data().toList() );

  //! Set next epsilon value
  m_animationEpsilon += 0.001;
  if( m_animationEpsilon > m_epsilonSpinBox->value() )
    m_animationEpsilon = 0.0;
}


void UI::PlotWindow::initialize()
{
  //! Create main layout
  QVBoxLayout* mainVBox = new QVBoxLayout();

  //! Create load button
  QPushButton* loadFileButton = new QPushButton( tr( "Load .csv file" ) );
  mainVBox->addWidget( loadFileButton );

  //! Create epsilon entry
  m_epsilonLabel = new QLabel( tr( "Epsilon: " ) );
  m_epsilonSpinBox = new QDoubleSpinBox();
  m_epsilonSpinBox->setRange( 0.0, 100.0 );
  m_epsilonSpinBox->setDecimals( 3 );
  m_epsilonSpinBox->setSingleStep( 0.001 );
  m_epsilonSpinBox->setValue( 0.0 );
  m_epsilonLabel->setEnabled( false );
  m_epsilonSpinBox->setEnabled( false );

  QHBoxLayout* epsilonLayout = new QHBoxLayout();
  epsilonLayout->addWidget( m_epsilonLabel );
  epsilonLayout->addWidget( m_epsilonSpinBox );
  epsilonLayout->addStretch( 1 );
  mainVBox->addLayout( epsilonLayout );

  //! Add animate button
  m_animateButton = new QPushButton( tr( "Start Animation" ) );
  m_animateButton->setEnabled( false );

  QHBoxLayout* animateLayout = new QHBoxLayout();
  animateLayout->addWidget( m_animateButton );
  animateLayout->addStretch( 1 );
  mainVBox->addLayout( animateLayout );

  //! Create chart
  m_chart = new QChart();
  m_chart->legend()->hide();
  m_chart->setTitle( "Ramer-Douglas-Peucker Algorithm" );

  //! Create chart view
  QChartView* chartView = new QChartView( m_chart );
  chartView->setRenderHint( QPainter::Antialiasing );
  mainVBox->addWidget( chartView );

  //! Create layout
  QWidget* layoutWidget = new QWidget();
  layoutWidget->setLayout( mainVBox );

  setCentralWidget( layoutWidget );
  resize( 800, 600 );

  //! Connect signals
  connect( loadFileButton, &QPushButton::clicked,
           this,           &PlotWindow::onLoadFile ); 
  connect( m_epsilonSpinBox, SIGNAL( valueChanged( double ) ),
           this,             SLOT( onEpsilonChanged( double ) ) );
  connect( m_animateButton, &QPushButton::clicked,
           this,            &PlotWindow::onAnimateClicked ); 
}


bool UI::PlotWindow::loadFile( const QString& filePath )
{
  if( !readCSVFile( filePath ) )
    return false;

  //! Remove old series
  if( m_lineSeries != nullptr )
  {
    m_chart->removeSeries( m_lineSeries );
    delete m_lineSeries;
    m_lineSeries = nullptr;
  }

  //! Create data series and update axes
  m_lineSeries = new QLineSeries();
  m_lineSeries->append( m_plotData.data().toList() );
  m_chart->addSeries( m_lineSeries );
  m_chart->createDefaultAxes();

  return true;
}


bool UI::PlotWindow::readCSVFile( const QString& filePath )
{
  QFile file( filePath );
  if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
  {
    qDebug() << "Error: Unable to open file!";
    return false;
  }

  QVector< QPointF > loadedPoints;
  while( !file.atEnd() )
  {
    QString line = file.readLine();
    QStringList parts( line.split( ',' ) );
    if( parts.count() != 2 )
      return false;

    loadedPoints.append( QPointF( parts[ 0 ].toDouble(),
                                  parts[ 1 ].toDouble() ) );
  }

  file.close();
  m_plotData = Data::PlotData( loadedPoints );
  return true;
}


void UI::PlotWindow::stopAnimation()
{
  if( m_animationTimer != nullptr )
  {
    m_animationTimer->stop();
    delete m_animationTimer;
    m_animationTimer = nullptr;
  }

  m_animateButton->setText( tr( "Start Animation" ) );
}


void UI::PlotWindow::startAnimation()
{
  //! Create the timer and reset epsilon
  m_animationEpsilon = 0.0;
  m_animationTimer = new QTimer( this );

  //! Connect signal and start
  connect( m_animationTimer, &QTimer::timeout,
           this,             &PlotWindow::animateStep );
  m_animationTimer->start( 100 );

  //! Change button text
  m_animateButton->setText( tr( "Stop Animation" ) );
}

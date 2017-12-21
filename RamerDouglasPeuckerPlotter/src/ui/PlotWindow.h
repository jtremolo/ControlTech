
#pragma once

#include <QMainWindow>
#include <QtCharts>
#include <data/PlotData.h>


namespace UI
{
  //! This main window contains a plotting area
  //! and the needed controls for the
  //! Ramer-Douglas-Peucker algorithm.
  class PlotWindow : public QMainWindow
  {
    Q_OBJECT

    public:

      //! Constructor
      //!
      //! \param Parent Parent widget to take ownership of this.
      explicit PlotWindow( QWidget* Parent = nullptr );

      //! Destructor
      virtual ~PlotWindow();


    private slots:

      //! Prompt user to select file and load data.
      void onLoadFile();

      //! Run the RDP algortithm for new epsilon.
      void onEpsilonChanged( double epsilon );

      //! Animate a range of epsilon values.
      void onAnimateClicked();

      //! Run the current animation step.
      void animateStep();


    private:

      void initialize();

      bool loadFile( const QString& filePath );
      bool readCSVFile( const QString& filePath );

      void startAnimation();
      void stopAnimation();

      Data::PlotData m_plotData;

      QChart* m_chart;
      QLineSeries* m_lineSeries;

      QLabel* m_epsilonLabel;
      QDoubleSpinBox* m_epsilonSpinBox;
      QPushButton* m_animateButton;

      double m_animationEpsilon;
      QTimer* m_animationTimer;
  };
}

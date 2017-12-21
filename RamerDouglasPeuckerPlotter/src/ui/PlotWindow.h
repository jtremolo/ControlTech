
#pragma once

#include <QMainWindow>
#include <QtCharts>
#include <data/PlotData.h>


namespace UI
{
  class PlotWindow : public QMainWindow
  {
    Q_OBJECT

    public:

      explicit PlotWindow( QWidget* Parent = nullptr );

      virtual ~PlotWindow();


    private slots:

      void onLoadFile();
      void onEpsilonChanged( double epsilon );


    private:

      void initialize();

      bool loadFile( const QString& filePath );
      bool readCSVFile( const QString& filePath );

      Data::PlotData m_plotData;

      QChart* m_chart;
      QLineSeries* m_lineSeries;

      QLabel* m_epsilonLabel;
      QDoubleSpinBox* m_epsilonSpinBox;
      QPushButton* m_animateButton;
  };
}

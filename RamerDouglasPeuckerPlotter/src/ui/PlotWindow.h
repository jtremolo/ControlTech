
#pragma once

#include <QMainWindow>


namespace UI
{
  class PlotWindow : public QMainWindow
  {
    public:

      explicit PlotWindow( QWidget* Parent = nullptr );

      virtual ~PlotWindow();
  };
}

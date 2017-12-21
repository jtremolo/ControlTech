
#include <QApplication>
#include "PlotWindow.h"


int main( int argc, char** argv )
{
  QApplication app( argc, argv );

  //! Create and show plot
  UI::PlotWindow plotter;
  plotter.show();

  return app.exec();
}

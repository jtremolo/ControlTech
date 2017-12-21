
#pragma once

#include <QList>
#include <QPair>


namespace Data
{
  class PlotData
  {
    public:

      bool smoothWithRDP( const double epsilon );


    private:

      QList< QPair< double, double > > douglasPeucker( const QList< QPair< double, double > >& data,
                                                       const double                            epsilon ) const;

      QList< QPair< double, double > > m_plotData;
  };
}


#pragma once

#include <QLine>
#include <QList>
#include <QPoint>


namespace Data
{
  class PlotData
  {
    public:

      //! Constructor
      //!
      //! \param plotData Plot data used to initialize the class.
      explicit PlotData( const QList< QPointF >& plotData );

      //! Smooth the plot data with Ramer-Douglas-Peucker algorithm
      //!
      //! \param epsilon Dimensional tolerance
      //! \returns \c true if successful, \c false otherwise.
      bool smoothWithRDP( const double epsilon );


    private:

      QList< QPointF > douglasPeucker( const QList< QPointF >& data,
                                       const double            epsilon ) const;
      double perpindicularDistance( const QLineF&  referenceLine,
                                    const QPointF& checkPoint ) const;

      QList< QPointF > m_plotData;
  };
}


#pragma once

#include <QLine>
#include <QVector>
#include <QPoint>


namespace Data
{
  //! Represents a continuous ordered dataset.
  //! If data is unordered, it will be sorted by
  //! x value.
  class PlotData
  {
    public:

      //! Constructor
      //!
      //! \param plotData Plot data used to initialize the class.
      explicit PlotData( const QVector< QPointF >& plotData );

      //! Get the plot data
      const QVector< QPointF >& data() const { return m_plotData; }

      //! Smooth the plot data with Ramer-Douglas-Peucker algorithm
      //!
      //! \param epsilon Dimensional tolerance
      //! \returns \c true if successful, \c false otherwise.
      bool smoothWithRDP( const double epsilon );


    private:

      void sortData();

      QVector< QPointF > douglasPeucker( const QVector< QPointF >& data,
                                         const double            epsilon ) const;

      double perpindicularDistance( const QLineF&  referenceLine,
                                    const QPointF& checkPoint ) const;

      QVector< QPointF > m_plotData;
  };
}

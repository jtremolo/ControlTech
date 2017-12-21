
#include "PlotData.h"


bool qpointLessThan( const QPointF& p1,
                     const QPointF& p2 )
{
  return ( p1.x() < p2.x() );
}


Data::PlotData::PlotData()
  : m_plotData()
{}


Data::PlotData::PlotData( const QVector< QPointF >& plotData )
  : m_plotData( plotData )
{
  //! Ensure data is sequential
  sortData();
}


bool Data::PlotData::smoothWithRDP( const double epsilon )
{
  if( m_plotData.length() < 2 )
    return false;

  m_plotData = douglasPeucker( m_plotData,
                               epsilon );

  return true;
}


void Data::PlotData::sortData()
{
  std::sort( m_plotData.begin(),
             m_plotData.end(),
             qpointLessThan );
}


QVector< QPointF > Data::PlotData::douglasPeucker( const QVector< QPointF >& plotData,
                                                   const double            epsilon ) const
{
  //! Find the point with the maximum distance
  const QLineF referenceLine( plotData.first(), plotData.back() );
  double dMax = 0.0;
  int maxIndex = 0;

  const int iEnd = ( plotData.length() - 1 );
  for( int i = 2; i < iEnd; ++i )
  {
    //! Calculate perpindicular distance
    double curDist = perpindicularDistance( referenceLine,
                                            plotData[ i ] );
    if( curDist > dMax )
    {
      maxIndex = i;
      dMax = curDist;
    }
  }

  //! If max distance is greater than epsilon,
  //! recursively simplify
  if( dMax > epsilon )
  {
    auto results1 = douglasPeucker( plotData.mid( 0, maxIndex ),
                                    epsilon );
    auto results2 = douglasPeucker( plotData.mid( maxIndex ),
                                    epsilon );

    //! Build list and return
    return results1.mid( 0, results1.count() - 1 ) + results2;
  }
  else
  {
    return QVector< QPointF >( { plotData.first(), plotData.back() } );
  }
}


double Data::PlotData::perpindicularDistance( const QLineF&  referenceLine,
                                              const QPointF& checkPoint ) const
{
  return std::abs( referenceLine.dy() * checkPoint.x() - 
                   referenceLine.dx() * checkPoint.y() +
                   referenceLine.p2().x() * referenceLine.p1().y() -
                   referenceLine.p2().y() * referenceLine.p1().x() ) /
         referenceLine.length();
}

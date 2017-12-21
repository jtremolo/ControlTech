
#include "PlotData.h"


bool Data::PlotData::smoothWithRDP( const double epsilon )
{
  if( m_plotData.length() < 2 )
    return false;

  m_plotData = douglasPeucker( m_plotData,
                               epsilon );
  return true;
}


QList< QPair< double, double > > Data::PlotData::douglasPeucker( const QList< QPair< double, double > >& plotData,
                                                                 const double                            epsilon ) const
{
  //! Find the point with the maximum distance
  double dMax = 0.0;
  int maxIndex = 0;

  const int iEnd = ( plotData.length() - 1 );
  for( int i = 2; i < iEnd; ++i )
  {
    //!TODO: Calculate perpindicular distance
    double curDist;
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
    return results1 + results2;
  }
  else
  {
    return QList< QPair< double, double > >( { plotData.first(), plotData.back() } );
  }
}

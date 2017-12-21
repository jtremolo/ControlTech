
#include <QTest>
#include "../PlotData.h"


class TestPerpindicular : public QObject
{
  Q_OBJECT

  private slots:

    void testHorizon() const;
};


void TestPerpindicular::testHorizon() const
{
  QLineF horizonLine( 0.0, 0.0, 10.0, 0.0 );
  QPointF testPoint( 2.0, 5.0 );
  double testDist = Data::PlotData::perpindicularDistance( horizonLine,
                                                           testPoint );
}


QTEST_MAIN( TestPerpindicular )
#include "testPerpindicular.moc"

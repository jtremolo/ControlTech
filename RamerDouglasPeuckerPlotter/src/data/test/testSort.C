
#include <QTest>
#include "../PlotData.h"


class TestSort : public QObject
{
  Q_OBJECT

  private slots:

    void testUnordered();
};


void TestSort::testUnordered()
{
  //! Test the auto-sorting of unordered data
  QVector< QPointF > testData( { { 2.0, 1.0 }, { 1.0, 5.0 }, { 0.0, 0.0 }, { 10.0, -5.0 } } );
  Data::PlotData plotData( testData );

  const QVector< QPointF >& sortedData( plotData.data() );
  QCOMPARE( sortedData[ 0 ].x(),  0.0 );
  QCOMPARE( sortedData[ 1 ].x(),  1.0 );
  QCOMPARE( sortedData[ 2 ].x(),  2.0 );
  QCOMPARE( sortedData[ 3 ].x(), 10.0 );
}


QTEST_MAIN( TestSort )
#include "testSort.moc"

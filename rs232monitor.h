#ifndef RS232MONITOR_H
#define RS232MONITOR_H
#include <QTimer>
#include <QtWidgets>
#include <QWidget>
#include "rs232.h"
#include <QObject>

class RS232MONITOR : public QWidget
{
    Q_OBJECT
public:

    RS232MONITOR(QWidget *parent=0);
public slots:
    slotParseRx(QString msg);
    slotParseTx(QString msg);
signals:
    sigForwardRx(QString msg);
    sigForwardTx(QString msg);
private:
    RS232 *rs232Rx;
    RS232 *rs232Tx;
    QTextBrowser *myLog;
    QSplitter *myHlayout;
    QSplitter *myVlayout;
};

#endif // RS232MONITOR_H

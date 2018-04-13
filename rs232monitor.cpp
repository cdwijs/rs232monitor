#include "rs232monitor.h"
#include <QDebug>


RS232MONITOR::RS232MONITOR(QWidget *parent) : QWidget(parent)
{
    qDebug()<<Q_FUNC_INFO;
    rs232Rx = new RS232(this);
    rs232Tx = new RS232(this);
    myLog = new QTextBrowser();
    myHlayout = new QSplitter();
    myVlayout = new QSplitter();


//    myHlayout->setOrientation(Qt::Horizontal);
//    myHlayout->addWidget(rs232Tx);
//    myHlayout->addWidget(rs232Rx);


    myVlayout->setOrientation(Qt::Vertical);
    myVlayout->addWidget(myLog);
    myVlayout->addWidget(rs232Rx);

    rs232Rx->slotConnect(true);
    rs232Tx->slotConnect(true);
    myHlayout->setParent(parent);
    myVlayout->show();
    rs232Rx->show();
    rs232Tx->show();
}

RS232MONITOR::slotParseRx(QString msg)
{
    qDebug()<<Q_FUNC_INFO;
    emit sigForwardRx(msg);
}

RS232MONITOR::slotParseTx(QString msg)
{
    qDebug()<<Q_FUNC_INFO;
    emit sigForwardTx(msg);
}

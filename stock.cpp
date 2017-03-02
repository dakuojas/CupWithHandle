#include "stock.h"
#include <QDebug>
#include <QFile>
Stock::Stock()
{

}

void Stock::init()
{
    this->ticker = "NULL";
    this->open = 0;
    this->high = 0;
    this->low = 0;
    this->close = 0;
    this->volume = 0;
}

void Stock::print()
{
    qDebug() << this->ticker << this->timestamp
             << this->open << this->high
             << this->low << this->close
             << this->volume;
}

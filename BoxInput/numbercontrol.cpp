#include "numbercontrol.h"
#include <QDebug>
#include <QQmlEngine>

NumberControl::NumberControl(QObject *parent)
    : QObject{parent}, Number("0")
{

}

void NumberControl::setNum(int num)
{
    Number.setNum(num);
    emit numchanged();
}

void NumberControl::increase()
{
    Number.setNum(Number.toInt() + 1);
    emit numchanged();
}

void NumberControl::decrease()
{
    Number.setNum(Number.toInt() - 1);
    emit numchanged();
}

QString NumberControl::getNum() const
{
    return Number;
}

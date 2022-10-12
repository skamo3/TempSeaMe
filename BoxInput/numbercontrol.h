#ifndef NUMBERCONTROL_H
#define NUMBERCONTROL_H

#include <QObject>

class NumberControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString number READ getNum NOTIFY numchanged)

public:
    explicit NumberControl(QObject *parent = nullptr);

    Q_INVOKABLE void setNum(int num);

    Q_INVOKABLE void increase();
    Q_INVOKABLE void decrease();

    Q_INVOKABLE QString getNum() const;

signals:
    void numchanged();

private:
    QString Number;

};

#endif // NUMBERCONTROL_H

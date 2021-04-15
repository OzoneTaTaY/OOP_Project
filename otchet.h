#ifndef OTCHET_H
#define OTCHET_H

#include <QWidget>
#include <QString>

namespace Ui {
class Otchet;
}

class Otchet : public QWidget
{
    Q_OBJECT

public:
    explicit Otchet(QWidget *parent = nullptr);
    ~Otchet();
    void set_data(QString data);
signals:
    void firstWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QString data;
    Ui::Otchet *ui;
};

#endif // OTCHET_H

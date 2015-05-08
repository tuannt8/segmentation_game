#ifndef OPTIONWINDOWS_H
#define OPTIONWINDOWS_H

#include <QMainWindow>

namespace Ui {
class optionWindows;
}

class optionWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit optionWindows(QWidget *parent = 0);
    ~optionWindows();

private:
    Ui::optionWindows *ui;
};

#endif // OPTIONWINDOWS_H

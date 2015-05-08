#include "optionwindows.h"
#include "ui_optionwindows.h"

optionWindows::optionWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::optionWindows)
{
    ui->setupUi(this);
}

optionWindows::~optionWindows()
{
    delete ui;
}

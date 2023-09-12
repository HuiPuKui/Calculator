#include "ccalculatorsecondpage.h"
#include "ui_ccalculatorsecondpage.h"

CcalculatorSecondPage::CcalculatorSecondPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CcalculatorSecondPage)
{
    ui->setupUi(this);
}

CcalculatorSecondPage::~CcalculatorSecondPage()
{
    delete ui;
}

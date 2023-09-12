#ifndef _CCALCULATORSECONDPAGE_H__
#define _CCALCULATORSECONDPAGE_H__

#include <QWidget>

namespace Ui { class CcalculatorSecondPage; }

class CcalculatorSecondPage : public QWidget
{
    Q_OBJECT

public:
    explicit CcalculatorSecondPage(QWidget *parent = nullptr);
    ~CcalculatorSecondPage();

private:
    Ui::CcalculatorSecondPage *ui;
};

#endif // _CCALCULATORSECONDPAGE_H__

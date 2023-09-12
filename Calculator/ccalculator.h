#ifndef _CCALCULATOR_H__
#define _CCALCULATOR_H__

#include <QWidget>
#include <iostream>
#include <QDebug>

#include "ui_ccalculator.h"
#include "ccalculateresult.h"
#include "datatype.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CCalculator; }
QT_END_NAMESPACE

class CCalculator : public QWidget
{
    Q_OBJECT
public:
    CCalculator(QWidget *parent = nullptr);
    virtual ~CCalculator();
    void Initilize();
public slots:
    void ClearAll();        // C
    void Back();            // back
    void ShowResult();      // =
    void EnterAnotherPage();// lnv
    void EnterTrangleLnv();
    void EnterTrangleHyp();

    void GetResult();       // 运算
    void OtherButton();     // 其他按钮点击发生的事件
    void ClickButtonOfTrangle();
    void ClickButtonOfFunction();
private:
    void ShowExpressionAndResult();
    void ShowExpressionAndLastestInputChar();
    void SetButtonSize(int, int);
    void DoPageTurn(bool, bool);

private:
    Ui::CCalculator *ui;

    QString m_qstrExpression;       // 供运算的表达式
    QString m_qstrNewExpression;    // 可以添加的最新的表达式
    QString m_qstrLastestInputChar; // 最后一次按下的按钮表示的运算符
    QString m_qstrResult;           // 运算后的结果
    bool m_bIsResult;               // 当前最新的表达式是否是结果
    bool m_bPage;                   // 当前页面三
    bool m_bTranglePageLnv;
    bool m_bTranglePageHyp;
};

#endif // _CCALCULATOR_H__

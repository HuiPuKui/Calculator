#ifndef _CCALCULATERESULT_H__
#define _CCALCULATERESULT_H__

#include <QPushButton>
#include <iostream>
#include <QDebug>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <ctime>
#include <cmath>

#include "datatype.h"
#include "crational.h"

class CCalculateResult
{
public:
    CCalculateResult(const Param&);

    Param Back();
    Param OtherButton(QPushButton*);
    Param GetResult();
private:
    void FunctionOfAll(double);
    void SetPIOrE(QString);

    void DeleteZero(QString &expression);
    bool IsNumber(const QString &expression);
    void DoOperating(QString &m_qstrNewExpression, QString &m_qstrExpression, bool &m_bPage, bool &m_bIsResult, char ops);
    int FindOnDatatype(QString ButtonText);
    void Eval(std::stack<double> &dStackOfValue, std::stack<char> &dStackOfSignal);
private:
    QString m_qstrExpression;
    QString m_qstrNewExpression;
    QString m_qstrLastestInputChar;
    QString m_qstrResult;
    bool m_bIsResult;
    bool m_bPage;
    bool m_bTranglePageLnv;
    bool m_bTranglePageHyp;
};

#endif // _CCALCULATERESULT_H__

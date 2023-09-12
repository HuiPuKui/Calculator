#include "ccalculateresult.h"
#include "functionals.h"

static int NumberOfLPart = 0;
static int NumberOfRPart = 0;

CCalculateResult::CCalculateResult(const Param &paramParam)
    : m_qstrExpression(paramParam.qstrExpression),
      m_qstrNewExpression(paramParam.qstrNewExpression),
      m_qstrLastestInputChar(paramParam.qstrLastestInputChar),
      m_qstrResult(paramParam.qstrResult),
      m_bIsResult(paramParam.bIsResult),
      m_bPage(paramParam.bPage),
      m_bTranglePageLnv(paramParam.bTranglePageLnv),
      m_bTranglePageHyp(paramParam.bTranglePageHyp)
{
}

/**
 * @brief CCalculateResult::Back
 * @return
 * 回退键：只有数字可以回退，每次回退一位,如果只有一位就变成 0 ；
 */

Param CCalculateResult::Back()
{
    int len = m_qstrNewExpression.size();
    if (len > 0)
    {
        if ((m_bIsResult == false && (m_qstrNewExpression.at(len - 1) >= '0' && m_qstrNewExpression.at(len - 1) <= '9')) || m_qstrNewExpression.at(len - 1) == '.' || m_qstrNewExpression.at(len - 1) == '-')
        {
            if (len == 1)
            {
                m_qstrNewExpression = "0";
            }
            else
            {
                QString qstrTemp("");
                for (int i = 0; i < len - 1; ++ i)
                {
                    qstrTemp += m_qstrNewExpression.at(i);
                }
                m_qstrNewExpression = qstrTemp;
            }
            m_qstrLastestInputChar = m_qstrNewExpression;
        }
        if (m_qstrNewExpression.size() == 0)
        {
            m_qstrNewExpression = "0";
        }
    }
    return {m_qstrExpression, m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp};
}

/**
 * @brief CCalculateResult::OtherButton
 * @param btn
 * @return
 * 如果按的是数 改变 LastestInputChar
 * 否则 改变 Result 和 LastestInputChar
 */

Param CCalculateResult::OtherButton(QPushButton *btn)
{
    if (m_qstrExpression.compare(" ") == 0)
    {
        NumberOfLPart = 0;
        NumberOfRPart = 0;
    }
    if (btn->text().size() == 1 && ((btn->text().at(0) >= '0' && btn->text().at(0) <= '9')))
    {
        if (m_bIsResult == true)
        {
            m_bIsResult = false;
            m_qstrNewExpression = btn->text();
            m_qstrLastestInputChar = m_qstrNewExpression;
        }
        else
        {
            if (m_qstrNewExpression.compare("0") == 0 || m_qstrNewExpression.compare("") == 0)
            {
                m_qstrNewExpression = btn->text();
            }
            else
            {
                m_qstrNewExpression += btn->text();
            }
            m_qstrLastestInputChar = m_qstrNewExpression;
        }
    }
    else
    {
        QString ButtonText = btn->objectName();
        int Number = FindOnDatatype(ButtonText);
        double dNumber = m_qstrNewExpression.toDouble();
        switch (Number)
        {
        case INPUT_TYPE_PI:
        {
            SetPIOrE("3.14159");
            break;
        }
        case INPUT_TYPE_E:
        {
            SetPIOrE("2.71828");
            break;
        }
        case INPUT_TYPE_POW2:
        {
            if (m_bPage == false) FunctionOfAll(pow(dNumber, 2));
            else FunctionOfAll(pow(dNumber, 3));
            break;
        }
        case INPUT_TYPE_COMPLEMENT:
        {
            FunctionOfAll(1.0 / dNumber);
            break;
        }
        case INPUT_TYPE_ABS:
        {
            FunctionOfAll(abs(dNumber));
            break;
        }
        case INPUT_TYPE_EXP:
        {
            DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, 'E');
            break;
        }
        case INPUT_TYPE_MOD:
        {
            DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, '%');
            break;
        }
        case INPUT_TYPE_SQRT:
        {
            if (m_bPage == false)
            {
                FunctionOfAll(sqrt(dNumber));
            }
            else
            {
                FunctionOfAll(pow(dNumber, 1.0 / 3));
            }
            break;
        }
        case INPUT_TYPE_LPART:
        {
            if ((m_qstrNewExpression.size() == 0 && m_qstrExpression.size() == 1) || (m_qstrExpression.size() == 1 && m_qstrExpression.at(0) == ' ' && m_qstrNewExpression.size() == 1 && m_qstrNewExpression.compare("0") == 0))
            {
                if (m_qstrExpression.at(0) == '(')
                {
                    m_qstrExpression += '(';
                }
                else
                {
                    m_qstrExpression = "(";
                }
                ++ NumberOfLPart;
                m_qstrNewExpression = "";
                m_qstrLastestInputChar = "(";
                break;
            }

            QChar ch = m_qstrExpression.at(m_qstrExpression.size() - 1);

            if (m_qstrNewExpression.size() && m_qstrNewExpression.at(0) == '-')
            {
                m_qstrNewExpression = "(" + m_qstrNewExpression + ")";
            }
            if (m_qstrExpression.size() == 1 && m_qstrExpression.at(0) == '0')
            {
                m_qstrExpression = "(";
                ++ NumberOfLPart;
            }
            else if ((m_qstrExpression.size() && m_qstrExpression.back() == ')') || (m_qstrNewExpression.size() && m_qstrNewExpression.back() == ')'))
            {
                m_qstrExpression += m_qstrNewExpression + "*(";
                ++ NumberOfLPart;
            }
            else if (m_qstrNewExpression.size() && ((m_qstrNewExpression.back() >= '0' && m_qstrNewExpression.back() <= '9')))
            {
                m_qstrExpression += m_qstrNewExpression + "*(";
                ++ NumberOfLPart;
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == '^' || ch == '%' || ch == 'L' || ch == 'E')
            {
                m_qstrExpression += m_qstrNewExpression + "(";
                ++ NumberOfLPart;
            }

            m_qstrNewExpression = "";
            m_qstrLastestInputChar = "(";

            break;
        }
        case INPUT_TYPE_RPART:
        {
            if (IsNumber(m_qstrNewExpression) && NumberOfRPart < NumberOfLPart)
            {
                if (m_qstrNewExpression.size() == 0 && (m_qstrExpression.size() == 0 || m_qstrExpression.back() == '+' || m_qstrExpression.back() == '-' || m_qstrExpression.back() == '*' || m_qstrExpression.back() == '/' || m_qstrExpression.back() == '^' || m_qstrExpression.back() == '%' || m_qstrExpression.back() == 'L' || m_qstrExpression.back() == '(' || m_qstrExpression.back() == 'E'))
                {
                    break;
                }
                if (m_qstrNewExpression.size() && m_qstrNewExpression.at(0) == '-')
                {
                    m_qstrNewExpression = "(" + m_qstrNewExpression + ")";
                }
                if (m_qstrExpression.size() && m_qstrExpression.back() == ')' && m_qstrNewExpression.size() && m_qstrNewExpression.at(0) >= '0' && m_qstrNewExpression.at(0) <= '9')
                {
                    m_qstrExpression += '*';
                }
                m_qstrExpression += m_qstrNewExpression + ")";
                ++ NumberOfRPart;
                m_qstrNewExpression = "";
                m_qstrLastestInputChar = ")";
            }
            else if (m_qstrLastestInputChar.compare("") == 0)
            {
                m_qstrLastestInputChar = m_qstrNewExpression;
            }
            break;
        }
        case INPUT_TYPE_FACTORIAL:
        {
            FunctionOfAll(tgamma(dNumber + 1));
            break;
        }
        case INPUT_TYPE_DIV:
        {
            DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, '/');
            break;
        }
        case INPUT_TYPE_MI:
        {
            DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, '^');
            if (m_bPage == true)
            {
                ++ NumberOfLPart;
            }
            break;
        }
        case INPUT_TYPE_MUL:
        {
            DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, '*');
            break;
        }
        case INPUT_TYPE_10MI:
        {
            if (m_bPage == false)
            {
                FunctionOfAll(pow(10, dNumber));
            }
            else
            {
                FunctionOfAll(pow(2, dNumber));
            }
            break;
        }
        case INPUT_TYPE_SUB:
        {
            DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, '-');
            break;
        }
        case INPUT_TYPE_LOG:
        {
            if (m_bPage == false)
            {
                FunctionOfAll(log10(dNumber));
            }
            else
            {
                DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, 'L');
            }
            break;
        }
        case INPUT_TYPE_ADD:
        {
            DoOperating(m_qstrNewExpression, m_qstrExpression, m_bPage, m_bIsResult, '+');
            break;
        }
        case INPUT_TYPE_LN:
        {
            if (m_bPage == false)
            {
                FunctionOfAll(log(dNumber));
            }
            else
            {
                FunctionOfAll(pow(E, dNumber));
            }
            break;
        }
        case INPUT_TYPE_RE:
        {
            FunctionOfAll(-dNumber);
            m_bIsResult = false;
            break;
        }
        case INPUT_TYPE_POINT:
        {
            if (IsNumber(m_qstrNewExpression))
            {
                if (m_qstrNewExpression.compare("") == 0)
                {
                    m_qstrNewExpression = "0";
                }
                bool HavePoint = false;
                for (int i = 0; i < m_qstrNewExpression.size(); ++ i)
                {
                    if (m_qstrNewExpression.at(i) == '.')
                    {
                        HavePoint = true;
                    }
                }
                if (HavePoint == false)
                {
                    int len = m_qstrNewExpression.size();
                    if (m_qstrNewExpression.at(len - 1) >= '0' && m_qstrNewExpression.at(len - 1) <= '9')
                    {
                        m_qstrNewExpression += '.';
                        m_qstrLastestInputChar = m_qstrNewExpression;
                    }
                }
            }
            break;
        }
        case INPUT_TYPE_ABS2:
        {
            FunctionOfAll(abs(dNumber));
            break;
        }
        case INPUT_TYPE_CEIL:
        {
            FunctionOfAll(ceil(dNumber));
            break;
        }
        case INPUT_TYPE_FLOOR:
        {
            FunctionOfAll(floor(dNumber));
            break;
        }
        case INPUT_TYPE_RAND:
        {
            if (IsNumber(m_qstrNewExpression))
            {
                if (m_qstrExpression.size() && m_qstrExpression.back() == ')')
                {
                    break;
                }
                srand(time(NULL));
                FunctionOfAll((rand() % 9999) * 1.0 / 9999);
            }
            break;
        }
        case INPUT_TYPE_DMS:
        {
            FunctionOfAll((int)dNumber + (dNumber - (int)dNumber) * 0.6);
            break;
        }
        case INPUT_TYPE_DEG:
        {
            FunctionOfAll((int)dNumber + (dNumber - (int)dNumber) / 0.6);
            break;
        }
        case INPUT_TYPE_SIN:
        {
            if (m_bTranglePageLnv == false && m_bTranglePageHyp == false)
            {
                FunctionOfAll(sin(dNumber / 180 * PI));
            }
            else if (m_bTranglePageLnv == true && m_bTranglePageHyp == false)
            {
                FunctionOfAll(180 * asin(dNumber) / acos(-1));
            }
            else if (m_bTranglePageLnv == false && m_bTranglePageHyp == true)
            {
                FunctionOfAll(sinh(dNumber));
            }
            else
            {
                FunctionOfAll(asinh(dNumber));
            }
            break;
        }
        case INPUT_TYPE_COS:
        {
            if (m_bTranglePageLnv == false && m_bTranglePageHyp == false)
            {
                FunctionOfAll(cos(dNumber / 180 * PI));
            }
            else if (m_bTranglePageLnv == true && m_bTranglePageHyp == false)
            {
                FunctionOfAll(180 * acos(dNumber) / acos(-1));
            }
            else if (m_bTranglePageLnv == false && m_bTranglePageHyp == true)
            {
                FunctionOfAll(cosh(dNumber));
            }
            else
            {
                FunctionOfAll(acosh(dNumber));
            }
            break;
        }
        case INPUT_TYPE_TAN:
        {
            if (m_bTranglePageLnv == false && m_bTranglePageHyp == false)
            {
                FunctionOfAll(tan(dNumber / 180 * PI));
            }
            else if (m_bTranglePageLnv == true && m_bTranglePageHyp == false)
            {
                FunctionOfAll(180 * atan(dNumber) / acos(-1));
            }
            else if (m_bTranglePageLnv == false && m_bTranglePageHyp == true)
            {
                FunctionOfAll(tanh(dNumber));
            }
            else
            {
                FunctionOfAll(atanh(dNumber));
            }
            break;
        }
        case INPUT_TYPE_SEC:
        {
            if (m_bTranglePageLnv == false && m_bTranglePageHyp == false)
            {
                FunctionOfAll(1.0 / cos(dNumber / 180 * PI));
            }
            else if (m_bTranglePageLnv == true && m_bTranglePageHyp == false)
            {
                FunctionOfAll(180 * acos(1.0 / dNumber) / acos(-1));
            }
            else if (m_bTranglePageLnv == false && m_bTranglePageHyp == true)
            {
                FunctionOfAll(1.0 / cosh(dNumber));
            }
            else
            {
                FunctionOfAll(acosh(1.0 / dNumber));
            }
            break;
        }
        case INPUT_TYPE_CSC:
        {
            if (m_bTranglePageLnv == false && m_bTranglePageHyp == false)
            {
                FunctionOfAll(1.0 / sin(dNumber / 180 * PI));
            }
            else if (m_bTranglePageLnv == true && m_bTranglePageHyp == false)
            {
                FunctionOfAll(180 * asin(1.0 / dNumber) / acos(-1));
            }
            else if (m_bTranglePageLnv == false && m_bTranglePageHyp == true)
            {
                FunctionOfAll(1.0 / sinh(dNumber));
            }
            else
            {
                FunctionOfAll(asinh(1.0 / dNumber));
            }
            break;
        }
        case INPUT_TYPE_COT:
        {
            if (m_bTranglePageLnv == false && m_bTranglePageHyp == false)
            {
                FunctionOfAll(1.0 / tan(dNumber / 180 * PI));
            }
            else if (m_bTranglePageLnv == true && m_bTranglePageHyp == false)
            {
                FunctionOfAll(180 * atan(1.0 / dNumber) / acos(-1));
            }
            else if (m_bTranglePageLnv == false && m_bTranglePageHyp == true)
            {
                FunctionOfAll(1.0 / tanh(dNumber));
            }
            else
            {
                FunctionOfAll(atanh(1.0 / dNumber));
            }
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return {m_qstrExpression, m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp};
}

/**
 * @brief CCalculateResult::GetResult
 * @return
 * 表达式求值
 */

Param CCalculateResult::GetResult()
{
    if ((m_qstrExpression.back() == ' ' && m_qstrNewExpression.size() == 0)|| ((m_qstrNewExpression.size() == 0) && (m_qstrExpression.back() == '+' || m_qstrExpression.back() == '-' || m_qstrExpression.back() == '*' || m_qstrExpression.back() == '/' || m_qstrExpression.back() == '^' || m_qstrExpression.back() == '%' || m_qstrExpression.back() == 'E' || m_qstrExpression.back() == 'L')))
    {
        return {"Error", m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp};
    }

    IsNumber(m_qstrNewExpression);

    if (m_qstrExpression.size() == 0)
    {
        return {m_qstrExpression, m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp};
    }
    if (NumberOfLPart != NumberOfRPart)
    {
        return {"Error", m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp};
    }

    if (m_qstrExpression.compare(" ") == 0)
    {
        m_qstrExpression = "";
    }

    if (m_qstrNewExpression.size() && m_qstrNewExpression.at(0) == '-')
    {
        m_qstrNewExpression = "(" + m_qstrNewExpression + ")";
    }
    m_qstrExpression += m_qstrNewExpression;

    std::stack<double> Number;
    std::stack<char> OperatorSignal;
    std::unordered_map<char, double> Hash;

    Hash = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'^', 3} , {'L', 3}, {'E', 4}};
    std::string qstrExpression = m_qstrExpression.toStdString();
    if (qstrExpression[0] == '-')
    {
        qstrExpression = "0" + qstrExpression;
    }
    for (std::size_t i = 0; i < qstrExpression.length(); ++ i)
    {
        auto tempChar = qstrExpression[i];
        if (isdigit(tempChar))
        {
            double sumValue = 0, j = i, p = 1;
            bool leap = false;
            while (j < qstrExpression.length() && (isdigit(qstrExpression[j]) || qstrExpression[j] == '.'))
            {
                if (qstrExpression[j] == '.')
                {
                    leap = true;
                    j ++;
                }
                else
                {
                    if (leap)
                    {
                        p /= 10;
                        sumValue = sumValue + (qstrExpression[j ++] - '0') * p;
                    }
                    else
                    {
                        sumValue = sumValue * 10 + qstrExpression[j ++] - '0';
                    }
                }
            }
            Number.push(sumValue);
            i = j - 1;
        }
        else if (tempChar == '(')
        {
            OperatorSignal.push(tempChar);
        }
        else if (tempChar == ')')
        {
            while (OperatorSignal.top() != '(')
            {
                Eval(Number, OperatorSignal);
            }
            OperatorSignal.pop();
        }
        else
        {
            while (OperatorSignal.size() && OperatorSignal.top() != '(' && Hash[OperatorSignal.top()] >= Hash[tempChar])
            {
                Eval(Number, OperatorSignal);
            }
            if (OperatorSignal.size() && OperatorSignal.top() == '(' )
            {
                if (tempChar == '-' && qstrExpression[i - 1] == '(')
                {
                    Number.push(0);
                }
            }
            OperatorSignal.push(tempChar);
        }
    }

    while (OperatorSignal.size())
    {
        Eval(Number, OperatorSignal);
    }

    QString temp = QString::number(Number.top());
    m_qstrResult = temp;
    m_bIsResult = true;

    DeleteZero(m_qstrExpression);
    return {m_qstrExpression, m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp};
}

void CCalculateResult::FunctionOfAll(double first)
{
    if (IsNumber(m_qstrNewExpression))
    {
        double dNumber = first;
        m_qstrNewExpression = QString::number(dNumber);
        m_qstrLastestInputChar = m_qstrNewExpression;
        m_bIsResult = true;
    }
}

void CCalculateResult::SetPIOrE(QString qstrNumber)
{
    if (IsNumber(m_qstrNewExpression) == false)
    {
        m_qstrExpression += m_qstrNewExpression;
    }
    DeleteZero(m_qstrExpression);
    m_bIsResult = true;
    m_qstrNewExpression = qstrNumber;
    m_qstrLastestInputChar = qstrNumber;
}

/**
 * @brief DeleteZero
 * @param expression
 * 去掉前导零 和 前导空格
 */

void CCalculateResult::DeleteZero(QString &expression)
{
    QString str;

    while (expression.size() > 1 && (expression.at(0) == '0' || expression.at(0) == ' ') && expression.at(1) != '.')
    {
        expression = expression.mid(1);
    }
}


/**
 * @brief CCalculateResult::IsNumber
 * @return
 * 判断字符串是不是一个数
 */

bool CCalculateResult::IsNumber(const QString &expression)
{
    if (expression.size() == 0)
    {
        return true;
    }

    int countPoint = 0;
    for (int i = expression.at(0) == '-'; i < expression.size(); ++ i)
    {
        if (expression.at(i) == '.')
        {
            ++ countPoint;
        }
        if (((expression.at(i) < '0' || expression.at(i) > '9') && (expression.at(i) != '.' && expression.at(i) != '-')) || countPoint > 1)
        {
            return false;
        }
    }

    return true;
}

void CCalculateResult::DoOperating(QString &m_qstrNewExpression, QString &m_qstrExpression, bool &m_bPage, bool &m_bIsResult, char ops)
{
    IsNumber(m_qstrNewExpression);
    if (m_qstrNewExpression.size() == 0 && m_qstrExpression.size() >= 4 && m_qstrExpression.mid(m_qstrExpression.size() - 4) == "^(1/")
    {
        m_qstrExpression = m_qstrExpression.mid(0, m_qstrExpression.size() - 4);
        if (ops == '^' && m_bPage == true)
        {
            m_qstrExpression += "^(1/";
        }
        else
        {
            m_qstrExpression += ops;
        }
        return ;
    }
    if (m_qstrNewExpression.size() == 0 && (m_qstrExpression.back() == '+' || m_qstrExpression.back() == '-' || m_qstrExpression.back() == '*' || m_qstrExpression.back() == '%' || m_qstrExpression.back() == '/' || m_qstrExpression.back() == '^' || m_qstrExpression.back() == 'L' || m_qstrExpression.back() == 'E'))
    {
        m_qstrExpression.back() = ops;
        if (m_bPage == true && ops == '^')
        {
            m_qstrExpression += "(1/";
        }
        return ;
    }

    if (m_qstrNewExpression.size() == 0 && m_qstrExpression.back() == '(')
    {
        m_qstrNewExpression = "0";
    }
    if (m_qstrNewExpression.size() && m_qstrNewExpression.at(0) == '-')
    {
        m_qstrNewExpression = "(" + m_qstrNewExpression + ")";
    }
    if (m_qstrExpression.size() && m_qstrExpression.back() == ')' && m_qstrNewExpression.size() && m_qstrNewExpression.at(0) >= '0' && m_qstrNewExpression.at(0) <= '9')
    {
        m_qstrExpression += '*';
    }
    m_qstrExpression += m_qstrNewExpression;
    DeleteZero(m_qstrExpression);
    m_qstrExpression += ops;
    m_qstrNewExpression = "";
    if (m_bPage == true && ops == '^')
    {
        m_qstrExpression += "(1/";
    }
    m_bIsResult = false;
}

/**
 * @brief CCalculateResult::FindOnDatatype
 * @param ButtonText
 * @return
 * 在 Datatype 中找到字符串下标
 */

int CCalculateResult::FindOnDatatype(QString ButtonText)
{
    int iResult = -1;
    for (int i = 0; i < 49; ++i)
    {
        if (ButtonText == DataArray[i])
        {
            iResult = i;
            break;
        }
    }
    return iResult;
}

/**
 * @brief eval
 * @param dStackOfValue
 * @param dStackOfSignal
 * 从栈中弹出两个数字 配合 另一个栈中的字符 进行运算
 */

void CCalculateResult::Eval(std::stack<double> &dStackOfValue, std::stack<char> &dStackOfSignal)
{
    double RightValue = dStackOfValue.top();
    dStackOfValue.pop();
    double LeftValue = dStackOfValue.top();
    dStackOfValue.pop();
    char Signal = dStackOfSignal.top();
    dStackOfSignal.pop();

    double Answer;
    switch (Signal)
    {
    case '+':
    {
        CRational<double> LeftRational(LeftValue, 1);
        CRational<double> RightRational(RightValue, 1);
        CRational<double> Res = LeftRational + RightRational;
        Answer = Res.getNumerator() * 1.0 / Res.getDenominator();
        break;
    }
    case '-' :
    {
        CRational<double> LeftRational(LeftValue, 1);
        CRational<double> RightRational(RightValue, 1);
        CRational<double> Res = LeftRational - RightRational;
        Answer = Res.getNumerator() * 1.0 / Res.getDenominator();
        break;
    }
    case '*' :
    {
        CRational<double> LeftRational(LeftValue, 1);
        CRational<double> RightRational(RightValue, 1);
        CRational<double> Res = LeftRational * RightRational;
        Answer = Res.getNumerator() * 1.0 / Res.getDenominator();
        break;
    }
    case '/' :
    {
        CRational<double> LeftRational(LeftValue, 1);
        CRational<double> RightRational(RightValue, 1);
        CRational<double> Res = LeftRational / RightRational;
        Answer = Res.getNumerator() * 1.0 / Res.getDenominator();
        break;
    }
    case '%' :
    {
        int p = LeftValue / RightValue;
        Answer = LeftValue - p * RightValue;
        if (Answer < 0)
        {
            Answer += RightValue;
        }
        break;
    }
    case '^' :
    {
        Answer = pow(LeftValue, RightValue);
        break;
    }
    case 'L' :
    {
        Answer = log(LeftValue) / log(RightValue);
        break;
    }
    case 'E' :
    {
        Answer = LeftValue * pow(10, RightValue);
        break;
    }
    default:
    {
        break;
    }
    }

    dStackOfValue.push(Answer);
}

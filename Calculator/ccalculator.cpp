#include "ccalculator.h"

static bool TranglePage = false;
static bool FunctionPage = false;

CCalculator::CCalculator(QWidget *parent) : QWidget(parent), ui(new Ui::CCalculator)
{
    ui->setupUi(this);
    Initilize();

    connect(ui->Button_lnv, SIGNAL(clicked(bool)), this, SLOT(EnterAnotherPage()));
    connect(ui->Button_pi, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_e, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_C, SIGNAL(clicked(bool)), this, SLOT(ClearAll()));
    connect(ui->Button_back, SIGNAL(clicked(bool)), this, SLOT(Back()));

    connect(ui->Button_pow2, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_complement, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_abs, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_exp, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_mod, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));

    connect(ui->Button_sqrt, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_lpart, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_rpart, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_factorial, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_div, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));

    connect(ui->Button_mi, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_7, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_8, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_9, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_mul, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));

    connect(ui->Button_10mi, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_4, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_5, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_6, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_sub, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));

    connect(ui->Button_log, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_1, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_2, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_3, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_add, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));

    connect(ui->Button_ln, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_re, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_0, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_point, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_equal, SIGNAL(clicked(bool)), this, SLOT(ShowResult()));

    connect(ui->Button_trangle, SIGNAL(clicked(bool)), this, SLOT(ClickButtonOfTrangle()));
    connect(ui->Button_function, SIGNAL(clicked(bool)), this, SLOT(ClickButtonOfFunction()));

    connect(ui->Button_TrLnv, SIGNAL(clicked(bool)), this, SLOT(EnterTrangleLnv()));
    connect(ui->Button_hyp, SIGNAL(clicked(bool)), this, SLOT(EnterTrangleHyp()));
    connect(ui->Button_sin, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_cos, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_tan, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_sec, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_csc, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_cot, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));

    connect(ui->Button_abs2, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_ceil, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_floor, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_rand, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_dms, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
    connect(ui->Button_deg, SIGNAL(clicked(bool)), this, SLOT(OtherButton()));
}

CCalculator::~CCalculator()
{
    delete ui;
}

/**
 * @brief CCalculator::Initilize
 * 初始化，只读，字号，靠右
 */

void CCalculator::Initilize()
{
    this->m_qstrResult = "0";
    this->m_qstrNewExpression = "0";
    this->m_qstrExpression = " ";
    this->m_qstrLastestInputChar = "0";
    this->m_bIsResult = false;
    this->m_bPage = false;
    this->m_bTranglePageLnv = false;
    this->m_bTranglePageHyp = false;

    ui->textEditMain->setReadOnly(true);
    ui->textEditMain->setFontPointSize(31);
    ui->Frame_Trangle->hide();
    ui->Frame_Function->hide();

    setWindowTitle("科学计算器");
    SetButtonSize(94, 43);
    ShowExpressionAndResult();
}

void CCalculator::SetButtonSize(int y, int x)
{
    ui->Button_lnv->setFixedSize(y, x);
    ui->Button_pi->setFixedSize(y, x);
    ui->Button_e->setFixedSize(y, x);
    ui->Button_C->setFixedSize(y, x);
    ui->Button_back->setFixedSize(y, x);

    ui->Button_pow2->setFixedSize(y, x);
    ui->Button_complement->setFixedSize(y, x);
    ui->Button_abs->setFixedSize(y, x);
    ui->Button_exp->setFixedSize(y, x);
    ui->Button_mod->setFixedSize(y, x);

    ui->Button_sqrt->setFixedSize(y, x);
    ui->Button_lpart->setFixedSize(y, x);
    ui->Button_rpart->setFixedSize(y, x);
    ui->Button_factorial->setFixedSize(y, x);
    ui->Button_div->setFixedSize(y, x);

    ui->Button_mi->setFixedSize(y, x);
    ui->Button_7->setFixedSize(y, x);
    ui->Button_8->setFixedSize(y, x);
    ui->Button_9->setFixedSize(y, x);
    ui->Button_mul->setFixedSize(y, x);

    ui->Button_10mi->setFixedSize(y, x);
    ui->Button_4->setFixedSize(y, x);
    ui->Button_5->setFixedSize(y, x);
    ui->Button_6->setFixedSize(y, x);
    ui->Button_sub->setFixedSize(y, x);

    ui->Button_log->setFixedSize(y, x);
    ui->Button_1->setFixedSize(y, x);
    ui->Button_2->setFixedSize(y, x);
    ui->Button_3->setFixedSize(y, x);
    ui->Button_add->setFixedSize(y, x);

    ui->Button_ln->setFixedSize(y, x);
    ui->Button_re->setFixedSize(y, x);
    ui->Button_0->setFixedSize(y, x);
    ui->Button_point->setFixedSize(y, x);
    ui->Button_equal->setFixedSize(y, x);
}

void CCalculator::DoPageTurn(bool PageLnv, bool PageHyp)
{
    if (PageLnv == false && PageHyp == false)
    {
        ui->Button_sin->setText("sin");
        ui->Button_cos->setText("cos");
        ui->Button_tan->setText("tan");
        ui->Button_sec->setText("sec");
        ui->Button_csc->setText("csc");
        ui->Button_cot->setText("cot");
    }
    else if (PageLnv == true && PageHyp == false)
    {
        ui->Button_sin->setText("sin-1");
        ui->Button_cos->setText("cos-1");
        ui->Button_tan->setText("tan-1");
        ui->Button_sec->setText("sec-1");
        ui->Button_csc->setText("csc-1");
        ui->Button_cot->setText("cot-1");
    }
    else if (PageLnv == false && PageHyp == true)
    {
        ui->Button_sin->setText("sinh");
        ui->Button_cos->setText("cosh");
        ui->Button_tan->setText("tanh");
        ui->Button_sec->setText("sech");
        ui->Button_csc->setText("csch");
        ui->Button_cot->setText("coth");
    }
    else
    {
        ui->Button_sin->setText("sinh-1");
        ui->Button_cos->setText("cosh-1");
        ui->Button_tan->setText("tanh-1");
        ui->Button_sec->setText("sech-1");
        ui->Button_csc->setText("csch-1");
        ui->Button_cot->setText("coth-1");
    }
}

/**
 * @brief CCalculator::ClearAll
 * 所有成员全部清零
 */

void CCalculator::ClearAll()
{
    this->m_qstrNewExpression = "0";
    this->m_bIsResult = false;
    if (m_qstrLastestInputChar != "0" || m_qstrResult != "0")
    {
        this->m_qstrResult = "0";
        this->m_qstrLastestInputChar = "0";
        ShowExpressionAndLastestInputChar();
    }
    else
    {
        this->m_qstrResult = "0";
        this->m_qstrLastestInputChar = "0";
        this->m_qstrExpression = " ";
        ShowExpressionAndResult();
    }
}

/**
 * @brief CCalculator::Back
 * 回退键：只有数字可以回退，每次回退一位,如果只有一位就变成 0 ；
 */

void CCalculator::Back()
{
    CCalculateResult *cCalculateResult = new CCalculateResult({m_qstrExpression, m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp});
    Param temp = cCalculateResult->Back();
    m_qstrExpression = temp.qstrExpression;
    m_qstrNewExpression = temp.qstrNewExpression;
    m_qstrLastestInputChar = temp.qstrLastestInputChar;
    m_qstrResult = temp.qstrResult;
    m_bIsResult = temp.bIsResult;
    m_bPage = temp.bPage;
    delete cCalculateResult;
    ShowExpressionAndLastestInputChar();
}

/**
 * @brief CCalculator::ShowResult
 * 在 textedit 中打印结果
 */

void CCalculator::ShowResult()
{
    GetResult();
}

void CCalculator::EnterAnotherPage()
{
    if (m_bPage == false)
    {
        m_bPage = true;
        ui->Button_pow2->setText("x³");
        ui->Button_sqrt->setText("3√x");
        ui->Button_mi->setText("y√x");
        ui->Button_10mi->setText("2^x");
        ui->Button_log->setText("logyx");
        ui->Button_ln->setText("e^x");
    }
    else
    {
        m_bPage = false;
        ui->Button_pow2->setText("x²");
        ui->Button_sqrt->setText("2√x");
        ui->Button_mi->setText("x^y");
        ui->Button_10mi->setText("10^x");
        ui->Button_log->setText("log");
        ui->Button_ln->setText("ln");
    }
}

void CCalculator::EnterTrangleLnv()
{
    if (m_bTranglePageLnv == false)
    {
        m_bTranglePageLnv = true;
        DoPageTurn(m_bTranglePageLnv, m_bTranglePageHyp);

    }
    else
    {
        m_bTranglePageLnv = false;
        DoPageTurn(m_bTranglePageLnv, m_bTranglePageHyp);
    }
}

void CCalculator::EnterTrangleHyp()
{
    if (m_bTranglePageHyp == false)
    {
        m_bTranglePageHyp = true;
        DoPageTurn(m_bTranglePageLnv, m_bTranglePageHyp);
    }
    else
    {
        m_bTranglePageHyp = false;
        DoPageTurn(m_bTranglePageLnv, m_bTranglePageHyp);
    }
}

/**
 * @brief CCalculator::GetResult
 * 表达式求值
 */

void CCalculator::GetResult()
{
    CCalculateResult *cCalculateResult = new CCalculateResult({m_qstrExpression, m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp});
    Param temp = cCalculateResult->GetResult();
    if (temp.qstrExpression.compare("Error") == 0)
    {
        return ;
    }
    m_qstrExpression = temp.qstrExpression;
    m_qstrNewExpression = temp.qstrNewExpression;
    m_qstrLastestInputChar = temp.qstrLastestInputChar;
    m_qstrResult = temp.qstrResult;
    m_bIsResult = temp.bIsResult;
    m_bPage = temp.bPage;
    delete cCalculateResult;
    ShowExpressionAndResult();
    m_qstrNewExpression = m_qstrResult;
    m_qstrResult = "";
    m_qstrExpression = " ";
    m_qstrLastestInputChar = "0";
    m_bIsResult = false;
}

/**
 * @brief CCalculator::OtherButton
 * 如果按的是数 改变 LastestInputChar
 * 否则 改变 Result 和 LastestInputChar
 */

void CCalculator::OtherButton()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    CCalculateResult *cCalculateResult = new CCalculateResult({m_qstrExpression, m_qstrNewExpression, m_qstrLastestInputChar, m_qstrResult, m_bIsResult, m_bPage, m_bTranglePageLnv, m_bTranglePageHyp});
    Param temp = cCalculateResult->OtherButton(btn);
    m_qstrExpression = temp.qstrExpression;
    m_qstrNewExpression = temp.qstrNewExpression;
    m_qstrLastestInputChar = temp.qstrLastestInputChar;
    m_qstrResult = temp.qstrResult;
    m_bIsResult = temp.bIsResult;
    m_bPage = temp.bPage;
    delete cCalculateResult;
    ShowExpressionAndLastestInputChar();
}

void CCalculator::ClickButtonOfTrangle()
{
    if (TranglePage == false)
    {
        TranglePage = true;
        FunctionPage = false;
        ui->Frame_Function->hide();
        m_bTranglePageLnv = false, m_bTranglePageHyp = false;
        DoPageTurn(m_bTranglePageLnv, m_bTranglePageHyp);
        ui->Frame_Trangle->show();
    }
    else
    {
        TranglePage = false;
        ui->Frame_Trangle->hide();
    }
}

void CCalculator::ClickButtonOfFunction()
{
    if (FunctionPage == false)
    {
        FunctionPage = true;
        TranglePage = false;
        ui->Frame_Trangle->hide();
        ui->Frame_Function->show();
    }
    else
    {
        FunctionPage = false;
        ui->Frame_Function->hide();
    }
}

/**
 * @brief CCalculator::ShowExpressionAndResult
 * 显示 表达式 和 结果
 */

void CCalculator::ShowExpressionAndResult()
{
    if (m_qstrResult.compare("nan") == 0)
    {
        m_qstrResult = "不存在";
    }
    if (m_qstrResult.compare("inf") == 0)
    {
        m_qstrResult = "溢出";
    }
    ui->textEditMain->clear();
    ui->textEditMain->setAlignment(Qt::AlignRight);
    ui->textEditMain->insertPlainText(m_qstrExpression);
    ui->textEditMain->append(m_qstrResult);
    if (m_qstrExpression.compare(" ") != 0 || m_qstrLastestInputChar != '0')
    {
        ui->Button_C->setText("CE");
    }
    else
    {
        ui->Button_C->setText("C");
    }
}

/**
 * @brief CCalculator::ShowExpressionAndLastestInputChar
 * 显示 表达式 和 最后输入
 */

void CCalculator::ShowExpressionAndLastestInputChar()
{
    if (m_qstrLastestInputChar.compare("nan") == 0)
    {
        m_qstrLastestInputChar = "不存在";
    }
    if (m_qstrLastestInputChar.compare("inf") == 0)
    {
        m_qstrLastestInputChar = "溢出";
    }
    ui->textEditMain->clear();
    ui->textEditMain->setAlignment(Qt::AlignRight);
    ui->textEditMain->insertPlainText(m_qstrExpression);
    ui->textEditMain->append(m_qstrLastestInputChar);
    if (m_qstrExpression.compare(" ") != 0 || m_qstrLastestInputChar != '0')
    {
        ui->Button_C->setText("CE");
    }
    else
    {
        ui->Button_C->setText("C");
    }
}



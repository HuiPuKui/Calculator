/********************************************************************************
** Form generated from reading UI file 'ccalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCALCULATOR_H
#define UI_CCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCalculator
{
public:
    QTextEdit *textEditMain;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Button_lnv;
    QPushButton *Button_pi;
    QPushButton *Button_e;
    QPushButton *Button_C;
    QPushButton *Button_back;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Button_pow2;
    QPushButton *Button_complement;
    QPushButton *Button_abs;
    QPushButton *Button_exp;
    QPushButton *Button_mod;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_sqrt;
    QPushButton *Button_lpart;
    QPushButton *Button_rpart;
    QPushButton *Button_factorial;
    QPushButton *Button_div;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Button_mi;
    QPushButton *Button_7;
    QPushButton *Button_8;
    QPushButton *Button_9;
    QPushButton *Button_mul;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Button_10mi;
    QPushButton *Button_4;
    QPushButton *Button_5;
    QPushButton *Button_6;
    QPushButton *Button_sub;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Button_log;
    QPushButton *Button_1;
    QPushButton *Button_2;
    QPushButton *Button_3;
    QPushButton *Button_add;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Button_ln;
    QPushButton *Button_re;
    QPushButton *Button_0;
    QPushButton *Button_point;
    QPushButton *Button_equal;
    QLabel *label;
    QPushButton *Button_trangle;
    QFrame *Frame_Trangle;
    QPushButton *Button_hyp;
    QPushButton *Button_sin;
    QPushButton *Button_cos;
    QPushButton *Button_tan;
    QPushButton *Button_sec;
    QPushButton *Button_csc;
    QPushButton *Button_cot;
    QPushButton *Button_TrLnv;
    QPushButton *Button_function;
    QFrame *Frame_Function;
    QPushButton *Button_abs2;
    QPushButton *Button_floor;
    QPushButton *Button_ceil;
    QPushButton *Button_deg;
    QPushButton *Button_rand;
    QPushButton *Button_dms;

    void setupUi(QWidget *CCalculator)
    {
        if (CCalculator->objectName().isEmpty())
            CCalculator->setObjectName(QString::fromUtf8("CCalculator"));
        CCalculator->resize(491, 522);
        CCalculator->setMinimumSize(QSize(0, 0));
        textEditMain = new QTextEdit(CCalculator);
        textEditMain->setObjectName(QString::fromUtf8("textEditMain"));
        textEditMain->setGeometry(QRect(10, 30, 471, 111));
        textEditMain->setTabletTracking(false);
        layoutWidget = new QWidget(CCalculator);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 202, 471, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Button_lnv = new QPushButton(layoutWidget);
        Button_lnv->setObjectName(QString::fromUtf8("Button_lnv"));
        Button_lnv->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(Button_lnv);

        Button_pi = new QPushButton(layoutWidget);
        Button_pi->setObjectName(QString::fromUtf8("Button_pi"));
        Button_pi->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(Button_pi);

        Button_e = new QPushButton(layoutWidget);
        Button_e->setObjectName(QString::fromUtf8("Button_e"));
        Button_e->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(Button_e);

        Button_C = new QPushButton(layoutWidget);
        Button_C->setObjectName(QString::fromUtf8("Button_C"));
        Button_C->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(Button_C);

        Button_back = new QPushButton(layoutWidget);
        Button_back->setObjectName(QString::fromUtf8("Button_back"));
        Button_back->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(Button_back);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Button_pow2 = new QPushButton(layoutWidget);
        Button_pow2->setObjectName(QString::fromUtf8("Button_pow2"));
        Button_pow2->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(Button_pow2);

        Button_complement = new QPushButton(layoutWidget);
        Button_complement->setObjectName(QString::fromUtf8("Button_complement"));
        Button_complement->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(Button_complement);

        Button_abs = new QPushButton(layoutWidget);
        Button_abs->setObjectName(QString::fromUtf8("Button_abs"));
        Button_abs->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(Button_abs);

        Button_exp = new QPushButton(layoutWidget);
        Button_exp->setObjectName(QString::fromUtf8("Button_exp"));
        Button_exp->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(Button_exp);

        Button_mod = new QPushButton(layoutWidget);
        Button_mod->setObjectName(QString::fromUtf8("Button_mod"));
        Button_mod->setEnabled(true);
        Button_mod->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(Button_mod);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Button_sqrt = new QPushButton(layoutWidget);
        Button_sqrt->setObjectName(QString::fromUtf8("Button_sqrt"));
        Button_sqrt->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(Button_sqrt);

        Button_lpart = new QPushButton(layoutWidget);
        Button_lpart->setObjectName(QString::fromUtf8("Button_lpart"));
        Button_lpart->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(Button_lpart);

        Button_rpart = new QPushButton(layoutWidget);
        Button_rpart->setObjectName(QString::fromUtf8("Button_rpart"));
        Button_rpart->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(Button_rpart);

        Button_factorial = new QPushButton(layoutWidget);
        Button_factorial->setObjectName(QString::fromUtf8("Button_factorial"));
        Button_factorial->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(Button_factorial);

        Button_div = new QPushButton(layoutWidget);
        Button_div->setObjectName(QString::fromUtf8("Button_div"));
        Button_div->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(Button_div);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Button_mi = new QPushButton(layoutWidget);
        Button_mi->setObjectName(QString::fromUtf8("Button_mi"));

        horizontalLayout_3->addWidget(Button_mi);

        Button_7 = new QPushButton(layoutWidget);
        Button_7->setObjectName(QString::fromUtf8("Button_7"));

        horizontalLayout_3->addWidget(Button_7);

        Button_8 = new QPushButton(layoutWidget);
        Button_8->setObjectName(QString::fromUtf8("Button_8"));

        horizontalLayout_3->addWidget(Button_8);

        Button_9 = new QPushButton(layoutWidget);
        Button_9->setObjectName(QString::fromUtf8("Button_9"));

        horizontalLayout_3->addWidget(Button_9);

        Button_mul = new QPushButton(layoutWidget);
        Button_mul->setObjectName(QString::fromUtf8("Button_mul"));

        horizontalLayout_3->addWidget(Button_mul);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Button_10mi = new QPushButton(layoutWidget);
        Button_10mi->setObjectName(QString::fromUtf8("Button_10mi"));

        horizontalLayout_2->addWidget(Button_10mi);

        Button_4 = new QPushButton(layoutWidget);
        Button_4->setObjectName(QString::fromUtf8("Button_4"));

        horizontalLayout_2->addWidget(Button_4);

        Button_5 = new QPushButton(layoutWidget);
        Button_5->setObjectName(QString::fromUtf8("Button_5"));

        horizontalLayout_2->addWidget(Button_5);

        Button_6 = new QPushButton(layoutWidget);
        Button_6->setObjectName(QString::fromUtf8("Button_6"));

        horizontalLayout_2->addWidget(Button_6);

        Button_sub = new QPushButton(layoutWidget);
        Button_sub->setObjectName(QString::fromUtf8("Button_sub"));

        horizontalLayout_2->addWidget(Button_sub);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Button_log = new QPushButton(layoutWidget);
        Button_log->setObjectName(QString::fromUtf8("Button_log"));

        horizontalLayout_6->addWidget(Button_log);

        Button_1 = new QPushButton(layoutWidget);
        Button_1->setObjectName(QString::fromUtf8("Button_1"));

        horizontalLayout_6->addWidget(Button_1);

        Button_2 = new QPushButton(layoutWidget);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));

        horizontalLayout_6->addWidget(Button_2);

        Button_3 = new QPushButton(layoutWidget);
        Button_3->setObjectName(QString::fromUtf8("Button_3"));

        horizontalLayout_6->addWidget(Button_3);

        Button_add = new QPushButton(layoutWidget);
        Button_add->setObjectName(QString::fromUtf8("Button_add"));

        horizontalLayout_6->addWidget(Button_add);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Button_ln = new QPushButton(layoutWidget);
        Button_ln->setObjectName(QString::fromUtf8("Button_ln"));

        horizontalLayout_7->addWidget(Button_ln);

        Button_re = new QPushButton(layoutWidget);
        Button_re->setObjectName(QString::fromUtf8("Button_re"));

        horizontalLayout_7->addWidget(Button_re);

        Button_0 = new QPushButton(layoutWidget);
        Button_0->setObjectName(QString::fromUtf8("Button_0"));

        horizontalLayout_7->addWidget(Button_0);

        Button_point = new QPushButton(layoutWidget);
        Button_point->setObjectName(QString::fromUtf8("Button_point"));

        horizontalLayout_7->addWidget(Button_point);

        Button_equal = new QPushButton(layoutWidget);
        Button_equal->setObjectName(QString::fromUtf8("Button_equal"));

        horizontalLayout_7->addWidget(Button_equal);


        verticalLayout->addLayout(horizontalLayout_7);

        label = new QLabel(CCalculator);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 101, 31));
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setWordWrap(false);
        label->setMargin(3);
        label->setIndent(-1);
        Button_trangle = new QPushButton(CCalculator);
        Button_trangle->setObjectName(QString::fromUtf8("Button_trangle"));
        Button_trangle->setGeometry(QRect(10, 150, 100, 27));
        Frame_Trangle = new QFrame(CCalculator);
        Frame_Trangle->setObjectName(QString::fromUtf8("Frame_Trangle"));
        Frame_Trangle->setGeometry(QRect(10, 180, 281, 101));
        Frame_Trangle->setFrameShape(QFrame::StyledPanel);
        Frame_Trangle->setFrameShadow(QFrame::Raised);
        Button_hyp = new QPushButton(Frame_Trangle);
        Button_hyp->setObjectName(QString::fromUtf8("Button_hyp"));
        Button_hyp->setGeometry(QRect(0, 50, 70, 50));
        Button_sin = new QPushButton(Frame_Trangle);
        Button_sin->setObjectName(QString::fromUtf8("Button_sin"));
        Button_sin->setGeometry(QRect(70, 0, 70, 50));
        Button_cos = new QPushButton(Frame_Trangle);
        Button_cos->setObjectName(QString::fromUtf8("Button_cos"));
        Button_cos->setGeometry(QRect(140, 0, 70, 50));
        Button_tan = new QPushButton(Frame_Trangle);
        Button_tan->setObjectName(QString::fromUtf8("Button_tan"));
        Button_tan->setGeometry(QRect(210, 0, 70, 50));
        Button_sec = new QPushButton(Frame_Trangle);
        Button_sec->setObjectName(QString::fromUtf8("Button_sec"));
        Button_sec->setGeometry(QRect(70, 50, 70, 50));
        Button_csc = new QPushButton(Frame_Trangle);
        Button_csc->setObjectName(QString::fromUtf8("Button_csc"));
        Button_csc->setGeometry(QRect(140, 50, 70, 50));
        Button_cot = new QPushButton(Frame_Trangle);
        Button_cot->setObjectName(QString::fromUtf8("Button_cot"));
        Button_cot->setGeometry(QRect(210, 50, 70, 50));
        Button_TrLnv = new QPushButton(Frame_Trangle);
        Button_TrLnv->setObjectName(QString::fromUtf8("Button_TrLnv"));
        Button_TrLnv->setGeometry(QRect(0, 0, 70, 50));
        Button_function = new QPushButton(CCalculator);
        Button_function->setObjectName(QString::fromUtf8("Button_function"));
        Button_function->setGeometry(QRect(140, 150, 100, 27));
        Frame_Function = new QFrame(CCalculator);
        Frame_Function->setObjectName(QString::fromUtf8("Frame_Function"));
        Frame_Function->setGeometry(QRect(140, 180, 211, 101));
        Frame_Function->setFrameShape(QFrame::StyledPanel);
        Frame_Function->setFrameShadow(QFrame::Raised);
        Button_abs2 = new QPushButton(Frame_Function);
        Button_abs2->setObjectName(QString::fromUtf8("Button_abs2"));
        Button_abs2->setGeometry(QRect(0, 0, 70, 50));
        Button_floor = new QPushButton(Frame_Function);
        Button_floor->setObjectName(QString::fromUtf8("Button_floor"));
        Button_floor->setGeometry(QRect(70, 0, 70, 50));
        Button_ceil = new QPushButton(Frame_Function);
        Button_ceil->setObjectName(QString::fromUtf8("Button_ceil"));
        Button_ceil->setGeometry(QRect(140, 0, 70, 50));
        Button_deg = new QPushButton(Frame_Function);
        Button_deg->setObjectName(QString::fromUtf8("Button_deg"));
        Button_deg->setGeometry(QRect(140, 50, 70, 50));
        Button_rand = new QPushButton(Frame_Function);
        Button_rand->setObjectName(QString::fromUtf8("Button_rand"));
        Button_rand->setGeometry(QRect(0, 50, 70, 50));
        Button_dms = new QPushButton(Frame_Function);
        Button_dms->setObjectName(QString::fromUtf8("Button_dms"));
        Button_dms->setGeometry(QRect(70, 50, 70, 50));

        retranslateUi(CCalculator);

        QMetaObject::connectSlotsByName(CCalculator);
    } // setupUi

    void retranslateUi(QWidget *CCalculator)
    {
        CCalculator->setWindowTitle(QApplication::translate("CCalculator", "Calculator", nullptr));
        Button_lnv->setText(QApplication::translate("CCalculator", "lnv", nullptr));
        Button_pi->setText(QApplication::translate("CCalculator", "\317\200", nullptr));
        Button_e->setText(QApplication::translate("CCalculator", "e", nullptr));
        Button_C->setText(QApplication::translate("CCalculator", "C", nullptr));
        Button_back->setText(QApplication::translate("CCalculator", "<x", nullptr));
        Button_pow2->setText(QApplication::translate("CCalculator", "x\302\262", nullptr));
        Button_complement->setText(QApplication::translate("CCalculator", "1/x", nullptr));
        Button_abs->setText(QApplication::translate("CCalculator", "|x|", nullptr));
        Button_exp->setText(QApplication::translate("CCalculator", "exp", nullptr));
        Button_mod->setText(QApplication::translate("CCalculator", "mod", nullptr));
        Button_sqrt->setText(QApplication::translate("CCalculator", "2\342\210\232x", nullptr));
        Button_lpart->setText(QApplication::translate("CCalculator", "(", nullptr));
        Button_rpart->setText(QApplication::translate("CCalculator", ")", nullptr));
        Button_factorial->setText(QApplication::translate("CCalculator", "n!", nullptr));
        Button_div->setText(QApplication::translate("CCalculator", "/", nullptr));
        Button_mi->setText(QApplication::translate("CCalculator", "x^y", nullptr));
        Button_7->setText(QApplication::translate("CCalculator", "7", nullptr));
        Button_8->setText(QApplication::translate("CCalculator", "8", nullptr));
        Button_9->setText(QApplication::translate("CCalculator", "9", nullptr));
        Button_mul->setText(QApplication::translate("CCalculator", "x", nullptr));
        Button_10mi->setText(QApplication::translate("CCalculator", "10^x", nullptr));
        Button_4->setText(QApplication::translate("CCalculator", "4", nullptr));
        Button_5->setText(QApplication::translate("CCalculator", "5", nullptr));
        Button_6->setText(QApplication::translate("CCalculator", "6", nullptr));
        Button_sub->setText(QApplication::translate("CCalculator", "-", nullptr));
        Button_log->setText(QApplication::translate("CCalculator", "log", nullptr));
        Button_1->setText(QApplication::translate("CCalculator", "1", nullptr));
        Button_2->setText(QApplication::translate("CCalculator", "2", nullptr));
        Button_3->setText(QApplication::translate("CCalculator", "3", nullptr));
        Button_add->setText(QApplication::translate("CCalculator", "+", nullptr));
        Button_ln->setText(QApplication::translate("CCalculator", "ln", nullptr));
        Button_re->setText(QApplication::translate("CCalculator", "+/-", nullptr));
        Button_0->setText(QApplication::translate("CCalculator", "0", nullptr));
        Button_point->setText(QApplication::translate("CCalculator", ".", nullptr));
        Button_equal->setText(QApplication::translate("CCalculator", "=", nullptr));
        label->setText(QApplication::translate("CCalculator", "\347\247\221\345\255\246", nullptr));
        Button_trangle->setText(QApplication::translate("CCalculator", "\344\270\211\350\247\222\345\255\246 v", nullptr));
        Button_hyp->setText(QApplication::translate("CCalculator", "hyp", nullptr));
        Button_sin->setText(QApplication::translate("CCalculator", "sin", nullptr));
        Button_cos->setText(QApplication::translate("CCalculator", "cos", nullptr));
        Button_tan->setText(QApplication::translate("CCalculator", "tan", nullptr));
        Button_sec->setText(QApplication::translate("CCalculator", "sec", nullptr));
        Button_csc->setText(QApplication::translate("CCalculator", "csc", nullptr));
        Button_cot->setText(QApplication::translate("CCalculator", "cot", nullptr));
        Button_TrLnv->setText(QApplication::translate("CCalculator", "lnv", nullptr));
        Button_function->setText(QApplication::translate("CCalculator", "\345\207\275\346\225\260 v", nullptr));
        Button_abs2->setText(QApplication::translate("CCalculator", "|x|", nullptr));
        Button_floor->setText(QApplication::translate("CCalculator", "\342\214\212x\342\214\213", nullptr));
        Button_ceil->setText(QApplication::translate("CCalculator", "\342\214\210x\342\214\211", nullptr));
        Button_deg->setText(QApplication::translate("CCalculator", "\342\206\222deg", nullptr));
        Button_rand->setText(QApplication::translate("CCalculator", "rand", nullptr));
        Button_dms->setText(QApplication::translate("CCalculator", "\342\206\222dms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CCalculator: public Ui_CCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCALCULATOR_H

/********************************************************************************
** Form generated from reading UI file 'ccalculatorsecondpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCALCULATORSECONDPAGE_H
#define UI_CCALCULATORSECONDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcalculatorSecondPage
{
public:

    void setupUi(QWidget *CcalculatorSecondPage)
    {
        if (CcalculatorSecondPage->objectName().isEmpty())
            CcalculatorSecondPage->setObjectName(QString::fromUtf8("CcalculatorSecondPage"));
        CcalculatorSecondPage->resize(400, 300);

        retranslateUi(CcalculatorSecondPage);

        QMetaObject::connectSlotsByName(CcalculatorSecondPage);
    } // setupUi

    void retranslateUi(QWidget *CcalculatorSecondPage)
    {
        CcalculatorSecondPage->setWindowTitle(QApplication::translate("CcalculatorSecondPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CcalculatorSecondPage: public Ui_CcalculatorSecondPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCALCULATORSECONDPAGE_H

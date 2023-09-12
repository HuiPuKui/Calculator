#include "ccalculator.h"

#include <QApplication>

#include "crational.h"

int main(int argc, char *argv[])
{
    CRational<int> b(1, 2);
    CRational<int> c(2, 3);
    CRational<int> d(3, 4);

    CRational<int> e = d = c = b;
    std::cout << e.getNumerator() << ' ' << e.getDenominator() << std::endl;

    QApplication a(argc, argv);
    CCalculator w;
    w.show();
    return a.exec();
}

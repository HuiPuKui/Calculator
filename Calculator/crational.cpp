#include "crational.h"

template<typename T>
CRational<T>::CRational(T tNumerator, T tDenominator) : m_tNumerator(tNumerator), m_tDenominator(tDenominator)
{
}

template<typename T>
CRational<T> &CRational<T>::operator = (const CRational &rhs)
{
    this->m_tNumerator   = rhs.m_tNumerator;
    this->m_tDenominator = rhs.m_tDenominator;
    return *this;
}

template<typename T>
CRational<T> &CRational<T>::operator += (const CRational rhs)
{
    CRational<T> TempRhs = rhs;
    ChangeToCommonDenominator(*this, TempRhs);
    (*this).m_tNumerator += TempRhs.m_tNumerator;
    DoReductionOfAFraction(*this);
    return *this;
}

template<typename T>
CRational<T> CRational<T>::operator + (const CRational rhs)
{
    CRational<T> Temp = *this;
    return Temp += rhs;
}

template<typename T>
long long CRational<T>::GetGcd(long long FirstNumber, long long SecondNumber)
{
    if (SecondNumber == 0)
    {
        return FirstNumber;
    }
    return GetGcd(SecondNumber, FirstNumber % SecondNumber);
}

template<typename T>
void CRational<T>::ChangeToCommonDenominator(CRational &lhs, CRational &rhs)
{
    CRational temp = lhs;
    lhs.m_tNumerator    *= rhs.m_tDenominator;
    lhs.m_tDenominator  *= rhs.m_tDenominator;
    rhs.m_tNumerator    *= temp.m_tDenominator;
    rhs.m_tDenominator  *= temp.m_tDenominator;
}

template<typename T>
void CRational<T>::DoReductionOfAFraction(CRational &TempRational)
{
    long long GCD = GetGcd(TempRational.m_tNumerator, TempRational.m_tDenominator);
    TempRational.m_tNumerator   /= GCD;
    TempRational.m_tDenominator /= GCD;
}



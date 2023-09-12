#ifndef CRATIONAL_H
#define CRATIONAL_H

template <typename T>
class CRational
{
public:
    CRational(const T&, const T&);
    CRational(const CRational&);
    CRational<T> &operator =  (const CRational&);

    CRational<T> &operator += (const CRational);
    CRational<T>  operator +  (const CRational);

    CRational<T> &operator -= (const CRational);
    CRational<T>  operator -  (const CRational);

    CRational<T> &operator *= (const CRational);
    CRational<T>  operator *  (const CRational);

    CRational<T> &operator /= (const CRational);
    CRational<T>  operator /  (const CRational);

    T getNumerator();
    T getDenominator();

private:
    long long GetGcd(long long FirstNumber, long long SecondNumber);
    void ChangeToCommonDenominator(CRational&, CRational&);
    void DoReductionOfAFraction(CRational &);

private:
    T m_tNumerator;     // 分子
    T m_tDenominator;   // 分母
};

template<typename T>
CRational<T>::CRational(const T &tNumerator, const T &tDenominator) : m_tNumerator(tNumerator), m_tDenominator(tDenominator)
{
}

template <typename T>
CRational<T>::CRational(const CRational& cRational)
{
    *this = cRational;
}

template <typename T>
CRational<T> &CRational<T>::operator = (const CRational &rhs)
{
    this->m_tNumerator   = rhs.m_tNumerator;
    this->m_tDenominator = rhs.m_tDenominator;
    return *this;
}

template <typename T>
CRational<T> &CRational<T>::operator += (const CRational rhs)
{
    CRational<T> TempRhs = rhs;
    ChangeToCommonDenominator(*this, TempRhs);
    (*this).m_tNumerator += TempRhs.m_tNumerator;
    DoReductionOfAFraction(*this);
    return *this;
}

template <typename T>
CRational<T> CRational<T>::operator + (const CRational rhs)
{
    CRational<T> Temp = *this;
    return Temp += rhs;
}

template <typename T>
CRational<T> &CRational<T>::operator -= (const CRational rhs)
{
    CRational<T> TempRhs = rhs;
    ChangeToCommonDenominator(*this, TempRhs);
    (*this).m_tNumerator -= TempRhs.m_tNumerator;
    DoReductionOfAFraction(*this);
    return *this;
}

template <typename T>
CRational<T> CRational<T>::operator - (const CRational rhs)
{
    CRational<T> Temp = *this;
    return Temp -= rhs;
}

template <typename T>
CRational<T> &CRational<T>::operator *= (const CRational rhs)
{
    CRational<T> TempRhs = rhs;
    this->m_tNumerator   *= TempRhs.m_tNumerator;
    this->m_tDenominator *= TempRhs.m_tDenominator;
    DoReductionOfAFraction(*this);
    return *this;
}

template <typename T>
CRational<T> CRational<T>::operator * (const CRational rhs)
{
    CRational<T> Temp = *this;
    return Temp *= rhs;
}

template <typename T>
CRational<T> &CRational<T>::operator /= (const CRational rhs)
{
    CRational<T> TempRhs = rhs;
    this->m_tNumerator   *= TempRhs.m_tDenominator;
    this->m_tDenominator *= TempRhs.m_tNumerator;
    DoReductionOfAFraction(*this);
    return *this;
}

template <typename T>
CRational<T> CRational<T>::operator / (const CRational rhs)
{
    CRational<T> Temp = *this;
    return Temp /= rhs;
}

template <typename T>
long long CRational<T>::GetGcd(long long FirstNumber, long long SecondNumber)
{
    if (SecondNumber == 0)
    {
        return FirstNumber;
    }
    return GetGcd(SecondNumber, FirstNumber % SecondNumber);
}

template <typename T>
void CRational<T>::ChangeToCommonDenominator(CRational &lhs, CRational &rhs)
{
    CRational temp = lhs;
    lhs.m_tNumerator    *= rhs.m_tDenominator;
    lhs.m_tDenominator  *= rhs.m_tDenominator;
    rhs.m_tNumerator    *= temp.m_tDenominator;
    rhs.m_tDenominator  *= temp.m_tDenominator;
}

template <typename T>
void CRational<T>::DoReductionOfAFraction(CRational &TempRational)
{
    bool IsNegative = false;
    if ((TempRational.m_tNumerator < 0 && TempRational.m_tDenominator > 0) || (TempRational.m_tNumerator >= 0 && TempRational.m_tDenominator < 0))
    {
        if (TempRational.m_tNumerator < 0)
        {
            TempRational.m_tNumerator = -TempRational.m_tNumerator;
        }
        if (TempRational.m_tDenominator < 0)
        {
            TempRational.m_tDenominator = -TempRational.m_tDenominator;
        }
        IsNegative = true;
    }
    for (int i = 0; i < 6; ++ i)
    {
        if ((TempRational.m_tNumerator != (long long)(TempRational.m_tNumerator)) || (TempRational.m_tDenominator != (long long)(TempRational.m_tDenominator)))
        {
            TempRational.m_tNumerator *= 10;
            TempRational.m_tDenominator *= 10;
        }
    }
    long long GCD = GetGcd(TempRational.m_tNumerator, TempRational.m_tDenominator);
    TempRational.m_tNumerator   /= GCD;
    TempRational.m_tDenominator /= GCD;
    if (IsNegative == true)
    {
        TempRational.m_tNumerator = -TempRational.m_tNumerator;
    }
}

template <typename T>
T CRational<T>::getNumerator()
{
    return m_tNumerator;
}

template <typename T>
T CRational<T>::getDenominator()
{
    return m_tDenominator;
}
#endif // CRATIONAL_H

#include "CppUnitTest.h"
#include "../zadanie21/Money.h"
#include "../zadanie21/Fractional.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Tests
{
    TEST_CLASS(FractionalTests)
    {
    public:
        TEST_METHOD(Fraction_Sum_Success)
        {
            Fractional f1(1, 2); // 0.5
            Fractional f2(1, 4); // 0.25
            Fractional res = f1 + f2;
            Assert::AreEqual(0.75, res.toDouble(), 0.001);
        }
        TEST_METHOD(Fraction_Sub_Success)
        {
            Fractional f1(3, 4); // 0.75
            Fractional f2(1, 4); // 0.25
            Fractional res = f1 - f2;
            Assert::AreEqual(0.5, res.toDouble(), 0.001);
        }
        TEST_METHOD(Fraction_Mult_Success)
        {
            Fractional f1(1, 2); // 0.5
            Fractional f2(1, 2); // 0.5
            Fractional res = f1 * f2;
            Assert::AreEqual(0.25, res.toDouble(), 0.001);
        }
        TEST_METHOD(Fraction_Div_Success)
        {
            Fractional f1(1, 2); // 0.5
            Fractional f2(1, 4); // 0.25
            Fractional res = f1 / f2;
            Assert::AreEqual(2.0, res.toDouble(), 0.001);
        }
        TEST_METHOD(Fraction_Double_Operations)
        {
            Fractional f(1, 2); // 0.5
            Fractional sumRes = f + 2.0;
            Assert::AreEqual(2.5, sumRes.toDouble(), 0.001);
            Fractional multRes = 2.0 * f;
            Assert::AreEqual(1.0, multRes.toDouble(), 0.001);
        }
    };
    TEST_CLASS(MoneyTests)
    {
    public:
        TEST_METHOD(Money_Sum_Success)
        {
            Money m1(10, 50.0); // 1050 коп.
            Money m2(5, 50.0);  // 550 коп.
            Money result = m1 + m2;
            Assert::AreEqual(1600.0, result.toKopeks(), 0.01);
        }
        TEST_METHOD(Money_Sub_Success)
        {
            Money m1(10, 50.0); // 1050 коп.
            Money m2(2, 0.0);   // 200 коп.
            Money result = m1 - m2;
            Assert::AreEqual(850.0, result.toKopeks(), 0.01);
        }
        TEST_METHOD(Money_Div_Money_Success)
        {
            Money m1(10, 0.0); // 1000 коп.
            Money m2(2, 50.0); // 250 коп.
            double ratio = m1 / m2;
            Assert::AreEqual(4.0, ratio, 0.01);
        }
        TEST_METHOD(Money_Multiply_Double_Success)
        {
            Money m(10, 0.0); // 1000 коп.
            Money result = m.multiply(2.5);
            Assert::AreEqual(2500.0, result.toKopeks(), 0.01);
        }
        TEST_METHOD(Money_Divide_Double_Success)
        {
            Money m(10, 0.0); // 1000 коп.
            Money result = m.divide(2.0);
            Assert::AreEqual(500.0, result.toKopeks(), 0.01);
        }
        TEST_METHOD(Money_Copy_Constructor_Success)
        {
            Money m1(15, 75.0); // 1575 коп.
            Money m2(m1);       // Копируем
            Assert::AreEqual(1575.0, m2.toKopeks(), 0.01);
        }
    };
}

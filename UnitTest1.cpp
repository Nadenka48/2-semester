#include "CppUnitTest.h"
#include "../zadanie21/Money.h"
#include "../zadanie21/Fractional.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Tests
{
    TEST_CLASS(MoneyTests){
        public :

            TEST_METHOD(Fraction_Sum_Success){
                double val = 2.5;
    Fractional f1(val);
    Fractional f2(1, 2);
    Fractional res = f1 + f2;
    Assert::AreEqual(3.0, res.toDouble(), 0.01);
}
TEST_METHOD(Money_Sum_Success)
{
    int r = 10;
    double k = 50.0;
    Money m1(r, k);
    Money m2(150.0);
    Money result = m1 + m2;
    Assert::AreEqual(1200.0, result.toKopeks(), 0.01);
}
}
;
}

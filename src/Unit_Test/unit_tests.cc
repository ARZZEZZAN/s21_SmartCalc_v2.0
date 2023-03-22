#include <gtest/gtest.h>

#include "../Model/CalculatorModel.h"
using namespace s21;
TEST(SmartCalculator, TestOperation) {
  s21::Model a;
  std::string str = "4 + 9 + 7 + 9";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_EQ(res, 29);
}
TEST(SmartCalculator, TestOperation1) {
  s21::Model a;
  std::string str = "4 + 9 / 2 * 67787";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_EQ(res, 305045.5);
}
TEST(SmartCalculator, TestFunc) {
  s21::Model a;
  std::string str = "(4^acos(2/4))";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 4.27047);
}
TEST(SmartCalculator, TestFunc1) {
  s21::Model a;
  std::string str = "(tan(2*2))";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 1.1578213);
}
TEST(SmartCalculator, TestFunc2) {
  s21::Model a;
  std::string str = "(4^acos(2/4)/tan(2*2))";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 3.6883678);
}
TEST(SmartCalculator, TestFunc3) {
  s21::Model a;
  std::string str = "(4^acos(2/4)/tan(2*2)/5^acos(2/4))";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 0.68371409);
}
TEST(SmartCalculator, TestFunc4) {
  s21::Model a;
  std::string str = "(4^acos(2/4)/tan(2*2)/5^acos(2/4)/tan(tan(tan(2*2))))";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, -0.58934796);
}
TEST(SmartCalculator, TestFunc5) {
  s21::Model a;
  std::string str = "3^cos(0.5)/5";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 0.52449733);
}
TEST(SmartCalculator, TestFunc6) {
  s21::Model a;
  std::string str = "3^cos(0.5)/sqrt(25)";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 0.52449733);
}
TEST(SmartCalculator, TestFunc7) {
  s21::Model a;
  std::string str = "log(10)";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 1);
}
TEST(SmartCalculator, TestFunc8) {
  s21::Model a;
  std::string str = "1+2*(3^sin(0.4))^3*2+1";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 16.436413);
}
TEST(SmartCalculator, TestFunc9) {
  s21::Model a;
  std::string str = "ln(10)";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 2.3025851);
}
TEST(SmartCalculator, TestFunc10) {
  s21::Model a;
  std::string str = "1+2*3^sin(0.4)^3*2+1";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 6.291162);
}
TEST(SmartCalculator, TestFunc11) {
  s21::Model a;
  std::string str = "1+2*3^sin(0.4)^56*2+1";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 6);
}
TEST(SmartCalculator, TestFunc12) {
  s21::Model a;
  std::string str = "acos(-0.5)+asin(-0.5)+atan(0.1)*cos(30)*sin(20)*tan(45)";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 1.5935309);
}
TEST(SmartCalculator, TestFunc13) {
  s21::Model a;
  std::string str = "(-5)^(-4)";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 0.0016);
}
TEST(SmartCalculator, TestFunc14) {
  s21::Model a;
  std::string str = "-4+5";
  double res;
  if (a.Validator(str)) {
    res = a.MainCalculation(str, 0.0);
  }
  EXPECT_FLOAT_EQ(res, 1);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

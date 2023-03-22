#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>

typedef enum {
  DIG_LEXEME = 1,
  X_LEXEME = 2,
  MINUS_LEXEME = 3,
  PLUS_LEXEME = 4,
  DIV_LEXEME = 5,
  MUL_LEXEME = 6,
  POW_LEXEME = 7,
  MOD_LEXEME = 8,
  UNARM_LEXEME = 9,
  UNARP_LEXEME = 10,
  COS_LEXEME = 11,
  SIN_LEXEME = 12,
  TAN_LEXEME = 13,
  ACOS_LEXEME = 14,
  ASIN_LEXEME = 15,
  ATAN_LEXEME = 16,
  SQRT_LEXEME = 17,
  LN_LEXEME = 18,
  LOG_LEXEME = 19,
  LEFT_SCOBE = 20,
  RIGHT_SCOBE = 21
} lexeme_enum;

namespace s21 {

typedef struct Lexeme {
  double value;
  int priority;
  lexeme_enum type;
} Lexeme;

class Model {
 public:
  Model() {}
  ~Model() {}
  double MainCalculation(std::string& str, double x);
  int Validator(std::string& str);

 private:
  std::stack<Lexeme> operations_;
  std::stack<Lexeme> numbers_;

  void Calculation();
  void Priority(std::stack<Lexeme> tmp, double x);
  std::stack<Lexeme> ParseLexemes(std::string lexem, int* i);
  std::stack<Lexeme> CalculateWith(double num1, lexeme_enum type);
  std::stack<Lexeme> CalculateWith(double num1, double num2, lexeme_enum type);
  bool IsOperator(char c);
};

}  // namespace s21

#endif

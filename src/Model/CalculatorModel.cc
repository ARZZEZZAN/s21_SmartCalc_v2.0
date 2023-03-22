#include "CalculatorModel.h"
namespace s21 {
std::stack<Lexeme> Model::ParseLexemes(std::string lexem, int* i) {
  std::stack<Lexeme> result;
  int it = 0;
  if (lexem[it] == 'x') {
    result.push({0, 0, X_LEXEME});
    (*i)++;
  } else if (lexem[it] == '+') {
    result.push({0, 1, PLUS_LEXEME});
    (*i)++;
  } else if (lexem[it] == '-') {
    result.push({0, 1, MINUS_LEXEME});
    (*i)++;
  } else if (lexem[it] == '/') {
    result.push({0, 2, DIV_LEXEME});
    (*i)++;
  } else if (lexem[it] == '*') {
    result.push({0, 2, MUL_LEXEME});
    (*i)++;
  } else if (lexem[it] == '^') {
    result.push({0, 3, POW_LEXEME});
    (*i)++;
  } else if (lexem[it] == 'm' && lexem[it + 1] == 'o' && lexem[it + 2] == 'd') {
    result.push({0, 3, MOD_LEXEME});
    (*i) += 3;
  } else if (lexem[it] == 's' && lexem[it + 1] == 'i' && lexem[it + 2] == 'n') {
    result.push({0, 4, SIN_LEXEME});
    (*i) += 3;
  } else if (lexem[it] == 'c' && lexem[it + 1] == 'o' && lexem[it + 2] == 's') {
    result.push({0, 4, COS_LEXEME});
    (*i) += 3;
  } else if (lexem[it] == 't' && lexem[it + 1] == 'a' && lexem[it + 2] == 'n') {
    result.push({0, 4, TAN_LEXEME});
    (*i) += 3;
  } else if (lexem[it] == 'l' && lexem[it + 1] == 'o' && lexem[it + 2] == 'g') {
    result.push({0, 4, LOG_LEXEME});
    (*i) += 3;
  } else if (lexem[it] == 'l' && lexem[it + 1] == 'n') {
    result.push({0, 4, LN_LEXEME});
    (*i) += 2;
  } else if (lexem[it] == 'a' && lexem[it + 1] == 's' && lexem[it + 2] == 'i' &&
             lexem[it + 3] == 'n') {
    result.push({0, 4, ASIN_LEXEME});
    (*i) += 4;
  } else if (lexem[it] == 'a' && lexem[it + 1] == 'c' && lexem[it + 2] == 'o' &&
             lexem[it + 3] == 's') {
    result.push({0, 4, ACOS_LEXEME});
    (*i) += 4;
  } else if (lexem[it] == 'a' && lexem[it + 1] == 't' && lexem[it + 2] == 'a' &&
             lexem[it + 3] == 'n') {
    result.push({0, 4, ATAN_LEXEME});
    (*i) += 4;
  } else if (lexem[it] == 's' && lexem[it + 1] == 'q' && lexem[it + 2] == 'r' &&
             lexem[it + 3] == 't') {
    result.push({0, 4, SQRT_LEXEME});
    (*i) += 4;
  } else if (lexem[it] == '(') {
    result.push({0, -1, LEFT_SCOBE});
    (*i)++;
  } else if (lexem[it] == ')') {
    result.push({0, -1, RIGHT_SCOBE});
    (*i)++;
  }
  return result;
}

double Model::MainCalculation(std::string& str, double x) {
  std::stack<Lexeme> tmp;
  std::stack<Lexeme> result;
  int i = 0;
  double value = 0.0;

  if (str[0] == '-' || str[0] == '+') {
    numbers_.push({0, 0, DIG_LEXEME});
  }
  while (i < (int)str.length()) {
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
    if (isdigit(str[i])) {
      value = atof(&str[i]);
      std::ostringstream stream;
      stream << value;
      std::string value_str = stream.str();
      numbers_.push({value, 0, DIG_LEXEME});
      i += value_str.length();
    } else {
      tmp = ParseLexemes(&str[i], &i);
      if (i > 1 && str[i - 2] == '(' &&
          (tmp.top().type == MINUS_LEXEME || tmp.top().type == PLUS_LEXEME)) {
        numbers_.push({0, 0, DIG_LEXEME});
      }
      Priority(tmp, x);
    }
  }
  while (!operations_.empty() && !numbers_.empty()) {
    Calculation();
  }
  result.push(numbers_.top());
  return result.top().value;
}
void Model::Priority(std::stack<Lexeme> tmp, double x) {
  std::stack<Lexeme> topStack;
  if (operations_.size() > 0) {
    topStack.push(operations_.top());
  } else {
    topStack.push({0, -1, DIG_LEXEME});
  }
  if (tmp.top().type == X_LEXEME) {
    numbers_.push({x, 1, DIG_LEXEME});
  } else if (tmp.top().type == LEFT_SCOBE) {
    operations_.push({x, -1, LEFT_SCOBE});
  } else if (tmp.top().priority > topStack.top().priority &&
             tmp.top().type != RIGHT_SCOBE) {
    operations_.push({0, tmp.top().priority, tmp.top().type});
  } else if (tmp.top().priority <= topStack.top().priority &&
             tmp.top().type != RIGHT_SCOBE && tmp.top().type != LEFT_SCOBE) {
    while (!operations_.empty() &&
           (tmp.top().priority <= operations_.top().priority &&
            tmp.top().type != POW_LEXEME)) {
      Calculation();
    }
    operations_.push(tmp.top());

  } else if (tmp.top().type == RIGHT_SCOBE) {
    while (operations_.size() > 0 && operations_.top().type != LEFT_SCOBE) {
      Calculation();
    }
    operations_.pop();
  }
}
void Model::Calculation() {
  std::stack<Lexeme> operation;
  operation.push(operations_.top());
  operations_.pop();

  std::stack<Lexeme> operand1;
  std::stack<Lexeme> operand2;

  if (operation.top().type > 8) {
    operand2.push(numbers_.top());
    numbers_.pop();
  } else {
    operand1.push(numbers_.top());
    numbers_.pop();
    operand2.push(numbers_.top());
    numbers_.pop();
  }
  std::stack<Lexeme> result;
  if (operation.top().type <= 8) {
    result = CalculateWith(operand2.top().value, operand1.top().value,
                           operation.top().type);
  } else {
    result = CalculateWith(operand2.top().value, operation.top().type);
  }
  numbers_.push(result.top());
}
std::stack<Lexeme> Model::CalculateWith(double num1, double num2,
                                        lexeme_enum type) {
  std::stack<Lexeme> result;
  result.push({0, 0, DIG_LEXEME});
  if (type == PLUS_LEXEME) {
    result.top().value = num1 + num2;
  } else if (type == MINUS_LEXEME) {
    result.top().value = num1 - num2;
  } else if (type == DIV_LEXEME) {
    result.top().value = num1 / num2;
  } else if (type == MUL_LEXEME) {
    result.top().value = num1 * num2;
  } else if (type == POW_LEXEME) {
    result.top().value = pow(num1, num2);
  } else if (type == MOD_LEXEME) {
    result.top().value = fmod(num1, num2);
  }
  return result;
}
std::stack<Lexeme> Model::CalculateWith(double num, lexeme_enum type) {
  std::stack<Lexeme> result;
  result.push({0, 0, DIG_LEXEME});
  if (type == SIN_LEXEME) {
    result.top().value = sin(num);
  } else if (type == COS_LEXEME) {
    result.top().value = cos(num);
  } else if (type == SQRT_LEXEME) {
    result.top().value = sqrt(num);
  } else if (type == TAN_LEXEME) {
    result.top().value = tan(num);
  } else if (type == ASIN_LEXEME) {
    result.top().value = asin(num);
  } else if (type == ACOS_LEXEME) {
    result.top().value = acos(num);
  } else if (type == ATAN_LEXEME) {
    result.top().value = atan(num);
  } else if (type == LN_LEXEME) {
    result.top().value = log(num);
  } else if (type == LOG_LEXEME) {
    result.top().value = log10(num);
  }
  return result;
}
bool Model::IsOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int Model::Validator(std::string& str) {
  int res = 1, i = 0;
  int lscob = 0;
  int rscob = 0;
  double value;
  for (i = 0; i < (int)str.size(); i++) {
    if (IsOperator(str[i])) {
      if (IsOperator(str[i + 1]) || i == (int)str.size() - 1) {
        res = 0;
      } else if ((i == 0 && str[i] != '-')) {
        res = 0;
      }
    } else if (str[i] == '.') {
      if (!isdigit(str[i + 1]) || i == (int)str.size() - 1 ||
          !isdigit(str[i - 1])) {
        res = 0;
      }
      value = atof(&str[i]);
      std::ostringstream stream;
      stream << value;
      std::string value_str = stream.str();
      if (str[i + value_str.size() - 1] == '.') {
        res = 0;
      }
    } else if (str[i] == '(') {
      if (i == (int)str.size() - 1 || str[i + 1] == ')') {
        res = 0;
      } else {
        lscob++;
      }
    } else if (str[i] == ')') {
      rscob++;
    }
  }
  if (lscob != rscob) {
    res = 0;
  }
  if (str.size() == 0) {
    res = 0;
  }
  return res;
}
}  // namespace s21
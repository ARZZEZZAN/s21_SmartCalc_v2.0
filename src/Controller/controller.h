#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../Model/CalculatorModel.h"
namespace s21 {

class Controller {
 public:
  Controller() {}
  ~Controller() {}
  double Calculation(std::string& str, double x);
  int Validate(std::string& str);

 private:
  s21::Model model_;
};  // Controller

}  //  namespace s21

#endif  // CONTROLLER_H
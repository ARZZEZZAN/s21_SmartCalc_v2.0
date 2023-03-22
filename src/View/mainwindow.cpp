#include "mainwindow.h"

#include <QLabel>
#include <QPixmap>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  window2_ = new GraphWindow(this);
  connect(ui_->pushButton_0, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_1, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_2, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_3, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_4, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_5, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_6, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_7, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_8, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_9, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_left, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_right, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_mul, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui_->pushButton_div, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui_->pushButton_mod, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui_->pushButton_pow, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui_->pushButton_sin, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_asin, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_cos, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_acos, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_tan, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_atan, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_ln, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_log, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_delete, SIGNAL(clicked()), this,
          SLOT(s21_on_pushButton_delete_clicked()));
  connect(ui_->pushButton_x, SIGNAL(clicked()), this,
          SLOT(s21_on_pushButton_x_clicked()));
  connect(ui_->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(s21_on_pushButton_tochka_clicked()));
  connect(ui_->pushButton_eq, SIGNAL(clicked()), this,
          SLOT(s21_on_pushButton_equal_clicked()));
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::s21_digit_numbers() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label = ui_->result_text->text() + button->text();

  ui_->result_text->setText(new_label);
}

void MainWindow::s21_operations() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;

  new_label = ui_->result_text->text();

  if (button->text() == "÷" && !(ui_->result_text->text().endsWith("÷")) &&
      !(ui_->result_text->text().endsWith("/"))) {
    new_label += "/";
  } else if (button->text() == "*" &&
             !(ui_->result_text->text().endsWith("*")) &&
             !(ui_->result_text->text().endsWith("*"))) {
    new_label += "*";
  } else if (button->text() == "+" &&
             !(ui_->result_text->text().endsWith("+"))) {
    new_label += "+";
  } else if (button->text() == "-" &&
             !(ui_->result_text->text().endsWith("-"))) {
    new_label += "-";
  } else if (button->text() == "^" &&
             !(ui_->result_text->text().endsWith("^"))) {
    new_label += "^";
  } else if (button->text() == "mod" &&
             !(ui_->result_text->text().endsWith("mod"))) {
    new_label += "mod";
  } else if (button->text() == "(") {
    new_label += "(";
  } else if (button->text() == ")") {
    new_label += ")";
  }

  ui_->result_text->setText(new_label);
}
void MainWindow::s21_functions() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;

  new_label = ui_->result_text->text() + button->text() + "(";

  ui_->result_text->setText(new_label);
}
void MainWindow::s21_on_pushButton_delete_clicked() {
  ui_->result_text->setText("");
}
void MainWindow::s21_on_pushButton_x_clicked() {
  QString new_label;

  if (!(ui_->result_text->text().endsWith("x")))
    new_label = ui_->result_text->text() + "x";

  ui_->result_text->setText(new_label);
}
void MainWindow::s21_on_pushButton_tochka_clicked() {
  if (!(ui_->result_text->text().endsWith('.')))
    ui_->result_text->setText(ui_->result_text->text() + ".");
}

void MainWindow::s21_on_pushButton_equal_clicked() {
  s21::Controller controller;
  std::string str = ui_->result_text->text().toStdString();

  if (controller.Validate(str) == 0) {
    ui_->result_text->setText("");
  } else if (ui_->result_text->text().contains("x")) {
    window2_->on_to_draw_button_clicked(str);
    window2_->show();
  } else {
    double result = controller.Calculation(str, 0.0);

    QString numberResult = QString::number(result);
    ui_->result_text->setText(numberResult);
  }
}

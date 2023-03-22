#include "graphwindow.h"

GraphWindow::GraphWindow(QWidget* parent)
    : QDialog(parent), ui_(new Ui::GraphWindow) {
  ui_->setupUi(this);
}

GraphWindow::~GraphWindow() { delete ui_; }

void GraphWindow::on_to_draw_button_clicked(std::string text) {
  s21::Model model;
  ui_->widget->clearGraphs();
  temp_str_ = text;

  double x_min_num = ui_->d_f_1->text().toDouble();
  double x_max_num = ui_->d_f_2->text().toDouble();
  double range_x = ui_->e_f_1->text().toDouble();
  double range_y = ui_->e_f_2->text().toDouble();

  xBegin_ = x_min_num;
  xEnd_ = x_max_num;

  ui_->widget->xAxis->setRange(-1 * range_x, range_x);
  ui_->widget->yAxis->setRange(-1 * range_y, range_y);

  h_ = 0.1;

  N_ = (xEnd_ - xBegin_) / h_ + 2;

  for (X_ = xBegin_; X_ < xEnd_; X_ += h_) {
    x_.push_back(X_);
    y_.push_back(model.MainCalculation(text, X_));
  }

  ui_->widget->addGraph();
  ui_->widget->graph(0)->addData(x_, y_);

  ui_->widget->setInteraction(QCP::iRangeZoom, true);
  ui_->widget->setInteraction(QCP::iRangeDrag, true);

  ui_->widget->replot();

  x_.clear();
  y_.clear();
}

void GraphWindow::on_to_draw_button_clicked() {
  GraphWindow::on_to_draw_button_clicked(temp_str_);
}

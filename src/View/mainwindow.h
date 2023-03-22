#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "graphwindow.h"
#include "ui_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui_;
  GraphWindow *window2_;

 private slots:
  void s21_digit_numbers();
  void s21_on_pushButton_tochka_clicked();
  void s21_on_pushButton_equal_clicked();
  void s21_operations();
  void s21_functions();
  void s21_on_pushButton_delete_clicked();
  void s21_on_pushButton_x_clicked();
};
#endif  // MAINWINDOW_H

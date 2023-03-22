#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>

#include "../Controller/controller.h"
#include "../QcustomLibrary/qcustomplot.h"
#include "QVector"
#include "ui_graphwindow.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  void on_to_draw_button_clicked(std::string text);

  ~GraphWindow();

 public slots:
  void on_to_draw_button_clicked();

 private:
  Ui::GraphWindow *ui_;
  double xBegin_, xEnd_, h_, X_;
  int N_;
  std::string temp_str_;
  QString text_str_;
  QVector<double> x_, y_;
};
#endif  // GRAPHWINDOW_H

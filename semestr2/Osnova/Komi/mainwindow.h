#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    void drawGraph();
    void solveTSPFromNode4();

    QVector<QVector<int>> costMatrix;
    int tsp(int pos, int visited);

    int n;
    QVector<QVector<int>> memo;
    QVector<QVector<int>> nextCity;
    void printPathFromNode4();
    void visualizePath(const QString& start);

};

#endif // MAINWINDOW_H

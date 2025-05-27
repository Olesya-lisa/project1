#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QStack>
#include <QBrush>
#include <QMap>
#include <QPair>
#include <QDebug>
#include <climits>

struct Node {
    int id;
    QPointF position;
};

struct Edge {
    int from;
    int to;
    int weight;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    drawGraph();
    solveTSPFromNode4();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawGraph()
{
    QMap<int, Node> nodes = {
        {1, {1, {300, 300}}},
        {2, {2, {200, 100}}},
        {3, {3, {400, 250}}},
        {4, {4, {100, 250}}},
        {5, {5, {350, 100}}},
        {6, {6, {150, 400}}},
        };

    QList<Edge> edges = {
    {1,2}, {2, 1},
    {1, 4}, {4, 1},
    {2, 3}, {3, 2},
    {2, 4}, {4, 2},
    {3, 5}, {5, 3},
    {4, 5}, {5, 4},
    {4, 7}, {7, 4},
    {4, 8}, {8, 4},
    {5, 6}, {6, 5},
    {5, 9}, {9, 5},
    {6, 10}, {10, 6},
    {6, 11}, {11, 6},
    {8, 9}, {9, 8},
    {9, 10}, {10, 9}

    };


    n = 6;
    costMatrix = QVector<QVector<int>>(n, QVector<int>(n, 999));

    // Отрисовка фона
    scene->setBackgroundBrush(QBrush(QColor(240, 223, 240)));
    QPen pen(Qt::black);
    pen.setWidth(2);

    //отрисовка ребер
    for (const Edge &e : edges) {
        QPointF p1 = nodes[e.from].position;
        QPointF p2 = nodes[e.to].position;
        scene->addLine(QLineF(p1, p2), pen);

        // Подписи весов ребер
        QGraphicsTextItem *text = scene->addText(QString::number(e.weight));
        text->setDefaultTextColor(Qt::black);
        QFont font = text->font();
        font.setBold(true);
        font.setPointSize(10);
        text->setFont(font);
        text->setPos((p1 + p2) / 2 - QPointF(7, 10));

        costMatrix[e.from - 1][e.to - 1] = e.weight;
    }

    //отрисовка узлов
    for (const Node &node : nodes) {
        QBrush brush(node.id == 4 ? QColor(255, 100, 100) : QColor(100, 170, 255));
        scene->addEllipse(node.position.x() - 20, node.position.y() - 20, 40, 40, pen, brush);

        QGraphicsTextItem* idText = scene->addText(QString::number(node.id));
        idText->setDefaultTextColor(Qt::white);
        QFont font = idText->font();
        font.setBold(true);
        font.setPointSize(14);
        idText->setFont(font);
        idText->setPos(node.position.x() - 7, node.position.y() - 15);
    }
}

int MainWindow::tsp(int pos, int visited)
{
    if (visited == (1 << n) - 1)
        return costMatrix[pos][3];  //возвращаемся в узел 4 (индекс 3)

    if (memo[pos][visited] != -1)
        return memo[pos][visited];

    int ans = INT_MAX;
    int bestNext = -1;

    for (int city = 0; city < n; ++city) {
        if (!(visited & (1 << city))) {
            int newAns = costMatrix[pos][city] + tsp(city, visited | (1 << city));
            if (newAns < ans) {
                ans = newAns;
                bestNext = city;
            }
        }
    }

    nextCity[pos][visited] = bestNext;
    return memo[pos][visited] = ans;
}

void MainWindow::solveTSPFromNode4()
{
    //инициализация структур данных
    memo = QVector<QVector<int>>(n, QVector<int>(1 << n, -1));
    nextCity = QVector<QVector<int>>(n, QVector<int>(1 << n, -1));

    // Узел 4 имеет индекс 3 (так как нумерация с 0)
    int startNode = 3;
    int result = tsp(startNode, 1 << startNode);

    qDebug() << "путь коммивояжера, начинающийся в вершине 4";
    qDebug() << "Минимальная стоимость пути:" << result;
    printPathFromNode4();
}

void MainWindow::printPathFromNode4()
{
    int startNode = 3; //индекс узла 4
    int visited = (1 << startNode);
    int pos = startNode;

    QString path = QString::number(pos + 1); //переводим индексы в номера узлов
    while (true) {
        int nxt = nextCity[pos][visited];
        if (nxt == -1)
            break;
        path += "->" + QString::number(nxt + 1);
        visited |= (1 << nxt);
        pos = nxt;
    }

    //добавляем возврат в начальную точку (узел 4)
    path += "->4";
    qDebug() << "Оптимальный путь:" << path;

    //визуализация пути
    visualizePath( path);
}

void MainWindow::visualizePath(const QString& start)
{
    //разбиваем строку пути на узлы
    QStringList nodes = start.split("->");

    //создаем список точек пути
    QVector<QPointF> points;
    for (const QString& node : nodes) {
        int nodeId = node.toInt();
        // фиктивные координаты
        points.append(QPointF(nodeId * 50, nodeId * 50));
    }

    //отрисовка пути
    QPen pathPen(Qt::red);
    pathPen.setWidth(3);
    pathPen.setStyle(Qt::DashLine);

    for (int i = 0; i < points.size() - 1; ++i) {
        scene->addLine(QLineF(points[i], points[i+1]), pathPen);
    }
}

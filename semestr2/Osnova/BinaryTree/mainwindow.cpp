#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QPen>
#include <cstring>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , root(nullptr)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}


MainWindow::~MainWindow()
{
    clearTree(root);
    delete scene;
    delete ui;
}
//добавление узла
void MainWindow::on_AddButton_clicked()
{
    QString input = ui->lineEdit->text();
    QByteArray pop = input.toLocal8Bit();
    root = insert(root, pop.data());
    scene->clear();
    visualizeTree(root, 400, 50, 1);
}
//удаление узла
void MainWindow::on_RemoveButton_2_clicked()
{
    QString input = ui->lineEdit->text();
    QByteArray hoh = input.toLocal8Bit();
    root = remove(root, hoh.data());
    scene->clear();
    visualizeTree(root, 400, 50, 1);
}

// подсчёт листьев
void MainWindow::on_countButton_clicked()
{
    int leavesCount = countLeaves(root);
    ui->label_2->setText(QString("Количество листьев: %1").arg(leavesCount));
}

//симметричный обход
void MainWindow::on_inOrderButton_3_clicked()
{
    QString result;
    inOrderTraversal(root, result);
    ui->label->setText("In-order: " + result);

}

//прямой
void MainWindow::on_preOrderButton_4_clicked()
{
    QString result;
    preOrderTraversal(root, result);
    ui->label->setText("Pre-order: " + result);
}

//обратный
void MainWindow::on_postOrderButton_5_clicked()
{
    QString result;
    postOrderTraversal(root, result);
    ui->label->setText("Post-order: " + result);
}
//отчистка дерева
void MainWindow::on_CleanButton_6_clicked()
{
    clearTree(root);
    root = nullptr;
    scene->clear();
    ui->label->clear();
    ui->label_2->clear();
}

// вставка с балансировкой
TreeNode* MainWindow::insert(TreeNode* node, const char* value)
{
    if (!node) return new TreeNode(value);

    int cmp = strcmp(value, node->value);
    if (cmp < 0) {
        node->left = insert(node->left, value);
    } else if (cmp > 0) {
        node->right = insert(node->right, value);
    } else {
        return node; // Дубликаты не допускаются
    }

    return balance(node);
}

// удаление с балансировкой
TreeNode* MainWindow::remove(TreeNode* node, const char* value)
{
    if (!node) return nullptr;

    if (!node) return nullptr;

    int cmp = strcmp(value, node->value);
    if (cmp < 0) {
        node->left = remove(node->left, value);
    } else if (cmp > 0) {
        node->right = remove(node->right, value);
    } else {
        if (!node->left || !node->right) {
            TreeNode* temp = node->left ? node->left : node->right;

            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            TreeNode* temp = minValueNode(node->right);
            delete[] node->value;
            node->value = new char[strlen(temp->value) + 1];
            strcpy(node->value, temp->value);
            node->right = remove(node->right, temp->value);
        }
    }

    if (!node) return nullptr;
    return balance(node);
}
//подсчет листьев
    int MainWindow::countLeaves(TreeNode* node)
{
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}
//поиск узла с минимальным значением
TreeNode* MainWindow::minValueNode(TreeNode* node)
{
    TreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

//высота узла
int MainWindow::height(TreeNode* node)
{
    return node ? node->height : 0;
}

//фактор баланса
int MainWindow::balanceFactor(TreeNode* node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

//обновление высоты узла
void MainWindow::updateHeight(TreeNode* node)
{
    if (node) {
        node->height = 1 + qMax(height(node->left), height(node->right));
    }
}

//правый поворот
TreeNode* MainWindow::rotateRight(TreeNode* y)
{
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

//левый поворот
TreeNode* MainWindow::rotateLeft(TreeNode* x)
{
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

//балансировка узла
TreeNode* MainWindow::balance(TreeNode* node)
{
    if (!node) return nullptr;

    updateHeight(node);

    int bf = balanceFactor(node);

    // Left Left Case
    if (bf > 1 && balanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }

    // Left Right Case
    if (bf > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Right Case
    if (bf < -1 && balanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }

    // Right Left Case
    if (bf < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

//очистка дерева
void MainWindow::clearTree(TreeNode* node)
{
    if (node) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

//визуализация дерева
void MainWindow::visualizeTree(TreeNode* node, int x, int y, int level)
{
    if (!node) return;

    const int circleRadius = 20;
    const int horizontalSpacing = 100 / level;

    //рисуем круг
    QGraphicsEllipseItem* circle = scene->addEllipse(
        x - circleRadius, y - circleRadius,
        circleRadius * 2, circleRadius * 2,
        QPen(Qt::black), QBrush(Qt::white));

    //добавляем текст
    QGraphicsTextItem* text = scene->addText(node->value);
    text->setPos(x - text->boundingRect().width() / 2,
                 y - text->boundingRect().height() / 2);

    //рисуем связи
    if (node->left) {
        int childX = x - horizontalSpacing;
        int childY = y + 80;
        scene->addLine(x, y + circleRadius, childX, childY - circleRadius);
        visualizeTree(node->left, childX, childY, level + 1);
    }

    if (node->right) {
        int childX = x + horizontalSpacing;
        int childY = y + 80;
        scene->addLine(x, y + circleRadius, childX, childY - circleRadius);
        visualizeTree(node->right, childX, childY, level + 1);
    }
}

//симметричный обход
void MainWindow::inOrderTraversal(TreeNode* node, QString& result)
{
    if (!node) return;

    inOrderTraversal(node->left, result);
    if (!result.isEmpty()) result += ", ";
    result += node->value;
    inOrderTraversal(node->right, result);
}

//прямой обход
void MainWindow::preOrderTraversal(TreeNode* node, QString& result)
{
    if (!node) return;

    if (!result.isEmpty()) result += ", ";
    result += node->value;
    preOrderTraversal(node->left, result);
    preOrderTraversal(node->right, result);
}

//обратный обход
void MainWindow::postOrderTraversal(TreeNode* node, QString& result)
{
    if (!node) return;

    postOrderTraversal(node->left, result);
    postOrderTraversal(node->right, result);
    if (!result.isEmpty()) result += ", ";
    result += node->value;
}

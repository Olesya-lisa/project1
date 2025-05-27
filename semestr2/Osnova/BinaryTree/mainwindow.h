#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class TreeNode {
public:
    char* value;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const char* val) : height(1), left(nullptr), right(nullptr) {
        value=new char[strlen(val)+1];
        strcpy(value, val);
    }
    TreeNode()
    {
        delete[] value;
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();
    void on_RemoveButton_2_clicked();
    void on_inOrderButton_3_clicked();
    void on_preOrderButton_4_clicked();
    void on_postOrderButton_5_clicked();
    void on_CleanButton_6_clicked();
    void on_countButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    TreeNode* root;

    // Основные методы дерева
    TreeNode* insert(TreeNode* node, const char* value);//добавление элемента
    TreeNode* remove(TreeNode* node, const char* value);//удаление элемента
    TreeNode* minValueNode(TreeNode* node);

    // Методы балансировки (AVL)
    int height(TreeNode* node);
    int balanceFactor(TreeNode* node);
    void updateHeight(TreeNode* node);
    TreeNode* rotateRight(TreeNode* y);
    TreeNode* rotateLeft(TreeNode* x);
    TreeNode* balance(TreeNode* node);

    // Вспомогательные методы
    void clearTree(TreeNode* node);
    void visualizeTree(TreeNode* node, int x, int y, int level);
    void inOrderTraversal(TreeNode* node, QString& result);
    void preOrderTraversal(TreeNode* node, QString& result);
    void postOrderTraversal(TreeNode* node, QString& result);
    int countLeaves(TreeNode* node);

};
#endif // MAINWINDOW_H

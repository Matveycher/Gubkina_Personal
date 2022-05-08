#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode
{
    struct treeNode *leftPtr;  //указатель на левую структуру
    int data;                  //данные
    struct treeNode *rightPtr; //указатель на правую структуру
};

typedef struct treeNode TREENODE; //для удобства заменяем на TREENODE
typedef TREENODE *TREENODEPTR;    //определяем  TREENODEPTR как указатель на  TREENODE

//прототипы
void insertNode(TREENODEPTR *, int); //создание дерева
void inOrder(TREENODEPTR);           //порядковая выборка
void preOrder(TREENODEPTR);          //предварительная выборка
void postOrder(TREENODEPTR);         //отлаженная выборка

int main()
{
    int i, item;
    TREENODEPTR rootPtr = NULL; //указатель на вершину

    srand(time(NULL));

    printf("The numbers being placed in the tree are: \n"); //числа помещенные в дерево
    for (i = 1; i <= 10; i++)                               // десять чисел в диапазоне от 0 до 14
    {
        item = rand() % 15;
        printf("%3d", item);        //выводим эти числа
        insertNode(&rootPtr, item); //вызываем функцию
    }

    /* обойти дерево с предварительной выборкой */
    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);

    /* обойти дерево с порядковой выборкой */
    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);

    /* обойти дерево с отложенной выборкой */
    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);

    getchar();
    return 0;
}

void insertNode(TREENODEPTR *treePtr, int value) //создание дерева
{
    if (*treePtr == NULL) //если treePtr равен нулю, то создаем новые узлы
    {
        *treePtr = malloc(sizeof(TREENODE)); //выделяем память под новый узел
        if (*treePtr != NULL)                // если treePtr не равен нулю
        {
            (*treePtr)->data = value; //присваиваем выделенной памяти целое значении и сохраняем его в value
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("%d not inserted. No memory available. \n", value);
    }
    else if (value < (*treePtr)->data)             //если значение меньше имеющихся значений
        insertNode(&((*treePtr)->leftPtr), value); //функция рекурсивно вызывается с указанием на адрес левой ветки
    else if (value > (*treePtr)->data)
        insertNode(&((*treePtr)->rightPtr), value);
    else
        printf("-dup"); // для дублирующихся значений
}

void inOrder(TREENODEPTR treePtr) //порядковая
{
    if (treePtr != NULL) //рекурсивные шаги продолжаются пока не обнаружен 0
    {
        inOrder(treePtr->leftPtr);    //обходим левре поддерево
        printf("%3d", treePtr->data); //обработать значения
        inOrder(treePtr->rightPtr);   //обойти правое
    }
}

void preOrder(TREENODEPTR treePtr) //предварительная
{
    if (treePtr != NULL)
    {
        printf("%3d", treePtr->data); //обработать значение
        preOrder(treePtr->leftPtr);   //пройти левое
        preOrder(treePtr->rightPtr);  //пройти правое
    }
}

void postOrder(TREENODEPTR treePtr) //отложенная
{
    if (treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);  //пройти левое
        postOrder(treePtr->rightPtr); //пройти правое
        printf("%3d", treePtr->data); //обработать
    }
}
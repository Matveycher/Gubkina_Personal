//ОЧЕРЕДЬ
#include <stdio.h>
#include <stdlib.h>

struct queueNode
{
    char data;                 //данные
    struct queueNode *nextPtr; //указатель на следующую такую структуру
};

typedef struct queueNode QUEUENODE; // меняем на QUEUENODE ,чтобы было проще
typedef QUEUENODE *QUEUENODEPTR;    //определяем QUEUENODEPTR как указатель на  QUEUENODE

//прототипы
void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, char); // вставка в очередь
char dequeue(QUEUENODEPTR *, QUEUENODEPTR *);       //исключение из очереди
int isEmpty(QUEUENODEPTR);                          // проверка пустая или не пустая очередь
void printQueue(QUEUENODEPTR);                      // печать//как и в isEmpty принимаем не по указателю, потому что не ходим вносить изменения
void instructions();                                //инструкция

int main()
{
    QUEUENODEPTR headPtr = NULL, tailPtr = NULL; // headPtr - узел "голова",tailPtr - узел "хвост"
    int choice;                                  // переменная для выбора действий в инструкции
    char item;                                   //символ , который вводит пользователь

    instructions(); // вызов функции инструкции
    printf("? ");
    scanf("%d", &choice); //считываем пункт инструкциии

    while (choice != 3) //пока пользователь не выбрал "завершить работу"
    {
        switch (choice)
        {
        case 1:                            //добавляем узел в конец
            printf("Enter a character: "); // выводим на экран "Введите символ:"
            scanf("\n%c", &item);
            enqueue(&headPtr, &tailPtr, item); //вызываем функцию вставки
            printQueue(headPtr);               // вызываем функцию печати , печатаем голову
            break;                             //стоп
        case 2:                                // удаление узла
            if (!isEmpty(headPtr))             //если список не пустой
            {
                item = dequeue(&headPtr, &tailPtr);      //присваиваем переменной item функцию удаления элементов
                printf("%c has been dequeued.\n", item); //сообщаем пользователю, что элемент удален
            }
            printQueue(headPtr);         //вызываем функцию печати очерели
            break;                       //стоп
        default:                         // если не 1, не 2 и не 3
            printf("Invalid choice!\n"); //выводим ошибку ввода
            break;                       // стоп
        }
        printf("? ");         // просим снова воспользоваться инструкцией
        scanf("%d", &choice); //считываем значение
    }
    printf("End of run.\n");
    return 0;
}

void instructions() //инструкция
{
    printf("Enter your choice:\n"
           "1 to add iten to the queue\n"
           "2 tp remove an item from the queue\n"
           "3 to end\n");
}

void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, char value) //вставка//передаём по адресу и принимаем по указателю, чтобы все изменения в функции отразились на списке
{
    QUEUENODEPTR newPtr = malloc(sizeof(QUEUENODE)); //создали новый узел,присвоили адресс выделенного блока памяти// выделили память для нового узла

    if (newPtr != NULL)                              // если новый узел не в конце
    {
        newPtr->data = value;   //присваиваем символ, который необходимо вставить в очередь
        newPtr->nextPtr = NULL; //присваиваем новому узлу NULL, чтобы показать, что он последний

        if (isEmpty(*headPtr))  //если список пустой, то новый элемент становится головой
        {
            *headPtr = newPtr;   // headPtr указатель на newPtr//(то новый элемент становится головой)
            *tailPtr = *headPtr; // при этом хвост== голове
        }
        else //иначе, встаёт в хвост
        {
            (*tailPtr)->nextPtr = newPtr; //прицепляем последний элемент к новому// указываем на адресс последнего
            *tailPtr = newPtr;            //новый узел теперь в хвост
        }
    }
    else
        printf("%c not inserted. No memory available.\n", value);
}

char dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr) // удаление элемента
{
    char value;                     //временная переменная, чтобы после удаления связей, можно было вернуть данные
    QUEUENODEPTR tempPtr;           //создали указатель, чтобы потом после разрыва связей почистить память

    value = (*headPtr)->data;       //сохранили данные, чтобы после чистки передать
    tempPtr = *headPtr;             //сохранили старую голову, чтобы потом очистить
    *headPtr = (*headPtr)->nextPtr; // сместили голову// указатель на новую голову

    if (*headPtr == NULL)           //если очередь пустая
        (*tailPtr) = NULL;          //то хвост указывает на конец

    free(tempPtr);                  //очищаем память
    return value;                   // возвращаем
}

int isEmpty(QUEUENODEPTR headPtr) //проверка пучтая или нет очередь
{
    return headPtr == NULL;
}
void printQueue(QUEUENODEPTR currentPtr) //печать
{
    if (currentPtr == NULL)
        printf("Queue is empty.\n\n");
    else
    {
        printf("The queue is:\n");
        while (currentPtr != NULL)
        {
            printf("%c -> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}
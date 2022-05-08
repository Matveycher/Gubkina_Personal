//СТЕК
#include <stdio.h>
#include <stdlib.h>

struct stackNode //структура
{
	int data;				 //данные
	struct stackNode *pNext; //указатель на следующую структуру
};

typedef struct stackNode STACKNODE; //заменяе на STACKNODE (для удобства)
typedef STACKNODE *STACKNODEPTR;	//определяем STACKNODEPTR как указатель на  STACKNODE

//прототипы
void push(STACKNODEPTR *, int); // создает новый узел и помещает его на вершину стека
int pop(STACKNODEPTR *);		//удаляет верхний узел стека, освобождает память, которая была выделена изъятому узлу и возвращает изъятое значение
int isEmpty(STACKNODEPTR);		//пустой или не пустой список
void printStack(STACKNODEPTR);	//печатает стек
void instructions();			//Инструкция

int main()
{
	STACKNODEPTR stackPtr = NULL; //указатель на вершину стека
	int choice, value;			  // инициализация переменных
	instructions();				  // вызов функции инструкции
	printf("? ");
	scanf("%d", &choice); // считываем чисто инструкции
	while (choice != 3)	  // пока пользователь не выбрал завершение работы
	{
		switch (choice)
		{
		case 1:							  //вставляем
			printf("Enter an integer: "); // просим ввести данные
			scanf("%d", &value);		  // считываем
			push(&stackPtr, value);		  // вставляем элемент в список
			printStack(stackPtr);		  // печатаем
			break;						  //стоп
		case 2:							  //удаляем
			if (!isEmpty(stackPtr))		  //если стек не пустой
			{
				printf("The popped value is: %d\n", pop(&stackPtr)); //извлекаем элемент
			}
			printStack(stackPtr); //печатаем
			break;				  // стоп
		default:				  // иначе
			printf("Invalid choice!\n\n");
			instructions();
			break;
		}
		printf("? ");
		scanf("%d", &choice);
	}
	printf("End of run.\n");
	return 0;
}
void instructions()
{
	printf("Enter a choice:\n"
		   "1 to push a value on the stack\n"
		   "2 to pop a value off the stack\n"
		   "3 to end a program\n");
}
void push(STACKNODEPTR *topPtr, int info) //вставка
{
	STACKNODEPTR newPtr = malloc(sizeof(STACKNODE)); // создаем новый узел,newPtr  присваиваем адресс блока выделенной памяти
	if (newPtr != NULL)
	{
		newPtr->data = info;	 //присваиваем необходимые данные
		newPtr->pNext = *topPtr; //привязали указатель на вершину стека
		*topPtr = newPtr;		 //теперь новый узел - голова (вершина)
	}
	else
		printf("%d not inserted. No memory available.\n", info);
}

int pop(STACKNODEPTR *topPtr) //удаление
{
	STACKNODEPTR tempPtr; //создали временный узел, чтобы после удаления связей почистить узел
	int popValue;
	tempPtr = *topPtr;			//сохранили голову, которую будем удалять
	popValue = (*topPtr)->data; //сохранили данные, которые находилось вверху
	*topPtr = (*topPtr)->pNext; // topPtr присваиваем адресс вкрхнего элемента
	free(tempPtr);				//почистили старую голову
	return popValue;
}
void printStack(STACKNODEPTR currentPtr)
{
	if (currentPtr == NULL)
	{
		printf("The stack is empty.\n\n");
	}
	else
	{
		printf("\nThe stack is:\n");
		while (currentPtr != NULL) //пока не наткнёмся на конец списка
		{
			printf(" %d ->", currentPtr->data);
			currentPtr = currentPtr->pNext;
		}
		printf("NULL\n\n");
	}
}

int isEmpty(STACKNODEPTR topPtr)
{
	return topPtr == NULL;
}
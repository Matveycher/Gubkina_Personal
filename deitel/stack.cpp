#include <stdio.h>
#include <stdlib.h>

struct stackNode {
    int data;
    struct stackNode* nextPtr;
};

typedef  struct stackNode STACKNODE;
typedef STACKNODE* STACKNODEPTR;

void push(STACKNODEPTR*, int);
int pop(STACKNODEPTR*);
int isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);
void instructions();

int main()
{
    STACKNODEPTR stackPtr = NULL;
    int choice, value;

    instructions();
    printf("? ");
    scanf("%d", &choice);

    while (choice != 3) {

        switch (choice) {
            case 1:
                printf("Enter an integer: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            case 2:
                if (!isEmpty(stackPtr))
                    printf("The popped value is %d\n", pop(&stackPtr));
                printStack(stackPtr);
                break;
            default:
                printf("Invalid choice.\n\n");
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
    printf("Enter choice:\n"
           "1 to push a value on the stack\n"
           "2 to pop a value off the stack\n"
           "3 to end program\n");
}

void push(STACKNODEPTR* topPtr, int info)
{
    STACKNODEPTR newPtr;

    newPtr = malloc(sizeof (STACKNODE));
    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
        printf("%d is not inserted, No memory available.\n", info);
}

int pop(STACKNODEPTR* topPtr)
{
    STACKNODEPTR tempPtr;
    int popValue;

    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

void printStack(STACKNODEPTR currentPtr)
{
    if (currentPtr == NULL)
        printf("The stack is empty.\n\n");
    else {
        printf("The stack is:\n");

        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

int isEmpty(STACKNODEPTR topPtr)
{
    return topPtr == NULL;
}



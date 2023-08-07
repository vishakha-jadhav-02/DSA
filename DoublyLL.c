// Doubly Linear Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous; 
} NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->previous = NULL;   

    if(*Head == NULL)          // LL is Empty
    {
        *Head = newn;
    }
    else                       // LL is not empty
    {
        (*Head)->previous= newn;
        newn-> next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    PNODE temp = *Head;

    newn->data = No;
    newn->next = NULL;
    newn->previous = NULL;
  
    if(*Head == NULL)          // LL is Empty
    {
        *Head = newn;
    }
    else                       // LL is not empty
    {
        while(temp -> next != NULL)
        {
            temp = temp-> next;
        }
        temp ->next = newn;
        newn ->previous = temp;
    }
}

void InsertAtPos(PPNODE Head, int No, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);

    int iCnt = 0;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position.\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head, No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(Head, No);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++) 
        {
            temp = temp ->next;
        }

        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;
        newn->previous = NULL; 

        newn -> next = temp -> next;        //      1
        temp->next->previous = newn;        //      2
        temp -> next = newn;                //      3
        newn-> previous = temp;             //      4

    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)          // LL is Empty
    {
        return;
    }
    else if ((*Head)-> next == NULL)        // LL contains one Node
    {
        free(*Head);
        *Head = NULL;
    }
    else                                    // LL contains more than one node
    {
        *Head = (*Head)->next;
        free((*Head)->previous);
        (*Head)->previous = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)          // LL is Empty
    {
        return;
    }
    else if ((*Head)-> next == NULL)        // LL contains one Node
    {
        free(*Head);
        *Head = NULL;
    }
    else                                    // LL contains more than one node
    {
        while(temp->next->next != NULL)
        {
            temp = temp-> next;
        }

        free(temp->next);
        temp -> next =NULL;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);

    int iCnt = 0;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position.\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp ->next;
        }
        temp -> next = temp -> next -> next;
        free(temp -> next -> previous);
        temp -> next -> previous = temp;
    }
}

void Display(PNODE Head)
{
    printf("Elements of linked list are: \n");
    
    printf("NULL <=>");
    while(Head != NULL)
    {
        printf("|%d|<=>", Head->data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head -> next;
    }
    return iCount;
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    int iRet = 0;
    iRet = Count(First);
    printf("Number of elements are: %d\n", iRet);
    
    Display(First);

    InsertLast(&First, 111);
    InsertLast(&First, 121);

    iRet = Count(First);
    printf("Number of elements are: %d\n", iRet);
    
    Display(First);

    InsertAtPos(&First, 55, 4);
    DeleteAtPos(&First,4);
    DeleteFirst(&First);
    DeleteLast(&First);

    iRet = Count(First);
    printf("Number of elements are: %d\n", iRet);
    
    Display(First);

    return 0;
}

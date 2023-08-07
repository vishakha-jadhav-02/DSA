#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = No;
    newn -> next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    PNODE temp = *Head;

    newn -> data = No;
    newn -> next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void Display(PNODE Head)
{
    printf("Elements of Linked List: \n");
    
    while(Head != NULL)
    {
        printf("|%d| -> ", Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCount = 0;
    
    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)   // LL is empty
    {
        return;
    }
    else if((*Head) -> next == NULL)        // LL contains one node
    {
        free(*Head);
        *Head = NULL;
    }
    else        // LL contains more than one node
    {
        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)   // LL is empty
    {
        return;
    }
    else if((*Head) -> next == NULL)        // LL contains one node
    {
        free(*Head);
        *Head = NULL;
    }
    else        // LL contains more than one node
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }
}

void InsertAtPos(PPNODE Head, int No, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);     // Calculate length of LL

    PNODE newn = NULL;
    int iCnt = 0;
    PNODE temp = *Head;

    // Filter
    if((iPos < 1)|| (iPos > iLength + 1))       //Invalid Position
    {
        printf("Invalid Position.\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head, No);
    }
    else if(iPos == iLength + 1)
    {
        InsertLast(Head, No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = No;
        newn -> next = NULL;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp-> next;
        }

        // Sequence is important
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);     // Calculate length of LL

    // Filter
    if((iPos < 1)|| (iPos > iLength))       //Invalid Position
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

    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertLast(&First, 11);
    InsertLast(&First, 21);
    InsertLast(&First, 51);
    InsertLast(&First, 101);          // 101  51  21  11

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are: %d \n\n",iRet);

    InsertFirst(&First, 10);          // 10  101  51  21  11
    InsertFirst(&First, 20);          // 20  10  101  51  21  11

    InsertAtPos(&First, 25, 5);          //20  10  101  51  25  21  11

    Display(First);

    DeleteAtPos(&First, 5);          //20  10  101  51  21  11

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are: %d \n\n",iRet);

    DeleteFirst(&First);          //10  101  51  21  11
    DeleteFirst(&First);          //101  51  21  11
    Display(First);

    iRet = Count(First);
    printf("Number of nodes are: %d \n",iRet);

    DeleteLast(&First);          //101  51  21  
    Display(First);

    iRet = Count(First);
    printf("Number of nodes are: %d \n",iRet);

    return 0;
}

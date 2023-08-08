// Stack

#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        node *next;

        node(int value)
        {
            data = value;
            next = NULL;
        }

}NODE, *PNODE;

class Stack
{
    private:
        PNODE First;
        int iCount;

    public:
        Stack();
        void Push(int no);      // InsertLast
        int Pop();              // InsertFirst
        void Display();
        int Count();
};

Stack::Stack()
{
    First = NULL;
    iCount = 0;
}

void Stack::Push(int no)
{
    PNODE newn = new NODE(no);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp ->next = newn;
    }
    iCount++;
}

int Stack::Pop()
{
    int Value = 0; 

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First ->data;
        delete First;
        First = NULL;
    }
    else
    {
        
        PNODE temp = First;
        
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;

    return Value;
}

void Stack::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display.";
        return;
    }
    cout<<"Elements of Stack are: \n";

    PNODE temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
}

int Stack::Count()
{
    return iCount;
}

int main()
{
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    Stack obj;

    cout<<"----------------------------------------\n";
    cout<<"Dynamic Implementation of Stack\n";
    cout<<"----------------------------------------\n";

    while(iChoice != 0)
    {
        cout<<"----------------------------------------\n";
        cout<<"Please enter the option: \n";

        cout<<"1: Push element into Stack\n";
        cout<<"2: Pop element from Stack\n";
        cout<<"3: Display elements from Stack\n";
        cout<<"4: Count number of elements from Stack\n";
        cout<<"0: Terminate the Application\n";
        cout<<"----------------------------------------\n";

        cout<<"Please enter the option: ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to push: ";
                cin>>iValue;
                obj.Push(iValue);
                break;

            case 2:
                iRet = obj.Pop();
                if(iRet != -1)
                {
                    cout<<"Poped element from stack is: "<<iRet<<"\n";
                }
                break;
            
            case 3: 
                obj.Display();
                break;

            case 4: 
                iRet = obj.Count();
                cout<<"Number of elements are: "<<iRet<<"\n";
                break;
            
            case 0:
                cout<<"Thank you for using the application.\n";
                break;

            default:
                cout<<"Please enter valid option\n";
                break;
        }// End of Switch
    } // End of while

    return 0;
} // End of main

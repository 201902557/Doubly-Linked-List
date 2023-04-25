#include <iostream>
#include <stdlib.h>
using namespace std;
int counter = 0;
struct nodeType
{
    int key;
    string data;
    struct nodeType *link;
    struct nodeType *plink;
};
nodeType *head, *current, *newNode, *p, *lastNode, *prevNode, *midNode;
void insertNode(int value, int k)
{
    if(head == NULL)
    {
        newNode = new nodeType;
        newNode->data = value;
        newNode->key = counter;
        newNode->plink = head;
        newNode->link = NULL;
        head = newNode;
        current = newNode;
        prevNode = newNode;
        lastNode = newNode;
        counter++;
        newNode = newNode->link;

        cout<<"Head Node Inserted Successfully......"<<endl;
    }
    else
    {
        if(k == 1)
        {
            lastNode = prevNode->plink;
            current = prevNode;
        }
        k = 1;
        newNode = new nodeType;
        newNode->data = value;
        newNode->key = counter;
        newNode->link = current->link;
        newNode->plink = prevNode->plink;

        current->link = newNode;
        current = current->link;

        prevNode = current;
        prevNode->plink = lastNode;

        lastNode = newNode;

        counter++;
        cout<<"Node Inserted Successfully......"<<endl;
    }
}
void searchNode(int pos)
{
    if(head == NULL)
    {
        cout<<"List Is Empty"<<endl;
    }
    else
    {
        current = head;
        while(current->key != counter/2)
        {
            current = current->link;
        }
        midNode = current;

        if(pos < midNode->key && pos >= 0)
        {
            current = head;
            while(current->key != midNode->key)
            {
                cout<<"Searching From Left To Right.."<<endl;
                if(current->key == pos)
                {
                    cout<<"Item Found In Doubly Linked List"<<endl;
                    cout<<"["<<current->key<<"]["<<current->data<<"]"<<endl;
                    break;
                }
                cout<<current->key<<endl;
                current = current->link;
            }
        }
        else if(pos > midNode->key && pos < counter)
        {
            prevNode = lastNode;
            while(prevNode->key != midNode->key)
            {
                cout<<"Searching From Right To Left.."<<endl;
                if(prevNode->key == pos)
                {
                    cout<<"Item Found In Doubly Linked List"<<endl;
                    cout<<"["<<prevNode->key<<"]["<<prevNode->data<<"]"<<endl;
                    break;
                }
                cout<<prevNode->key<<endl;
                prevNode = prevNode->plink;
            }
        }
        else if(pos == midNode->key)
        {
            cout<<"Item Found In Doubly Linked List"<<endl;
            cout<<"["<<midNode->key<<"]["<<midNode->data<<"]"<<endl;
        }
        else
        {
            cout<<"Item Not Found In Doubly Linked List!!!!!"<<endl;
        }
        current = lastNode;
    }
}
/*void deleteNode(int pos)
{
    if(head == NULL)
    {
        cout<<"List Is Empty"<<endl;
    }
    else if(pos == 0)
    {
        cout<<"Cannot Delete Head Node.!!!"<<endl;
    }
    else if (head != NULL)
    {
        int temp = 0;
        current = head;
        while(current->link != NULL)
        {
            if(current->link->key == pos)
            {
                temp = 1;
                p = current->link;
                current->link = current->link->link;
                delete p;
                p = NULL;
                counter--;
                cout<<"Node Deleted Successfully"<<endl;
                break;
            }
            current = current->link;
        }
        if(temp == 0)
        {
            cout<<"Node Item Not Found!!!!!"<<endl;
        }
    }
    else
    {
        cout<<"Invalid Delete Item!!!!!"<<endl;
    }
}*/
void print()
{
    if(head == NULL)
    {
        cout<<"List Is Empty"<<endl;
    }
    else
    {
        current = head;
        cout<<"List is :";
        while(current != NULL)
        {
            if(current->key == counter/2)
            {
                midNode = current;
            }
            cout<<"["<<current->key<<"]["<<current->data<<"]<-->";
            current = current->link;
        }
        current = lastNode;
    }
}
void createNewList()
{
    current = head;
    while(head != NULL)
    {
        current = head;
        delete current;
        current = NULL;
        head = head->link;
    }
    head = NULL;
    lastNode = NULL;
    prevNode = NULL;
    counter = 0;
}
int main()
{
    int option, value, pos, k = 0;
    do
    {
        cout<<"Doubly Linked List"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"What Operation do you want to perform?Select Option number. Enter 99 to exit."<<endl;
        cout<<"1. Create New List"<<endl;
        cout<<"2. Insert New Item to the List"<<endl;
        cout<<"3. Search for an Item in the List By Key"<<endl;
        //cout<<"4. Delete an Item from the List By Key"<<endl;
        cout<<"5. Print Sorted Doubly Linked List"<<endl<<endl;
        cin>>option;
        cout<<endl;
        switch(option)
        {
        case 1:
            k = 0;
            createNewList();
            cout<<"New List Created!!!"<<endl;
            break;
        case 2:
            cout<<"Enter Item to store in the Node."<<endl;
            cin>>value;
            insertNode(value, k);
            break;
        case 3:
            cout<<"Enter Key Of Item To Search For In Doubly Linked List."<<endl;
            cin>>pos;
            searchNode(pos);
            break;
        /*case 4:
            cout<<"Enter Item Of Node To Delete"<<endl;
            cin>>pos;
            deleteNode(pos);
            break;*/
        case 5:
            print();
            break;
        default:
            break;
        }
        cout<<endl;
        system("PAUSE");
        system("CLS");
    }while(option != 99);
    return 0;
}

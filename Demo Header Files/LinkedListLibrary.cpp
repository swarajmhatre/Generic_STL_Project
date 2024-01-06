#include "LinkedListLibrary.h"
#include<iostream>
using namespace std;


template <class T>
NodeG<T>::NodeG() {
    next = nullptr;
    prev = nullptr;
}

template <class T>
NodeG<T>::NodeG(T data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//_______________________________________________________________________Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
LinkedList<T>::LinkedList() {
    First = nullptr;
    iSize = 0;
}

template <class T>
int LinkedList<T>::Count() {
    return iSize;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Doubly Circular Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
DoublyCL<T>::DoublyCL()
{
    Last = NULL;
}

template <class T>
DoublyCL<T>::~DoublyCL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i < iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeG<T> *temp = First;
    cout << "\nThe elements of the Linked List Are: ";
    cout << "<=> ";
    for (int i = 1; i <= iSize; i++)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    iSize++;
};

template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;
    iSize++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T iNo, int iPos)
{
    if ((iPos < 1) && (iPos > iSize + 1))
    {
        cout << "\nInvalid Input!";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        NodeG<T> *newn = new NodeG<T>(iNo);
        NodeG<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        newn->prev = temp;
        newn->next->prev = newn;
        iSize++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "\nNothing to delete!";
        return;
    }
    if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }
    iSize--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "\nInvalid Input!";
        return;
    }
    if (First == Last)
    {
        delete Last;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
    iSize--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if ((iPos < 1) && (iPos > iSize))
    {
        cout << "\nInvalid Input!";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize + 1)
    {
        DeleteLast();
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iSize--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Doublu Linear Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLL<T>::~DoublyLL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i < iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    NodeG<T> *temp = First;
    cout << "\nThe elements of the Linked List Are: ";
    cout << "NULL <=> ";
    for (int i = 1; i <= iSize; i++)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL ";
}

template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iSize++;
}

template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize; i++)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iSize++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
{
    if ((iPos < 1) && (iPos > iSize + 1))
    {
        cout << "\nInvalid Input!";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        NodeG<T> *newn = new NodeG<T>(iNo);
        NodeG<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        newn->prev = temp;
        newn->next->prev = newn;
        iSize++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == nullptr)
    {
        cout << "Nothing to delete...\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    iSize--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        cout << "Nothing to delete\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if ((iPos < 1) && (iPos > iSize))
    {
        cout << "\nInvalid Input!";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize + 1)
    {
        DeleteLast();
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iSize--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Singly Circular Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    Last = NULL;
}

template <class T>
SinglyCL<T>::~SinglyCL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i < iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeG<T> *temp = First;
    printf("\nThe Linked list is: ");
    for (int i = 1; i <= iSize; i++)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
}

template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
    iSize++;
}

template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        Last->next = newn;
        Last = newn;
    }
    iSize++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T iNo, int iPos)
{
    if ((iPos < 1) || (iPos > iSize + 1))
    {
        cout << "Invalid Input\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        NodeG<T> *newn = new NodeG<T>(iNo);
        NodeG<T> *temp = First;
        for (int i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "Nothing to Delete...\n";
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iSize--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "Nothing to Delete...\n";
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = First;
        delete Last;
        Last = temp;
    }
    iSize--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if ((iPos < 1) || (iPos > iSize))
    {
        cout << "Invalid Input";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
        NodeG<T> *temp = First;
        NodeG<T> *tempX = NULL;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;
        iSize--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Singly Linear Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
SinglyLL<T>::~SinglyLL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i < iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iSize++;
}

template <class T>
void SinglyLL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

    if (First == NULL)
    {
        First = newn;
    }
    else if (First->next == NULL)
    {
        First->next = newn;
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize; i++)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T iNo, int iPos)
{

    if ((iPos < 1) || (iPos > iSize + 1))
    {
        printf("Invalid Input\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        NodeG<T> *temp = First;
        NodeG<T> *newn = new NodeG<T>(iNo);

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iSize++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        printf("Nothing to delete...");
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeG<T> *temp = First;
        First = First->next;
        delete temp;
    }
    iSize--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        printf("Nothing to delete...");
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 0; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    if ((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid Input.\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
        NodeG<T> *temp = First;
        NodeG<T> *tempX = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;
        iSize--;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    NodeG<T> *temp = First;
    printf("The Linked list is: ");
    for (int i = 1; i <= iSize; i++)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// cStack implementation

template <class T>
cStack<T>::~cStack()
{
    NodeG<T> *temp = First;
    for (int i = 0; i < iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void cStack<T>::push(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iSize++;
}

template <class T>
void cStack<T>::pop()
{
    if (iSize == 0)
    {
        printf("cStack is Empty");
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeG<T> *temp = First;
        First = First->next;
        delete temp;
    }
    iSize--;
}

template <class T>
int cStack<T>::top(){
    if(iSize == 0){
        return -1;
    }
    else{
        return (First->data);
    }
}

template <class T>
bool cStack<T>::isEmpty(){
    if(iSize == 0){
        return true;
    }
    else{
        return false;
    }
}


// cQueue implementation


template <class T>
cQueue<T>::~cQueue()
{
    NodeG<T> *temp = First;
    for (int i = 0; i < iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void cQueue<T>::enqueue(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

    if (First == NULL)
    {
        First = newn;
    }
    else if (First->next == NULL)
    {
        First->next = newn;
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize; i++)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

template <class T>
void cQueue<T>::dequeue()
{
    if (iSize == 0)
    {
        printf("cQueue is Empty");
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeG<T> *temp = First;
        First = First->next;
        delete temp;
    }
    iSize--;
}

template <class T>
int cQueue<T>::peek(){
    if(iSize == 0){
        return -1;
    }
    else{
        return (First->data);
    }
}

template <class T>
bool cQueue<T>::isNull(){
    if(iSize == 0){
        return true;
    }
    else{
        return false;
    }
}
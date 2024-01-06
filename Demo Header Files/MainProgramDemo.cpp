// MainProgram.cpp

#include "LinkedListLibrary.h"

int main()
{
    DoublyCL<int> myList;
    myList.InsertFirst(42);
    myList.InsertLast(123);
    myList.Display();

    SinglyCL<int> myList2;
    myList2.InsertFirst(5);
    myList2.InsertLast(10);
    myList2.Display();

    SinglyLL<int> myList3;
    myList3.InsertFirst(3);
    myList3.InsertLast(7);
    myList3.Display();

    return 0;
}

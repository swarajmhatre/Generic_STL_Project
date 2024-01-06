// LinkedListLibrary.h

#ifndef LINKED_LIST_LIBRARY_H
#define LINKED_LIST_LIBRARY_H

#include <iostream>

template <class T>
class NodeG {
public:
    T data;
    NodeG *next;
    NodeG *prev;

    NodeG();
    NodeG(T data);
};

template <class T>
class LinkedList {
protected:
    NodeG<T> *First;
    int iSize;

public:
    LinkedList();
    virtual void InsertFirst(T iNo) = 0;
    virtual void InsertLast(T iNo) = 0;
    virtual void InsertAtPos(T iNo, int iPos) = 0;
    virtual void DeleteFirst() = 0;
    virtual void DeleteLast() = 0;
    virtual void DeleteAtPos(int iPos) = 0;

    int Count();
};

template <class T>
class DoublyCL : public LinkedList<T> {
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;
    NodeG<T> *Last;

public:
    DoublyCL();
    ~DoublyCL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
class DoublyLL : public LinkedList<T>
{
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;

public:
    ~DoublyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
class SinglyCL : public LinkedList<T> {
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;
    NodeG<T> *Last;

public:
    SinglyCL();
    ~SinglyCL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
class SinglyLL : public LinkedList<T> {
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;

public:
    ~SinglyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
class cStack : public LinkedList<T> {
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;

public:
    ~cStack();
    void push(T iNo);
    void pop();
    int top();
    bool isEmpty();
};

template <class T>
class cQueue : public LinkedList<T> {
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;

public:
    ~cQueue();
    void enqueue(T iNo);
    void dequeue();
    int peek();
    bool isNull();
};

#include "LinkedListLibrary.cpp" // Include the implementation file

#endif // LINKED_LIST_LIBRARY_H

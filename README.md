# Linked List Operations

This C++ project demonstrates various operations on different types of linked lists, including Singly Linear, Singly Circular, Doubly Linear, and Doubly Circular Linked Lists. The project is structured using classes and templates for flexibility.

## Linked List Classes

### 1. `NodeG` Class
- Represents a node in the linked list.
- Contains data, a pointer to the next node (`next`), and a pointer to the previous node (`prev`).

### 2. `LinkedList` Class (Abstract Base Class)
- An abstract class defining the basic operations for a linked list.
- Operations include insertion at the beginning, end, and at a specified position, as well as deletion from the beginning, end, and at a specified position.

### 3. `DoublyCL` Class
- Inherits from `LinkedList` and implements a Doubly Circular Linked List.
- Supports operations such as insertion, deletion, and display.

### 4. `DoublyLL` Class
- Inherits from `LinkedList` and implements a Doubly Linear Linked List.
- Supports operations such as insertion, deletion, and display.

### 5. `SinglyCL` Class
- Inherits from `LinkedList` and implements a Singly Circular Linked List.
- Supports operations such as insertion, deletion, and display.

### 6. `SinglyLL` Class
- Inherits from `LinkedList` and implements a Singly Linear Linked List.
- Supports operations such as insertion, deletion, and display.

## Sample Usage

The `main` function provides examples of using each type of linked list. It demonstrates creating instances, inserting elements, deleting elements, and displaying the contents of the linked lists.

```cpp
int main()
{
    // Examples of using Doubly Circular Linked List
    DoublyCL<int> dcobj;
    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);
    dcobj.Display();

    // ... (continue with various operations)

    // Examples of using Singly Linear Linked List
    SinglyLL<int> slobj;
    slobj.InsertFirst(51);
    slobj.InsertFirst(21);
    slobj.InsertFirst(11);
    slobj.Display();

    // ... (continue with various operations)

    return 0;
}
```

## Contribution

Feel free to contribute to this project by extending or improving the existing functionality of linked list operations. If you have ideas for additional features or optimizations, your contributions are welcome.

## Author

This project was created by Swaraj Mhatre.

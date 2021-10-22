#pragma once
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

//*******************************************
// The ListNode class creates a type used to *
// store a node of the linked list.          *
//*******************************************

template <class T>
class ListNode
{
public:
    T value;           //node value
    ListNode<T> *next; // next node

    //constructor
    ListNode(T nodeValue)
    {
        value = nodeValue;
        next = nullptr;
    }
};

//*******************************************
// LinkedList class                          *
//                                           *
//*******************************************

template <class T>
class CircularLinkedList
{
private:
    ListNode<T> *head; // list head pointer
    int count;         // to count the number of nodes
public:
    //constructor
    CircularLinkedList()
    {
        head = nullptr;
        count = 0;
    }

    //destructor
    ~CircularLinkedList()
    {
        destroyNode();
    }

    // circular linked list operations
    int Length();         //number of nodes
    void insertNode(T);   // to insert the node according to its value
    void deleteNode(T);   // to delete the node
    void displayList();   // to display all the nodes
    void searchNode(T);   // to search the certain node
    void appfrontNode(T); //  to appfront
    void destroyNode();   // to destroy the list
};

//*******************************************
// Length function                           *
// Return the number of the nodes in the list*
//*******************************************

template <class T>
int CircularLinkedList<T>::Length()
{
    return count;
}

//*******************************************
// appfrontNode function                           *
// insert the node at the head of the list       *
//*******************************************
template <class T>
void CircularLinkedList<T>::appfrontNode(T newvalue)
{
    ListNode<T> *newNode; // to point to a new node
    ListNode<T> *nodePtr; //to move through the list

    //allocate a new node and store newValue there
    newNode = new ListNode<T>(newvalue); // at here only declare the class
    nodePtr = head;                      // tracker
    newNode->next = head;                // position and beginning
    if (head != nullptr)                 // insert into an existing list
    {
        while (nodePtr->next != head) // before back to the head
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    else // it is an empty list
    {
        newNode->next = newNode; // point to itselves
    }
    head = newNode; // let the new Node become the head
    count++;
}

//*******************************************
// displayList shows the value stored in each node*
// of the linked list pointed to by head       *
//*******************************************

template <class T>
void CircularLinkedList<T>::displayList()
{
    ListNode<T> *nodePtr; // to move through the list

    if (head == nullptr || count == 0)
    {
        cout << "Circular Linked list is empty\n";
    }
    else // there is at least 1 node in the list
    {
        if (count > 0)
        {
            nodePtr = head;
            do
            {
                cout << nodePtr->value << " ";
                nodePtr = nodePtr->next;
            } while (nodePtr != head); // back to the head
        }
    }
}

//*******************************************
// deleteNode function searches for a node with searchValue as its value.*
// The node, if found, is deleted from the list and from memory.*
//*******************************************

template <class T>
void CircularLinkedList<T>::deleteNode(T searchValue)
{
    ListNode<T> *nodePtr;      // to traverse the list
    ListNode<T> *previousNode; // to point to the previous node
    bool found = false;
    nodePtr = nullptr;
    previousNode = nullptr;
    //if the list is empty
    if (!head)
    {
        cout << "List is empty\n";
    }

    //delete the first node
    if (head->value == searchValue)
    {
        // initialize nodePtr to head of list
        nodePtr = head;
        previousNode = head->next;         // previousNode in this case is secondTracker node
        while (previousNode->next != head) // to make sure that we reach the last node in the list
        {
            previousNode = previousNode->next;
        }
        head = head->next;         // let second node be the head
        previousNode->next = head; // the last node connect to the second node
        delete nodePtr;
        count--;
        if (count == 0) // no node in the list after deleting the first node
        {
            head = nullptr;
        }
    }
    else // the value is in somewhere else
    {
        // initialize nodePtr to head of list
        nodePtr = head;
        // skip all nodes whose value member is not equal to num
        while (nodePtr->value != searchValue && nodePtr->next != head)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr->value == searchValue) // nodePtr is pointing to the right node
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
            count--;
        }
        else // the value is not in the list
        {
            cout << "Cannot find the value " << searchValue << "  in the list\n";
        }
    }
}

//*******************************************
// destroylist function delete all the nodes in the list*
//                                                      *
//*******************************************

template <class T>
void CircularLinkedList<T>::destroyNode()
{
    ListNode<T> *nodePtr;  // to traverse the list
    ListNode<T> *nextNode; // to point to the next node

    //position nodePtr at the head of the list
    nodePtr = head;
    nextNode = nullptr;
    //while nodePtr is not at the end of the list
    while (nodePtr->next != head)
    {
        //save a pointer to the next node
        nextNode = nodePtr->next;
        head = nextNode;

        //delete the current node
        delete nodePtr;

        nodePtr = nextNode;
        count--;
    } // will delete until the last node
    deleteNode(nodePtr->value);
}

//*******************************************
// search function will search for the certain nodes*
//                                                      *
//*******************************************
template <class T>
void CircularLinkedList<T>::searchNode(T searchValue)
{

    ListNode<T> *nodePtr; //tracker
    nodePtr = head;
    while (nodePtr->next != head && nodePtr->value != searchValue)
    {
        nodePtr = nodePtr->next;
    }

    if (nodePtr->next != head) // the number is not at the last node but exist in somewhere else
    {
        cout << "This item " << nodePtr->value << " is exist in this list\n";
    }
    else if (nodePtr->next == head && nodePtr->value == searchValue) // the number is in the last node
    {
        cout << "This item " << nodePtr->value << " is exist in this list\n";
    }
    else // the number is not exist in the list
    {
        cout << "This item " << searchValue << " is not exist in this list\n";
    }
}

//*******************************************
// insert node function will insert the nodes according to the value*
//                                                      *
//*******************************************
template <class T>
void CircularLinkedList<T>::insertNode(T newValue)
{
    ListNode<T> *nodePtr;      // to traverse the list
    ListNode<T> *previousNode; // to point to the previous node
    ListNode<T> *NextNode;     // to point to the next node
    ListNode<T> *newNode;      // new node
    //allocate a new node and store newValue there
    newNode = new ListNode<T>(newValue); // at here only declare the class
    newNode->next = nullptr;

    //initialise the nodes
    nodePtr = nullptr;
    previousNode = nullptr;
    NextNode = nullptr;

    //if the list is empty
    if (!head)
    {
        //now head is null, so need to let head connect to newNode
        head = newNode;
        newNode->next = head; // point to itself.

        count++;
    }
    else // the list is not empty
    {
        // traverse the list and find the position to inesrt newItem and the newItem must bigger then PreviousPtr and smaller than nextNode
        nodePtr = head;
        //go to the next nodes

        while (nodePtr->next != head && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        //case 1: insertion at beginning in a nonempty list
        if (nodePtr == head)
        {
            //if only have 1 node in the list
            if (nodePtr->next == head)
            {
                if (nodePtr->value > newValue) // if the only node is bigger than the newnode
                {
                    nodePtr->next = newNode;
                    newNode->next = nodePtr;
                    cout << nodePtr->value << "a" << endl;
                    system("pause");
                    head = newNode;
                }
                else // if the only node is less than or equal to the newnode
                {
                    nodePtr->next = newNode;
                    newNode->next = nodePtr;
                    cout << nodePtr->value << "b" << endl;
                    system("pause");
                    //the head is still the same
                }
            }
            else // if have 2 or more nodes in the list
            {
                // to get the last node
                NextNode = nodePtr->next;
                while (NextNode->next != head)
                {
                    NextNode = NextNode->next;
                }
                // let the newNode become the head
                head = newNode;
                cout << nodePtr->value << endl;
                system("pause");
                //connect the last node to the newNode
                NextNode->next = newNode;
                //newNode connect to the head
                newNode->next = nodePtr;
            }
        }
        else // nodePtr is not in the head of the list
        {
            // case 2: insertion somewhere in a nonempty list
            if (nodePtr->next != head) // not at the last node
            {
                //connect the previousNode to the newNode
                previousNode->next = newNode;
                //connect newNode to the nodePtr
                newNode->next = nodePtr;
                cout << nodePtr->value << "c" << endl;
                system("pause");
            }
            else // case 3: at the end of the list
            {
                if ((nodePtr->value) > newValue) // if the last list is bigger than newNode
                {
                    previousNode->next = newNode;
                    newNode->next = nodePtr;
                    cout << nodePtr->value << "e" << endl;
                    system("pause");
                }
                else // if the last list is smaller than newNode
                {
                    nodePtr->next = newNode;
                    newNode->next = head;
                    cout << nodePtr->value << "d" << endl;
                    system("pause");
                }
            }
        }
        count++;
    }
}
#endif
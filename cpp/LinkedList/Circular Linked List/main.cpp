// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CircularLinkedList.h"
using namespace std;
void menu()
{
    system("cls");
    cout << "\t------------------\n";
    cout << "\t-----WELCOME------\n";
    cout << "\t 1. Insert a value at the beginning of list\n";
    cout << "\t 2. Delete a value\n";
    cout << "\t 3. Length of list\n";
    cout << "\t 4. Display all the values in the list\n";
    cout << "\t 5. search the value\n";
    cout << "\t 6. destroy the list\n";
    cout << "\t 7. Enter the node according to its value into the list\n";
    cout << "\t 8. Exit\n";
    cout << "\t Please enter your choice(1-7)\n";
}

int main()
{
    CircularLinkedList<int> list; // list as object type class linked list- an int value

    int value;
    int choice;
    do
    {
        menu();
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // insert a value at the beginning of list
            cout << "\t\n Insert a value : ";
            cin >> value;
            list.appfrontNode(value);
            break;
        case 2: // delete a value in the list
            cout << "\t\n Delete a value : ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 3: //display the length of the list
            cout << "\t\n Number of nodes: ";
            cout << list.Length() << endl;
            system("pause");
            break;
        case 4: // display the value in the list
            cout << "\t\n Display the list: ";
            list.displayList(); // display the content of linked list
            cout << endl;
            system("pause");
            break;
        case 5: // to search the certain node
            cout << "\t\n Value of node that you want to find: ";
            cin >> value;
            list.searchNode(value);
            system("pause");
            break;
        case 6: // to destroy the list
            list.destroyNode();
            cout << "The list had been destroyed\n";
            system("pause");
            break;
        case 7:
            cout << "\t\n Insert a value to insert it to the list according to its value: ";
            cin >> value;
            list.insertNode(value);
            system("pause");
            break;
        case 8:
            break;
        default:
            cout << "Wrong choice\n";
        }
    } while (choice != 8);
    cout << "-----------------------------\n";
    cout << "End of Program\n";
    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

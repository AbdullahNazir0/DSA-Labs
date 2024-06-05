#include <iostream>
#include "MyBinarySearchTree.h"

template <typename T>
using BST = MyBinarySearchTree<T>;

using namespace std;

int main()
{

    int value;
    BST<int> bst;
    char choice;
    while (true)
    {
        cout << "Press 1 to add node in BST.\n"
                "Press 2 to delete node in BST.\n"
                "Press 3 to print BST in InOrder.\n"
                "Press 4 to print BST in PreOrder.\n"
                "Press 5 to print BST in PostOrder.\n"
                "Press 6 to count the number of edges from root node to given node in BST.\n"
                "Press 7 to the find largest node in BST.\n"
                "Press 8 to the find smallest node in BST.\n"
                "Press 0 to exit.\n"
                "You Entered: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter the value you want to add node in BST: ";
            cin >> value;
            bst.insertNode(value);
            break;
        case '2':
            cout << "Enter the value you want to delete node from BST: ";
            cin >> value;
            bst.deleteNode(value);
            break;
        case '3':
            bst.displayInorder();
            break;
        case '4':
            bst.displayPreorder();
            break;
        case '5':
            bst.displayPostorder();
            break;
        case '6':
            cout << "Enter the node value, you want to count edges: ";
            cin >> value;
            bst.countEdges(value);
            break;
        case '7':
            cout << "largest value: " << bst.findMax() << "\n";
            break;
        case '8':
            cout << "smallest value: " << bst.findMin() << "\n";
            break;
        case '0':
            cout << "Exiting...\n";
            return (0);
        default:
            cout << "Invalid input, please try again.\n";
            break;
        }
    }
    return 0;
}
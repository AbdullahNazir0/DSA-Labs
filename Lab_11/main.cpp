#include <iostream>
#include <iomanip>
#include "MinHeap.h"
#include "MaxHeap.h"

using namespace std;

void displayMenu()
{
    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "HEAP OPERATIONS MENU" << endl;
    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ');

    cout << left << setw(45) << "  1. Add element to Min Heap" << endl;
    cout << left << setw(45) << "  2. Delete smallest element from Min Heap" << endl;
    cout << left << setw(45) << "  3. Add element to Max Heap" << endl;
    cout << left << setw(45) << "  4. Delete largest element from Max Heap" << endl;
    cout << left << setw(45) << "  5. Print elements of heap" << endl;
    cout << left << setw(45) << "  6. HeapifyUp in Min Heap" << endl;
    cout << left << setw(45) << "  7. HeapifyUp in Max Heap" << endl;
    cout << left << setw(45) << "  8. HeapifyDown in Min Heap" << endl;
    cout << left << setw(45) << "  9. HeapifyDown in Max Heap" << endl;
    cout << left << setw(45) << " 10. Heap Sort Min Heap" << endl;
    cout << left << setw(45) << " 11. Heap Sort Max Heap" << endl;
    cout << left << setw(45) << "  0. Exit" << endl;

    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ');
}

void main_panel()
{
    MinHeap minHeap;
    MaxHeap maxHeap;
    int choice, value, index;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert in Min Heap: ";
            cin >> value;
            minHeap.insert(value);
            break;
        case 2:
            minHeap.deleteMin();
            cout << "Deleted smallest element " << endl;
            break;
        case 3:
            cout << "Enter value to insert in Max Heap: ";
            cin >> value;
            maxHeap.insert(value);
            break;
        case 4:
            maxHeap.deleteMax();
            cout << "Deleted largest element " << endl;
            break;
        case 5:
            cout << "Min Heap: ";
            minHeap.display();
            cout << "Max Heap: ";
            maxHeap.display();
            break;
        case 6:
            cout << "Enter index for HeapifyUp in Min Heap: ";
            cin >> index;
            minHeap.heapifyUp(index);
            break;
        case 7:
            cout << "Enter index for HeapifyUp in Max Heap: ";
            cin >> index;
            maxHeap.heapifyUp(index);
            break;
        case 8:
            cout << "Enter index for HeapifyDown in Min Heap: ";
            cin >> index;
            minHeap.heapifyDown(index);
            break;
        case 9:
            cout << "Enter index for HeapifyDown in Max Heap: ";
            cin >> index;
            maxHeap.heapifyDown(index);
            break;
        case 10:
            minHeap.heapSort();
            cout << "Min Heap sorted in descending order." << endl;
            break;
        case 11:
            maxHeap.heapSort();
            cout << "Max Heap sorted in ascending order." << endl;
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        if (choice != 0)
        {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);
}

int main()
{
    main_panel();
    return 0;
}
#include <iostream>
#include "Classes.h"

void displayMenu()
{
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Remove element from specific position" << std::endl;
    std::cout << "2. Find first repeating element" << std::endl;
    std::cout << "3. Find first non-repeating element" << std::endl;
    std::cout << "4. Find pairs" << std::endl;
    std::cout << "5. Count frequency of each element" << std::endl;
    std::cout << "6. Left rotate" << std::endl;
    std::cout << "7. Right rotate" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    MyList myList(arr, 5, 5); // Assuming initial size is 5

    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int position;
            std::cout << "Enter position to remove: ";
            std::cin >> position;
            int result = myList.removeElementFromSpecificPositionList(position);
            if (result == -1)
                std::cout << "Invalid position!" << std::endl;
            else
                std::cout << "Element removed successfully!" << std::endl;
            break;
        }
        case 2:
        {
            int result = myList.firstRepeatingElement();
            if (result == -1)
                std::cout << "No repeating element found!" << std::endl;
            else
                std::cout << "First repeating element: " << result << std::endl;
            break;
        }
        case 3:
        {
            int result = myList.firstNonRepeatingElement();
            if (result == -1)
                std::cout << "No non-repeating element found!" << std::endl;
            else
                std::cout << "First non-repeating element: " << result << std::endl;
            break;
        }
        case 4:
        {
            int target;
            std::cout << "Enter target sum: ";
            std::cin >> target;
            Pair *pairs = myList.findPairs(target);
            // Process pairs as needed
            break;
        }
        case 5:
        {
            int *frequency = myList.countFrequencyOfEachElement();
            // Process frequency as needed
            delete[] frequency; // Don't forget to free memory
            break;
        }
        case 6:
        {
            int k;
            std::cout << "Enter number of positions to left rotate: ";
            std::cin >> k;
            myList.leftRotate(k);
            std::cout << "Array left rotated by " << k << " positions." << std::endl;
            break;
        }
        case 7:
        {
            int k;
            std::cout << "Enter number of positions to right rotate: ";
            std::cin >> k;
            myList.rightRotate(k);
            std::cout << "Array right rotated by " << k << " positions." << std::endl;
            break;
        }
        case 8:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 8);

    return 0;
}

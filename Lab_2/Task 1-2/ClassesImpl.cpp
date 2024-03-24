#include "Classes.h"

// Class List Implementation
List::List(int *arr, int maxSize, int currentSize)
{
    this->arr = arr;
    this->maxSize = maxSize;
    this->currentSize = currentSize;
}
List::~List()
{
    if (arr)
        delete arr;
}

// Class MyList Implementation
MyList::MyList(int *arr = nullptr, int maxSize = 100, int currentSize = 0) : List(arr, maxSize, currentSize)
{
}
int MyList::removeElementFromSpecificPositionList(int position = 0)
{
    if (currentSize = 0)
        return -1;
    if (position < 0 || position > currentSize)
        return -1;
    int temp = arr[position];
    for (int i = position; i < currentSize - 1; i++)
        arr[i] = arr[i + 1];
    currentSize--;
}
int MyList::firstRepeatingElement()
{
    int *temp = new int[currentSize];
    int temp_count = 0;
    for (int i = 0; i < currentSize; i++)
    {
        for (int j = 0; j < currentSize; j++)
        {
            if (temp[j] == arr[i])
                return arr[i];
            temp[temp_count++] = arr[i];
        }
    }
    return -1; // If no element is repeating.
}
int MyList::firstNonRepeatingElement()
{
    for (int i = 0; i < currentSize; i++)
    {
        bool flag = false;
        for (int j = 0; j < currentSize; j++)
        {
            if (arr[i] == arr[j] && i != j)
                flag = true;
        }
        if (flag == false)
            return arr[i];
    }
}
Pair *MyList::findPairs(int target)
{
    Pair *pairs = nullptr;
    int pairs_count = 0;
    for (int i = 0; i < currentSize; i++)
    {
        for (int j = i + 1; j < currentSize; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                if (pairs == nullptr)
                {
                    pairs = new Pair[1];
                    pairs[0].value1 = i;
                    pairs[0].value2 = j;
                }
                else
                {
                    Pair *temp = new Pair[pairs_count + 1];
                    for (int i = 0; i < pairs_count; i++)
                        temp[i] = pairs[i];
                    temp[pairs_count].value1 = i;
                    temp[pairs_count].value2 = j;
                    delete[] pairs;
                    pairs = temp;
                }
            }
        }
    }
    return pairs;
}
int *MyList::countFrequencyOfEachElement()
{
    const int MAX_ELEMENT_VALUE = 1000;         // Assuming a maximum value for elements
    int frequency[MAX_ELEMENT_VALUE + 1] = {0}; // Initialize frequency array with zeros

    // Count frequency of each element
    for (int i = 0; i < currentSize; i++)
    {
        frequency[arr[i]]++;
    }

    return frequency;
}
void MyList::leftRotate(int k)
{
    // Check if rotation is possible
    if (currentSize == 0 || k <= 0)
        return;

    k = k % currentSize; // Normalize rotation count

    // Create a temporary array to store rotated elements
    int *temp = new int[currentSize];

    // Copy elements to temporary array after rotation
    for (int i = 0; i < currentSize; i++)
    {
        int newIndex = (i + k) % currentSize;
        temp[i] = arr[newIndex];
    }

    // Copy elements from temporary array back to original array
    for (int i = 0; i < currentSize; i++)
    {
        arr[i] = temp[i];
    }

    delete[] temp; // Free memory allocated for temporary array
}
void MyList::rightRotate(int k)
{
    // Check if rotation is possible
    if (currentSize == 0 || k <= 0)
        return;

    k = k % currentSize; // Normalize rotation count

    // Create a temporary array to store rotated elements
    int *temp = new int[currentSize];

    // Copy elements to temporary array after rotation
    for (int i = 0; i < currentSize; i++)
    {
        int newIndex = (i - k + currentSize) % currentSize;
        temp[i] = arr[newIndex];
    }

    // Copy elements from temporary array back to original array
    for (int i = 0; i < currentSize; i++)
    {
        arr[i] = temp[i];
    }

    delete[] temp; // Free memory allocated for temporary array
}
MyList::~MyList()
{
    List::~List();
}
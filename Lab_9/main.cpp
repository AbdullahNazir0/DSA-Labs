#include <iostream>

using namespace std;

// function prototypes
// task 1
int recursivePower(int, int);
// task 2
void recursiveFibonacci(int);
void helperFibonacci(int, int, int);
// task 3
int recursiveBinarySearch(int *, int, int, int);
// task 4
bool recursiveCheckPalindrome(int *, int, int);

int main()
{
    char choice;

    while (true)
    {
        cout << "Press 1 to recursively calculate power of a number.\n"
                "Press 2 to recursively display Fibonacci series upto n number of times.\n"
                "Press 3 to recursively find an element using binary search.\n"
                "Press 4 to recursively check palindrome.\n"
                "Press 0 to exit.\n"
                "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '0':
            return 0;
        case '1':
        {
            int base, exp;
            cout << "Base: ";
            cin >> base;
            cout << "Exponent: ";
            cin >> exp;
            cout << "Result: " << recursivePower(base, exp) << "\n";
            break;
        }
        case '2':
        {
            int n;
            cout << "Enter the number of times, you want to print fibonacci series upto: ";
            cin >> n;
            recursiveFibonacci(n);
            break;
        }
        case '3':
        {
            int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int start = 0, end = 10, num;
            cout << "Array is ";
            for (int i = start; i < end; i++)
                cout << arr[i] << " ";
            cout << "\n";
            cout << "Enter the number you want to find: ";
            cin >> num;
            cout << "Index: " << recursiveBinarySearch(arr, start, end, num) << "\n";
            break;
        }
        case '4':
        {
            int arr[] = {2, 0, 0, 2};
            if (recursiveCheckPalindrome(arr, 0, 3))
                cout << "Palindrome.\n";
            else
                cout << "Not a Palindrome.\n";

            int arr2[] = {2, 0, 1, 2};
            if (recursiveCheckPalindrome(arr2, 0, 3))
                cout << "Palindrome.\n";
            else
                cout << "Not a Palindrome.\n";
            break;
        }
        default:
            cout << "Invalid input, try again.\n";
            break;
        }
    }
}

// function definitions
// task 1
int recursivePower(int base, int exp)
{
    if (exp == 0)
        return 1;

    return (base * recursivePower(base, exp - 1));
}
// task 2
void recursiveFibonacci(int n)
{
    if (n <= 0)
        return;

    helperFibonacci(n, 0, 0);
}
void helperFibonacci(int n, int a, int b)
{
    if (n == 0)
    {
        cout << "\n";
        return;
    }

    int c = a + b;
    cout << c << " ";
    if (a == 0 && b == 0)
        helperFibonacci(n - 1, b + 1, c);
    else
        helperFibonacci(n - 1, b, c);
}
// task 3
int recursiveBinarySearch(int *arr, int start, int end, int key)
{
    if (start >= end) // base case
        return -1;

    int mid = (start + end) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return recursiveBinarySearch(arr, mid + 1, end, key);
    else
        return recursiveBinarySearch(arr, start, mid - 1, key);
}
// task 4
bool recursiveCheckPalindrome(int *arr, int start, int end)
{
    if (start >= end)
        return true;

    if (arr[start] != arr[end])
        return false;

    return recursiveCheckPalindrome(arr, start + 1, end - 1);
}
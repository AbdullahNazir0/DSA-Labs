#include <iostream>
using namespace std;

void printFirstElementOfArray(int arr[])
{
    cout << "First element of array :" << arr[0];
}
// Time Complexity: O(1
)
void printAllElementOfArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}
// Time Complexity: O(n) or O(size)

void printAllPossibleOrderedPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "(" << arr[i] << "," << arr[j] << ")";
        }
    }
}
// TIme Complexity: O(size * size) or O(n * n)

void printAllNumbersThenAllPairSums(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout <<, arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i] + arr[j];
        }
    }
}
// Time Complexity: O(size) + O(size * size) -> O(size * size)

void phytagorean(int value)
{
    for (int i = 1; i <= value; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            for (int k = 1; k <= value; k++)
            {
                int num1 = (i * i) + (j * j);
                int num2 = (k * k);
                if (num1 == num2)
                    cout << "Pair is: (" << i << ", " << j << ", " << k << ")" << endl;
            }
        }
    }
}
// Time Complexity: O(value * value * value) or O(n * n * n)

void RangeCheck(int arr[], int sixe, int num1, int num2)
{
    int counter = 0;
    for (int i = 0; i < sixe; i++)
    {
        if (arr[i] >= num1 && arr[i] <= num2)
        {
            counter++;
            cout << arr[i] << "is in the range " << endl;
        }
    }
    cout << "Total Numbers in range are: " << counter << endl;
}
// Time Complexity: O(sixe) or O(n)

int main()
{
    int Max = 0;                //  -> O(1)
    for (int I = 0; I < N; I++) //  -> O(N)
    {
        if (S[I] > Max) //  -> O(1)
            Max = S[I]; //  -> O(1)
    }
    cout << Max //  -> O(1)
}
// Time complexity: O(N)

// Algorithm 2

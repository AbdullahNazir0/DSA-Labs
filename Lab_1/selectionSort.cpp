#include <iostream>

using namespace std;

int main()
{
	int arr[5] = {2, 4, 7, 5, 0 };

	int size = 5, min;

	for(int i = 0; i < size - 1; i++)
	{
		min = i;
		for(int j = i + 1; j < size; j++)
		{
			if(arr[min] > arr[j])
				min = j;
		}
		if(min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}

	cout << "Sorted Array: ";
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
 
	return 0;
}

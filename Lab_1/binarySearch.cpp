#include <asm-generic/errno.h>
#include <iostream>

using namespace std;

int main()
{

	int arr[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

	int size = 10;
	int start = 0, end = size - 1, mid, toFind = 9;

	while(start <= end)
	{

		mid = ( start + end ) / 2;

		if( toFind == arr[mid] )
		{
			cout << "Found '" << toFind 
			     << "' at index: " << mid << endl;
			exit(0);
		}
		else if ( toFind < arr[mid] )
			end = mid - 1;
		else
			start = mid + 1;
	}

	cout << "Cannot find '" << toFind << "' in the array.\n";
	
	return 0;
}

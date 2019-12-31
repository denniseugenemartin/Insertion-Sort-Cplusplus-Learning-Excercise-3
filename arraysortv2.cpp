#include <iostream>
#include <string>

using namespace std;


void insertionSort(double arrayToSort[], int arrayLength)
{
	bool arrayUnsorted = 1;
	{
		//while the extreme values are not located at the front and back of the array
		//arrayUnsorted will be true and it will move the values to the ends. When the highest
		//and lowest values are at the front and back it will exit the loop and continue with next for loop.

		while (arrayUnsorted)
			if (arrayToSort[0] > arrayToSort[1])
				{
					swap(arrayToSort[0], arrayToSort[1]);
					insertionSort(arrayToSort, arrayLength);
				}
			else if (arrayToSort[arrayLength - 1] < arrayToSort[arrayLength - 2])
				{
					swap(arrayToSort[arrayLength - 1], arrayToSort[arrayLength - 2]);
					insertionSort(arrayToSort, arrayLength);
				}
			else
				break;

		//for loop will move through the array calling swap function to move values forward one spot in the
		//array until the middle of the array is sorted.

		for (int i = 0; i < arrayLength - 1; ++i)
			{
				if (arrayToSort[i] > arrayToSort[i + 1])
				{
					swap(arrayToSort[i], arrayToSort[i + 1]);
				}
				else
					continue;
			}
	}
}


//function is called by the insertionSort function and swaps the value of two adjacent values.

void swap(double &number1, double &number2)
{
	double a = number1;
	number1 = number2;
	number2 = a;
}

//function is callled by main to print the values of the array at the end.

void printArray(double arrayToSort[], double arrayLength)
{
	for (int i = 0; i < arrayLength; ++i)
	{
		cout << arrayToSort[i] << "\t";
	}
	cout << "\n";
}


//function takes user input to search array for value.  First it starts at the midpoint of the array
//if this position is where the number is located it reports that. If is is greater 
//than the number position it goes to the midpoint of previous midpoint. It continues this way until the position
//is less than the numbers position. If it goes all the way through the array it returns not found.
int find_number(double arrayToSort[], int arrayLength)

{
	bool notFound = 1;
	double numberToSearch;
	int position = arrayLength/2;
	cout << "Enter a value to search for:\n";
	cin >> numberToSearch;

	while (notFound)
	{
		if (arrayToSort[position] == numberToSearch)
		{
			return position;
		}
		else if (arrayToSort[position] > numberToSearch)
		{
			if (position / 2 <= 0)
			{
				position = 0;
				break;
			}
			else
				position = position / 2;
			continue;
		}
		else
			break;
		
	}
	
	while (notFound)
		{
			if (arrayToSort[position] == numberToSearch)
			{
				return position;
			}
			else if (position == arrayLength-1)
			{
				cout << "This value is not present in the array.\n";
				return -1;
			}

			else
				++position;
		}

	

}

int main()
{
	double numbers[] = { 16,4,-3,12.4,77,2.1 };
	int arrayLength = 6;
	int position;
	insertionSort(numbers, 6);
	printArray(numbers, arrayLength);
	position = find_number(numbers, arrayLength);
	if (position == -1)
		return -1;
	cout << "Your number is located at position " << position;

}
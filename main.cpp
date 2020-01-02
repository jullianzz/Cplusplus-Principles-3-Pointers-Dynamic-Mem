//updated
#include <iostream>
//#include <array>
#include <cmath>
using namespace std;

int * ReverseMultiply (int *list, int size);
int * ReverseAdd (int *list, int size);


int main ()
{
	int size;

	cout << "Enter the number of entries: " ;
	cin >> size ;
	int originalArray[size]; 
	for (int i = 0; i < size; i++)
	{
		cout << "Entry " << i << " is: " ;
		cin >> originalArray[i]; 
	}


	cout << endl << "Original array is: { " ;
	for (int i = 0; i <= size-1; i++)
		cout << originalArray[i] << " ";
	cout << "} and the address of the zero element is: " << originalArray << endl << endl;




	int * arrayPtr1;

	arrayPtr1 = ReverseMultiply(originalArray, size);

	cout << "ReverseMultiply array is: { " ;
	for (int i = 0; i <= 2*size; i++)
		cout << *(arrayPtr1+i) << " " ;
	cout << "} and the address of zero element is: " << arrayPtr1 << endl << endl;


	

	int * arrayPtr2;

	arrayPtr2 = ReverseAdd(originalArray, size);

	cout << "ReverseAdd array is: { " ;
	for (int i = 0; i <= 2*size-2; i++)
		cout << *(arrayPtr2+i) << " " ;
	cout << "} and the address of zero element is: " << arrayPtr2 << endl << endl;


	return 0;
}

int * ReverseMultiply (int *list, int size)
{
	int * arrayPtr = new int[2*size];

	int product = 1; 

	for (int i = 0; i <= size-1; i++)
	{
		*(arrayPtr+i) = *(list+i);  
		*(arrayPtr+2*size-i-1) = *(list+i);
		product *= *(arrayPtr+i); 
	}

	*(arrayPtr + 2*size) = pow(product,2);
	return arrayPtr; 

}


int * ReverseAdd (int *list, int size)
{
	int * arrayPtr = new int[2*size-1];

	for (int i = 0; i <= size-1; i++)
		*(arrayPtr+i) = *(list+i);  

	for (int j = size; j <= 2*size-2; j++)
	{
		*(arrayPtr+j) = *(list+(2*size-1-j)) + *(list+(2*size-2-j));
	}

	return arrayPtr;

}


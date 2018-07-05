// Heap Program
// Demonstrates dynamic memory allocation

#include <iostream>

using namespace std;

// function prototypes
int* intOnHeap(); // return an int on the heap
void leak1(); // creates a memory leak
void leak2(); // creates another memory leak

int main(){
	
	int* pHeap = new int; // declare an int pointer 'pHeap' pointing to the address of a blank integer
	*pHeap = 10; // initialise as the value 10
	
	cout << "*pHeap: " << *pHeap << endl; // output the result
	
	int* pHeap2 = intOnHeap(); // point to the location of the specified pointer returned by intOnHeap()
	cout << "*pHeap2: " << *pHeap2 << endl;
	
	cout << "\nFreeing memory pointed to by pHeap.\n\n";
	delete pHeap;
	
	cout << "Freeing memory pointed to by pHeap2.\n\n";
	delete pHeap2;
	
	// get rid of dangling pointers
	pHeap = 0;
	pHeap2 = 0;
	
	return 0;
}

int* intOnHeap(){
	
	int* pTemp = new int(20); // Assign the value '20' to the memory address allocated at the new address
	return pTemp; // return a pointer to the new address containing the value '20'. No copies of the value are made (very efficient)
	
}

void leak1(){
	int* drip1 = new int(30); // no corresponding delete statement, memory will leak
}

void leak2(){
	int* drip2 = new int(50); // memory address assigned the value 50. Pointer 'drip2' points to this location in memory
	drip2 = new int(100); // pointer points to a new address in memory and assigns it 100. The memory address with thew value '50' leaks as a result
	delete drip2; // release the memory, creating a dangling pointer (drip2) assign drip2 = 0 to fix. No worries about it in terminating function
}





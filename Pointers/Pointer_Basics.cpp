/**
 *****************************************************************************************
 * @file
 * @details See header file for module overview.
 *
 *****************************************************************************************
 */
#include <iostream>

/*
 *****************************************************************************************
 *		Prototypes
 *****************************************************************************************
 */


/*
 *****************************************************************************************
 *		Constants
 *****************************************************************************************
 */


/*
 *****************************************************************************************
 *		Globals
 *****************************************************************************************
 */

/*
 *****************************************************************************************
 *		Functions
 *****************************************************************************************
 */
int Pointers_Basics( void )
{
	std::cout << "/************* Pointers Basics ***********/" << std::endl;
	int x = 5;
	int* p = &x;

	/** Simple pointer access vs value access **/
	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Value of p: " << p << std::endl;
	std::cout << "Address of p: " << &p << std::endl;
	std::cout << "Value of *p: " << *p << std::endl;

	//delete p; 
	//p = nullptr; 
	// above two lines of code creates access violation issue. Code compiles but crashes at runtime

	int *pointer = new int; // Allocates memory for an integer
	*pointer = 5; // Assigns 5 to the memory location
	std::cout << "Value of pointer: " << pointer << std::endl;
	std::cout << "Value of *pointer: " << *pointer << std::endl;
	pointer = nullptr; // Set pointer to null to avoid dangling pointer
	delete pointer; // mem is not deleted

	// delete []pointer; is used for pointer to an array	
	/** Accessing Array values using pointers**/
	int array[5] = {1, 2, 3, 4, 5};
	p = array; // this is equivalent to p = &array[0]; array name is a pointer to the first element of the array
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Value of arr[" << i << "]: " << *p << std::endl;
		//p[i] is equivalent to *(p + i)
		p++;
	}

	/** Allocation of different memory at run time to a single pointer**/
	int *ptr_var = new int[5];
	delete []ptr_var; // Deletes the memory location that p is pointing to
	ptr_var= new int[15];
	// initial 5 mem is lost and new 15 mem is created. if delete is not done then memory leak occurs

	/** Arthimetic operations on pointers **/
	int arr[5] = {1, 2, 3, 4, 5};
	int *ptr = arr;
	std::cout << "Value of ptr: " << ptr << std::endl;
	std::cout << "Value of ptr+1: " << ptr+1 << std::endl;
	int *q = ptr+2;
	std::cout << "Value of q: " << q << std::endl;
	std::cout << "Value of q-p: " << q-ptr << std::endl;
	std::cout << "Value of q++: " << q++ << std::endl;
	std::cout << "Value of p-q " << ptr-q << std::endl; // expected -ve value states that ptr is nearer than q

	/** Problems using pointers **/
	// Un initialized pointers
	int *problem_ptr1 = nullptr; // Initialize the pointer to nullptr
	int *problem_ptr2; // This is an uninitialized pointer
	//*problem_ptr1 = 5; // This will cause a segmentation fault
	std::cout << "Value of problem_ptr1: " << problem_ptr1 << std::endl;
	//std::cout << "Value of problem_ptr1: " << *problem_ptr1 << std::endl; // this will cause segemntation fault
	//std::cout << "Value of problem_ptr1: " << problem_ptr2 << std::endl; // this will cause segemntation fault

	// Heap overflow with pointers
	int* heapArray = new int[5]; // Allocate memory for an array of 5 integers
	// Write more data into the allocated memory than it can hold
	for (int i = 0; i < 10; i++) {
		heapArray[i] = i; // Heap overflow occurs here
	}
	// Clean up the allocated memory
	delete[] heapArray;

	// Dangling pointers
	int* danglingPtr = new int; // Allocate memory for an integer
	*danglingPtr = 5; // Assign 5 to the memory location
	delete danglingPtr; // Deallocate the memory
	// Access the memory location after it has been deallocated
	//std::cout << *danglingPtr << std::endl; // This will cause a segmentation fault
	// danglingPtr = nullptr; // Set pointer to null to avoid dangling pointer

	// Memory leak
	int* memoryLeak = new int; // Allocate memory for an integer
	*memoryLeak = 5; // Assign 5 to the memory location
	// The allocated memory is never deallocated
	//delete memoryLeak; // mem is not deleted
	//memoryLeak = nullptr; // Set pointer to null to avoid dangling pointer

	// Access violation
	//int* accessViolation = new int; // Allocate memory for an integer
	//*accessViolation = 5; // Assign 5 to the memory location
	//delete accessViolation; // Deallocate the memory
	//accessViolation = nullptr; // Set pointer to null to avoid dangling pointer
	// Access the memory location after it has been deallocated
	//std::cout << *accessViolation << std::endl; // This will cause a segmentation fault

	// Memory corruption
	int* memoryCorruption = new int; // Allocate memory for an integer
	*memoryCorruption = 5; // Assign 5 to the memory location
	// Overwrite the allocated memory
	*memoryCorruption = 10; // Memory corruption occurs here
	delete memoryCorruption; // Deallocate the memory
	memoryCorruption = nullptr; // Set pointer to null to avoid dangling pointer

	/** references **/
	int y = 5;
	int a = 10;
	int &ref = y; // ref is a reference to y
	std::cout << "Value of y: " << y << std::endl;
	std::cout << "Value of ref: " << ref << std::endl;
	std::cout << "Address of y: " << &y << std::endl;
	std::cout << "Address of ref: " << &ref << std::endl;
	ref = 10; // This will change the value of y
	std::cout << "Value of y: " << y << std::endl;
	//&ref = a; // This will cause a compilation error

	/** reference to a pointer **/
	int z = 5;
	int *ptr1 = &z;
	int* &ref1 = ptr1; // ref1 is a reference to a pointer
	std::cout << "Value of z: " << z << std::endl;
	std::cout << "Value of ptr1: " << ptr1 << std::endl;
	std::cout << "Value of ref1: " << ref1 << std::endl;
	std::cout << "Value of *ref1: " << *ref1 << std::endl;
	ref1 = &a; // This will change the value of ptr1
	std::cout << "Value of ptr1: " << ptr1 << std::endl;
	std::cout << "Value of *ptr1: " << *ptr1 << std::endl;
	//&ref1 = ptr1; // This will cause a compilation error

	/** pointer to a reference **/ //not possible
	//int b = 5;
	//int &ref2 = b;
	//int* ptr2 = &b;
	//int &*ref3 = ptr2; // ref3 is a pointer to a reference which is not allowed
	//int & ref3 = ptr2; // this is not possible either



	std::cout << "/*************  end pointers ***********/" << std::endl;
	return ( 0 );
}
// *****************    More  References ****************
// https://www.learncpp.com/cpp-tutorial/6-8a-pointers-and-references/
// https://www.codingninjas.com/studio/library/pointers-interview-questions
// https://www.geeksforgeeks.org/c-plus-plus-gq/pointers-gq/

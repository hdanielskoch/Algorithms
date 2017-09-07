/*
File: heapSort.cpp

Authors Henry and Jiun
Date: 10/7/16

*/

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const int N = 1000000;

//Get left child of node j
int leftChild(int j){
	return 2*j+1;
}

//Get right child of node j
int rightChild(int j){
	return 2*j+2;
}

/* Heapify array such that it satisfies the heap property*/
//Note that n is the size of the heap, not of the array
void heapify(vector<double> &heap, int j, int n){

	int temp = 0;

	//check if node has children 
	//(if it does not have children, it will have a child node > n)
	if(leftChild(j) >= n){

		return;
	}

	//node only has one child
	//if it has one child, its child must be last node 
	//which forces it's child to be the n-1 node
	if(rightChild(j) == n){

		//parent is bigger
		if(heap[j] > heap[leftChild(j)]) {

			//Swap parent and child
			temp = heap[j];
			heap[j] = heap[leftChild(j)];
			heap[leftChild(j)] = temp;
		}
		return;
	}

	//iterate until j=leaf or j is smaller than both children
	while ((j <= (n/2)) && ((heap[j] > heap[leftChild(j)]) || (heap[j] > heap[rightChild(j)]))){
		//cout << "in here" << endl;

		//left child is smaller
		if (heap[leftChild(j)] < heap[rightChild(j)]) {

			//swap
			temp = heap[j];
			heap[j] = heap[leftChild(j)];
			heap[leftChild(j)] = temp;

			//make the left child the new node
			j = leftChild(j);

		//right child is smaller 
		} else {
			//swap
			temp = heap[j];
			heap[j] = heap[rightChild(j)];
			heap[rightChild(j)] = temp;

			//make the right child the new node
			j = rightChild(j);
		}

		//Check if node has no children
		if((leftChild(j)) >= n){

			break;
		}

		//Node has 1 child
		if((rightChild(j)) == n){

		 	//parent is bigger
			if(heap[j] > heap[leftChild(j)]){

				//Swap parent and child
				temp = heap[j];
				heap[j] = heap[leftChild(j)];
				heap[leftChild(j)] = temp;
			}
			//Done heapifying
			break;
		}	
	}
	return;
}

/*heap sort builds a heap and reapedly calls delete min to get the next element in order */
void heapSort(vector<double> &a, int n)
{	
	//build heap
	//declare and allocate the heap array
	vector<double> heap;

	//copy array a to heap (not heapified yet)
	for(int i = 0; i < n; i++) {
		heap.push_back(a[i]);
	}


	//Iterate through first half of array (which has elements containing children) to build heapified MIN heap
	for(int i = n/2-1; i >= 0; i--) {
		heapify(heap,i,n);
	}


	//iterate through b
	for(int i=0; i < n; i++){

		//Put root of heap (minimum of remaining numbers) into a
		a[i] = heap[0];

		//Put last leaf of heap into root of heap
		heap[0] = heap[n-i-1];

		//heapify array of size n-i-1 (subtract 1 since we got rid of root)
		heapify(heap,0,n-i-1);
	}
}

/* Checks if array a is sorted. Returns 1 is a is sorted in non-decreasing order
and 0 otherwise. We assume the array is allocated and populated prior.*/
int isSorted(vector<double> &a, int n)
{	

	for(int i = 0; i < (n-1); i++){

		//Not sorted
		if (a[i] > a[i+1]) {

			return 0;
		}
	}
	return 1;
}


//Generates an array of length N that is populated with random integers and is sorted with heapSort
//Confirms that array is sorted if NDEBUG flag is NOT used
int main() {	

	//Array size
	int n = N;

	//Array has less than 2 elements and is already sorted
	if (n < 2){

		if (n==1){
			cout << "List is sorted, but only has one element in it" << endl;
		} else {
			cout << "List has no elements in it. Change list size. " << endl;
		}
		return 0;
	}

	//declare and allocate the array
	vector<double> a;

	//Populate the array with random data
	for(int i = 0; i < n; i++){

		//Generate random number from 0 to 5000000
		double randNum = rand() * 0.000001;
		int randInt = (int) randNum;
		a.push_back(randInt);
	}

	//Call heapSort
	heapSort(a,n);

	//Test if array is sorted
	#ifndef NDEBUG
	
	if (isSorted(a,n)){

		cout << "Array is sorted!" << endl;


	}else {

		cout << "Ooops! Array is NOT sorted" << endl;

	}
	//}
	#endif
}



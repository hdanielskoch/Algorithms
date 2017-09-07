/*
File: quicksort.cpp
 
Authors Henry and Jiun
Date: 10/7/16
 
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

const int N = 100000000;
//Change N to quicksort different scale of numbers.



/*
Partition the given array with range from index l to index n. Return the integer of the index of the pivot.
*/
int partition(double* array, int l, int n){
    
    int i = l-1;
    //i becomes the index that keeps track of numbers smaller than the pivot.
    
    double pivot = array[n];
    //Set the pivot as the last element in the array
    
    for(int j = l;j < n; j++){
    //go through the array using j as the iterator
        
        if(array[j] < pivot){
            //Everytime we run into a number that is smaller than the pivot we add 1 to i and swap the doubles.
            i++;
            double temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            //swap
        }
        else{
            
        }
    }
    array[n] = array[i+1];
    array[i+1] = pivot;
    
    //At last swap pivot with the double at index i+1. That is where pivot belongs.
    
    return i+1;
    
}

/*
Quicksort function. It takes in array of doubles ranging from l to n. It returns when the index l and n becomes equal.
*/
void quicksort(double* array, int l, int n){
    
    
    //This is the base case of the recursive function. Base case is operated when there is no more doubles in the array t sort.
    if(l >= n ){
        return;
    }
    
    
    
    int q = partition(array, l, n);
    //calls partition function.
    
    quicksort(array, l, q-1);
    //This runs resurvie quicksort function on the lower half.
    quicksort(array, q+1, n);
    //This runs recursive quicksort function on the upper half.
    
}

//This function checks whether the array is sorted or not. Returns 1 if sorted, returns 0 if not.
int issorted(double * array, int n){
    //For loop goes through the array.
    for(int i = 0; i< n-1; i++){
        if(array[i] > array[i+1]){
            return 0;
        }
    }
    return 1;
}


//This is the main function.
//It generates an array of length N that is populated with random doubles and is quicksorted.
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
    
    
    //Randomize seed for the random number generator.
    unsigned long seed = time(0);
    srand(int(seed));
    
    //Declare and allocate the array.
    double* array1 = new double[n];
    
    
    //Populate the array with random data
    for(int i = 0; i < n; i++){
        
        //Generate random number from 0 to 5000000
        array1[i] = rand() % 5000000;
    }
    
    //quicksort
    quicksort(array1, 0, n-1);

#ifdef NDEBUG
    
    if(issorted(array1, n)){
        printf("Array is sorted!\n");
    }
    else{
        printf("Array is NOT sorted!\n");
    }
    
    free(array1);
    return 0;
#endif
    
}


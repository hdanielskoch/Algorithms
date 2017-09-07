//
//  main.cpp
//  selection
//
//  Created by Henry Daniels-Koch on 10/20/16.
//  Copyright © 2016 Henry Daniels-Koch. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

const int N = 10;

//Partition array around x
int partition(int* array, int l, int n){

    //Randomize seed for the random number generator.
    //Tried to implement randomized quicksort but it did not work.
    unsigned long seed = time(0);
    srand(int(seed));

    
    int i = l-1;
    int pivot = array[r];
    for(int j = l;j < n; j++){
        if(array[j] < pivot){
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        else{
            
        }
    }
    array[n] = array[i+1];
    array[i+1] = pivot;
    return i+1;

}

//p is left index, r is right index, i is the middle median index
//returns index of median of array
int select(int *array, int p, int r, int i){

        //Base case, array size is 1
    if(p == r ){
        return array[p];
    }
 
    //Partition array with r as pivot
    int q = partition(array, p, r);

    //int k = q-p+1; //k is rank of pivot

    //Found element
    if(i==q){
        return array[q];
    }

    //Recurse on left side of pivot
    if(i < q){

        return select(array, p, q-1, i);

    //Recurse on right side of pivot
    } else{

        return select(array, q+1, r, i);
    }

}

//Generate array of random numbers and find ith smallest element in linear time
int main(){

    //Randomize seed for the random number generator.
    unsigned long seed = time(0);
    srand(int(seed));

    //Size of array
    int n = 10;
    
    //Declare and allocate the array.
    int* array = new int[N];

    //Input to find ith smallest number in array
    int i = 5;


    
    //Populate the array with random data
    for(int i = 0; i < n; i++){
        
        //Generate random number from 0 to 5000000
        array[i] = rand() % 20;
        cout << array[i] << endl;
    }

    cout << "finding " << i << "th/rd smallest element" << endl << endl;


    //Call on 
    int x = select(array, 0, n-1, i-1);
    cout << i << "th smallest  is : " << x << endl;
}
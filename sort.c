#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//quick sort algorithm?
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    //set pivot to last element
    int pivot = arr[high];
    //set i to first element
    int i = (low - 1);

    //loop through array to check for smaller elements
    for (int j = low; j <= high- 1; j++) {
        //if element is smaller than pivot, swap with element at i
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    //swap pivot to new high position
    swap(&arr[i + 1], &arr[high]);
    //return new high position
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    //if low is less than high
    if (low < high) {
        //partition initial array into sub lists
        int pi = partition(arr, low, high);
        //sort sub lists
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//selection sort algorithm
void selection(int a[], int n){
    //loop through array
    for(int i = 0; i<n-1; i++){
        //initialize min to current index
        int min = i;
        
        //loop through elements greater than current index
        for(int j=i+1; j<n; j++){

            //set min to current index if current index is smaller than min
            if (a[j]<a[min]){
                min = j;
            }
        }
        //swap current index with min index if they are not equal
        if(a[min]!= a[i]){
            //swap elements
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

//insertion sort algorithm
void insertion(int a[], int n){

    //loop through array
    for (int i = 0; i<n; i++){

        //store current array element from unsorted sublist in temp
        int temp = a[i];

        //initialize j to index element before the current element, i
        int j = i-1;

        //loop through unsorted list to compare with temp and swap positions if true
        while(j>=0 && a[j]> temp){
            //swap elements if the one before(in sorted) is greater than the current one in temp
            a[j+1] = a[j];
            //decrement j to check the next element in the unsorted list
            j--;
        }

        //assign current element in temp to the rightmost position of the sorted list
        a[j+1] = temp;
    }
}

//bubble sort algorithm
void bubble(int a[],int n){

    //loop through array
    for(int i=0;i<n; i++){
        //initialize flag variable to keep track of when the list is already sorted(makes no sense to me)
        int flag = 0;

        //loop through all values except the last one
        for (int j =0;j<n-1-i;j++){

            //check if the current value is greater than the next value in the array
            if (a[j]>a[j+1]){

                //store that current element in a variable temp
                int temp = a[j];

                //swap positions for the two variables
                a[j]=a[j+1];
                a[j+1] = temp;

                //set flag to 1 to avoid breaking
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
}

//print the array
void printArray(int arr[], int size){
    int i;
    for(i=0;i<size; i++)
        printf("%d, ", arr[i]);
}
int main(){
    int a[]={16,14,5,6,8};

    //get length of array
    int length = (sizeof(a)/sizeof(a[0]));

    //you can switch in between bubble, insertion and selection here
    selection(a,length);

    //uncomment below to run quick sort
    //quickSort(a,0,length-1);

    //print out sorted array
    printf("Array : \n");
    printArray(a, length);
    return 0;
}

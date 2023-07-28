#include<bits/stdc++.h>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    bool swapbool;
    for (int i = 0; i < n - 1; i++) {
        swapbool = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j],arr[j+1]);
                swapbool = true;
            }
        }

        if(swapbool == false) 
            break;
    }
    
}

// Insertion sort
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    
}

// Selection sort
void selectionSort(int arr[], int n) {
    int min_index;
    for (int i = 0; i < n-1; i++) {
        min_index = i;
        for (int j = i + 1; i < n; i++) {
            if(arr[j] < arr[min_index])
                min_index = j;
        }

        if(min_index != i)
            swap(arr[min_index],arr[i]);
        
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    // bubbleSort(arr,n);
    insertionSort(arr,n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i];
    }
    
    
    return 0;
}
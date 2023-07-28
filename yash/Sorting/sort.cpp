#include<bits/stdc++.h>
using namespace std;

//Bubble Sort
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


int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    return 0;
}
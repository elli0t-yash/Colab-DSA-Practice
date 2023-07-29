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

// Quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return(i+1);
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int partition_index = partition(arr, low, high);
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, high, partition_index + 1);
    }
}

// Merge Sort (usimg stl vector for this for revision of stl)
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;        
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSec(vector<int>& arr, int low, int high) {
    if(low == high) return;
    int mid = (low + high) / 2;
    mergeSec(arr, low, mid);
    mergeSec(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr, int n) {
    mergeSec(arr, 0, n-1);
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);  
    }
}

void heapSort(vector<int>& arr, int n) {
    for(int i = n/2  -1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> arr1;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>arr1[i];
    }
    // bubbleSort(arr,n);
    // insertionSort(arr,n);
    // quickSort(arr,0,n-1);
    heapSort(arr1, n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i];
    }
    return 0;
}
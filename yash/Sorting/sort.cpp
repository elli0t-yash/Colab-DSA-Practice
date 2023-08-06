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

// Comb Sort (better version of bubble sort[in bubble sort we compare adjacent elements] but in comb sort we make use of dynamic gap and compare elements within the gap and swap)
int getGap(int gap) {
    gap = (gap*10)/13;
    if(gap < 1)
        return 1;
    return gap;
}

void combSort(vector<int>& arr, int n) {
    int gap = n;
    bool swapped = true;
    while(gap != 1 || swapped == true) {
        gap = getGap(gap);
        swapped = false;
        for(int i = 0; i < n-gap; i++) {
            if(arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}

// Radix Sort (Unit based sorting algo)
int getMax(vector<int> arr, int n) {
    int mx = arr[0];
    for (int i = 0; i < n; i++) {
        if(arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(vector<int> arr, int n, int exp) {
    vector<int> result;
    int i, count[10] = { 0 };
    for(i = 0; i< n; i++)
        count[(arr[i]/exp)%10]++;
    for(i = 1; i<10;i++)
        count[i] += count[i-1];
    for(i = n- 1; i>=0; i--) {
        result[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        arr[i] = result[i];
}

void radixSort(vector<int>& arr, int n) {
    int m = getMax(arr, n);
    for(int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n ,exp);
}

// Sleep Sort - OS use this sort for multithreading 
void sleepSort(vector<int>& arr, int n) {
    for (int i = 0; i < n   ; i++) {
        this_thread::sleep_for(chrono::milliseconds(arr[i]));
        cout<<arr[i]<<" ";
    }
    
}

// Binary Insertion sort - Binary Search + Insertion Sort
int binarySearch(vector<int>& arr, int item, int low, int high) {
    if(high <= low)
        return (item > arr[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if(item == arr[mid])
        return mid + 1;
    if(item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

void insertionSortBS(vector<int>& arr, int n) {
    int loc, selected;
    int j, k;
    for(int i = 1; i < n; i++) {
        j = i - 1;
        selected = arr[i];
        loc = binarySearch(arr, selected, 0, j);
        while(j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = selected;
    }
}

// Tim Sort - the default sorting technique of python (uses Binary Insertion Sort + Merge Sort)


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
    // heapSort(arr1, n);
    // combSort(arr1, n);
    // radixSort(arr1, n);
    // for (int i = 0; i < n; i++) {
    //     cout<<arr[i];
    // }
    sleepSort(arr1, n);
    return 0;
}
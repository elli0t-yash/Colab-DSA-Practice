#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// vector<vector<int>> pairSum(vector<int> &arr, int s){
//     vector<vector<int>> answer;
//     unordered_map<int, int> pair_map;
//     for(int i = 0; i < arr.size(); i++) {
//         if(pair_map.find(s - arr[i]) != pair_map.end()) {
//             vector<int> temp = {arr[pair_map[s - arr[i]]], arr[i]};
//             answer.push_back(temp);
//         }
//         pair_map[arr[i]] = i;
//     }
//     return answer;
// }

// Pair-Sum (array is given and K is given find all pairs whose sum is equal to K) 
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> answer;
    unordered_set<int> seen;
    for (int i = 0; i < arr.size(); i++) {
        if(seen.find(s - arr[i]) != seen.end()) {
            vector<int> temp = {s - arr[i], arr[i]};
            answer.push_back(temp);
        }
        seen.insert(arr[i]);
    }
    return answer;
}

// Rotate array
vector<int> rotateArray(vector<int>arr, int k) {
    int p = 1;
    int n = arr.size();
    while (p <= k) {
        int last = arr[0];
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = last;
        p++;
    }
    return arr;
}

// Next Permutation
vector<int> nextPermutation(vector<int> &permutation, int n) {
    int index = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(permutation[i] < permutation[i + 1]) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        reverse(permutation.begin(),permutation.end());
    }
    for(int i = n - 1; i > index; i--) {
        if(permutation[i] > permutation[index]) {
            swap(permutation[i],permutation[index]);
        }
        break;
    }
    reverse(permutation.begin() + index + 1, permutation.end());
    return permutation;
}

// Count ways reach nth stair using less space
int countWaysLessSpace(int n) {
    int prev = 1;
    int prev2 = 1;
    for(int i = 2; i <= n; i++) {
        int curr = (prev + prev2) % MOD;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// Delete Middle Element from the stack
void deleteMiddle_util(stack<int>&inputStack, int N, int current) {
   if(current == N/2) {
      inputStack.pop();
      return;
   }
   int x = inputStack.top();
   inputStack.pop();
   current += 1;
   deleteMiddle_util(inputStack, N, current);
   inputStack.push(x);
}
void deleteMiddle(stack<int>&inputStack, int N){
	deleteMiddle_util(inputStack, N, 0);
}

void bubbleSort(vector<int>& arr, int n)
{   
    bool swapbubble;
    for(int i = 0; i < n - 1; i++) {
        swapbubble = false;
        for(int j = 0; j < n - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            swapbubble = true;
          }
        }

        if(swapbubble == false)
            break;
    }
}

// Longest Common Substring
int lcs(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m+1,0));
    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans,dp[i][j]);
            }
        }
    }
    return ans;
}

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

int main() {
    int n,s;
    cin>>n>>s;
    vector<int> arr;
    vector<vector<int>> temp;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    temp = pairSum(arr, s);
    for(const auto &p :temp) {
        cout<<p[0]<<","<<p[1]<<endl;
    }
    return 0;
}
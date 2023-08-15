#include<bits/stdc++.h>
using namespace std;

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
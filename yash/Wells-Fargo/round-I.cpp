#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> answer;
    unordered_map<int, int> pair_map;
    for(int i = 0; i < arr.size(); i++) {
        if(pair_map.find(s - arr[i]) != pair_map.end()) {
            vector<int> temp = {arr[pair_map[s - arr[i]]], arr[i]};
            answer.push_back(temp);
        }
        pair_map[arr[i]] = i;
    }
    return answer;
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
    
    return 0;
}
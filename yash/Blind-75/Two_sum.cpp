#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            int sum = nums[i] + nums[j];
            if(target == sum) {
                answer.push_back(i); answer.push_back(j);
                break;
            }
        }   
    }
    return answer;
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    vector<int> result = twoSum(nums, target);
    for(auto i : result) {
        cout<<result[i];
    }
}
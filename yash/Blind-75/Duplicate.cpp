#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int ,int> mp;
    for(int num : nums) {
        if(mp.find(num) != mp.end()) {
            return true;
        }
        mp[num] = 1;
    }
    return false;
}

int main() {
    
    return 0;
}
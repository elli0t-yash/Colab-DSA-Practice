#include<bits/stdc++.h>
using namespace std;

// 2-D trapping rainwater problem


// 1-D trapping rainwater problem 
int getMax(vector<int>& block, int n) {
    int left = 0;
    int right = n - 1;

    int leftMax = block[left];
    int rightMax = block[right];

    int rainwater = 0;
    while(left <= right) {
        if(leftMax <= rightMax) {
            cout<<"left :"<<left<<endl;
            leftMax = max(leftMax, block[left]);
            rainwater += max(0, leftMax - block[left]);
            cout<<rainwater<<endl;
            left++;
        } else {
            cout<<"right: "<<right<<endl;
            rightMax = max(rightMax, block[right]);
            rainwater += max(0, rightMax - block[right]);
            cout<<rainwater<<endl;
            right--;
        }
    }

    return rainwater;
}




int main() {
    // int n;
    // cin>>n;
    vector<int> block = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int re = getMax(block, block.size());
    cout<<re;
    // for (int i = 0; i < n; i++) {
    //     cin>>block[i];
    // }
    return 0;
}
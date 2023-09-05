#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();        
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for(int i = n - 1; i >=0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }       

    return dp[0][0];
}


int longestCommonSubstring(string text1, string text2) {
    int n = text1.size();        
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int ans = 0;

    for(int i = n - 1; i >=0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
                ans = max(ans,dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }       

    return ans;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    substringCheck(0, s, path, res);
}

void substringCheck(int index, string s, vector<string>& path, vector<vector<string>>& res) {
    if(index == s.size()) {
        res.push_back(path);
        return;
    } 
    for(int i = index; i < s.size(); i++) {
        if(isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            substringCheck(i+1, s, path, res);
            path.pop_back();
        }
    }
}

bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

int main() {

    return 0;
}
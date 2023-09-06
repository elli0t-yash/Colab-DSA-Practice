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

//using dp (memoization)
int no_of_partition(int index, int n, string& str, vector<int>& dp) {
    if(index == n) return 0;
    if(dp[index] != -1) return dp[index];
    int minCost = INT_MAX;
    for(int j = index; j < n; j++) {
        if(isPalindrome(str, index, j)) {
            int cost = 1 + no_of_partition(j+1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[index] = minCost;
}


int palindromicPartition(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    return no_of_partition(0, n, str, dp) - 1;
}


bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}


// using tabular dp
int palindromicPartition(string str) {
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--) {
        int minCost = INT_MAX;
        for(int j = i; j < n; j++) {
        if(isPalindrome(str, i, j)) {
            int cost = 1 + dp[j+1];
            minCost = min(minCost, cost);
        }
    }
     dp[i] = minCost;
    }
    return dp[0] - 1;
}

// MCM
int no_of_multiplication(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for(int k = i; k < j; k++) {
        int steps = arr[i-1] * arr[k] * arr[j] + no_of_multiplication(i, k, arr, dp) + no_of_multiplication(k+1, j, arr, dp);
        if(steps < mini) mini = steps;
    }
    return dp[i][j] = mini;
}


int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return no_of_multiplication(1, N-1, arr, dp);
}

//using tabular dp
int matrixMultiplication(vector<int> &arr, int N) {
    int dp[N][N];
    for(int i = 0; i < N; i++) dp[i][i] = 0;
    for(int i = N - 1; i >= 1; i--) {
        for(int j = i + 1; j < N; j++) {
            int mini = 1e9;
        for(int k = i; k < j; k++) {
            int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
            if(steps < mini) mini = steps;
        }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}

int main() {

    return 0;
}
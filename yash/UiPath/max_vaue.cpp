#include<bits/stdc++.h>
using namespace std;

int calculateMaxValue(int n, int T, vector<int> serial, vector<int> value, vector<int> price, vector<int> marking) {
    vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= T; j++) {
            if(marking[i] == 1) {
                if(j >= price[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + value[i]);
                }
            } else if(marking[i] == 2) {
                if(j >= 2 * price[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 2 * price[i]] + 2 * value[i]);
                }
            }

            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    return dp[n][T];
}

int main() {
    int n, T;
    cin>>n>>T;
    vector<int> serial(n + 1), value(n + 1), price(n + 1), marking(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin>>serial[i]>>value[i]>>price[i]>>marking[i];
    }

    int maxValue = calculateMaxValue(n, T, serial, value, price, marking);
    cout<<maxValue<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// const int N = 1e7+10;

vector<int> sieveAlgo(int N) {
    vector<bool> isPrime(N, 1);
    vector<int> answer;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < N; i++) {
        if(isPrime[i] == true) {
            for(int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i < N; i++) {
        if(isPrime[i]) {
            answer.push_back(i);
        }
    }

    return answer;
}

int main() {
    int n;
    cin>>n;
    vector<int> result;

    result = sieveAlgo(n);
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
    
}

#include<bits/stdc++.h>
using namespace std;

int minKnightMoves(int x, int y) {
    x = abs(x);
    y = abs(y);
    vector<pair<int, int>> direc {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    pair<int, int> start {0,0};
    int moves = 0;
    queue<pair<int ,int>> q;
    q.push(start);
    set<pair<int, int>> visited;
    while (!q.empty()) {
        int q_size = q.size();
        for(int i = 0; i < q_size; i++) {
            pair<int, int> p = q.front();
            visited.insert(p);
            if(p.first == x && p.second == y) return moves;
            q.pop();
            for(auto d : direc) {
                if(visited.find({p.first + d.first, p.second + d.second}) == visited.end() && p.first + d.first >= -2 && p.second + d.second >= -2) {
                    q.push({p.first + d.first, p.second + d.second});
                    visited.insert({p.first + d.first, p.second + d.second});
                }
            }
        }
        moves++;
    }
    return -1;
}

int main() {
    int x, y;
    cin>>x>>y;

    return 0;
}
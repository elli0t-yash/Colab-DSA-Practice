#include<bits/stdc++.h>
using namespace std;

struct node {
    int height;
    int x,y;
};

struct Compare {
    bool operator()(node const& a, node const& b) {
        return a.height > b.height;
    }
};

// 2-D trapping rainwater problem
int getMax2D(vector<vector<int>>& block) {
    vector<vector<int>> dirs = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m = block.size();
    int n = block[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<node, vector<node>, Compare> pq;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!(i == 0|| i == m - 1 || j == 0 || j == n - 1)) {
                continue;
            }

            visited[i][j] = true;

            node t;
            t.x = i;
            t.y = j;
            t.height = block[i][j];

            pq.push(t);
        }
    }

    int water = 0;
    int max_height = INT_MIN;

    while(!pq.empty()) {
        node front = pq.top();
        pq.pop();
        max_height = max(max_height, front.height);

        int curr_pos_x = front.x;
        int curr_pos_y = front.y;

        for(int i = 0; i < 4; i++) {
            int new_pos_x = curr_pos_x + dirs[i][0];
            int new_pos_y = curr_pos_y + dirs[i][1];

            if(new_pos_x < 0 || new_pos_y < 0 || new_pos_x >= m || new_pos_y >= n || visited[new_pos_x][new_pos_y]) {
                continue;
            }

            int height = block[new_pos_x][new_pos_y];
            if(height < max_height) {
                water += (max_height - height);
            }

            node temp;
            temp.x = new_pos_x;
            temp.y = new_pos_y;
            temp.height = height;

            pq.push(temp);

            visited[new_pos_x][new_pos_y] = true;
        } 
    }

    return water;
}

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
    // vector<int> block = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int re = getMax(block, block.size());
    // cout<<re;
    vector<vector<int>> height = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    cout<<getMax2D(height);
    // for (int i = 0; i < n; i++) {
    //     cin>>block[i];
    // }
    return 0;
}
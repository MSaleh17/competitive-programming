#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

struct Node {
    int val;
    bool cur, next;

    Node(int val, bool cur, bool next) : val(val), cur(cur), next(next) {}
};


vector<int> bfs(vector<vector<int>> &v, vector<int> &val, vector<int> &need) {
    vector<int> ans, vis(v.size(), 0);
    queue<Node> q;
    q.push(Node(0, false, false));

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        if(node.cur)
            val[node.val] = 1 - val[node.val];

        bool flip = node.cur;
        if(val[node.val] != need[node.val])
            flip = !flip, ans.push_back(node.val + 1);

        for(auto e : v[node.val]) {
            if(vis[e] == 1)
                continue;

            q.push({e, node.next,flip});
            vis[e] = 1;
        }
    }

    return ans;
}

int main() {
    init();

    int n, x, y;
    cin>> n;

    vector<vector<int>> v(n);
    vector<int> val(n), need(n);


    for(int i = 0; i < n-1; i++) {
        cin>> x >> y;
        x--,y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i = 0; i < n; i++)
        cin>> val[i];

    for(int i = 0; i < n; i++)
        cin>> need[i];

    vector<int> ans = bfs(v, val, need);

    cout<< ans.size() << "\n";
    for(auto it : ans)
        cout<< it  << "\n";


    return 0;
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

struct edgeDijkstra {
    int from, to, weight;

    edgeDijkstra(int from_, int to_, int weight_){
        from = from_;
        to = to_;
        weight = weight_;
    }

    bool operator < (const edgeDijkstra &e) const{
        return weight > e.weight;
    }
};


vector<long long> Dijkstra(vector<vector<edgeDijkstra>> &edgeList, int source, int t,int n){
    vector<long long> dis(n, 1e15);
    priority_queue<edgeDijkstra> q;


    q.push(edgeDijkstra(-1, source, 0));
    dis[source] = 0;

    while (!q.empty()) {
        edgeDijkstra e = q.top();
        q.pop();

        if(e.weight > dis[e.to])
            continue;

        for(auto newE : edgeList[e.to]){
            if(dis[newE.to] > dis[newE.from] + newE.weight){
                dis[newE.to] = dis[newE.from] + newE.weight;
                q.push(newE);
            }
        }
    }

    return dis;
};


int main() {
    init();
#ifndef ONLINE_JUDGE
    freopen("t.text", "r", stdin);
#else
#endif

    int n, m, q, u, v, c, k =0;

    while (cin>> n >> m) {
        cout<< "Set #" << ++k << endl;

        vector<vector<edgeDijkstra>> graph(n);

        while (m--) {
            cin>> u >> v >> c;

            graph[u].push_back({u, v, c});
            graph[v].push_back({v, u, c});
        }

        cin>> q;
        while (q--) {
            cin>> u >> v;

            vector<long long> dis1 = Dijkstra(graph, u, v, n);
            vector<long long> dis2 = Dijkstra(graph, v, u, n);

            long long ans = 1e15;

            for(int i = 0; i < n; i++) {
                for(auto it : graph[i]) {
                    if(dis1[i] + it.weight + dis2[it.to] > dis1[v])
                        ans = min(ans, dis1[i] + it.weight + dis2[it.to]);
                }
            }


            if(ans == 1e15)
                cout<< "?" << endl;
            else
                cout<< ans << endl;
        }
    }


    return 0;
}

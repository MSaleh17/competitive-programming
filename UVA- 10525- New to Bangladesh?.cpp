#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

struct edge {
    long long to, dis, time;

    edge(long long int to, long long int dis, long long int time) : to(to), dis(dis), time(time) {}

    bool operator < (const edge &e) const {
        return dis > e.dis;
    }
};

pair<long long, long long> dijkstra(vector<vector<edge>> &graph, int sr, int t) {
    vector<long long> dis(graph.size(), LLONG_MAX), time(graph.size(), LLONG_MAX);

    priority_queue<edge> q;
    q.push(edge(sr, 0, 0));
    dis[sr] = 0;
    time[sr] = 0;

    while (!q.empty()) {
        edge e = q.top();
        q.pop();


        if(e.time > time[e.to])
            continue;

        for(auto newEdge : graph[e.to]) {
            if(time[newEdge.to] > time[e.to] + newEdge.time){
                newEdge.time = time[newEdge.to] = time[e.to] + newEdge.time;
                dis[newEdge.to] = dis[e.to] + newEdge.dis;
                q.push(newEdge);
            }else if(time[newEdge.to] == time[e.to] + newEdge.time)
                dis[newEdge.to] = min(dis[newEdge.to], dis[e.to] + newEdge.dis);
        }

    }

    return {dis[t], time[t]};
}

int main() {
    init();

    int t, n, x, y, m, q, dis, time;
    cin>> t;

    for(int k = 0; k < t; k++){
        if(k)
            cout<< "\n";

        cin>> n >> m;

        vector<vector<edge>> graph(n);
        for(int i = 0; i < m; i++) {
            cin>> x >> y >> time >> dis;
            x--, y--;

            graph[x].push_back(edge(y, dis, time));
            graph[y].push_back(edge(x, dis, time));
        }

        cin>> q;

        while (q--) {
            cin>> x >> y;
            x--,y--;

            pair<long long, long long> ans = dijkstra(graph, x, y);
            if(ans.first == LLONG_MAX)
                cout<< "No Path.\n";
            else
                cout<< "Distance and time to reach destination is " << ans.first << " & " << ans.second<<".\n";
        }
    }

    return 0;
}

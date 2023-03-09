#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    init();

     int n, m, x, y, r, ans = INT_MAX;
     cin>> n >> m;

     vector<int> col(n), row;

     for(int i = 0; i < n; i++)
         cin>> col[i];
     col.push_back(1e9);

    while (m--) {
        cin>> x >> y >> r;
        if(x != 1)
            continue;
        row.push_back(y);
    }

    sort(col.begin(), col.end());
    sort(row.begin(), row.end());

    for(int i = 0; i < col.size(); i++) {
        x = lower_bound(row.begin(), row.end(), col[i]) - row.begin();

        
        x = row.size() - x;

        ans = min(ans, i + x);
    }
    cout<< ans;




    return 0;
}

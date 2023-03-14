#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main() {
    init();


    long long n, m, k, x, y, min_ = LLONG_MAX, max_ = 0, j, l;
    cin>> n >> m >> k >> x >> y;

    vector<vector<long long>> v(n, vector<long long>(m));

    j = n * m + max((n - 2), 0ll) * m;
    l = k / j;
    k %= j;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1)
                v[i][j] +=  l;
            else
                v[i][j] +=  2* l;
        }
    }


        for(int i = 0; i < n && k > 0; i++) {
            for(int j = 0; j < m && k > 0; j++)
                v[i][j]++, k--;
        }

        for(int i = n-2; i > -1 && k > 0; i--) {
            for(int j = 0; j < m && k > 0; j++)
                v[i][j]++, k--;
        }

    for(int i = 1; i < n && k > 0; i++) {
        for(int j = 0; j < m && k > 0; j++)
            v[i][j]++, k--;
    }




    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            max_ = max(v[i][j], max_), min_ = min(v[i][j], min_);
    }

    cout<< max_ << " " << min_ << " " << v[x-1][y-1];

    return 0;
}

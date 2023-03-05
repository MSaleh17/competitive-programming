#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    init();

    int n, x = 1;
    cin>> n;

    if(n == 1)
        return cout<< 1, 0;

    if(n == 2)
        return cout<< "1 2", 0;

    if(n == 3)
        return cout<< "1 1 3", 0;


    vector<pair<int, int>> ans(n);
    while (x * 2 <= n) {
        x *= 2;
    }

    x /=2;


    for(int i = 1; i<=n; i++) {
        int k = 1, m = i;

        while (m % 2 == 0) {
            k *= 2;
            m /= 2;
            if(k == x)
                break;
        }
        ans[i-1] = {k, i};
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            cout<< ans[i].second;
            break;
        }
        cout<< ans[i].first<<" ";
    }


    return 0;
}

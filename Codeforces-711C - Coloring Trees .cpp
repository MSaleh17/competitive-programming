#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

long long max_ = 1e13;
int n, m, k;

long long p[100][101], v[100], dp[100][101][101];

long long solve(int i, int lastColor, int reminder) {
    if(reminder < 0)
        return max_;

    if(i == n) {
        if(reminder == 0)
            return 0;
        return max_;
    }


    long long &ret = dp[i][lastColor][reminder];
    if(ret != -1)
        return ret;


    if(v[i] != 0)
        return ret = solve(i + 1, v[i], reminder - (v[i] != lastColor));

    ret = max_;
    for(int j = 1; j <= m; j++)
        ret = min(ret, p[i][j] + solve(i + 1, j, reminder - (j != lastColor)));


    return ret;
}

int main() {
    init();

    ::memset(p, 0, sizeof p);
    ::memset(dp, -1, sizeof dp);

    cin>> n >> m >> k;


    for(int i = 0; i < n; i++)
        cin>> v[i];

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++)
            cin>> p[i][j];
    }


    long long ans = solve(0, 0, k);

    if(ans == max_)
        cout<< -1;
    else
        cout<< ans;



    return 0;
}

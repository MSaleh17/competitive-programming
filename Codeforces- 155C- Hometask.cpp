#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

string s;
int n;
const int max_ = 1e5 + 3;
set<string> isForbidden;
int dp[max_][30];


int solve(int idx, int lastChar) {
    if(idx >= n)
        return 0;

    auto &ret = dp[idx][lastChar];
    if(ret != -1)
        return ret;

    string prev = "";
    prev.push_back(char(lastChar + 'a'));
    prev.push_back(s[idx]);

 
    ret = INT_MAX;
    if(isForbidden.count(prev))
        return ret = 1 + solve(idx + 1, lastChar);

    return ret = min(1 + solve(idx + 1, lastChar), solve(idx + 1, s[idx] - 'a'));
}

int main() {
    init();

    ::memset(dp, -1, sizeof dp);

    int k;
    string st;

    cin>> s >> k;

    n = s.size();
    s += char('a' + 25);

    while (k--) {
        cin>> st;

        isForbidden.emplace(st);
        reverse(st.begin(), st.end());
        isForbidden.emplace(st);
    }

    cout<< solve(0, 26);





    return 0;
}

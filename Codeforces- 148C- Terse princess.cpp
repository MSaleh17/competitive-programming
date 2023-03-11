#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int maxVal = 50000;

int main() {
    init();


    int n, a, b;
    long long sum = 1;
    cin>> n >> a >> b;


    vector<int> ans;
    ans.push_back(1), n--;

    while (b--){
        ans.push_back(sum + 1);
        sum += sum + 1;
        n--;
    }

    if(ans.size() == 1 && a > 0)
        ans.push_back(1), n--;

    while (a--)
        ans.push_back(ans.back() + 1), n--;


    if(n < 0 || ans.back() > maxVal)
        return cout<< -1, 0;

    for(auto it : ans)
        cout<< it << " ";
    for(int i = 0; i < n; i++)
        cout<< 1 << " ";





    return 0;
}

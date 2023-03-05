#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

bool check(string s, string t, int x, int y) {
    int X = 0, Y = 0;

    for(int i = 0; i < 4; i++) {
        if(s[i] == t[i])
            X++;
    }

    if(x != X)
        return false;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j)
                continue;
            if(s[i] == t[j])
                Y++;
        }
    }

    if(y != Y)
        return false;
    return true;
}


int main() {
    init();


    int n;
    cin>> n;

    vector<string> v(n), ans;
    string temp = "";
    int X[n], Y[n];


    for(int i = 0; i < n; i++)
        cin>> v[i] >> X[i] >> Y[i];


    for(char i = '0'; i <= '9'; i++) {

        temp.push_back(i);
        for(char j = '0'; j <= '9'; j++) {
            if(j == i)
                continue;

            temp.push_back(j);
            for(char k = '0'; k <= '9'; k++) {
                if(k == i || k == j)
                    continue;

                temp.push_back(k);
                for(char c = '0'; c <= '9'; c++) {
                    if(c == i || c == j || c == k)
                        continue;

                    temp.push_back(c);
                    for(int id = 0; id < n; id++) {

                        if(!check(v[id], temp, X[id], Y[id]))
                            break;

                        if(id == n - 1)
                            ans.push_back(temp);
                    }

                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }
        temp.pop_back();
    }

    if(ans.size() == 1)
        cout<< ans[0];
    else if(ans.size() > 1)
        cout<< "Need more data";
    else
        cout<< "Incorrect data";


    return 0;
}

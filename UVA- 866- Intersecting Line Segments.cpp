#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


const double EPS = 1e-9;

typedef complex<double> point;

#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel


int ccw(point a, point b, point c) {
    point v1(b - a), v2(c - a);
    double t = cp(v1, v2);

    if (t > +EPS)
        return +1;
    if (t < -EPS)
        return -1;
    if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
        return -1;
    if (norm(v1) < norm(v2) - EPS)
        return +1;
    return 0;
}

bool intersect(point p1, point p2, point p3, point p4) {
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

int main() {
    init();

    int t, n, x, y;
    cin>> t;


    for(int k  = 0; k < t; k++) {
        if(k)
            cout<< "\n";
        cin>> n;

        vector<pair<point, point>> v(n);
        vector<int> vis(n);

        for(int i = 0; i < n; i++) {
            cin>> x >> y;
            v[i].first.real(x);
            v[i].first.imag(y);

            cin>> x >> y;
            v[i].second.real(x);
            v[i].second.imag(y);

        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(intersect(v[i].first, v[i].second, v[j].first, v[j].second))
                    vis[i]++, vis[j]++;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
            ans += vis[i] + 1;

        cout<< ans << "\n";


    }



    return 0;
}

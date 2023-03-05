#include <bits/stdc++.h>

using namespace std;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int numberOfOnesInRow(int val, int n) {
    int ones = 0;

    while (n > 0) {
        ones += min(val * 2, n);
        val = 1 - val;
        n -= 2;
    }
    return ones;
}

int main() {
    init();

    int x;
    cin>> x;

    if(x == 1)
        return cout<< 1, 0;
    if(x == 3)
        return cout<< 5, 0;

    for(int i = 2; i <= 100; i++) {
        int n = i;

        if(i % 2 == 0)
            n -= 2;

        int k = numberOfOnesInRow(1, n);
        int j = numberOfOnesInRow(0, n);

        int y = max(k, j) * (n / 2 + 1);
        int z = min(k, j) * (n / 2);
        if(y + z >= x)
            return cout<< i, 0;
    }

    return 0;
}

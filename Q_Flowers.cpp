#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000 + 1;

int n, h[MAX_N], arr[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

struct FenwickTree {
    int n; long long val[MAX_N];

    FenwickTree(int _n = 0) {
        n = _n;

        for (int i = 1; i <= n; i++) val[i] = 0;
    }

    void Update(int x, long long v) {
        for (; x <= n; x += x & -x) val[x] = max(val[x], v);
    }

    long long getMax(int x) {
        long long result = 0;

        for (; x >= 1; x -= x & -x) result = max(result, val[x]);

        return result;
    }
} bit;

void Process() {
    bit = FenwickTree(n);

    for (int i = 1; i <= n; i++) bit.Update(h[i], bit.getMax(h[i] - 1) + arr[i]);

    long long result = bit.getMax(n);

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

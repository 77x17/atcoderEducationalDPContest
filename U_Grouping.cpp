#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 16 + 1;

int n, arr[MAX_N][MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
}

long long cost[1 << (MAX_N - 1)], dp[1 << (MAX_N - 1)];

void Process() {
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i + 1 <= n; i++) for (int j = i + 1; j + 1 <= n; j++) {
            if (mask & (1 << i) && mask & (1 << j)) cost[mask] += arr[i + 1][j + 1];
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        int revMask = ((1 << n) - 1) ^ mask;

        for (int subMask = revMask; subMask >= 1; subMask = (subMask - 1) & revMask) {
            dp[mask ^ subMask] = max(dp[mask ^ subMask], dp[mask] + cost[subMask]);
        }
    }

    cout << dp[(1 << n) - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

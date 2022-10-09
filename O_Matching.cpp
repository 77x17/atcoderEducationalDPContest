#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 21 + 1;

int n, arr[MAX_N][MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
}

int dp[1 << (MAX_N - 1)];

void Process() {
    dp[0] = 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = __builtin_popcount(mask);

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) || arr[cnt + 1][i + 1] == false) continue;

            dp[mask | (1 << i)] += dp[mask];

            if (dp[mask | (1 << i)] >= MOD) dp[mask | (1 << i)] -= MOD;
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

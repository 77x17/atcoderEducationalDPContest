#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 1;
const int MAX_M = 100000 + 1;

int n, m, w[MAX_N], v[MAX_N];

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
}

long long dp[MAX_N][MAX_M];

void Process() {
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

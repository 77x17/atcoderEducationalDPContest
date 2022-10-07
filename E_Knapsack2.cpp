#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 1;
const int MAX_V = 100000 + 2332;
const long long INF = 1e18 + 7;

int n, m, w[MAX_N], v[MAX_N];

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
}

long long dp[MAX_N][MAX_V];

void Process() {
    for (int i = 0; i <= n; i++) for (int j = 1; j < MAX_V; j++) dp[i][j] = INF; dp[0][0] = 0;

    for (int i = 1; i <= n; i++) for (int j = 0; j < MAX_V; j++) {
        dp[i][j] = dp[i - 1][j];

        if (j - v[i] >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
    }

    int result; for (result = MAX_V - 1; result >= 0 && dp[n][result] > m; result--);

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

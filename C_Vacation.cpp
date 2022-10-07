#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000 + 1;

int n, a[MAX_N], b[MAX_N], c[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
}

int dp[MAX_N][3];

void Process() {
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

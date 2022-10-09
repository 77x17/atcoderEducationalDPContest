#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 401 + 1;
const long long INF = 1e18 + 7;

int n, arr[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

long long dp[MAX_N][MAX_N], f[MAX_N];

void Process() {
    f[0] = 0; for (int i = 1; i <= n; i++) f[i] = f[i - 1] + arr[i];

    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= n + 1; j++) dp[i][j] = INF;

    for (int i = 1; i <= n; i++) dp[i][i] = 0;

    for (int i = 1; i + 1 <= n; i++) dp[i][i + 1] = arr[i] + arr[i + 1];

    for (int i = n; i >= 1; i--) {
        for (int j = i + 2; j <= n; j++) {
            for (int k = i; k + 1 <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }

            dp[i][j] = dp[i][j] + f[j] - f[i - 1];
        }
    }

    cout << dp[1][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

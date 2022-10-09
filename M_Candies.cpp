#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 100 + 1;
const int MAX_M = 100000+ 1;

int n, m, arr[MAX_N];

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int dp[MAX_N][MAX_M], f[MAX_M];

int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;

    return x;
}

int Minus(int x, int y) {
    if ((x -= y) < 0) x += MOD;

    return x;
}

void Process() {
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        f[0] = 1;

        for (int j = 1; j <= m; j++) f[j] = Add(f[j - 1], dp[i - 1][j]);

        for (int j = 0; j <= m; j++) {
            if (j - arr[i] - 1 >= 0) dp[i][j] = Minus(f[j], f[j - arr[i] - 1]);
            else dp[i][j] = f[j];
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

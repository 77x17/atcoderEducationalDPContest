#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1000 + 1;

int n, m; char arr[MAX_N][MAX_N];

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];
}

int dp[MAX_N][MAX_N];

int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;

    return x;
}

void Process() {
    memset(dp, 0, sizeof dp); dp[0][1] = 1;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (arr[i][j] != '#') {
        dp[i][j] = Add(dp[i - 1][j], dp[i][j - 1]);
    }

    cout << dp[n][m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

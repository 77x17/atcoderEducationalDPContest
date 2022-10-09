#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2999 + 1;

int n; double arr[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

double dp[MAX_N][MAX_N];

void Process() {
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - arr[i]);

        for (int j = 1; j <= i; j++) dp[i][j] = dp[i - 1][j - 1] * arr[i] + dp[i - 1][j] * (1 - arr[i]);
    }

    double result = 0;

    for (int j = n / 2 + 1; j <= n; j++) result += dp[n][j];

    cout << fixed << setprecision(9) << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

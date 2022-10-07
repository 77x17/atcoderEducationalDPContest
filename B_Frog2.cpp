#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 100000 + 1;

int n, k, arr[MAX_N];

void Input() {
    cin >> n >> k; arr[0] = 0;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int dp[MAX_N];

void Process() {
    fill(dp, dp + n + 1, INF); dp[1] = 0;

    for (int i = 2; i <= n; i++) for (int j = 1; j <= min(i - 1, k); j++) {
        dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
    }

    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 100000 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n; arr[0] = 0;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int dp[MAX_N];

void Process() {
    fill(dp, dp + n + 1, 0); dp[2] = abs(arr[2] - arr[1]);

    for (int i = 3; i <= n; i++) dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));

    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

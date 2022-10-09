#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3000 + 1;

int n, m; string s, t;

void Input() {
    cin >> s >> t;

    n = s.size(), m = t.size();

    s = '^' + s; t = '^' + t;
}

int dp[MAX_N][MAX_N];

void Trace() {
    string result;

    while (n && m) {
        if (s[n] == t[m]) {
            result.push_back(s[n]);

            n--, m--;
        } else {
            if (dp[n][m] == dp[n - 1][m]) n--;
            else m--;
        }
    }

    reverse(result.begin(), result.end());

    cout << result << '\n';
}

void Process() {
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        else dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
    }

    Trace();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

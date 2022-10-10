#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 3000 + 1;

void Add(int& x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

int n; string s;

void Input() {
    cin >> n >> s;
}

int dp[MAX_N][MAX_N];

void Process() {
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        char x = s[i - 2];

        for (int j = 1; j <= i; j++) {
            if (x == '<') dp[i][j] = dp[i - 1][j - 1];
            else {
                int temp = dp[i - 1][i - 1] - dp[i - 1][j - 1];

                if (temp < 0) temp += MOD; if (temp >= MOD) temp -= MOD;

                dp[i][j] = temp;
            }
        }

        for (int j = 1; j <= i; j++) {
            Add(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

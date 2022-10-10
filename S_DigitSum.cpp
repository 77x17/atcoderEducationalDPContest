#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_D = 100 + 1;
const int MAX_N = 10000 + 1;

void Add(int& x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

string s; int n, d;

void Input() {
    cin >> s >> d;
}

int dp[MAX_N][MAX_D];

void Process() {
    n = s.size(); dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i--) for (int j = 0; j < d; j++) {
        for (int k = 0; k <= 9; k++) Add(dp[i][j], dp[i + 1][(j + k) % d]);
    }

    int result = 0, carry = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (s[i] - '0'); j++) Add(result, dp[i + 1][(carry + j) % d]);

        carry = (carry + s[i] - '0') % d;
    }

    if (carry == 0) result++;

    if (--result < 0) result += MOD;

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

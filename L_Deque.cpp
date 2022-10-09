#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 3001 + 1;
const long long INF = 1e18 + 7;

int n, arr[MAX_N];

void Input() {
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

// perfect (X - Y) from i to j
long long dp[MAX_N][MAX_N];

void Process() {
	for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= n + 1; j++) dp[i][j] = -INF;

	for (int i = 1; i <= n; i++) dp[i][i] = arr[i];

	for (int i = n; i >= 1; i--) for (int j = i + 1; j <= n; j++) {
		dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
	}

	cout << dp[1][n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Input();

	Process();

    return 0;
}


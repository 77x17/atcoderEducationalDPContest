#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 100000 + 1;

int n, k, arr[MAX_N];

void Input() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

// isFirstplayer are winner
bool dp[MAX_N];

void Process() {
	memset(dp, false, sizeof dp);

	for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) {
		if (i - arr[j] >= 0 && dp[i - arr[j]] == false) dp[i] = true;
	}

	cout << (dp[k] == true ? "First" : "Second") << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Input();

	Process();

    return 0;
}

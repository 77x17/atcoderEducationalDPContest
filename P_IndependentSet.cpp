#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 100000 + 1;

int n;
vector<int> adj[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i + 1 <= n; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v); adj[v].push_back(u);
    }
}

int dp[MAX_N][2];

int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;

    return x;
}

void Dfs(int u, int par) {
    dp[u][0] = dp[u][1] = 1;

    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];

        if (v != par) {
            Dfs(v, u);

            dp[u][0] = 1LL * dp[u][0] * dp[v][1] % MOD;

            dp[u][1] = 1LL * dp[u][1] * Add(dp[v][0], dp[v][1]) % MOD;
        }
    }
}

void Process() {
    Dfs(1, -1);

    cout << Add(dp[1][0], dp[1][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

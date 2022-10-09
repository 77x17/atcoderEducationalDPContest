#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000 + 1;

int n, m;
vector<int> adj[MAX_N];

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
    }
}

int dp[MAX_N];

int Dfs(int u) {
    if (dp[u]) return dp[u];

    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];

        dp[v] = Dfs(v);

        dp[u] = max(dp[u], dp[v] + 1);
    }

    return dp[u];
}

void Process() {
    memset(dp, 0, sizeof dp);

    int result = 0;

    for (int i = 1; i <= n; i++) result = max(result, Dfs(i));

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

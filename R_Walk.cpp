#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 50 + 1;

int n; long long m;

struct Matrix {
    int v[MAX_N][MAX_N];
} arr;

void Add(int& x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

Matrix matrixMultiplication(Matrix a, Matrix b) {
    Matrix result;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) result.v[i][j] = 0;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) {
        Add(result.v[i][j], (int)(1LL * a.v[i][k] * b.v[k][j] % MOD));
    }

    return result;
}

Matrix matrixPower(Matrix a, long long b) {
    Matrix result;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) result.v[i][j] = 0;

    for (int i = 1; i <= n; i++) result.v[i][i] = 1;

    while (b > 0) {
        if (b & 1) result = matrixMultiplication(result, a);

        a = matrixMultiplication(a, a);

        b >>= 1;
    }

    return result;
}

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr.v[i][j];
}

void Process() {
    arr = matrixPower(arr, m);

    int result = 0;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) Add(result, arr.v[i][j]);

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}

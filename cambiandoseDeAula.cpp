#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
// para la estructura de memorizacion combino vectores y un diccionario para optimizarlo en cuanto a tiempo y tambien memoria
int n, m;
vector<vector<int>> M;

bool funcion(int i, int j, int balance, vector<vector<int>> &M, vector<vector<unordered_map<int, bool>>> &dp) {
    if (i >= n || j >= m) return false;

    if (M[i][j] == 1) balance++;
    else if (M[i][j] == -1) balance--;

    int pasos_restantes = (n - 1 - i) + (m - 1 - j);
    if (abs(balance) > pasos_restantes || (balance + pasos_restantes) % 2 != 0) return false;

    if (i == n - 1 && j == m - 1) return balance == 0;

    if (dp[i][j].count(balance)) return dp[i][j][balance];

    if (funcion(i + 1, j, balance, M, dp)) return dp[i][j][balance] = true;
    if (funcion(i, j + 1, balance, M, dp)) return dp[i][j][balance] = true;

    return dp[i][j][balance] = false;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        M = vector<vector<int>>(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];

        vector<vector<unordered_map<int, bool>>> dp(n, vector<unordered_map<int, bool>>(m));

        bool res = funcion(0, 0, 0, M, dp);
        cout << (res ? "YES" : "NO") << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> treeEdges; //init en []
void dfs(int v, int p =  -1){
    estado[v] = EMPECE_A_VER;
    for(int u: aristas[v]){
        if(estado[u] == NO_LO_VI){
            treeEdges[v].push_back(u);
            dfs(u, v);

        } else if(u != p){
            backConExtremoInfEn[v]++;
            backConExtremoSupE[u]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}

vector<int> memo;
int cubren(int v, int p = - 1){
    if(if memo[v] != -1) return memo[v];
    int res = 0;
    res += backConExtremoInfEn[v];
    res -= backConExtremoSupEn[v];
    for(int hijo: treeEdges[v]) if(hijo != p){
        res += cubren(hijo, v);
    }
    memo[v] = res;
    return res;
}
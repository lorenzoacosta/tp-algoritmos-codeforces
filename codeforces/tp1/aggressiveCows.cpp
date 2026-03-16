#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool posible(vector<int> vec, int vacas, int dist){
    vector<int> posiciones = vec;
    int vacasRestantes = vacas - 1;
    int ultimoOcupado = posiciones.front();
    
    for(int i = 1; i < posiciones.size(); i++){
        if(posiciones[i] >= dist + ultimoOcupado){
            vacasRestantes--;
            ultimoOcupado = posiciones[i];
        }
    }
    
    if(vacasRestantes > 0) return false;
    return true;
}

int main(){
    int T;
    cin >> T;
    vector<int> output;

    for(int i = 0; i < T; i++){
        int N, C;
        cin >> N >> C;
        
        vector<int> establos;

        for(int i = 0; i < N; i++){
            int posicion;
            cin >> posicion;
            establos.push_back(posicion);
        }
    
        sort(establos.begin(), establos.end());
        
        int low, high, prom;
        low = 0;
        high = establos.back() - establos.front();
        int res = 0;
        
        while(low <= high){
            prom = (low + high) / 2;
            if(posible(establos, C, prom)){
                res = prom;
                low = prom + 1;
            }
            else{
                high = prom - 1;
            }
        }
        output.push_back(res);
    }

    for (int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }

    return 0;
}


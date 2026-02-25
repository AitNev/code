#include <iostream>
#include <fstream>
#include <vector>

/*
 *  Variables:
 *  - difWays(i, j): Numero de soluciones para la longitud de cuerda i, mirando la cuerda j
 *  - difWays(i): El valor mas grande de cualquier j en difWays(i, j)
 *  - minNum(i, j): Minimo de cuerdas necesarias para obtener la longitud i, mirando la cuerda j
 *  - minNum(i): El valor mas pequenyo de cualquier j en minNum(i, j)
 *  - minCost(i, j): Coste minimo necesario para obtener la longitud i, mirando la cuerda j
 *  - minCost(i): El valor mas pequenyo de cualquier j en minCost(i, j)
 *  - lj: Longitud de la cuerda j
 *  - cj: Coste de la cuerda i
 *
 *  Casos Base:
 *  - difWays(0, j): 1
 *  - difWays(i, j): 0
 *  - minNum(0, j): 0
 *  - minNum(i, j): INF
 *  - minCost(i, j): 0
 *  - minCost(i, j): INF
 *
 *  Caso Recursivo:
 *  - difWays(i, j) = difWays(i, j-1) + difWays(i - lj)
 *  - minNum(i, j) = min( minNum(i, j-1), minNum(i - lj) + 1)
 *  - minCost(i, j) = min( minCost(i, j-1), minCost(i - lj) + cj)
 *
 *  Reduccion de espacio a un vector
 *  - Podemos hacer un vector que se sobre escribe en j, haciendo que solo i sea importante
 *
 *  Solucion iterativa
 *  Costes:
 *  - Tiempo O(n * l) => O(n2) ambos maximos son iguales
 *    - Son 2 bucles
 *  - Espacio O(l)
 *    - Solo usamos vectores de tamanyo l
 *
 */

using namespace std;

const int INF = 1000000000;
typedef struct s_answer {
    long long int combinations, minNum, minCost;
} t_answer;

t_answer solveKite(int n, int l, vector<pair<int, int>> ropes) {
    vector<long long int> difWays = vector<long long int>(l + 1, 0);
    difWays[0] = 1;
    vector<long long int> minNum = vector<long long int>(l + 1, INF);
    minNum[0] = 0;
    vector<long long int> minCost = vector<long long int>(l + 1, INF);
    minCost[0] = 0;

    // O(n * l) Iterate for each possible step for each rope
    for(int i=0; i<n; i++){
        int curr_len = ropes[i].first;
        int curr_cos = ropes[i].second;

        for (int j=l; j>0; j--){
            // Rope length is bounded between 1-1000
            if(j - curr_len >= 0){  // We won't get IOB Error
                if(difWays[j - curr_len] != 0){ // Adding this rope finds a solution here
                    difWays[j] += difWays[j - curr_len];                // Add all the previous possible combinations
                    if (minNum[j - curr_len] + 1 < minNum[j]){          // Found a better solution
                        minNum[j] = minNum[j - curr_len] + 1;
                    }
                    if (minCost[j - curr_len] + curr_cos < minCost[j]){ // Found a cheaper solution
                        minCost[j] = minCost[j - curr_len] + curr_cos;
                    }
                }
            }
        }
    }
    t_answer answer;
    answer.combinations = difWays[l];
    answer.minNum = minNum[l];
    answer.minCost = minCost[l];

    return answer;
}


bool resuelveCaso() {
    // Read input
    int n, l;
    if (!(cin >> n >> l))
        return false;

    int len, cost;
    vector<pair<int, int>> ropes = vector<pair<int, int>>();
    for(int i = 0; i < n; i++) {
        cin >> len >> cost;
        ropes.push_back({len, cost});
    }

    // Solve problem
    t_answer answer = solveKite(n, l, ropes);

    // Print solution
    if(answer.combinations > 0) {
        cout << "SI " << answer.combinations << " " << answer.minNum
             << " " << answer.minCost << "\n";
    }
    else
        cout << "NO\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("cases.txt");
    if (!in) {
        std::cerr << "Could not open cases.txt\n";
        return 0;
    }
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
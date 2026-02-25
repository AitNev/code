#include <iostream>
#include <fstream>
#include <vector>

/*
 *  Solucion iterativa
 *  Costes:
 *  - Tiempo O(n * p)
 *    - Hacemos maxPower iteraciones combrobando cada bombilla
 *  - Espacio O(p)
 *    - Usamos un unico vector de tamanyo maxPower l
 */

using namespace std;

const int INF = 1000000000;
typedef struct s_answer {
    int minCost, power;
} t_answer;

// Time cost O(n * p) We do maxPower iterations on each we check all bulbs
// Space cost O(p) since we use a vector of size maxPower
t_answer solvePower(int maxPower, int minPower, vector<pair<int, int>> *bulbs) {
    vector<int> costs = vector<int>(maxPower + 1, INF);
    t_answer answer;
    answer.minCost = INF;
    answer.power = INF;

    costs[0] = 0;   // Starting basecase
    for (int i = 1; i <= maxPower; ++i) {   // Iterate all powers until maxPower
        int minCost = INF;
        for (pair<int, int> bulb: *bulbs) { // Check all the bulbs
            if (i - bulb.first >= 0) {  // No IOB Error
                if (costs[i - bulb.first] + bulb.second < minCost) {
                    // Found a better solution for the current power
                    minCost = costs[i - bulb.first] + bulb.second;
                }
            }
        }
        costs[i] = minCost; // Store the lowest cost for the current power
        if (i >= minPower && minCost < answer.minCost) {    // Update answer if we should
            answer.minCost = minCost;
            answer.power = i;
        }
    }

    return answer;
}


bool resuelveCaso() {
    // Read input
    int n, maxPower, minPower;
    if (!(cin >> n >> maxPower >> minPower))
        return false;

    int power, cost;
    vector<pair<int, int>> bulbs = vector<pair<int, int>>(n, {0 ,0});
    for(int i = 0; i < n; i++) {
        cin >> power;
        bulbs[i].first = power;
    }
    for(int i = 0; i < n; i++) {
        cin >> cost;
        bulbs[i].second = cost;
    }

    // Solve problem
    t_answer answer = solvePower(maxPower, minPower, &bulbs);

    // Print solution
    if(answer.minCost != INF) {
        cout << answer.minCost << " " << answer.power << endl;
    }
    else
        cout << "IMPOSIBLE\n";

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
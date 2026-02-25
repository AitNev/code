#include <iostream>
#include <fstream>
#include <vector>

/*
 *  Reduccion de espacio a un vector
 *  - Podemos hacer un vector que se sobre escribe en j, haciendo que solo i sea importante
 *
 *  Solucion recursiva
 *  Costes:
 *  - Tiempo O(t) Peor caso, calculamos todas las posiciones
 *  - Espacio O(t) Peor caso, cuando el sector mas grande es 1
 *
 */

using namespace std;

const int INF = 1000000000;

typedef struct s_answer {
    vector<int> solutions;  // The lowest number of darts required
    vector<int> sol_sector; // Chosen sector for the given positon, To print the answer efficiently
} t_answer;

// Worst case scenario, there's a stack depth of 50000, each one has 1000 array reads, one per sector
// On normally, on most cases it can skip checking positions that are unreachable
// Time cost O(t) where t is the target
// Space cost O(t) t is the stack space when biggest sector value is 1
int recursiveBullsEye(int pos, t_answer *answer, vector<int> *sectors) {
    if (pos == 0) {                                 // We reach the end
        return 1;
    }else if (answer->solutions.at(pos) == INF) {   // Know this position has no solution
        return INF;
    }else if(answer->solutions.at(pos) == 0) {      // Compute the best solution for this pos if not done
        int minSol = INF, minSolSector = 0;

        // Sectors input is sorted we iterate the biggest elements first to save iterations if possible
        for (auto it = sectors->crbegin(); it != sectors->crend(); ++it) {
            int sector = *it;
            if (pos - sector >= 0) {
                int sol = recursiveBullsEye(pos - sector, answer, sectors);
                if (sol < minSol) { // Store the best solution
                    minSol = sol;
                    minSolSector = sector;
                }
            }
        }

        // Store the best answer
        answer->solutions.at(pos) = minSol;
        answer->sol_sector.at(pos) = minSolSector;
    }
    // Return the value from the dp
    return answer->solutions.at(pos) + 1;
}

t_answer solveBullsEye(int target, vector<int> *sectors) {
    t_answer answer;
    answer.solutions = vector<int>(target + 1, 0);
    answer.sol_sector = vector<int>(target + 1, 0);

    recursiveBullsEye(target, &answer, sectors);

    return answer;
}


bool resuelveCaso() {
    // Read input
    int target, s;
    if (!(cin >> target >> s))
        return false;

    int sector;
    vector<int> sectors = vector<int>();
    for(int i = 0; i < s; i++) {
        cin >> sector;
        sectors.push_back(sector);
    }

    // Solve problem
    t_answer answer = solveBullsEye(target, &sectors);

    // Print solution
    if(answer.solutions.at(target) != INF && answer.solutions.at(target) != 0) {
        cout << answer.solutions.at(target) << ": ";

        int i = target;
        while (i > 0) {
            cout << answer.sol_sector.at(i) << " ";
            i -= answer.sol_sector.at(i);
        }

        cout << endl;
    }
    else
        cout << "Imposible\n";

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
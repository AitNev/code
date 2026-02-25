#include <iostream>
#include <fstream>
#include <vector>

/*
 *  Solucion iterativa
 *  Costes:
 *  - Tiempo O(n2) N^2 iteraciones para leer la matriz
 *  - Espacio O(n) Usamos vectores de tamanyo n
 */

using namespace std;

// Time cost O(n2) n^2 iterations to read the square
// Space cost O(n) since we use vectors of size n
bool resuelveCaso() {
    // Read input
    int n, number, max;
    if (!(cin >> n))
        return false;

    vector<int> prev = vector<int>(n);
    for(int i = 0; i < n; i++) {    // Read the first row
        cin >> number;
        prev[i] = number;
    }

    vector<int> curr = vector<int>(n);
    for (int i = 1; i < n; i++) {   // Read all the remaining rows O(n2)
        for (int j = 0; j < n; j++) {   // Process each col value
            cin >> number;
            max = prev[j];

            if (j > 0 && prev[j - 1] > max) {       // Lookup the Left element
                max = prev[j - 1];
            }if (j + 1 < n && prev[j + 1] > max) {  // Lookup the Right element
                max = prev[j + 1];
            }
            curr[j] = number + max;     // Update the greatest reachable value
        }
        swap(prev, curr);   // Constant time pointer swap operation
    }

    // Print the answer O(n)
    int best = 0, best_index = 0;
    for (int i = 0; i < n; ++i) {
        if (prev[i] > best) {
            best = prev[i];
            best_index = i;
        }
    }

    cout << best << " " << (best_index + 1) << endl;

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
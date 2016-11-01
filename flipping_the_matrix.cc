#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Enunciado: https://www.hackerrank.com/challenges/flipping-the-matrix

int main() {
    unsigned q, n;
    cin >> q;
    for (int cq = 0; cq < q; ++cq) {
        cin >> n;

        // Cada elemento tiene 4 posiciones posibles mediante las operaciones dadas
        // Idea 3 (la buena): basta tomar el máximo de las 4 posiciones posibles para cada elemento del cuadrante

        vector<vector<unsigned>> m(2*n, vector<unsigned>(2*n));

        for (auto& v : m) {
            for (unsigned& e : v) {
                cin >> e;
            }
        }

        long long unsigned sum = 0;

        for (unsigned i = 0; i < n; ++i) {
            for (unsigned j = 0; j < n; ++j) {
                // calcular las 4 posiciones simétricas respecto de los ejes centrales
                sum += max(
                    m[i][j], max(
                    m[2*n-i-1][j], max(
                    m[i][2*n-j-1],
                    m[2*n-i-1][2*n-j-1])));
            }
        }

        cout << sum << endl;
    }
    
    return 0;
}

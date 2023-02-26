#include <iostream>
using namespace std;

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    // Check if it is impossible to satisfy both Ryo and Kita
    if (r > n || c > m || (n * m - (n-r) * (m-c)) < r * c - (r * c - r - c)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Create a poster that satisfies Ryo and Kita
    char poster[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            poster[i][j] = 'a' + (i+j)%26;
        }
    }
    for (int i = 0; i < r; i++) {
        int j = i % 2 == 0 ? 0 : m-1;
        if (m % 2 == 0 && j == m-1 && c == m/2) {
            j--;
        }
        while (j >= 0 && j < m) {
            poster[i][j] = poster[i][m-j-1];
            j += 2;
        }
    }
    for (int j = 0; j < c; j++) {
        int i = j % 2 == 0 ? 0 : n-1;
        if (n % 2 == 0 && i == n-1 && r == n/2) {
            i--;
        }
        while (i >= 0 && i < n) {
            poster[i][j] = poster[n-i-1][j];
            i += 2;
        }
    }

    // Output the poster
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << poster[i][j];
        }
        cout << endl;
    }

    return 0;
}

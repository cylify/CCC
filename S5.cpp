#include <iostream>
#include <vector>
using namespace std;


vector<int> apply_filter(int k, int start, int end) {
    vector<int> res;
    int interval_size = (end - start) / (3 * k);
    int a = start + interval_size;
    for (int i = 1; i <= 3 * k - 2; i += 3) {
        int b = a + interval_size;
        if (i == 1 || i % 3 == 0) {
            res.push_back(a);
        }
        a = b;
    }
    if (end - a >= interval_size) {
        res.push_back(a);
    }
    return res;
}

vector<int> cantor_set(int n, int start, int end) {
    if (n == 0) {
        return {start};
    }
    vector<int> res;
    vector<int> left = cantor_set(n - 1, start, (2 * end + start) / 3);
    vector<int> right = cantor_set(n - 1, (2 * start + end) / 3, end);
    for (int x : left) {
        if (x < start || x > end) {
            continue;
        }
        bool covered = false;
        for (int k = 1; k <= n; k++) {
            vector<int> filtered = apply_filter(k, start, end);
            for (int y : filtered) {
                if (y == x) {
                    covered = true;
                    break;
                }
            }
            if (covered) {
                break;
            }
        }
        if (!covered) {
            res.push_back(x);
        }
    }
    for (int x : right) {
        if (x < start || x > end) {
            continue;
        }
        bool covered = false;
        for (int k = 1; k <= n; k++) {
            vector<int> filtered = apply_filter(k, start, end);
            for (int y : filtered) {
                if (y == x) {
                    covered = true;
                    break;
                }
            }
            if (covered) {
                break;
            }
        }
        if (!covered) {
            res.push_back(x);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans = cantor_set(n, 0, n);
    for (int x : ans) {
        cout << x << endl;
    }
    return 0;
}

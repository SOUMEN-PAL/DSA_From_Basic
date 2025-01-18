#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        set<pair<int, int>> stampedCells;
        int x = 0, y = 0; 
        for (int i = 0; i < n; i++) {
            int ox, oy;
            cin >> ox >> oy;
            x += ox;
            y += oy;

            for (int dx = 0; dx < m; dx++) {
                for (int dy = 0; dy < m; dy++) {
                    stampedCells.insert({x + dx, y + dy});
                }
            }
        }

        int perimeter = 0;
        for (auto cell : stampedCells) {
            int cx = cell.first;
            int cy = cell.second;

            if (!stampedCells.count({cx - 1, cy})) perimeter++; 
            if (!stampedCells.count({cx + 1, cy})) perimeter++; 
            if (!stampedCells.count({cx, cy - 1})) perimeter++; 
            if (!stampedCells.count({cx, cy + 1})) perimeter++; 
        }

        cout << perimeter << endl;
    }

    return 0;
}

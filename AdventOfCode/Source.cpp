#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main() {
    string line;
    vector<string> matrix;
    ifstream file("day3part2.txt");
    int res = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            matrix.push_back(line);
        }
        file.close();
    }
    int m = matrix.size();
    int n = matrix[0].size();
    // 8 directions
    vector<int> dx = { 0,0, 1,1,1, -1,-1 ,-1};
    vector<int> dy = { 1,-1,0,1,-1, 0,1,-1 };  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '*') {
                set<pair<int, int>> visited;
                vector<int> v;
                int number = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || y < 0 || x == m || y == n || !isdigit(matrix[x][y]) || visited.find({x,y}) != visited.end()) continue;
                    //a number found. search greedy to left and right and mark all continuous number as visited
                    number++;
                    if (number > 2) break;
                    visited.insert({ x,y });
                    string left;
                    string right;
                    int l = y - 1;
                    int r = y + 1;
                    while (l >= 0 && isdigit(matrix[x][l])) {
                        left.insert(left.begin(), matrix[x][l]);
                        visited.insert({ x,l });
                        l--;
                    }
                    while (r < n && isdigit(matrix[x][r])) {
                        right += matrix[x][r];
                        visited.insert({ x,r });
                        r++;
                    }
                    string cur = left + matrix[x][y] + right;
                    v.push_back(stoi(cur));
                }
                if (v.size() == 2) res += v[0] * v[1];
            }
        }
    }
    cout << res << endl;
    return 0;
}
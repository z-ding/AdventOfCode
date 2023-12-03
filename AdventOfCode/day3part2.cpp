/*
* The engineer finds the missing part and installs it in the engine! As the engine springs to life, you jump in the closest gondola, finally ready to ascend to the water source.

You don't seem to be going very fast, though. Maybe something is still wrong? Fortunately, the gondola has a phone labeled "help", so you pick it up and the engineer answers.

Before you can explain the situation, she suggests that you look out the window. There stands the engineer, holding a phone in one hand and waving with the other. You're going so slowly that you haven't even left the station. You exit the gondola.

The missing part wasn't the only issue - one of the gears in the engine is wrong. A gear is any * symbol that is adjacent to exactly two part numbers. Its gear ratio is the result of multiplying those two numbers together.

This time, you need to find the gear ratio of every gear and add them all up so that the engineer can figure out which gear needs to be replaced.

Consider the same engine schematic again:

467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
In this schematic, there are two gears. The first is in the top left; it has part numbers 467 and 35, so its gear ratio is 16345. The second gear is in the lower right; its gear ratio is 451490. (The * adjacent to 617 is not a gear because it is only adjacent to one part number.) Adding up all of the gear ratios produces 467835.
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
*/
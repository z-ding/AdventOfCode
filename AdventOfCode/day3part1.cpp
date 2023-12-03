/*
* --- Day 3: Gear Ratios ---
You and the Elf eventually reach a gondola lift station; he says the gondola lift will take you up to the water source, but this is as far as he can bring you. You go inside.

It doesn't take long to find the gondolas, but there seems to be a problem: they're not moving.

"Aaah!"

You turn around to see a slightly-greasy Elf with a wrench and a look of surprise. "Sorry, I wasn't expecting anyone! The gondola lift isn't working right now; it'll still be a while before I can fix it." You offer to help.

The engineer explains that an engine part seems to be missing from the engine, but nobody can figure out which one. If you can add up all the part numbers in the engine schematic, it should be easy to work out which part is missing.

The engine schematic (your puzzle input) consists of a visual representation of the engine. There are lots of numbers and symbols you don't really understand, but apparently any number adjacent to a symbol, even diagonally, is a "part number" and should be included in your sum. (Periods (.) do not count as a symbol.)

Here is an example engine schematic:

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
In this schematic, two numbers are not part numbers because they are not adjacent to a symbol: 114 (top right) and 58 (middle right). Every other number is adjacent to a symbol and so is a part number; their sum is 4361.

Of course, the actual engine schematic is much larger. What is the sum of all of the part numbers in the engine schematic?
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string line;
    vector<string> matrix;
    ifstream file("day3part1.txt");
    int res = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            matrix.push_back(line);
        }
        file.close();
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    // 8 directions
    vector<int> dx = { 0,0, 1,1,1, -1,-1 ,-1 };
    vector<int> dy = { 1,-1,0,1,-1, 0,1,-1 };
    bool hasSymbol = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //cout << i << "," << j << endl;
            string num;
            while (j < n && isdigit(matrix[i][j]) && !visited[i][j]) {
                visited[i][j] = 1;
                num += matrix[i][j];
                if (!hasSymbol) {
                    //search for adjacent symbol
                    for (int k = 0; k < 8; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || y < 0 || x == m || y == n || matrix[x][y] == '.' || isdigit(matrix[x][y])) continue;
                        hasSymbol = true;
                        break;
                    }
                }
                j++;
            }
            if (hasSymbol) {
                res += stoi(num);
                hasSymbol = false;
            }
        }
    }
    cout << res << endl;
    return 0;
}
*/
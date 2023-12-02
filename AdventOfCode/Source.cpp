#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    string line;
    ifstream file("day2part2.txt");
    int res = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.size() < 6) continue;
            int idx = 5;
            string index;
            while (isdigit(line[idx])) {
                index += line.substr(idx, 1);
                idx++;//idx will stop at :
            }
            //cout <<"index" <<  index << endl;
            idx += 2;
            string num;
            string color;
            unordered_map<string, int> maxcube;
            while (idx < line.size()) {
                if (line[idx] == ' ') {
                    idx++;
                    continue;
                }
                while (isdigit(line[idx])) {
                    num += line.substr(idx, 1);
                    idx++;//idx will stop at space
                }
                //idx should be a color
                while (idx < line.size() && line[idx] != ',' && line[idx] != ';' && line[idx] != ' ') {
                    color += line.substr(idx, 1);
                    idx++;//idx will stop at ,or ;
                }
                if (idx >= line.size() - 1 || line[idx] == ',' || line[idx] == ';') {
                    //cout << "cn" << "," << color << "," << num << endl;
                    maxcube[color] = max(maxcube[color], stoi(num));
                    num = "";
                    color = "";
                    idx++;

                }
            }
            int cur = 1;
            for (auto& e : maxcube) cur *= e.second;
            maxcube.clear();
            res += cur;
        }
        file.close();
        cout << res << endl;
    }
    return 0;
}
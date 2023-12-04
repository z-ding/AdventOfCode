#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main() {
    string line;
    ifstream file("day4part1.txt");//card number, multiplier
    int res = 0;
    unordered_map<int, int> mp;
    int card = 0;
    for (int i = 1; i < 1000000; i++) mp[i] = 1;
    if (file.is_open()) {
        while (getline(file, line)) {
            card++;
            int idx = line.find(":");
            int partition = line.find("|");
            idx += 2;
            string num;
            unordered_set<int> u;
            while (idx < partition) {
                if (line[idx] == ' ') {
                    if (!num.size()) {
                        idx++;
                        continue;
                    }
                    u.emplace(stoi(num));
                    num = "";
                    idx++;
                    continue;
                }
                while (isdigit(line[idx])) {
                    num += line[idx];
                    idx++;//idx stops at a space
                }
            }
            //idx at '|'
            //cout << idx << endl;
            num = "";
            idx = partition +2;
            int match = 0;
            while (idx < line.size()) {
                if (line[idx] == ' ' ) {
                    //cout << "num " << num << endl;
                    if ( !num.size() || !isdigit(num[0])) {
                        num = "";          
                    }
                    else {
                        if (u.find(stoi(num)) != u.end()) match++;
                        //cout << "stoi" << endl;
                        num = "";
                    }                    
                    idx++;
                    continue;
                }
                while ( isdigit(line[idx])) {
                    num += line[idx];
                    idx++;//idx stops at a space
                }
            }
            if (num.size()) {
                if (u.find(stoi(num)) != u.end()) match++;
            }
            //create copy for card number [card+1,card+match]
            int curcopy = mp[card];
            for (int j = card + 1; j <= card + match; j++) {            
                mp[j] += curcopy ;
            }
        }
        file.close();
    }
    for (auto& e : mp) {      
        if (e.first <= card) {
            res += e.second;
        } 
    }
    cout << res << endl;
    return 0;
}
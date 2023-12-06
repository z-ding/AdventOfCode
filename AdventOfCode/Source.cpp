#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<long long> getnumber(string &s) {
    int idx = 0;
    string num;
    vector<long long> tmp;
    while (idx < s.size()) {
        if (!isdigit(s[idx])) {
            if (num.size() && isdigit(num[0])) {
                tmp.push_back(stoll(num));
                num = "";
            }
            idx++;
        }
        else {//a digit
            num += s[idx];
            idx++;
        }
    }
    if (num.size() && isdigit(num[0])) {
        tmp.push_back(stoi(num));
    }
    return tmp;
}


int main() {
    long long res = 1;
    string line;
    ifstream file("day6part1.txt");//card number, multiplier
    vector<string> v;
    if (file.is_open()) {
        while (getline(file, line)) {
            v.push_back(line);
        }
        file.close();
    }
    //get seed number
    auto seed = getnumber(v[0]);
    int idx = 0;
    vector<vector<long long>> mtx;
    vector<int> partition = { 0 };
    while (idx < v.size()) {
        auto x = getnumber(v[idx]);
        mtx.push_back(x);
        idx++;      
    }
    string t1;
    string d1;
    for (int i = 0; i < mtx[0].size(); i++) {
        t1 += to_string(mtx[0][i]);
        d1 += to_string(mtx[1][i]);
        //cout << t << "," << d << endl;
    }
    int win = 0;
    long long t = stoll(t1);
    long long d = stoll(d1);
    cout << t << "," << d << endl;
    for (int j = 0; j <= t; j++) {
        int speed = j;
        int run = t - j;
        if ((long long)run * (long long)speed > d) win++;
    }
    cout << win << endl;
    return 0;
}
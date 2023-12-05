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
long long best = LLONG_MAX;
void dfs(long long sr, long long er, vector<vector<long long>> &mtx, int posp, vector<int> &partition) {
    //cout << sr << "," << er << ":" << posp << "," << partition.size() << endl;
    if (posp == partition.size() - 1) {
        best = min(best, sr);
        return;
    }
    int a = partition[posp];
    int b = partition[posp + 1] - 1;
    int r = a;
    while (r <= b) {
        
        auto minsrc = mtx[r][1];
        auto maxsrc = mtx[r][1] + mtx[r][2] - 1ll;
        //cout << r << ":" << minsrc << "," << maxsrc << endl;
        if (sr > maxsrc) {
            r++;
            if (r > b) {
                dfs(sr, er, mtx, posp + 1, partition);
            }
        }
        else if (er < minsrc) {
            dfs(sr, er, mtx, posp + 1, partition);
            break;
        }
        else {
            //sr <= maxsrc, er >=minsrc
            if (sr < minsrc && er > maxsrc) {
                dfs( sr,minsrc - 1ll ,mtx,posp+1,partition);
                dfs(mtx[r][0], mtx[r][0] + mtx[r][2] - 1ll, mtx, posp + 1, partition);
                sr = maxsrc + 1ll;
                r++;//search for next interval since er > maxsrc
            }
            else if (sr < minsrc) {//er <= maxsrc
                dfs( sr,minsrc - 1ll, mtx, posp + 1, partition);
                dfs(mtx[r][0], er - mtx[r][1] + mtx[r][0] , mtx, posp + 1, partition);
                break;
            }
            else if (er > maxsrc) {//sr >= minsrc
                dfs(sr - mtx[r][1] + mtx[r][0],mtx[r][0] + mtx[r][2] - 1ll, mtx, posp + 1, partition);
                sr = maxsrc + 1ll;
                r++;//search for next interval since er > maxsrc
            }
            else {//sr >= minsrc, er <= maxsrc
                dfs(sr - mtx[r][1] + mtx[r][0], er - mtx[r][1] + mtx[r][0] , mtx, posp + 1, partition);
                break;
            }
        }
    }
    
}
int main() {
    string line;
    ifstream file("day5part1.txt");//card number, multiplier
    long long res = LLONG_MAX;
    vector<string> v;
    if (file.is_open()) {
        while (getline(file, line)) {
            v.push_back(line);
        }
        file.close();
    }
    //get seed number
    auto seed = getnumber(v[0]);
    int idx = 3;
    vector<vector<long long>> mtx;
    vector<int> partition = { 0 };
    while (idx < v.size()) {
        if (!isdigit(v[idx][0])) {
            idx++;
        }
        else {
            auto x = getnumber(v[idx]);
            mtx.push_back(x);
            idx++;
            if (idx == v.size() || !isdigit(v[idx][0])) partition.push_back(mtx.size());
        }
    }
    
    //sort according to source in asd order
    for (int i = 0; i < partition.size() - 1; i++) {
        int start = partition[i];
        int end = partition[i + 1] - 1;
        sort(mtx.begin() + start, mtx.begin() + end+1, [](vector<long long>& a, vector<long long>& b) {
            return a[1] < b[1];
            });
    }
    //convert seed to other resources
    vector < vector<long long>> rng;
    for (int i=0; i< seed.size();i+=2) {
        rng.push_back({ seed[i],seed[i] + seed[i + 1] - 1ll });
     }
    sort(rng.begin(), rng.end());  
    for (int i = 0; i < rng.size(); i++) {
        dfs(rng[i][0], rng[i][1], mtx, 0, partition);
    }
    /*
    for (int i = 0; i < mtx.size(); i++) {
        for (auto x : mtx[i]) cout << x << ",";
        cout << endl;
    }*/
    cout << best << endl;
    return 0;
}
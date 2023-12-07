/*
* --- Part Two ---
To make things a little more interesting, the Elf introduces one additional rule. Now, J cards are jokers - wildcards that can act like whatever card would make the hand the strongest type possible.

To balance this, J cards are now the weakest individual cards, weaker even than 2. The other cards stay in the same order: A, K, Q, T, 9, 8, 7, 6, 5, 4, 3, 2, J.

J cards can pretend to be whatever card is best for the purpose of determining hand type; for example, QJJQ2 is now considered four of a kind. However, for the purpose of breaking ties between two hands of the same type, J is always treated as J, not the card it's pretending to be: JKKK2 is weaker than QQQQ2 because J is weaker than Q.

Now, the above example goes very differently:

32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483
32T3K is still the only one pair; it doesn't contain any jokers, so its strength doesn't increase.
KK677 is now the only two pair, making it the second-weakest hand.
T55J5, KTJJT, and QQQJA are now all four of a kind! T55J5 gets rank 3, QQQJA gets rank 4, and KTJJT gets rank 5.
With the new joker rule, the total winnings in this example are 5905.

Using the new joker rule, find the rank of every hand in your set. What are the new total winnings?
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int hand(string s) {
    unordered_map<char, int> freq;
    int j = 0;
    for (auto c : s) {
        if (c == 'J') j++;
        freq[c]++;
    }
    //cout << s << "," << j << endl;
    if (freq.size() == 1) return 5;//five same card
    int maxf = 0; int secondf = 0;
    for (auto& e : freq) {
        if (e.second >= maxf) {
            secondf = maxf;
            maxf = e.second;
        }
        else if (e.second >= secondf) {
            secondf = e.second;
        }
    }
    if (j == 0) {
        if (maxf == 4) return 4;
        else if (maxf == 3 && secondf == 2) return 3;
        else if (maxf == 3) return 2;
        else if (maxf == 2 && secondf == 2) return 1;
        else if (maxf == 2) return 0;
        return -1;
    }
    else {
        if (maxf == 4) {//JJJJX || XXXXJ -> XXXXX
            return 5;
        }
        else if (maxf == 3 && secondf == 2) return 5;// XXX JJ || JJJ XX
        else if (maxf == 3) return 4;//XXXJY -> XXXXY || JJJXY -> XXXXY
        else if (maxf == 2 && secondf == 2) {//AABBJ -> AABBB || JJAAX -> AAAAX
            if (j ==1) return 3;
            return 4;
        }
        else if (maxf == 2) return 2;//AAJBC -> AAABC || JJABC -> AAABC
        else if (maxf == 1) return 0;//JABCD
        return -1;
    }
}
unordered_map<char, int> order = { {'A',13},{'K',12},{'Q',11}, {'J',0},{'T',9},{'9',8},{'8',7},{'7',6},{'6',5},{'5',4},{'4',3},{'3',2},{'2',1} };

bool big(string a, string b) {//check if string a > string b
    for (int i = 0; i < a.size(); i++) {
        char ca = a[i];
        char cb = b[i];
        if (order[ca] > order[cb]) return true;
        else if (order[ca] < order[cb]) return false;
      }
    return true;
}
int main() {
    long long res = 0;
    string line;
    ifstream file("day7part1.txt");//card number, multiplier
    vector<pair<string,int>> mtx;
    if (file.is_open()) {
        while (getline(file, line)) {
            int spc = line.find(" ");
            mtx.push_back({ line.substr(0,spc),stoi(line.substr(spc + 1)) });
        }
        file.close();
    }
    //A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, or 2.
    sort(mtx.begin(), mtx.end(), [](pair<string, int> &p1, pair<string, int> &p2) {
        int a = hand(p1.first);
        int b = hand(p2.first);
        return a > b || (a == b && big(p1.first, p2.first));
        });
    for (int i = 0; i < mtx.size(); i++) {
        res += (mtx.size() - i)*mtx[i].second;
        //cout << mtx[i].first << "," << mtx[i].second << endl;
    }

    cout << res << endl;
    return 0;
}
*/
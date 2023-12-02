/*
* Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".

Equipped with this new information, you now need to find the real first and last digit on each line. For example:

two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

What is the sum of all of the calibration values?
int main() {
    fstream new_file;
    unordered_map<string, int> mp = { {"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9} };
    // open a file to perform read operation using file object.
    new_file.open("day1part2.txt", ios::in);

    int res = 0;
    // Checking whether the file is open.
    if (new_file.is_open()) {
        string sa;
        // Read data from the file object and put it into a string.
        while (getline(new_file, sa)) {
            // Print the data of the string.
            int first = -1;
            int last = -1;
            int i = 0;
            while (i< sa.size()) {
                if (int(sa[i]) >= 48 && int(sa[i]) <= 57) {
                    if (first == -1) first = stoi(sa.substr(i, 1));
                    else last = stoi(sa.substr(i, 1));
                    i++;
                }
                else {//a letter found, check substring of length 3-5 to see whether they are one -nine
                    auto p = findnum(mp, sa, i);
                    if (p.first != -1) {//num found
                        if (first == -1) first = p.first;
                        else last = p.first;
                        i++;
                    }
                    else {//no number found
                        i++;
                    }
                }
            }
            if (last != -1) res = res + first*10 + last;
            else if (first != -1) res = res + first*10 + first;
        }

        // Close the file object.
        new_file.close();
    }
    cout << res << endl;
    return 0;
}
*/

using namespace std;
/*
* --- Day 1: Trebuchet?! ---
Something is wrong with global snow production, and you've been selected to take a look. The Elves have even given you a map; on it, they've used stars to mark the top fifty locations that are likely to be having problems.

You've been doing this long enough to know that to restore snow operations, you need to check all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you ("the sky") and why your map looks mostly blank ("you sure ask a lot of questions") and hang on did you just say the sky ("of course, where do you think snow comes from") when you realize that the Elves are already loading you into a trebuchet ("please hold still, we need to strap you in").

As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a very young Elf who was apparently just excited to show off her art skills. Consequently, the Elves are having trouble reading the values on the document.

The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?
int main() {
    fstream new_file;

    // open a file to perform read operation using file object.
    new_file.open("day1_Trebuchet.txt", ios::in);
    int res = 0;
    // Checking whether the file is open.
    if (new_file.is_open()) {
        string sa;
        // Read data from the file object and put it into a string.
        while (getline(new_file, sa)) {
            // Print the data of the string.
            int first = -1;
            int last = -1;
            for (int i = 0; i < sa.size(); i++) {
                if (int(sa[i]) >= 48 && int(sa[i]) <= 57) {
                    if (first == -1) first = stoi(sa.substr(i, 1));
                    else last = stoi(sa.substr(i, 1));
                }
            }
            if (last != -1) res = res + first * 10 + last;
            else if (first != -1) res = res + first * 10 + first;
        }

        // Close the file object.
        new_file.close();
    }
    cout << res << endl;
    return 0;
}
*/

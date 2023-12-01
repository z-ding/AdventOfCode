
using namespace std;
/*
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

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input1("file1.txt");
    ifstream input2("file2.txt");
    ofstream output("output.txt");

    string line1, line2;

    // Read initial lines from both files
    getline(input1, line1);
    getline(input2, line2);

    // Merge files based on the key field
    while (!input1.eof() && !input2.eof()) {
        string key1 = line1.substr(0, line1.find(' ')); // Assuming space-separated key field
        string key2 = line2.substr(0, line2.find(' '));

        if (key1 < key2) {
            output << line1 << endl;
            getline(input1, line1);
        }
        else {
            output << line2 << endl;
            getline(input2, line2);
        }
    }

    // Write remaining lines from input1
    while (!input1.eof()) {
        output << line1 << endl;
        getline(input1, line1);
    }

    // Write remaining lines from input2
    while (!input2.eof()) {
        output << line2 << endl;
        getline(input2, line2);
    }

    // Close file streams
    input1.close();
    input2.close();
    output.close();

    cout << "Files merged successfully." << endl;

    return 0;
}

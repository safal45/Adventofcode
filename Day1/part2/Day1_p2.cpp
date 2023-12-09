#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> input;

    ifstream file("input_p2.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            vector<string> digits;
            for (size_t i = 0; i < numbers.size(); ++i) {
                digits.push_back(numbers[i][0] + to_string(i + 1) + numbers[i].back());
            }

            for (size_t index = 0; index < numbers.size(); ++index) {
                size_t found = line.find(numbers[index]);
                while (found != string::npos) {
                    line.replace(found, numbers[index].length(), digits[index]);
                    found = line.find(numbers[index], found + 1);
                }
            }

            int x = -1, y = -1;

            for (char i : line) {
                if (isdigit(i)) {
                    if (x == -1) {
                        x = i - '0';
                    }
                    y = i - '0';
                }
            }

            int mus = x * 10 + y;
            cout << mus << endl;
        }
        file.close();
    }

    return 0;
}

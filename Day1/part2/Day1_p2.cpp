// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// int main() {
//     ifstream inputFile("input_p2.txt");
//     int ans = 0;

//     if (!inputFile.is_open()) {
//         cerr << "Error opening the file!" << endl;
//         return 1;
//     }
     
//     // Read inputs until the end of the file is reached
//     while (!inputFile.eof()) {
//         string s;
//         inputFile >> s;
       

//         // Check if reading was successful
//         if (!inputFile.fail()) {
            
            
//         }
        
//     }
//     cout << ans << endl;

//     inputFile.close();

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int partTwo(const std::vector<std::string>& text) {
    int mus = 0;
    std::vector<std::string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> digits;
    for (size_t i = 0; i < numbers.size(); ++i) {
        digits.push_back(numbers[i][0] + std::to_string(i + 1) + numbers[i].back());
    }

    for (const std::string& line : text) {
        std::string modifiedLine = line;
        for (size_t index = 0; index < numbers.size(); ++index) {
            size_t found = modifiedLine.find(numbers[index]);
            while (found != std::string::npos) {
                modifiedLine.replace(found, numbers[index].length(), digits[index]);
                found = modifiedLine.find(numbers[index], found + 1);
            }
        }

        int x = -1, y = -1;

        for (char i : modifiedLine) {
            if (std::isdigit(i)) {
                if (x == -1) {
                    x = i - '0';
                }
                y = i - '0';
            }
        }

        mus += x * 10 + y;
    }

    return mus;
}

int main() {
    std::vector<std::string> input;

    std::ifstream file("input_p2.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            input.push_back(line);
        }
        file.close();
    }

    std::cout << partTwo(input) << std::endl;

    return 0;
}

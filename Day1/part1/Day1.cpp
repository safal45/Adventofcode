#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input_1.txt");
    int ans = 0;

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
     
    // Read inputs until the end of the file is reached
    while (!inputFile.eof()) {
        string s;
        inputFile >> s;
       

        // Check if reading was successful
        if (!inputFile.fail()) {
            // Find the first and last digits in the string
            char firstDigit = '\0';
            char lastDigit = '\0';

            for (char c : s) {
                if (isdigit(c)) {
                    if (firstDigit == '\0') {
                        firstDigit = c;
                    }
                    lastDigit = c;
                }
            }

            // Convert the found digits to integers
            if (firstDigit != '\0' && lastDigit != '\0') {
                int firstNumber = firstDigit - '0';
                int lastNumber = lastDigit - '0';

                int temp_ans = firstNumber * 10 + lastNumber;
                ans = ans + temp_ans;
                
            }
           
        }
        
    }
    cout << ans << endl;

    inputFile.close();

    return 0;
}

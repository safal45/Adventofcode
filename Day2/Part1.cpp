#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Game {
    vector<int> red, green, blue;
};

bool isPossible(const Game& game, int redCount, int greenCount, int blueCount) {
    int maxRed = 0, maxGreen = 0, maxBlue = 0;

    for (int count : game.red) {
        maxRed = max(maxRed, count);
    }

    for (int count : game.green) {
        maxGreen = max(maxGreen, count);
    }

    for (int count : game.blue) {
        maxBlue = max(maxBlue, count);
    }

    return maxRed <= redCount && maxGreen <= greenCount && maxBlue <= blueCount;
}

int main() {
    ifstream inputFile("Input_1.txt");
    vector<Game> games;
    int redCount = 12, greenCount = 13, blueCount = 14;

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string gameData;

        Game game;
        while (getline(ss, gameData, ';')) {
            stringstream subsetStream(gameData);
            int count;

            while (subsetStream >> count) {
                char color;
                subsetStream >> color;

                if (color == 'r' || color == 'R') {
                    game.red.push_back(count);
                } else if (color == 'g' || color == 'G') {
                    game.green.push_back(count);
                } else if (color == 'b' || color == 'B') {
                    game.blue.push_back(count);
                }

                if (subsetStream.peek() == ',') {
                    subsetStream.ignore();
                }
            }
        }

        games.push_back(game);
    }

    inputFile.close();

    int possibleGamesSum = 0;

    for (size_t i = 0; i < games.size(); ++i) {
    if (isPossible(games[i], redCount, greenCount, blueCount)) {
        possibleGamesSum += (i + 1);
    }
}


    cout << "Sum of IDs of possible games: " << possibleGamesSum << endl;

    return 0;
}

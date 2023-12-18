#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include<numeric>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<char>> sch;
    while (std::getline(file, line)) {
        std::vector<char> row(line.begin(), line.end());
        sch.push_back(row);
    }
    file.close();

    std::vector<std::vector<std::pair<int, int>>> numCoords;
    for (size_t i = 0; i < sch.size(); ++i) {
        std::vector<std::pair<int, int>> num;
        for (size_t j = 0; j < sch[i].size(); ++j) {
            if (!isdigit(sch[i][j]) && !num.empty()) {
                numCoords.push_back(num);
                num.clear();
            }
            if (isdigit(sch[i][j])) {
                num.push_back({static_cast<int>(i), static_cast<int>(j)});
            }
        }
        if (!num.empty()) {
            numCoords.push_back(num);
        }
    }

    int ans2 = 0;

    for (const auto& gear : numCoords) {
        std::vector<int> adjNums;
        for (const auto& coord : gear) {
            std::vector<std::pair<int, int>> adj = {
                {coord.first - 1, coord.second - 1}, {coord.first - 1, coord.second},
                {coord.first - 1, coord.second + 1}, {coord.first, coord.second - 1},
                {coord.first, coord.second + 1}, {coord.first + 1, coord.second - 1},
                {coord.first + 1, coord.second}, {coord.first + 1, coord.second + 1}
            };
            for (const auto& num : numCoords) {
                if (std::any_of(adj.begin(), adj.end(), [&num](const auto& adjCoord) {
                        return std::find(num.begin(), num.end(), adjCoord) != num.end();
                    })) {
                    adjNums.push_back(std::stoi(std::string(num.begin(), num.end())));
                }
            }
        }
        if (adjNums.size() == 2) {
            ans2 += std::accumulate(adjNums.begin(), adjNums.end(), 1, std::multiplies<>());
        }
    }

    std::cout << ans2 << std::endl;

    return 0;
}

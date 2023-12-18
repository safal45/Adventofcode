#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

bool checkAdj(int r, int c, const std::vector<std::vector<char>>& schematic) {
    std::vector<std::pair<int, int>> adj = {
        {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}
    };

    for (const auto& adjPair : adj) {
        int rr = adjPair.first;
        int cc = adjPair.second;
        if (0 <= rr + r && rr + r < schematic.size() &&
            0 <= cc + c && cc + c < schematic[0].size()) {
            if (schematic[rr + r][cc + c] != '.' && !isdigit(schematic[rr + r][cc + c])) {
                return true;
            }
        }
    }
    return false;
}

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

    int ans = 0;

    for (const auto& num : numCoords) {
        if (std::any_of(num.begin(), num.end(), [&sch](const auto& coord) {
                return checkAdj(coord.first, coord.second, sch);
            })) {
            ans += std::stoi(std::string(num.begin(), num.end()));
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

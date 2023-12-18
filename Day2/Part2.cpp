#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include<fstream>

std::unordered_map<std::string, int> MAX = {
    {"red", 12},
    {"green", 13},
    {"blue", 14}
};



int part_two(std::unordered_map<std::string, std::vector<std::vector<std::pair<int, std::string>>>>& data) {
    int mus = 0;
    for (const auto& kv : data) {
        std::unordered_map<std::string, int> minimum = {
            {"red", 0},
            {"green", 0},
            {"blue", 0}
        };

        for (const auto& subset : kv.second) {
            for (const auto& color : subset) {
                minimum[color.second] = std::max(minimum[color.second], color.first);
            }
        }

        mus += minimum["red"] * minimum["green"] * minimum["blue"];
    }
    return mus;
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, std::vector<std::vector<std::pair<int, std::string>>>> data;

    std::string line;
    while (std::getline(file, line)) {
        size_t colon = line.find(":");
        std::string key = line.substr(0, colon);
        std::string value_str = line.substr(colon + 1);
        
        std::vector<std::vector<std::pair<int, std::string>>> new_value;
        size_t semicolon_pos = 0;
        while ((semicolon_pos = value_str.find(";")) != std::string::npos) {
            std::string subset_str = value_str.substr(0, semicolon_pos);
            value_str.erase(0, semicolon_pos + 1);

            std::vector<std::pair<int, std::string>> games;
            size_t comma_pos = 0;
            while ((comma_pos = subset_str.find(",")) != std::string::npos) {
                std::string each_str = subset_str.substr(0, comma_pos);
                subset_str.erase(0, comma_pos + 1);

                size_t space_pos = each_str.find(" ");
                int x = std::stoi(each_str.substr(0, space_pos));
                std::string y = each_str.substr(space_pos + 1);
                games.push_back(std::make_pair(x, y));
            }

            new_value.push_back(games);
        }

        data[key] = new_value;
    }

    file.close();

    // std::cout << part_one(data) << std::endl;
    std::cout << part_two(data) << std::endl;

    return 0;
}

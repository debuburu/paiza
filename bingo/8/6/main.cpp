#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

int main() {
    std::string a_list_input, b_list_input;
    std::getline(std::cin, a_list_input);
    std::getline(std::cin, b_list_input);

    std::istringstream a_list_ss(a_list_input);
    std::unordered_set<std::string> a_list;
    std::string num;
    while (a_list_ss >> num) {
        a_list.insert(num);
    }
    sort(num);

    std::istringstream b_list_ss(b_list_input);
    bool found = true;
    while (b_list_ss >> num) {
        if (a_list.find(num) == a_list.end()) {
            found = false;
            break;
        }
    }

    if (found) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
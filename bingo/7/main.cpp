#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string S, T;
    std::cin >> S >> T;
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    if (S.length() == n && T.length() == n && S == T) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
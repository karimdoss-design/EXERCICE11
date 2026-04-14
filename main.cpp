#include <iostream>
#include <string>
#include <stdexcept>
#include "utils.hpp"

int main() {
    std::string email;

    while (true) {
        std::cout << "Enter your email address: ";
        std::cin >> email;

        try {
            check_email(email);
            std::cout << "Valid email entered.\n";
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
            std::cout << "Please try again.\n";
        }
    }

    return 0;
}

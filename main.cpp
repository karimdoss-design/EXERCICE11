#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

#include "utils.hpp"

int main() {
    std::map<std::string, std::string> users;
    int choice = -1;
    bool logged_in = false;

    while (choice != 0) {
        std::cout << "1. Sign up\n";
        std::cout << "2. Login\n";

        if (logged_in) {
            std::cout << "3. Logout\n";
        }

        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1 && !logged_in) {
            std::string email;
            std::string password;

            std::cout << "Enter email: ";
            std::cin >> email;

            try {
                check_email(email);
                std::cout << "Enter password: ";
                std::cin >> password;
                users[email] = password;
                std::cout << "Sign up successful\n";
            } catch (std::invalid_argument& e) {
                std::cout << e.what() << "\n";
            }
        } else if (choice == 2 && !logged_in) {
            std::string email;
            std::string password;

            std::cout << "Enter email: ";
            std::cin >> email;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (users.find(email) != users.end() && users[email] == password) {
                logged_in = true;
                std::cout << "Login successful\n";
            } else {
                std::cout << "Invalid email or password\n";
            }
        } else if (choice == 3 && logged_in) {
            logged_in = false;
            std::cout << "Logout successful\n";
        } else if (choice != 0) {
            std::cout << "Invalid choice\n";
        }

        std::cout << "\n";
    }

    return 0;
}

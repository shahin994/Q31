#include <iostream>
#include <vector>

// Function to validate the first 4 digits of the card number
bool validateCardPrefix(std::string cardNumber) {
    std::vector<std::string> validPrefixes = {"1234", "5678", "9876"};

    for (const std::string& prefix : validPrefixes) {
        if (cardNumber.find(prefix) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string cardNumber;
    std::vector<int> cardArray;
    
    while (cardArray.size() < 16) {
        std::cout << "Enter a digit for the card number: ";
        int digit;
        std::cin >> digit;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid digit." << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        }

        cardArray.push_back(digit);

        // Display entered digits
        std::cout << "Entered card number digits: ";
        for (int num : cardArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Validate first 4 digits
        if (cardArray.size() >= 4) {
            std::string prefix;
            for (int i = 0; i < 4; i++) {
                prefix += std::to_string(cardArray[i]);
            }
            if (!validateCardPrefix(prefix)) {
                std::cout << "Invalid card number prefix. Please try again." << std::endl;
                cardArray.clear();
            }
        }
    }

    std::cout << "Card number input completed. Thank you!" << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "inputValidation.h"
#include "contact.h"

bool nameValidation(std::string full_name) {
    std::vector<Contact> allContacts = displayAllContacts(); 
    if (full_name.length() == 0 || full_name.length() > 30) {
        std::cout << "Name shouldn't be empty or more than 30 characters\n";
        return false;
    }
    for (char c : full_name) {
        if (!std::isalpha(c) && c != ' ') {
            std::cout << "Name should only have letters or spaces in it\n";
            std::cout << c << "\n";
            return false;
        }
    }
    for (Contact contact : allContacts) {
        if (strcasecmp(contact.getName().c_str(), full_name.c_str()) == 0) {
            std::cout << "Name can't be the same as a name already entered onto the app\n";
            return false;
        }
    }
    return true;
}

bool phoneValidation(std::string phone_number) {
    if (phone_number[0] != '0') {
        std::cout << "Phone number should start with 0\n";
        return false;
    }
    if (phone_number.length() != 11) {
        std::cout << "Phone number is the incorrect length\n";
        return false;
    }
    for (char c : phone_number) {
        if (!std::isdigit(c)) {
            std::cout << "Phone number should only have integers in it\n";
            return false;
        }
    }
    return true;
}
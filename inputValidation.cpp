#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "inputValidation.hpp"
#include "contact.hpp"

bool nameValidation(std::string full_name) {
    std::vector<Contact> allContacts = displayAllContacts(); 
    if (full_name.length() == 0 || full_name.length() > 30) {
        std::cout << "Name shouldn't be empty or more than 30 characters\n";
        return false;
    }
    for (char c : full_name) {
        if (!std::isalpha(c) && c != ' ') {
            std::cout << "Name should only have letters or spaces in it\n";
            return false;
        }
    }
    for (Contact contact : allContacts) {
        if (strncasecmp(contact.getName().c_str(), full_name.c_str(), 30) == 0) {
            std::cout << "Name can't be the same as a name already entered onto the app\n";
            return false;
        }
    }
    return true;
}

bool phoneValidation(std::string phone_number) {
    std::vector<Contact> allContacts = displayAllContacts();
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
    for (Contact contact : allContacts) {
        if (strncasecmp(contact.getNumber().c_str(), phone_number.c_str(), 11) == 0) {
            std::cout << "Name can't be the same as a name already entered onto the app\n";
            return false;
        }
    }
    return true;
}

bool addressValidation(std::string address) {
    if (address.length() == 0 || address.length() > 40) {
        std::cout << "Address length should be between 0 and 40 characters\n";
        return false;
    }
    for (char c : address) {
        if (!std::isalpha(c) && !std::isdigit(c) && c!=' ') {
            std::cout << "Address should only contain letters and numbers\n";
            return false;
        }
    }
    return true;
}

bool postcodeValidation(std::string postcode) {
    if (postcode.length()<5 || postcode.length()>7) {
        std::cout << "Postcode should be between 5 and 7 characters\n";
        return false;
    }
    for (char c : postcode) {
        if (!std::isalpha(c) && !std::isdigit(c)) {
            std::cout << "Postcode should only contain letters and numbers\n";
            return false;
        }
    }
    return true;
}
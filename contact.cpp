#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
#include "contact.h"

Contact::Contact(std::string full_name, std::string phone_number) {
    this->full_name = full_name;
    this->phone_number = phone_number;
}

Contact::Contact() {
}

void Contact::setName(std::string full_name) {
    this->full_name = full_name;
}

void Contact::setNumber(std::string phone_number) {
    this->phone_number = phone_number;
}

std::string Contact::getName() {
    return full_name;
}

std::string Contact::getNumber() {
    return phone_number;
}

void addContactToFile(std::string name, std::string number) {
    std::ofstream name_file;
    std::ofstream phone_file;
    name_file.open("names.txt", std::ios::app);
    name_file << name << std::endl;
    name_file.close();
    phone_file.open("phones.txt", std::ios::app);
    phone_file << number << std::endl;
    phone_file.close();
}

std::vector<Contact> displayAllContacts() {
    std::string input;
    std::string num_input;
    std::ifstream name_file("names.txt");
    std::ifstream phone_file("phones.txt");
    std::vector<Contact> contactDetails;
    std::vector<std::string> names;
    std::vector<std::string> numbers;
    if (name_file.is_open()) {
        while(name_file >> input) {
            names.push_back(input);
        }
    }
    else
        std::cout << "No contacts present.\n";
    if (phone_file.is_open()) {
        while (phone_file >> num_input){
            numbers.push_back(num_input);
        }
    }
    for (int x=0; x<names.size(); x++) {
        Contact contact(names[x], numbers[x]);
        contactDetails.push_back(contact);
    }
    return contactDetails;
}

Contact displaySpecificContact(std::string full_name) {
    std::vector<Contact> allContacts = displayAllContacts();
    for (Contact contact : allContacts) {
        if (strcasecmp(contact.getName().c_str(), full_name.c_str()) == 0) {
            return contact;
        }
    }
    Contact contact;
    return contact;
}

void deleteContact(std::string full_name) {
    std::ofstream name_file;
    std::ofstream phone_file;
    std::vector<Contact> allContacts = displayAllContacts();
    for (int x=0; x<allContacts.size(); x++) {
        if (strcasecmp(allContacts[x].getName().c_str(), full_name.c_str()) == 0) {
            allContacts.erase(allContacts.begin() + x);
            break;
        }
    }
    name_file.open("names.txt");
    phone_file.open("phones.txt");
    for (Contact contact : allContacts) {
        name_file << contact.getName() << std::endl;
        phone_file << contact.getNumber() << std::endl;
    }
    name_file.close();
    phone_file.close();
}

void changeEditedContact(std::string changedDetail, std::string oldName, bool editName) {
    std::ofstream name_file;
    std::ofstream phone_file;
    std::vector<Contact> allContacts = displayAllContacts();
    for (int x=0; x<allContacts.size(); x++) {
        if (strcasecmp(allContacts[x].getName().c_str(), oldName.c_str()) == 0) {
            editName ? allContacts[x].setName(changedDetail) : allContacts[x].setNumber(changedDetail);
            break;
        }
    }
    name_file.open("names.txt");
    phone_file.open("phones.txt");
    for (Contact contact : allContacts) {
        name_file << contact.getName() << std::endl;
        phone_file << contact.getNumber() << std::endl;
    }
    name_file.close();
    phone_file.close();
}
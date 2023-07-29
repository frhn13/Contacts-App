#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
#include "contact.h"

Contact::Contact(std::string full_name, std::string phone_number, std::string address, std::string postcode) {
    this->full_name = full_name;
    this->phone_number = phone_number;
    this->address = address;
    this->postcode = postcode;
}

Contact::Contact() {
}

void Contact::setName(std::string full_name) {
    this->full_name = full_name;
}

void Contact::setNumber(std::string phone_number) {
    this->phone_number = phone_number;
}

void Contact::setAddress(std::string address) {
    this->full_name = address;
}

void Contact::setPostcode(std::string postcode) {
    this->postcode = postcode;
}

std::string Contact::getName() {
    return full_name;
}

std::string Contact::getNumber() {
    return phone_number;
}

std::string Contact::getAddress() {
    return address;
}

std::string Contact::getPostcode() {
    return postcode;
}

void addContactToFile(std::string name, std::string number, std::string address, std::string postcode) {
    std::ofstream name_file;
    std::ofstream phone_file;
    std::ofstream address_file;
    std::ofstream postcode_file;
    name_file.open("names.txt", std::ios::app);
    name_file << name << std::endl;
    name_file.close();
    phone_file.open("phones.txt", std::ios::app);
    phone_file << number << std::endl;
    phone_file.close();
    address_file.open("addresses.txt", std::ios::app);
    address_file << address << std::endl;
    address_file.close();
    postcode_file.open("postcodes.txt", std::ios::app);
    postcode_file << postcode << std::endl;
    postcode_file.close();
}

std::vector<Contact> displayAllContacts() {
    std::string name_input;
    std::string num_input;
    std::string address_input;
    std::string postcode_input;
    std::ifstream name_file("names.txt");
    std::ifstream phone_file("phones.txt");
    std::ifstream address_file("addresses.txt");
    std::ifstream postcode_file("postcodes.txt");
    std::vector<Contact> contactDetails;
    std::vector<std::string> names;
    std::vector<std::string> numbers;
    std::vector<std::string> addresses;
    std::vector<std::string> postcodes;
    if (name_file.is_open()) {
        while(name_file >> name_input) {
            names.push_back(name_input);
        }
    }
    else
        std::cout << "No contacts present.\n";
    if (phone_file.is_open()) {
        while (phone_file >> num_input){
            numbers.push_back(num_input);
        }
    }
    if (address_file.is_open()) {
        while (address_file >> address_input){
            addresses.push_back(address_input);
        }
    }
    if (postcode_file.is_open()) {
        while (postcode_file >> postcode_input){
            postcodes.push_back(postcode_input);
        }
    }
    for (int x=0; x<names.size(); x++) {
        Contact contact(names[x], numbers[x], addresses[x], postcodes[x]);
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
    std::ofstream address_file;
    std::ofstream postcode_file;
    std::vector<Contact> allContacts = displayAllContacts();
    for (int x=0; x<allContacts.size(); x++) {
        if (strcasecmp(allContacts[x].getName().c_str(), full_name.c_str()) == 0) {
            allContacts.erase(allContacts.begin() + x);
            break;
        }
    }
    name_file.open("names.txt");
    phone_file.open("phones.txt");
    address_file.open("addresses.txt");
    postcode_file.open("postcodes.txt");
    for (Contact contact : allContacts) {
        name_file << contact.getName() << std::endl;
        phone_file << contact.getNumber() << std::endl;
        address_file << contact.getAddress() << std::endl;
        postcode_file << contact.getPostcode() << std::endl;
    }
    name_file.close();
    phone_file.close();
    address_file.close();
    postcode_file.close();
}

void changeEditedContact(std::string changedDetail, std::string oldName, int whatToEdit) {
    std::ofstream name_file;
    std::ofstream phone_file;
    std::ofstream address_file;
    std::ofstream postcode_file;
    std::vector<Contact> allContacts = displayAllContacts();
    for (int x=0; x<allContacts.size(); x++) {
        if (strcasecmp(allContacts[x].getName().c_str(), oldName.c_str()) == 0) {
            switch(whatToEdit) {
                case 1:
                    allContacts[x].setName(changedDetail);
                    break;
                case 2:
                    allContacts[x].setNumber(changedDetail);
                    break;
                case 3:
                    allContacts[x].setAddress(changedDetail);
                    break;
                case 4:
                    allContacts[x].setPostcode(changedDetail);
                    break;
                default:
                    break;
            }
            break;
        }
    }
    name_file.open("names.txt");
    phone_file.open("phones.txt");
    address_file.open("addresses.txt");
    postcode_file.open("postcodes.txt");
    for (Contact contact : allContacts) {
        name_file << contact.getName() << std::endl;
        phone_file << contact.getNumber() << std::endl;
        address_file << contact.getAddress() << std::endl;
        postcode_file << contact.getPostcode() << std::endl;
    }
    name_file.close();
    phone_file.close();
    address_file.close();
    postcode_file.close();
}
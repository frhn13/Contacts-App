#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>
#include "contact.hpp"

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

bool addContactToFile(std::string name, std::string number, std::string address, std::string postcode) {
    std::ofstream contacts_file("contacts.csv", std::ios::app);
    if (!contacts_file.is_open())
        return false;
    contacts_file << name << "," << number << "," << address << "," << postcode << "\n";
    contacts_file.close();
    return true;
}

std::vector<Contact> displayAllContacts() {
    std::string contact_line;
    std::ifstream contacts_file("contacts.csv");
    std::vector<Contact> contactDetails;

    if (!contacts_file.is_open()) {
        Contact contact;
        contactDetails.push_back(contact);
        return contactDetails;
    }

    while(std::getline(contacts_file, contact_line)) {
        std::stringstream stringstream(contact_line);
        std::string name_input, num_input, address_input, postcode_input;
        std::getline(stringstream, name_input, ',');
        std::getline(stringstream, num_input, ',');
        std::getline(stringstream, address_input, ',');
        std::getline(stringstream, postcode_input, '\n');
        contactDetails.push_back(Contact(name_input, num_input, address_input, postcode_input));
    }
    contacts_file.close();
    return contactDetails;
}

Contact displaySpecificContact(std::string full_name) {
    std::vector<Contact> allContacts = displayAllContacts();
    if (allContacts.empty() == false && allContacts[0].getName() == "") {
        return Contact("Invalid", "", "", "");
    }
    for (Contact contact : allContacts) {
        if (strncasecmp(contact.getName().c_str(), full_name.c_str(), 30) == 0) {
            return contact;
        }
    }
    Contact contact;
    return contact;
}

std::string deleteContact(std::string full_name) {
    std::string contact_status = "ContactNotFound";
    std::vector<Contact> allContacts = displayAllContacts();
    if (allContacts.empty() == false && allContacts[0].getName() == "")
        return "NoFile";
    
    for (int x=0; x<allContacts.size(); x++) {
        if (strncasecmp(allContacts[x].getName().c_str(), full_name.c_str(), 30) == 0) {
            allContacts.erase(allContacts.begin() + x);
            contact_status = "ContactFound";
            break;
        }
    }
    if (contact_status == "ContactNotFound")
        return contact_status;

    std::ofstream contacts_file("contacts.csv");
    if (!contacts_file) {
        contact_status = "NoFile";
        return contact_status;
    }
    for (Contact contact : allContacts)
        contacts_file << contact.getName() << "," << contact.getNumber() << "," 
        << contact.getAddress() << "," << contact.getPostcode() << "\n";
    contacts_file.close();
    return contact_status;
}

bool changeEditedContact(std::string changedDetail, std::string oldName, int whatToEdit) {
    std::vector<Contact> allContacts = displayAllContacts();
    if (allContacts.empty() == false && allContacts[0].getName() == "")
        return false;
    std::ofstream contacts_file("contacts.csv");
    for (int x=0; x<allContacts.size(); x++) {
        if (strncasecmp(allContacts[x].getName().c_str(), oldName.c_str(), 30) == 0) {
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

    if (!contacts_file) {
        return false;
    }
    for (Contact contact : allContacts)
        contacts_file << contact.getName() << "," << contact.getNumber() << "," 
        << contact.getAddress() << "," << contact.getPostcode() << "\n";
    contacts_file.close();
    return true;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <sstream>
#include "contact.h"
#include "inputValidation.h"

int main() {
    int choice;
    std::string phone_number;
    std::string full_name;
    std::string address;
    std::string postcode;
    std::string new_name;
    std::string new_number;
    std::string new_address;
    std::string new_postcode;
    std::vector<Contact> allContacts;
    int contactNumber = 1;
    Contact specificContact;
    Contact contactToEdit;  
    bool nameValidated;
    bool phoneValidated;
    bool addressValidated;
    bool postcodeValidated;
    int whatToEdit;
    
    do {
        std::cout << "What would you like to do:\n";
        std::cout << "1: Display all contacts\n";
        std::cout << "2: Add a contact\n";
        std::cout << "3: Delete a contact\n";
        std::cout << "4: Search for a specific contact\n";
        std::cout << "5: Edit a specific contact\n";
        std::cout << "6: Leave the contacts app\n\n";
        std::cout << "Choose from 1-6: ";
        std::cin >> choice;
        fflush(stdin);

        switch(choice) {
            case 1:
                allContacts = displayAllContacts();
                contactNumber = 1;
                for (Contact contact : allContacts) {
                    std::cout << "Contact " << contactNumber << ":\n";
                    std::cout << "Full name: " << contact.getName() << "\n";
                    std::cout << "Phone Number: " << contact.getNumber() << "\n";
                    std::cout << "Address: " << contact.getAddress() << "\n";
                    std::cout << "Postcode: " << contact.getPostcode() << "\n\n";
                    contactNumber++;
                }
                break;

            case 2:
                do {
                    std::cout << "Enter their full name: ";
                    std::getline(std::cin >> std::ws, full_name);
                    nameValidated = nameValidation(full_name);
                } while (!nameValidated);
                do {
                    std::cout << "Enter their phone number without spaces: ";
                    std::cin >> phone_number;
                    phoneValidated = phoneValidation(phone_number);
                } while (!phoneValidated);
                do {
                    std::cout << "Enter their address: ";
                    std::getline(std::cin >> std::ws, address);
                    addressValidated = addressValidation(address);
                } while (!addressValidated);
                do {
                    std::cout << "Enter their postcode without spaces: ";
                    std::getline(std::cin >> std::ws, postcode);
                    postcodeValidated = postcodeValidation(postcode);
                } while (!postcodeValidated);
                addContactToFile(full_name, phone_number, address, postcode);
                break;

            case 3:
                std::cout << "Enter the name of the contact you want to delete: ";
                std::getline(std::cin >> std::ws, full_name);
                deleteContact(full_name);
                break;

            case 4:
                std::cout << "Enter the name of the contact you are looking for: ";
                std::getline(std::cin >> std::ws, full_name);
                specificContact = displaySpecificContact(full_name);
                if (specificContact.getName() != "") {
                    std::cout << "Contact Details:\n\n";
                    std::cout << "Their full name is: " << specificContact.getName() << "\n";
                    std::cout << "Their phone number is: " << specificContact.getNumber() << "\n";
                    std::cout << "Their address is: " << specificContact.getAddress() << "\n";
                    std::cout << "Their postcode is: " << specificContact.getPostcode() << "\n\n";
                }
                else
                    std::cout << "That contact doesn't exist.\n\n";
                break;

            case 5:
                std::cout << "Enter the full name of the contact you want to edit: ";
                std::getline(std::cin >> std::ws, full_name);
                contactToEdit = displaySpecificContact(full_name);
                if (contactToEdit.getName() != "") {
                    std::cout << "Do you want to edit the name, phone number, address or postcode, answer with 1, 2, 3 or 4 respectively: ";
                    std::cin >> whatToEdit;
                    switch(whatToEdit) {
                        case 1:
                            do {
                                std::cout << "What would you like to change the name to: ";
                                std::getline(std::cin >> std::ws, new_name);
                                nameValidated = nameValidation(new_name);
                            } while (!nameValidated);
                            changeEditedContact(new_name, full_name, whatToEdit);
                            break;
                        case 2:
                            do {
                                std::cout << "What would you like to change your phone number to: ";
                                std::cin >> new_number;
                                phoneValidated = phoneValidation(new_number);
                            } while (!phoneValidated);
                            changeEditedContact(new_number, full_name, whatToEdit);
                            break;
                        case 3:
                            do {
                                std::cout << "What would you like to change your phone number to: ";
                                std::getline(std::cin >> std::ws, new_address);
                                addressValidated = addressValidation(new_address);
                            } while (!addressValidated);
                            changeEditedContact(new_address, full_name, whatToEdit);
                            break;
                        case 4:
                            do {
                                std::cout << "What would you like to change your phone number to: ";
                                std::cin >> new_postcode;
                                postcodeValidated = postcodeValidation(new_postcode);
                            } while (!postcodeValidated);
                            changeEditedContact(new_postcode, full_name, whatToEdit);
                            break;
                        default:
                            std::cout << "Input is invalid.\n\n";
                            break;
                    }
                }
                else
                    std::cout << "That contact doesn't exist\n\n";
                break;

            case 6:
                std::cout << "Goodbye.";
                break;

            default:
                std::cout << "\nInput was invalid, please try again\n\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
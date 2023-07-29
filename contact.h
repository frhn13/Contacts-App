#ifndef CONTACT
#define CONTACT

class Contact {
    private:
        std::string full_name;
        std::string phone_number;
        std::string postcode;
        std::string address;
    public:
    Contact(std::string full_name, std::string phone_number, std::string address, std::string postcode);
    Contact();
    void setName(std::string full_name);
    void setNumber(std::string phone_number);
    void setAddress(std::string address);
    void setPostcode(std::string postcode);
    std::string getName();
    std::string getNumber();
    std::string getAddress();
    std::string getPostcode();
};

void addContactToFile(std::string name, std::string number, std::string address, std::string postcode);
std::vector<Contact> displayAllContacts();
Contact displaySpecificContact(std::string full_name);
bool deleteContact(std::string full_name);
void changeEditedContact(std::string changed_detail, std::string oldName, int whatToEdit);

#endif
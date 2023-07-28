#ifndef CONTACT
#define CONTACT

class Contact {
    private:
        std::string full_name;
        std::string phone_number;
    public:
    Contact(std::string full_name, std::string phone_number);
    Contact();
    void setName(std::string full_name);
    void setNumber(std::string phone_number);
    std::string getName();
    std::string getNumber();
};

void addContactToFile(std::string name, std::string number);
std::vector<Contact> displayAllContacts();
Contact displaySpecificContact(std::string full_name);
void deleteContact(std::string full_name);
void changeEditedContact(std::string changed_detail, std::string oldName, bool editName);

#endif
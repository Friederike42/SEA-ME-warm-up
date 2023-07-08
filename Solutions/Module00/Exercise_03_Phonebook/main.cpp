#include "contact.hpp"
#include "converter.hpp"
#include <vector>

/*Adds and Removes Contacts to a phonebook list and provides additional capability for bookmarks and search.
You find the exercise description in Modules\Module00 folder
The main() method is the main entry point of the program.*/

void print(vector<Contact> contacts)
{
    cout << "List of contacts" << endl;
    int count = 0;
    for (vector<Contact>::iterator i = contacts.begin(); i != contacts.end(); ++i)
    {
        cout << endl << count << "--------------\n" << (*i).to_string();
    }
    cout << endl;
}

string ask_for_user_input(string ask)
{
    string user_input;
    cout << ask << endl;
    cin >> user_input;
    if (user_input != "EXIT")
    {
        return user_input;
    }
    else
    {
        exit(0);
    }
}

Contact* search_contact(vector<Contact> contacts, string index_of_contact)
{

    //Contact found_contact("", "", "");
    int index = stoi(index_of_contact);
    cout << "size: " << contacts.size();
    if (index >= 0 && index < contacts.size())
    {
        Contact *found_contact = &contacts[index];
        return found_contact;
    }
    return nullptr;
}

bool is_valid_phone_number(string phone_number, vector<Contact> contacts)
{
    if(phone_number.length() == 0)
        return false;

    return true;
}

void add_contact(vector<Contact> contacts)
{
    string name, phone_number, nick_name;
    cout << "Type in name, phone number (must be unique) and nick name of the contact. \n Name: ";
    cin.ignore(100, '\n');
    getline(cin, name);
    cout << " Phone Number: ";
    getline(cin, phone_number);
    cout << " Nick name: ";
    getline(cin, nick_name);

    if (is_valid_phone_number(phone_number, contacts))
    {
        Contact new_contact(name, phone_number, nick_name);
        contacts.push_back(new_contact);
    }
    else
    {
        cout << "Phone number" << phone_number << " is not a valid phone number. The new contact was not added. Phone number must be unique in all existing contacts and non-empty. Show all contacts by typing <SEARCH>";
    }
}

int main(int argc, char **argv)
{
    Converter converter;
    vector<Contact> contacts;

    cout << "Choose one of the Phonebook options <ADD/REMOVE/SEARCH/BOOKMARK> by typing it into the console. You can type <EXIT> anywhere to close the Phonebook: \n";
    string command;
    cin >> command;
    command = converter.convert("up", command);

    while (command != "EXIT")
    {

        // for searching in contacts
        string user_input;

        if(command == "ADD"){
            add_contact(contacts);  // Todo: this is a problematic call. Likely the contacts is having a scope issue (need to pass by reference or sth?)
        }else if(command == "REMOVE"){
            ask_for_user_input("Remove a contact with an index or phone number. Type Index or phone number:");
            // remove(contacts, number);
        }else if(command == "SEARCH"){
            print(contacts);
            string index;
            index = ask_for_user_input("Enter a contact number to display its details");
            
            Contact* found_contact = search_contact(contacts, index);
            if (found_contact){
                Contact my_contact = *found_contact;
                string test = my_contact.to_string();
                cout << test;
            }
        }else if(command == "BOOKMARK"){

        }
        cin >> command;
        command = converter.convert("up", command);
    }
    return 0;
}

void exit(int success)
{
    exit(success);
}

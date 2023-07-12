#include "contact.hpp"
#include "converter.hpp"
#include <vector>

/*Adds and Removes Contacts to a phonebook list and provides additional capability for bookmarks and search.
You find the exercise description in Modules\Module00 folder
The main() method is the main entry point of the program.*/

vector<Contact> contacts;

void print(vector<Contact> contacts);
string ask_for_user_input(string ask);
Contact* search_contact(string index_of_contract);
Contact *search_contact_by_phone(string phone_number);
vector<Contact> filter_contacts_by_bookmark(bool is_bookmarked);
bool is_valid_phone_number(string phone_number);
bool string_to_bool(string to_convert);
Contact create_contact();
void erase_by_phone_number(string phone_number);

int main()
{
    Converter converter;

    cout << "Choose one of the Phonebook options <ADD/REMOVE/SEARCH/BOOKMARK> by typing it into the console. You can type <EXIT> anywhere to close the Phonebook: \n";
    string command;
    cin >> command;
    command = converter.convert("up", command);

    while (command != "EXIT")
    {

        // for searching in contacts
        string user_input;
        if(command == "ADD"){
            contacts.push_back(create_contact());

            print(contacts);
        }else if(command == "REMOVE"){
            string user_input = ask_for_user_input("Remove a contact with a contact number or phone number. Type a contact number (default) or use a preceding #in front of a phone number to indicate you want to remove by phone number: ");
            if(user_input[0] != '#' && stoi(user_input) < contacts.size())
            { // this code will fail if user types sth like '#' instead of a digit; try catch for the stoi method?
                contacts.erase(contacts.begin() + stoi(user_input));
            }
            else if (user_input[0] == '#')
            {
                string phone_number = user_input.substr(1, user_input.size() - 1);
                erase_by_phone_number(phone_number);
            }
            print(contacts);
           
        }else if(command == "SEARCH"){
            print(contacts);
            string index = ask_for_user_input("Enter a contact number to display its details");
            cout << search_contact(index)->to_string() << endl;
            string bookmark = ask_for_user_input("Shall this contact be bookmarked? Type <0> for no, <1> for yes: ");
            contacts.at(stoi(index)).set_bookmark(string_to_bool(bookmark));
            print(contacts);
        }else if(command == "BOOKMARK"){
            vector<Contact> contacts_by_bookmark = filter_contacts_by_bookmark(true);
            print(contacts_by_bookmark);
        }
        cout << "Next, choose one of the Phonebook options <ADD/REMOVE/SEARCH/BOOKMARK> by typing it into the console. You can type <EXIT> anywhere to close the Phonebook: \n";
        cin >> command;
        command = converter.convert("up", command);
    }
    return 0;
}

void exit(int success)
{
    exit(success);
}

void print(vector<Contact> contacts)
{
    cout << "List of contacts" << endl;
    int count = 0;
    for (vector<Contact>::iterator i = contacts.begin(); i != contacts.end(); ++i)
    {
        cout << endl
             << count << "--------------\n"
             << (*i).to_string();
        count++;
    }
    cout << endl;
}

Contact create_contact()
{
    string name, phone_number, nick_name;
    cout << "Type in name, phone number (must be unique) and nick name of the contact. \n Name: ";
    cin.ignore(100, '\n');
    getline(cin, name);
    cout << " Phone Number: ";
    getline(cin, phone_number);

    while(!is_valid_phone_number(phone_number)){
        cout << "Is not a valid phone number. Please type in a phone number longer than 0 digits which is unique in the list of contacts. \n";
        getline(cin, phone_number);
    }

    cout << " Nick name: ";
    getline(cin, nick_name);

    Contact new_contact(name, phone_number, nick_name);
    return new_contact; //somehow code breaks here. Without error message??
   
}

string ask_for_user_input(string ask)
{
    cout << ask;
    string user_input;
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

Contact* search_contact(string index_of_contact)
{

    int index = stoi(index_of_contact);
    
    if (index >= 0 && index < contacts.size())
    {
        return &contacts[index];
    }
    return nullptr;
}

Contact* search_contact_by_phone(string phone_number)
{
    for (vector<Contact>::iterator i = contacts.begin(); i != contacts.end(); ++i)
    {
        if ((*i).get_phone_number() == phone_number)
        {
            return &(*i);
        }
    }
    return nullptr;
}

vector<Contact> filter_contacts_by_bookmark(bool is_bookmarked)
{
    vector<Contact> contacts_by_bookmark;
    for (Contact &c : contacts)
    {
        if (c.get_bookmark() == is_bookmarked)
        {
            contacts_by_bookmark.push_back(c);
        }
    }
    return contacts_by_bookmark;
}

bool is_valid_phone_number(string phone_number)
{
    if (phone_number.length() == 0)
        return false;
    else if (search_contact_by_phone(phone_number))
        return false;
    else
        return true;
}

void erase_by_phone_number(string phone_number)
{
    vector<Contact>::iterator j;
    for (vector<Contact>::iterator i = contacts.begin(); i != contacts.end(); ++i)
    {
        if ((*i).get_phone_number() == phone_number)
        {
            j = i;
        }
    }
    contacts.erase(j);
}

bool string_to_bool(string to_convert)
{
    if (to_convert.at(0) == '1')
        return true;
    else
        return false;
}

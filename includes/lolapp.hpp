#ifndef ILLINI_BOOK_HPP
#define ILLINI_BOOK_HPP

#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <pair>
#include <string>

#include "utilities.hpp"

class AccountApp {
public:
    AccountApp();
    /*
        If text file is not present, create a new empty one.
    */

    void Update();
    /*
        Access the accounts list stored within the txt file. If not present, create a new empty one.
        Update the account_list private variable.
        Update the app interface to represent the updated list.
    */
    
    void Add(std::string account_name, std::string account_id, std::string account_password);
    /*
        Take user input for account_name, account_id and account_password.
        If the txt file is not found, create a new one and add it.
        Add the new information to the accounts list txt file. 
        Run Update()
    */

    void Remove(std::string account_name);
    /*
        Take user input for account_name.
        Remove the account from the account list txt file.
        Run Update()
    */

    void Launch(std::string account_name);
    /*
        Close and sign out of all current instances of the riot client.
        Open riot client.
        Sign in with the information associated with the account_name.
    */
private:
    std::map<std::string, std::pair<std::string,std::string>> account_list;
    /*
        Private Variable containing data in the form of account name : [account_id, account_password]
    */

    std::string fpath = "account_list.txt";
    /*
        Private Variable containing a string of the file path used to acces the account_list document.
    */
};

#endif
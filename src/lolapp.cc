#include "illini_book.hpp"

AccountApp:AccountApp() {

    // If text file is not present, create a new empty one.

    fstream f;
    f.open(fpath);

    if (!f) {
        ofstream new_file(fpath);

        new_file.close();
    }

    else {
        f.close();

        Update();
    }
 
}

void AccountApp::Update() {

    // Access the accounts list stored within the txt file. If not present, create a new empty one.

    fstream f;
    f.open(fpath);
    if (!f) {
        ofstream new_file(fpath);

        new_file.close();
    }

    else {
        f.close();
    }    

    // Update the account_list private variable.

    std::ifstream account_file(fpath);

    std::map<std::string, std::pair<std::string, std::string>> updated_account_list;

    for (std::string line; std::getline(fpath, line);) {

        std::vector<std::string> vec = utilities::Split(line, ',');

        std::pair<std::string, std::string> data;
        data.first = vec[1];
        data.second = vec[2];

        updated_account_list[vec[0]] = data;
    }

    acount_list = updated_account_list;

    // Update the app interface to represent the updated list.
    // TODO
}

void AccountApp::Add() {

    // Take user input for account_name, account_id and account_password.
    std::string account_name = "replace later";
    std::string account_id = "replace later";
    std::string account_password = "replace later";

    // If the txt file is not found, create a new one and add it.

    fstream f;
    f.open(fpath);

    if (!f) {
        ofstream new_file(fpath);

        new_file.close();
    }

    // Add the new information to the accounts list txt file.

    else {
        f << account_name + "," + account_id + "," + account_password;
        f.close();
    }

    // Run Update()

    Update();
}

void Account::Remove() {
    
    //Take user input for account_name.

    std::string account_name = "replace later";

    //Remove the account from the account list txt file.

    int result = remove(fpath);

    ofstream new_file(fpath);

    for (auto index : account_list) {
        if (index.first != account_name) {
            new_file << index.first + "," + index.second.first + "," + index.second.second;
        }
    }

    new_file.close();

    //Run Update()

    Update();
}

void AccountApp::Launch {
    //TODO
}
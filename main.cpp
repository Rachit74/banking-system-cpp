#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


// User Defined Functions


// A function to calculate the index for user id
/*
older function
------------------------------
int findIndex(vector <string> vec, string target) {
    int index;
    if (vec.size() == 0) {
        index = 0;
    } else {
        for(int i=0;i<vec.size();i++) {
            if (vec.at(i) == target) {
                index = i;
            } else {
                continue;
            };
        };
    };
    return index;
};

I am returning index=0 for an empty vector which is not correct, i should be returning -1 as index for an empty vector.
useless else and continue; use
-------------------------------- */
// new function

int findIndex(vector <string> vec,string target) {
    int index = -1; //initalize to -1
    for (int i=0;i<vec.size();i++){
        if (vec.at(i) == target) {
            return i;
        }
    }
    return index;
}


void createAccount(vector <string> user_name,vector <int> user_account) {
    string  userName;
    int userAccountAmount;
    cout << "-----------------------\nCREATING NEW ACCOUNT\n";
    cout << "Enter your name: ";
    cin >> userName;
    cout << "Enter the amount you want to deposit: ";
    cin >> userAccountAmount;
    
    int userID = findIndex(user_name,userName);

    /*here the function does not know that to do if userID, i.e the index is -1 or the vector is emepty
    user_name.at(userID) = userName;
    user_account.at(userID) = userAccountAmount;

    it is currently pusing to the index that does not exist
    and i was using .at to change the index that does not exit in the vector
    */

   if (userID == -1) {
    user_name.push_back(userName);
    user_account.push_back(userAccountAmount);
    userID = user_name.size(); //index of newly added user to access in future
   };

    cout << "Your account has been created\n User ID: " << userID << "\nUser Name: " << userName << "\nAccount Amount: " << userAccountAmount << "\nPlease remeber your user id for accessing your account!\n-----------------------"; 

};

void findUser(int userID,vector <string> user_name,vector <int> user_account) {
    if (userID >= 0 && userID < user_name.size()) {
        cout << "User ID: " << userID << "\nUser Name: " << user_name[userID] << "\nBalance: " << user_account[userID] << "\n-----------------------" << endl;
    } else {
        cout << "User ID not found." << endl;
    }
}

// main function 

int main() {
    vector <string> user_name;
    vector <int> user_account;

    int primary_input;

    while(true) {
        cout << "Welcome to the banking system\n-----------------------\nWhat do you want to do?\n1. Create New Account\n2. Access Account\n3. Exit\n(enter 1/2/3):  ";
        cin >> primary_input;

        if (primary_input == 1) {
            createAccount(user_name,user_account);
        } else if (primary_input == 2)
        {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            findUser(id,user_name,user_account);
        }else{
            exit(0);
        };
    };


    return 0;
};
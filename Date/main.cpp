#include <iostream>
#include <list>
#include <string>
#include <format>

#include "User.h"
#include "utils.h"

using namespace std;


int main()
{
    list<User> users;
    int k;
    int i = 0;

    // Fill list with users (here just for example)
    users.push_back(User("John", "17.7.2004"));
    users.push_back(User("Mary", "16.7.2004"));
    users.push_back(User("James", "3.8.2001"));
    users.push_back(User("Jane", "15.7.2004"));
    users.push_back(User("Alex", "14.7.2004"));

    // Sorting with comparator
    users.sort(CompareUsersByDate);

    cout << "Input K: ";
    cin >> k;
    cout << endl;

    cout << "Today: " << getCurrentDate() << endl << endl;
    cout << format("Nearest {} birthdays:", k) << endl;

    // Write to console first K users in sorted list
    for (auto user : users) {
        if (i++ < k)
        {
            cout << user.name << " " << user.birthday << endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}

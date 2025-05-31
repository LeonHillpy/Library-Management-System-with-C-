
#include <iostream>
using namespace std;

namespace user {

    class User {
    private:
        string username;
        string password;

    public:
        // Constructor
        User(string u, string p) : username(u), password(p) {}
        // Destructor to deallocate memory.
        ~User() {}
        // Getter for username.
        string GetUsername() {
            return username;
        }
        // Getter for password.
        string GetPassword() {
            return password;
        }
    };
}

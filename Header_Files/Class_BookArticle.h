
#include <vector>
#include <string>
using namespace std;

namespace book_and_articles {

    class Book {
    private:
        string title;
        int year;
        
    public:
        // Constructor
        Book(string t, int y) : title(t), year(y) {}
        // Destructor to deallocate memory.
        ~Book() {}
        // Getter for name
        string getName() {
            return title;
        }
        // Getter for year
        int getYear() {
            return year;
        }
    };

    class Article: public Book {
    public:
        string subject;
        // Constructor
        Article(string t, int y, string s) : Book(t, y), subject(s) {}
        // Destructor
        ~Article() {}
        // Getter for subject
        string getSubject() {
            return subject;
        }
    };
}

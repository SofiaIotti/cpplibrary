#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    struct Book
    {
        string title;
        string author;
        int year;
        bool available;
    } book;

    vector<Book> books;

    string menu_choice;
    string new_title;
    string new_author;
    int new_year = 0;
    bool new_available = false;

    bool continue_program = true;
    string choice_continue;
    string search_choice;
    string search_string;
    string book_choice;

    cout << "Menu:\nA) Add a book to the library\nB) Borrow a book\nC) Return a book\nD) Show all books\nSelect: " << endl;
    cin >> menu_choice;

    do
    {
        if (menu_choice == "A")
        {
            cout << "Insert the Title:" << endl;
            cin >> new_title;
            cout << "Insert the Author:" << endl;
            cin >> new_author;
            cout << "Insert the year:" << endl;
            cin >> new_year;

            books.push_back({new_title, new_author, new_year, true});

            cout << "Want to go back to the menu or exit the program?" << endl
                 << "A) Go back\nB) Exit\nSelect:" << endl;
            cin >> choice_continue;
            if (choice_continue == "A")
            {
                continue_program = true;
            }
            else
            {
                continue_program = false;
            }
        }
        else if (menu_choice == "B" || menu_choice == "C")
        {
            cout << "Search by:" << endl
                 << "T) Title\nA) Author\nY) Year\nAll) All available books" << endl;
            cin >> search_choice;
            if (search_choice != "All" || search_choice != "all")
            {
                cout << "Insert your search: " << endl;
                cin >> search_string;
            }

            if (search_choice == "All" || search_choice == "all")
            {
                for (const auto &book : books)
                {
                    cout << "Title: " << book.title << endl;
                    cout << "Author: " << book.author << endl;
                    cout << "Year: " << book.year << endl;
                    cout << "Available: " << (book.available ? "Yes" : "No") << endl;
                    cout << "\n------------------------\n"
                         << endl;
                }
            }
            else if (search_choice == "T" || search_choice == "t")
            {
                for (size_t i = 0; i < books.size(); ++i)
                {
                    if (book.title.find(search_string) != string::npos)
                    {
                        cout << "#" << i << endl;
                        cout << "Title: " << book.title << endl;
                        cout << "Author: " << book.author << endl;
                        cout << "Year: " << book.year << endl;
                        cout << "Available: " << (book.available ? "Yes" : "No") << endl;
                        cout << "\n------------------------\n"
                             << endl;
                    }
                }
            }
            else if (search_choice == "A" || search_choice == "a")
            {
            }
            else if (search_choice == "Y" || search_choice == "y")
            {
            }

            if (menu_choice == "B")
            {
            }
            else if (menu_choice == "C")
            {
            }

            cout << "Want to go back to the menu or exit the program?" << endl
                 << "A) Go back\nB) Exit\nSelect:" << endl;
            cin >> choice_continue;
            if (choice_continue == "A")
            {
                continue_program = true;
            }
            else
            {
                continue_program = false;
            }
        }
        else if (menu_choice == "D")
        {
            for (size_t i = 0; i < books.size(); ++i)
            {
                
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Year: " << book.year << endl;
                cout << "Available: " << (book.available ? "Yes" : "No") << endl;
                cout << "\n------------------------\n"
                     << endl;
            }
            cout << "Want to borrow or return a book?" << endl
                 << "A) Yes\nB) No\nSelect:" << endl;
            cin >> choice_continue;
            if (choice_continue == "A")
            {
            }
            else if (choice_continue == "B")
            {
                cout << "Want to go back to the menu or exit the program?" << endl
                     << "A) Go back\nB) Exit\nSelect:" << endl;
                cin >> choice_continue;

                if (choice_continue == "A")
                {
                    continue_program = true;
                }
                else
                {
                    continue_program = false;
                }
            }
        }
    } while (continue_program = true);

    cout << "Thanks for stopping by, see you next book!\n";

    return 0;
}
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
        string year;
        bool available;
    } book;

    vector<Book> books;

    string menu_choice;
    string new_title;
    string new_author;
    string new_year;
    bool new_available = false;

    bool continue_program = true;
    string choice_continue;
    string search_choice;
    string search_parameter;
    string search_string;
    string book_choice;

    cout << "Menu:\nA) Add a book to the library\nB) Borrow a book\nC) Return a book\nD) Show all books\nSelect: " << endl;
    cin >> menu_choice;

    do
    {
        if (menu_choice == "A" || menu_choice == "a")
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
            if (choice_continue == "A" || choice_continue == "a")
            {
                continue_program = true;
            }
            else
            {
                continue_program = false;
            }
        }
        else if (menu_choice == "B" || menu_choice == "C" || menu_choice == "b" || menu_choice == "c")
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
                for (size_t i = 0; i < books.size(); ++i)
                {
                    if (book.available == true)
                    {
                        cout << "#" << (i + 1) << endl;
                        cout << "Title: " << book.title << endl;
                        cout << "Author: " << book.author << endl;
                        cout << "Year: " << book.year << endl;
                        cout << "Available: " << (book.available ? "Yes" : "No") << endl;
                        cout << "\n------------------------\n"
                             << endl;
                    }
                }
            }
            else
            {
                if (search_choice == "T" || search_choice == "t")
                {
                    search_parameter = book.title;
                }
                else if (search_choice == "A" || search_choice == "a")
                {
                    search_parameter = book.author;
                }
                else if (search_choice == "Y" || search_choice == "y")
                {
                    search_parameter = book.year;
                }

                for (size_t i = 0; i < books.size(); ++i)
                {
                    if ((search_parameter.find(search_string) != string::npos) && (book.available == true))
                    {
                        cout << "#" << (i + 1) << endl;
                        cout << "Title: " << book.title << endl;
                        cout << "Author: " << book.author << endl;
                        cout << "Year: " << book.year << endl;
                        cout << "Available: " << (book.available ? "Yes" : "No") << endl;
                        cout << "\n------------------------\n"
                             << endl;
                    }
                }
            }

            if (menu_choice == "B")
            {

                cout << "Which book would you like to borrow?" << endl;
                cin >> book_choice;

                if (isdigit(book_choice))
                {
                    books.at(book_choice).available = false;
                    cout << "You successfully borrowed " << books.at(book_choice)
                    .title << endl;
                }
            }
            else if (menu_choice == "C")
            {
                cout << "Which book would you like to return?" << endl;
                cin >> book_choice;
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
        else if (menu_choice == "D" || menu_choice == "d")
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
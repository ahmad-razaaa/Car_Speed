#include <iostream>
using namespace std;
class Book
{
    string Title;
    string Author,ISBN;
    int publicationYear;
    public:
    Book(){} 
    Book(string T, string Aut, string Is, int Pub){
        Title = T;
        Author = Aut;
        ISBN = Is;
        publicationYear = Pub;
    }
    void setTitle(string t){
        Title = t;
    }
    void setAuthor(string a){
        Author = a;
    }	
    void setISBN(string i){
        ISBN = i;
    }
    void setPublicationYear(int p){
        publicationYear = p;
    }
    string getTitle(){
        return Title;
    }
    string getAuthor(){
        return Author;
    }
    string getISBN(){
        return ISBN;
    }
    int getPublicationYear(){
        return publicationYear;
    }
    void display(){
        cout << "Title: " << Title << endl;
        cout << "Author: " << Author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Publication Year: " << publicationYear << endl;
    
    }
};

class Library{
    private:
    Book *books;
    int maxBooks;
    int noOfBooks=0;
    public:
    Library(){
    
    }
    Library(int m){
        maxBooks = m;
        books = new Book[maxBooks];
    }

    ~Library(){}

    void addBook(string title, string author, int pubyear, string ISBN) {
        if (noOfBooks >= maxBooks) {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }

        for (int i = 0; i < noOfBooks; ++i) {
            if (books[i].getISBN() == ISBN) {
                cout << "Book with this ISBN already exists." << endl;
                return;
            }
        }

        books[noOfBooks++] = Book(title, author, ISBN, pubyear);
        cout << "Book added successfully." << endl;
    }
    void searchBooks(string query) {
        bool found = false;
        for (int i = 0; i < noOfBooks; i++) {
            if (books[i].getISBN() == query) {
                books[i].display(); 
                found = true;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }
    void display(){
        for(int i=0;i<noOfBooks;i++){
            books[i].display();
        }
    }
};

int main (){
    int maxSize;
    cout << "Enter the maximum size of the library: ";
    cin >> maxSize;	

    Library lib(maxSize);
    int choice;
    string i;
    do {
        cout << "\nMenu:\n1. Add a Book\n2. Search for a Book by ISBN\n3. Display All Books\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
            {      
               string title, author, isbn;
               int year;
               cout << "Enter book details:\n";
               cout << "Title: ";
               cin>> title;
               cout << "Author: ";
               cin>> author;
               cout << "Publication Year: ";
               cin >> year;
               cout << "ISBN: ";
               cin >> isbn;
               lib.addBook(title, author, year, isbn);
                break;
            }
            case 2:   
                cout << "Enter ISBN to search: ";
                cin >> i;
                lib.searchBooks(i);
                break;
            case 3:
                cout << "All books in the library:" << endl;
                lib.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
                break;
        }
    } while (choice != 4);
    

return 0;
} 

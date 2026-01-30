#include<iostream>
using namespace std;

class Book {
    private:
        int bookID;
        string title;
        string author;
        bool isIssued;
    public:
        Book(int b, string t, string a ){
            bookID = b;
            title = t;
            author = a;
            isIssued = false;
        }
        int getID(){
            return bookID;
        }
        void displayBook(){
            cout<<"\nID | Title | Author | Status\n";
            cout<<bookID<<" | "<<title<<" | "<<author<<" | ";
            if(isIssued)
                cout<<"Issued\n";
            else
                cout<<"Available\n";
        }
        void issueBook(){
            if(isIssued)
                cout<<"Book already issued!\n";
            else{
                isIssued = true;
                cout<<"Book issued successfully!\n";
            }
        }
        void returnBook(){
            if(!isIssued)
                cout<<"Book was not issued!\n";
            else{
                isIssued = false;
                cout<<"Book returned successfully!\n";
            }
        }
};

int main(){
    int choice;
    Book* books[10];
    int count = 0;
do{
    cout<<"\n---Library Menu---\n";
    cout<<"1.Add New Book\n";
    cout<<"2.Display All Books\n";
    cout<<"3.Issue Book\n";
    cout<<"4.Return Book\n";
    cout<<"5.Exit\n";
    cout<<"Enter choice: ";
    cin>>choice;

    switch(choice){
        case 1:{
            int ID;
            string tt;
            string author;

            cout<<"Enter Book ID: ";
            cin>>ID;

            cout<<"Enter Book Title: ";
            cin.ignore();
            getline(cin, tt);

            cout<<"Enter Author name of Book: ";
            getline(cin, author);

            books[count++] = new Book(ID, tt, author);
            break;
        }
        case 2:{
            for(int i = 0; i < count; i++){
                books[i]->displayBook();
            }
            break;
        }
        case 3:{
            int id;
            cout<<"Enter Book ID to issue: ";
            cin>>id;

            for(int i = 0; i < count; i++){
                if(books[i]->getID() == id){
                    books[i]->issueBook();
                    break;
                }
            }
            break;
        }
        case 4:{
            int id;
            cout<<"Enter Book ID to return: ";
            cin>>id;
            for(int i = 0; i < count; i++){
                if(books[i]->getID() == id){
                    books[i]->returnBook();
                    break;
                }
            }
            break;
        }
        case 5:{
            cout<<"Thank You.";
            break;
        }
        default: cout<<"Invalid choice!\n";
    }
}while( choice != 5);


    return 0;
}
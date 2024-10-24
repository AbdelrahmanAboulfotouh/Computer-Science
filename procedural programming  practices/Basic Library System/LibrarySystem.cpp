#include <iostream>
#include<algorithm>
using namespace std;



struct BOOK{

    int ID;
    int Q;
    string NAME;
    string borrowlist[1000];
    int total_borrow{0};
};


struct USER{
    int Id;
    string NAME;
      int total_books{0};
    string borrowedlist[1000];
    };

// Asuuming that total books & users  in the library is 10000
 BOOK SHELFS[10000]; int B{0};
 USER GUEST[1000];int G{0};

void Library_System();
void Menu();

void Add_book();
void Perfix_search_books();
void Print_borrow_list_by_name();
void print_library_by_id();
void print_libraray_by_name();
void Add_user();
void Borrow_book();
void Return_book();
void Print_users();

bool compare_by_name (BOOK a, BOOK b)
{
    if(a.NAME !=  b.NAME)
        return a.NAME < b.NAME;

    return a.NAME < b.NAME;
}

bool compare_by_id (BOOK a, BOOK b)
{
    if(a.ID !=  b.ID)
        return a.ID < b.ID;

    return a.ID < b.ID;
}


int main()
{
    Library_System();
    return 0;
}


void Library_System()
    {
        short int choice;
        while (true)
        {
            Menu();
            cin>>choice;
            if(choice>=0&&choice<=10);
            else
                {cout<<"Wrong Entry please choose [1-10]\n";continue;}
            switch (choice)
            {
            case 1:
                Add_book();
                break;
            case 2:
                Perfix_search_books();
                break;
            case 3:
                Print_borrow_list_by_name();
                break;
            case 4:
              print_library_by_id();
                break;
            case 5:
                print_libraray_by_name();
                break;
            case 6:
                Add_user();
                break;
            case 7:
                Borrow_book();
                break;
            case 8:
                Return_book();
                break;
            case 9:
                Print_users();
                break;

            }
            if(choice==10)
                break;

        }
    }

    void Menu()
    {
        cout<<"Enter your Menu choice[ 1 - 10]\n"
            <<"1) add_book\n"
            <<"2) search_books_by_perfix\n"
            <<"3) print_who_borrowed_book_by_name\n"
            <<"4) print_library_by_id\n"
            <<"5) print_library_by_name\n"
            <<"6) add_user\n"
            <<"7) user_borrow_book\n"
            <<"8) user_return_book\n"
            <<"9) print_users\n"
            <<"10) Exit\n";

    }
void Add_book()
{
    cout<<"Enter book info: id && name && quantity \n";
    string name;
    int id;
    int quantity;
    cin>>id>>name>>quantity;
    SHELFS[B].NAME=name;
    SHELFS[B].ID=id;
    SHELFS[B].Q=quantity;
    ++B;

}
void Perfix_search_books()
{
    cout<<"Enter book name perfix \n";
    string Perfix;
    cin>>Perfix;
    bool f=false;
    
    for(int i{0};i<B;++i)
        {
           string SUB=SHELFS[i].NAME.substr(0,Perfix.size());
           if(SUB==Perfix)
           {
               f=true;
                cout<<SHELFS[i].NAME<<"\n";
           }

        }
    
 if(f==false)
            cout<<"No books found with this name\n";
}
void Print_borrow_list_by_name()
{

    cout<<"Enter book name \n";
    string Book_name;
    cin>>Book_name;
    bool f=false;
    for(int i{0};i<G;++i)
        {
            for(int j{0};j<GUEST[j].total_books;++j)
                {
                    if(Book_name==GUEST[i].borrowedlist[j])
                    {
                        f=true;
                        cout<<GUEST[i].NAME<<"\n";
                    }

                }
        }
        if(f==false)
            cout<<"This book has not been borrowed yet. \n";
}
 void print_library_by_id()
 {
        //sorting library books database by id and print it
        sort(SHELFS,SHELFS+B, compare_by_id);
        for(int i{0};i<B;++i)
            {
                 cout<<"id "<<SHELFS[i].ID<<"  "<<"name "
                <<SHELFS[i].NAME<<"  "<<"total quantity "
                <<SHELFS[i].Q<<"  "<<"total borrowed "
                <<SHELFS[i].total_borrow<<"\n";
            }
 }

void print_libraray_by_name()
{
// sorting library books database by name and print it
sort(SHELFS,SHELFS+B,compare_by_name);
for(int i{0};i<B;++i)
    {
         cout<<"id "<<SHELFS[i].ID<<"  "<<"name "
        <<SHELFS[i].NAME<<"  "<<"total quantity "
        <<SHELFS[i].Q<<"  "<<"total borrowed "
        <<SHELFS[i].total_borrow<<"\n";
    }

}
void Add_user()
{
    cout<<"Enter your name and national id : \n";
    string user_name; cin>>user_name;
    int id; cin>>id;
    GUEST[G].Id=id;
    GUEST[G].NAME=user_name;
    ++G;

}
void Borrow_book()
{
    cout<<"Enter user_name and book_name \n";
    string user_name; cin>>user_name;
    string book_name; cin>>book_name;
    for(int i{0};i<B;++i)
        {
            if(book_name==SHELFS[i].NAME)
            {
                SHELFS[i].borrowlist[SHELFS[i].total_borrow]=user_name;
                ++SHELFS[i].total_borrow;
                --SHELFS[i].Q;
            }
        }

        for(int i{0};i<G;++i)
            {
                if(user_name==GUEST[i].NAME)
                {
                    GUEST[i].borrowedlist[GUEST[i].total_books]=book_name;
                    ++GUEST[i].total_books;
                }
            }

}
void Return_book()
{
    cout<<"Enter user_name and book_name \n";
    string user_name; cin>>user_name;
    string book_name; cin>>book_name;
    for(int i{0};i<B;++i)
        {
            if(book_name==SHELFS[i].NAME)
            {
                --SHELFS[i].total_borrow;
                SHELFS[i].borrowlist[SHELFS[i].total_borrow]="";
                 ++SHELFS[i].Q;
            }
        }

         for(int i{0};i<G;++i)
            {
                if(user_name==GUEST[i].NAME)
                {
                    --GUEST[i].total_books;
                    GUEST[i].borrowedlist[GUEST[i].total_books]="";

                }
            }
}
void Print_users()
{
// printing all system users with [name,id,borrowed books names,books id]

        for(int i{0};i<G;++i)
            {
                cout<<"User : "<<GUEST[i].NAME<<"  "<<"Id : "<<GUEST[i].Id<<"  "<<"Borrowed books : ";

                for(int j{0};j<GUEST[i].total_books;++j)
                    cout<<GUEST[i].borrowedlist[j]<<" ";

                    cout<<"\n";

            }

}

#include <iostream>
using namespace std;

// Global Variables & data structures
    int QUEUE[20+1]={0};
    int specialization[20+1][5+1];
    string patient_name[20+1][5+1];
    int IDr{1},IDc{1};   // patient ID.

// project functions
    void add_patient();
    void print();
    void Get_next();
    void  Hospital_system();

    int main()
        {
       Hospital_system();
        return 0;
         }



void add_patient()
    {
        int user_specialization;
        string user_name;
        int user_status;
        bool capacity_validation = false;

        cout << "Enter specialization , Name and status :\n ";
        cin >> user_specialization >> user_name >> user_status;

        if (user_specialization >= 1 && user_specialization <= 20 && user_status >= 0 && user_status <= 1)
        {
            // queue capacity  check:
            for (int j{1}; j <= 5; ++j)
                if (specialization[user_specialization][j] == -1)
                {
                    capacity_validation = true;
                    break;

                }

            if (capacity_validation)
            {

                //queuing patient based on statues

                if (user_status == 0) //regulager.
                {
                    for (int i{5}; i >= 1; --i)
                        if (specialization[user_specialization][i] == -1)
                        {
                            specialization[user_specialization][i] = user_status;
                            IDc = i;
                            break;
                        }

                }
                else //urgent
                {
                    for (int i{1}; i <= 5; ++i)
                        if (specialization[user_specialization][i] == -1)
                            {specialization[user_specialization][i] = user_status;
                            IDc = i;
                            break;}

                }

                IDr = user_specialization;
                patient_name[IDr][IDc] = user_name;
                ++QUEUE[user_specialization];


            }
            else
                {cout << "sorry NO room for more patients in this specialization.\n";}


        }
        else
            {cout<<"Wrong Entery\n";}
    }

    void print()
        {

            for(int i{1};i<=20;++i)//specialization
            {
                if(QUEUE[i]!=0)
                {
                    cout<<"There are "<<QUEUE[i]
                        <<" patients in specialization "<<i<<"\n";

                    for(int j{1};j<=5;++j)//QUEUE
                    {
                        if(specialization[i][j]!=-1)
                        {
                            cout<<patient_name[i][j]<<" ";

                                    if(specialization[i][j]==1)
                                        cout<<"urgent \n";
                                    else
                                        cout<<"regular \n";


                        }
                    }
                }
                cout<<"\n\n";
            }
        }

        void Get_next()
            {
                int spec;
                cout << "Enter specialization :\n";
                cin >> spec;
                if (spec >= 1 && spec <= 20)
                {
                    if (QUEUE[spec] != 0)
                    {
                        for (int j{1}; j <= 5; ++j)
                            if (specialization[spec][j] != -1)
                            {
                                //informing
                                cout << patient_name[spec][j]
                                     << " please go with Dr\n";
                                //removing
                                specialization[spec][j] = -1;
                                patient_name[spec][j] = "";
                                --QUEUE[spec];
                                break;

                            }

                    }
                    else
                      {cout << "No patients at the moment ,Have rest Dr. \n";}

                }
                else
                    {cout << "Wrong Entery\n";}
            }

void  Hospital_system()
    {
        // stting defualt values such that -1 maens empty.
        for(int i{1}; i<=20 ;++i)
            for(int j{1};j<=5;++j)
                specialization[i][j]=-1;


        bool exit_flag= true;
        int choice{-1};
        while (choice==-1)
        {
            cout<<"Enter your Choice:\n"
                <<"1) Add new patient\n"
                <<"2) Print all patients\n"
                <<"3) Get next patient\n"
                <<"4) Exit\n";

            cin>>choice;

            if(!(choice>=1&&choice<=4))
            {
                cout<<"Wrong Choice please Re-Enter \n";
                choice=-1;
                continue;
            }

            switch (choice)
            {
                case 1:
                    add_patient();
                    break;
                case 2:
                    print();
                    break;
                case 3:
                    Get_next();
                    break;
                case 4:
                    exit_flag= false;
                    break;
            }

            if(!exit_flag)
                break;

            choice=-1;

        }

    }

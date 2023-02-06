#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    
    // complete

    bool read(Customers &rec){

        string userName;
        cout << "user name: ";
        getline(cin, userName);
        if(userName.empty()){
            return false;
        }else{
            if(userName.length() > 21){
        userName.resize(21);
    }
            // strcpy(rec.user_name, userName.c_str());
            strncpy(rec.user_name, userName.c_str(), 20);
            rec.user_name[20] = '\0';

            // cout << rec.likes_count;
            // cin.ignore();
            // cout << rec.retweets_count;
            // cin.ignore();
            // cout << rec.replies_count;
            // cin.ignore();
            // cout << rec.share_videos;
            // cin.ignore();

            cout << "Enter likes count: ";
            cin >> rec.likes_count;
            cin.ignore();
            cout << "Enter retweets count: ";
            cin >> rec.retweets_count;
            cin.ignore();
            cout << "Enter replies count: ";
            cin >> rec.replies_count;
            cin.ignore();
            // cin >>​rec.replies_count;
            cout << "Share videos? (y/n): ";
            // cin >>​rec.share_videos;
            cin >> rec.share_videos;
            cin.ignore();
        }

        return true;
    };

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec){
    //     Customers *temp = new Customers[t_rec.noOfRecords + 1];
    //     for (int i = 0; i < t_rec.noOfRecords; i++){
    //         temp[i] = t_rec.ptr_rec[i];
    //     }
        
    //     temp[t_rec.noOfRecords] = c_rec;
    //     delete[] t_rec.ptr_rec;
    //     t_rec.noOfRecords++;




        int i;
        Customers* cr = new Customers[t_rec.noOfRecords + 1];
        for (i = 0; i < t_rec.noOfRecords; i++) {
            cr[i] = t_rec.ptr_rec[i];
        }
        cr[i] = c_rec;
        t_rec.noOfRecords++;
        delete[] t_rec.ptr_rec;
        t_rec.ptr_rec = cr;

     };
    

    void EmptyRecord(Customers &customersData){
        customersData.likes_count = 0;
        customersData.replies_count = 0;
        customersData.retweets_count = 0;

        for (int i = 0; i < 21; i++)
        {
            customersData.user_name[i] = '\0';
        };
        customersData.share_videos = '\0';
        
    };
    void EmptyRecord(CustomersRecord& customersRecordData){ 

        //  delete[] customersRecordData.ptr_rec; // deallocate memory for customer records
           customersRecordData.ptr_rec = nullptr; // set pointer to null
          customersRecordData.noOfRecords = 0;
    };

   

       void display(const Customers& c_rec){ 
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", "
      << c_rec.retweets_count << ", " << c_rec.replies_count << ", "
<< c_rec.share_videos << endl;

        };

       void display(const CustomersRecord &t_rec){

        for (int i = 0; i < t_rec.noOfRecords; i++)
    {
        cout << i+1 << ". " << t_rec.ptr_rec[i].user_name << endl;
        cout << "Likes Count: " << t_rec.ptr_rec[i].likes_count << endl;
        cout << "Retweets Count: " << t_rec.ptr_rec[i].retweets_count << endl;
        cout << "Replies Count: " << t_rec.ptr_rec[i].replies_count << endl;
        cout << "Share Videos: " << t_rec.ptr_rec[i].share_videos << endl << endl;
    }
       };
    }

  
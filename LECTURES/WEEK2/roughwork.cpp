//copy existing records from t_rec.ptr_rec to temp
for (int i = 0; i < t_rec.noOfRecords; i++) {
    temp[i] = t_rec.ptr_rec[i];
}

//add new record to temp
temp[t_rec.noOfRecords] = c_rec;

//delete old memory and set t_rec.ptr_rec to temp
delete [] t_rec.ptr_rec;
t_rec.ptr_rec = temp;

//increment the number of records
t_rec.noOfRecords++;




void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
    Customers* temp = new Customers[t_rec.noOfRecords + 1];
    for (int i = 0; i < t_rec.noOfRecords; i++) {
        temp[i] = t_rec.ptr_rec[i];
    }
    temp[t_rec.noOfRecords] = c_rec;
    delete[] t_rec.ptr_rec;
    t_rec.ptr_rec = temp;
    t_rec.noOfRecords++;
}



/*In this example, a new Customers array of size t_rec.noOfRecords + 1 is dynamically allocated using new. The existing customers from the original array t_rec.ptr_rec are then copied over to the new array temp. The new customer c_rec is added to the end of the temp array. Finally, the original array t_rec.ptr_rec is deleted using delete[], and the ptr_rec pointer is updated to point to the new array temp. The noOfRecords member of t_rec is incremented to reflect the addition of the new customer.




*/

void displayCustomers(const CustomersRecord& t_rec) {
cout<<"Displaying Customers Record: "<<endl;
cout<<"User Name\tRetweets\tLikes\tReplies\tShare Videos"<<endl;
for(int i = 0; i < t_rec.noOfRecords; i++) {
cout<<t_rec.ptr_rec[i].user_name<<"\t\t"<<t_rec.ptr_rec[i].retweets_count<<"\t\t"<<t_rec.ptr_rec[i].likes_count<<"\t\t"<<t_rec.ptr_rec[i].replies_count<<"\t\t"<<t_rec.ptr_rec[i].share_videos<<endl;
}
}



#include <iostream>
#include <string>
using namespace std;

bool read(Customers& rec) {
cout<<"Enter user name: ";
cin.getline(rec.user_name, 21);
if(rec.user_name[0] == '\0') {
return false;
} else {
cout​1
Malformed citation <<"Enter likes count: ";
 cin>>
​rec.likes_count;
cout​2
Malformed citation <<"Enter retweets count: ";
 cin>>
​rec.retweets_count;
cout​3
Malformed citation <<"Enter replies count: ";
 cin>>
​rec.replies_count;
cout​4
Malformed citation <<"Share videos? (y/n): ";
 cin>>
​rec.share_videos;
return true;
}
}




// last attempt

#include <iostream>
#include <string>
#include <afx.h>
using namespace std;

bool read(Customers& rec) {
cout<<"Enter user name: ";
cin.ignore();
CString userName;
getline(cin, userName);
if(userName.IsEmpty()) {
return false;
} else {
strcpy(rec.user_name, userName.GetBuffer(userName.GetLength()));
cout​1
Malformed citation <<"Enter likes count: ";
 cin>>
​rec.likes_count;
cout​2
Malformed citation <<"Enter retweets count: ";
 cin>>
​rec.retweets_count;
cout​3
Malformed citation <<"Enter replies count: ";
 cin>>
​rec.replies_count;
cout​4
Malformed citation <<"Share videos? (y/n): ";
 cin>>
​rec.share_videos;
return true;
}
}



// anover version
bool read(Customers &rec) {
    std::cout << "Enter user name: ";
    std::cin.getline(rec.user_name, 21);

    std::cout &#8203;`oaicite:{"index":0,"invalid_reason":"Malformed citation << \"Enter likes count: \";\n    std::cin >>"}`&#8203; rec.likes_count;

    std::cout &#8203;`oaicite:{"index":1,"invalid_reason":"Malformed citation << \"Enter retweets count: \";\n    std::cin >>"}`&#8203; rec.retweets_count;

    std::cout &#8203;`oaicite:{"index":2,"invalid_reason":"Malformed citation << \"Enter replies count: \";\n    std::cin >>"}`&#8203; rec.replies_count;

    std::cout &#8203;`oaicite:{"index":3,"invalid_reason":"Malformed citation << \"Enter y if you share videos and n if you don't: \";\n    std::cin >>"}`&#8203; rec.share_videos;
    return true;
}



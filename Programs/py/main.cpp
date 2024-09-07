#include <iostream>
#include <fstream>

using namespace std;

class shopping {

private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();
};

void shopping :: menu() {
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t\t_________________________________________________\n";
    cout<<"\t\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t\t           SUPER MARKET MAIN MENU                \n";
    cout<<"\t\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t\t_________________________________________________\n";
    cout<<"\t\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t\t|   1) ADMINISTRATOR |\n";
    cout<<"\t\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t\t|   2) BUYER         |\n";
    cout<<"\t\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t\t|   3)EXIT           |\n";
    cout<<"\t\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t\t    PLEASE SELECT                                       \n";
    cin>>choice;

    switch (choice) {
        case 1:
            cout<<"\t\t\t PLEASE LOGIN \n";
        cout<<"\t\t\t ENTER EMAIL  \n";
        cin>>email;
        cout<<"\t\t\t PASSWORD     \n";
        cin>>password;

        if (email == "QuickSnackOASIS@gmail.com" && password == "QuickSnackOASIS") {
            administrator();
        }
        else {
            cout<<"\t\t\t INVALID USERNAME OR PASSWORD \n";
        }
        break;

        case 2: {
            buyer();
        }

        case 3: {
            exit(0);
        }

        default: {
            cout<<"\t\t\t\t Please select from the given option      \n";
        }



    }
    goto m;
}

void shopping::administrator() {
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Adminstartor menu \n ";
    cout<<"\t\t\t\t|______________1) Add the product_______________\n";
    cout<<"\t\t\t\t|                                           \n";
    cout<<"\t\t\t\t|______________2) Modify the product_______________\n";
    cout<<"\t\t\t\t|                                           \n";
    cout<<"\t\t\t\t|______________3) Delete the product_______________\n";
    cout<<"\t\t\t\t|                                           \n";
    cout<<"\t\t\t\t|______________4) Back To the Main Menu_______________\n";

    cout<<"\n\n\n\t\t\t Please Enter Your Choice: ";
    cin>>choice;

    switch (choice) {
        case 1:
            add();
            break;

        case 2:
           edit();
           break;

        case 3:
            rem();
            break;

        case 4:
            menu();
             break;

        default:
            cout<<"\t\t\t\t Please select a valid option\n";

    }
    goto m;
}

void shopping::buyer() {
    m:
    int choice;
    cout<<"\t\t\t  Buyer \n";
    cout<<"\t\t\t\t_______________________________________\n";
    cout<<"\t\t\t\t                                        \n";
    cout<<"\t\t\t\t             1) Buy Product             \n";
    cout<<"\t\t\t\t                                        \n";
    cout<<"\t\t\t\t             2) Go Back             \n";

    cout<<"\n\n\n\t\t\t Please Enter Your Choice: ";
    cin>>choice;

    switch (choice) {
        case 1:
            reciept();
        break;

        case 2:
            menu();
        break;

        default:
            cout<<"\t\t\t\t Please select a valid option\n";
    }
    goto m;
}

void shopping::add() {
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product"; cout<<"\n\n\t Product code of the product "; cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>discount;

    data.open("database.txt",ios::in);

    if(!data) {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else {
        data>>c>>n>>p>>d;

        while(!data.eof()) {
            if(c == pcode) {
                token++;

            }
            data>>c>>n>>p>>d;
        }
        data.close();



        if(token == 1)
            goto m;
        else {
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<price<<" "<<discount;
            data.close();
        }
    }
       cout<<"\n\t\t\t\t RECORD INSERTED \n";
}

void shopping::edit() {
    fstream data,data1;
    int pkey;
    int token;
    int c;
    string n;
    float p;
    float d;

    cout<<"\n\t\t\t\t\t\t MODIFY THE PRODUCT";
    cout<<"\n\t\t\t\t\t\t PRODUCT CODE: " ;
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data) {
        cout<<"\n\n FILE DOES NOT EXIST";
    }
    else {
        data1.open("database.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>price>>discount;

        while(!data.eof()) {
            if(pkey == pcode){
                cout<<"\n\t\t Product new code";
                cin>>c;
                cout<<"\n\t\t Name of the product";
                cin>>n;
                cout<<"\n\t\t Price of the product";
                cin>>p;
                cout<<"\n\t\t Discount on the product";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t\t Record to be edited";
                token++;
            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<price<<" "<<discount;

            }
            data>>pcode>>pname>>price>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0) {
            cout<<"\n\t\t\t\t Record not found Sorry";
        }
    }


}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token=0;

    cout<<"\n\t\t\t\t Delete Product";
    cout<<"\n\t\t\t\t\t Product Code: " ;
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data) {
        cout<<"\n\n File doesn't exsist";
    }
    else {
        data1.open("database.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>price>>discount;
        while(!data.eof()) {
            if(pkey == pcode) {
                cout<<"\n\n\t\t\t\t Product Deleted succesfully";
                token++;
            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount;

            }
            data>>pcode>>pname>>price>>price>>discount;

        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0) {
            cout<<"\n\t\t\t\t Record not found Sorry";
        }
    }

}

void shopping::list() {
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________________________";
    cout<<"ProNo\t\tName\t\tPrice\t\tDiscount\n";
    cout<<"_________________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()) {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<discount;
        data>>pcode>>pname>>price>>discount;
    }
    data.close();
}

void shopping::reciept() {
    m:
    fstream data;
    int choice;
    int arrc[100];
    int arrq[100];
    char c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\t\t\t\t RECIEPT";
    data.open("database.txt",ios::in);
    if(!data) {
        cout<<"\n\n Empty Database ";
    }
    else {
        data.close();

        list();
        cout<<"\n____________________________________________________________\n";
        cout<<"\n                                                            \n";
        cout<<"\n               Please Place order                           \n";
        cout<<"\n                                                             \n ";
        cout<<"\n ___________________________________________________________\n";

        do
        {
            cout<<"\n\n Enter Product Code: ";
            cin>>arrc[c];
            cout<<"\n\n\t\t\t\t Enter Product Quantity: ";
            cin>>arrq[c];

            for(int i=0;i<c;i++) {
                if(arrc[c]==arrc[i]) {
                    cout<<"\n\t\t\t\t Duplicate product code. Please Try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\t\t\t\t Do you want to buy a product or not? If yes press y else press q";
            cin>>choice;
        }
        while(choice =='y' || choice =='Y');

        cout<<"\n\n\t\t\t_______________________________________RECIEPT___________________________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";

        for(int i=0;i<c;i++) {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>price>>discount;
            while(!data.eof()) {
                if(pcode == arrc[i]) {
                    amount=price*arrq[i];
                    dis=amount-(amount*discount/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;

                }
                data>>pcode>>pname>>price>>price>>discount;
            }
        }
        data.close();
    }
    cout<<"\n\n ___________________________________________________________\n";
    cout<<"\n\n Total Amount"<<total;
}

int main(){
   shopping s;
    s.menu();

}

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// Made by Adham Elagaty :)

string takePasswdFromUser();
void current_date_and_time();
void Loading_interface();
void welcome_admin_interface();
void system_interface();
void employee_options(int choice, bool &r);
void admin_options(int &choice, bool &r);
void system_preform(int choice, bool &r);

class SystemFile
{
private:
    int TicketID();
    int get_number_of_ticket(int Case);
public:
    void insert_ticket(string movie_name, int number_of_individuals, string show_time, string chair_number, double price);
    void insert_movie(string movie_name, string show_time1, string show_time2, string show_time3, string show_time4);
    void display_tickets();
    void display_last_ticket();
    void display_last_information_ticket();
    void display_movie();
    void display_movie_name_only();
    void search_for_movie_and_show_time_by_number(int num_movie, int num_show_time, string &movie_name, string &show_time);
    void search_for_movie_and_show_time_by_name(int &num_movie, int &num_show_time, string movie_name, string show_time);
    bool find_ticket_id(string ID);
    void delete_movie(int pos);
    void Delete_ticket(string remove_ID);
    void delete_last_ticket();
    int get_number_of_movie(int Case);
    void reset_data_in_ticket_file_system();
    void reset_all_system_data();
    void store_chair_number(int chair_number, int num_movie, int num_show_time);
    void separate_chair_ticket(int num_movie, int num_show_time);
    void insert_chair_number_in_memory(int num_movie, int num_show_time);
    void check_corruption_in_the_system_file_and_fix_it_at_first_time_run();
    void check_new_admin();
    bool check_password();
    void modify_password();
};

class Hall{
private:
    double standard_ticket_price, premium_ticket_price;
    SystemFile f;
public:
    int chair[239] = {0};
    Hall();
    void display();
    void Interface(double &total_ticket_price, string &number_of_chair, int &number_of_individuals, int num_movie, int num_show_time, bool &t);
};

Hall H[100][4];

class Employee
{
protected:
    SystemFile f;
public:
    void booking_ticket();
    void display_movies_currently_showing_in_cinema();
    void view_ticket_booked();
    void display_last_ticket();
};

class Admin : public Employee
{
public:
    void display_and_edit_movie();
    void display_and_edit_ticket();
    void display_last_ticket();
    void rest_and_delete_all_ticket_file();
    bool rest_and_delete_all_system_file();
    void modify_password();
};

int main() {
    Loading_interface();
    int choice;
    bool r = false;
    do {
        system ("cls");
        system_interface();
        SetConsoleTextAttribute(h,6);
        cout << "\n\n\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[1] Enter as \"Employee\".     ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[2] Enter as \"Admin\".        ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[3] Exit.                    ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        SetConsoleTextAttribute(h,9);
        if (r){
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\t\t\t\t\t\t\tError! Enter correct choice :( ." << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t\t\t\t\t\t\t----> Enter Your Choice : ";
        SetConsoleTextAttribute(h,15);
        string CHOICE;
        cin >> CHOICE;
        try {
            std::stoi(CHOICE);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            r = true;
            continue;
        }
        choice = stoi(CHOICE);
        SetConsoleTextAttribute(h,9);
        r = true;
        system_preform(choice, r);
    } while (choice != 3);
}

void system_preform(int choice, bool &r)
{
    SystemFile f;
    f.check_corruption_in_the_system_file_and_fix_it_at_first_time_run();
    if (choice == 1)
    {
        int ch;
        r = false;
        bool R = false;
        do {
            system("cls");
            system_interface();
            SetConsoleTextAttribute(h,10);
            cout << "\n\n\t\t\t\t\t\t\t\t\t    #@#@#@#@ Homepage @#@#@#@#";
            SetConsoleTextAttribute(h,6);
            cout << "\n\n\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "\t\t\t\t\t\t\t\t&  ";
            SetConsoleTextAttribute(h,9);
            cout << "[1] Ticket booking.                              ";
            SetConsoleTextAttribute(h,13);
            cout << "&" << endl;
            SetConsoleTextAttribute(h,6);
            cout << "\t\t\t\t\t\t\t\t&  ";
            SetConsoleTextAttribute(h,9);
            cout << "[2] View the names of the movies available.      ";
            SetConsoleTextAttribute(h,13);
            cout << "&" << endl;
            SetConsoleTextAttribute(h,6);
            cout << "\t\t\t\t\t\t\t\t&  ";
            SetConsoleTextAttribute(h,9);
            cout << "[3] View reserved tickets.                       ";
            SetConsoleTextAttribute(h,13);
            cout << "&" << endl;
            SetConsoleTextAttribute(h,6);
            cout << "\t\t\t\t\t\t\t\t&  ";
            SetConsoleTextAttribute(h,9);
            cout << "[4] View last ticket.                            ";
            SetConsoleTextAttribute(h,13);
            cout << "&" << endl;
            SetConsoleTextAttribute(h,6);
            cout << "\t\t\t\t\t\t\t\t&  ";
            SetConsoleTextAttribute(h,9);
            cout << "[5] Back.                                        ";
            SetConsoleTextAttribute(h,13);
            cout << "&" << endl;
            cout << "\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            SetConsoleTextAttribute(h,9);
            if (R){
                SetConsoleTextAttribute(h,12);
                cout << "\t\t\t\t\t\t\t\tError! Enter correct choice :( ." << endl;
                SetConsoleTextAttribute(h,9);
            }
            cout << "\t\t\t\t\t\t\t\t----> Enter Your Choice : ";
            SetConsoleTextAttribute(h,15);
            string CH;
            cin >> CH;
            try {
                std::stoi(CH);
            } catch (std::exception& e) {
                SetConsoleTextAttribute(h,9);
                R = true;
                continue;
            }
            ch = stoi(CH);
            SetConsoleTextAttribute(h,9);
            R = true;
            employee_options(ch,R);
        } while(ch != 5);
    }else if(choice == 2){
        system ("cls");
        system_interface();
        r = false;
        f.check_new_admin();
        system ("cls");
        system_interface();
        if (f.check_password())
        {
            system ("cls");
            welcome_admin_interface();
            int ch;
            bool R = false;
            do {
                system("cls");
                system_interface();
                SetConsoleTextAttribute(h,10);
                cout << "\n\n\t\t\t\t\t\t\t\t\t #@#@#@#@ Admin Homepage @#@#@#@#";
                SetConsoleTextAttribute(h,6);
                cout << "\n\n\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[1] Ticket booking.                                          ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                SetConsoleTextAttribute(h,6);
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[2] View and edit the names of the movies available.         ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                SetConsoleTextAttribute(h,6);
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[3] View reserved tickets and Edit on them.                  ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                SetConsoleTextAttribute(h,6);
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[4] View last ticket and delete it if you want.              ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                SetConsoleTextAttribute(h,6);
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[5] Reset Ticket system file.                                ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                SetConsoleTextAttribute(h,6);
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[6] Reset All system file.                                   ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                SetConsoleTextAttribute(h,6);
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[7] Change Password.                                         ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                SetConsoleTextAttribute(h,6);
                cout << "\t\t\t\t\t\t\t&  ";
                SetConsoleTextAttribute(h,9);
                cout << "[8] Back.                                                    ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                cout << "\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                SetConsoleTextAttribute(h,9);
                if (R){
                    SetConsoleTextAttribute(h,12);
                    cout << "\t\t\t\t\t\t\tError! Enter correct choice :(" << endl;
                    SetConsoleTextAttribute(h,9);
                }
                cout << "\t\t\t\t\t\t\t----> Enter Your Choice : ";
                SetConsoleTextAttribute(h,15);
                string CH;
                cin >> CH;
                try {
                    std::stoi(CH);
                } catch (std::exception& e) {
                    SetConsoleTextAttribute(h,9);
                    R = true;
                    continue;
                }
                ch = stoi(CH);
                SetConsoleTextAttribute(h,9);
                R = true;
                admin_options(ch,R);
            } while(ch != 8);
        }
    }
}

void employee_options(int choice, bool &r)
{
    Employee e;
    if (choice == 1){
        r = false;
        e.booking_ticket();
    }else if (choice == 2){
        r = false;
        e.display_movies_currently_showing_in_cinema();
    }else if (choice == 3){
        r = false;
        e.view_ticket_booked();
    }else if (choice == 4){
        r = false;
        e.display_last_ticket();
    }
}

void admin_options(int &choice, bool &r){
    Admin a;
    if (choice == 1){
        r = false;
        a.booking_ticket();
    }else if (choice == 2){
        r = false;
        a.display_and_edit_movie();
    }else if (choice == 3){
        r = false;
        a.display_and_edit_ticket();
    }else if (choice == 4){
        r = false;
        a.display_last_ticket();
    }else if (choice == 5){
        r = false;
        a.rest_and_delete_all_ticket_file();
    }else if (choice == 6){
        r = false;
        if (a.rest_and_delete_all_system_file()){
            system ("cls");
            Loading_interface();
            choice = 8;
        }
    }else if (choice == 7){
        r = false;
        a.modify_password();
    }
}

string takePasswdFromUser(){
    char sp = '*';
    string passwd = "";
    char ch_ipt;
    while (true) {
        ch_ipt = getch();
        if (ch_ipt == 13) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == 8 && passwd.length() != 0) {
            passwd.pop_back();
            cout << "\b \b";
            continue;
        }
        else if (ch_ipt == 8 && passwd.length() == 0) {
            continue;
        }
        passwd.push_back(ch_ipt);
        SetConsoleTextAttribute(h,15);
        cout << sp;
        SetConsoleTextAttribute(h,9);
    }
}

void current_date_and_time(){
    time_t now = time(nullptr);
    string  date_and_time = ctime(&now);
    cout <<"\t\t\t----> Current Date & Time : ";
    SetConsoleTextAttribute(h,15);
    cout << date_and_time << endl;
    SetConsoleTextAttribute(h,9);
}

void Loading_interface()
{
    SetConsoleTextAttribute(h,15);
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t                       :-=+***++=-:" << endl;
    cout << "\t\t\t\t\t\t\t                   -++++=+=======++=+++=:" << endl;
    cout << "\t\t\t\t\t\t\t               .+*+==*#@@@@@@%+==+#@@#+==+*=" << endl;
    cout << "\t\t\t\t\t\t\t             .**::#@@@@@@@@#.       *@@@@#--%=" << endl;
    cout << "\t\t\t\t\t\t\t            =#-+@@@%@@@@@@@          %@@@@@%-=%=" << endl;
    cout << "\t\t\t\t\t\t\t          :#==@*:    .-*@@@          #@@@@@@@#--#." << endl;
    cout << "\t\t\t\t\t\t\t         =@:*@+         *@@*        =@@@@@%@@@@*:%." << endl;
    cout << "\t\t\t\t\t\t\t        -%.+@@.         -@@@@*=--=+%@@#-     -*+.:-:::::" << endl;
    cout << "\t\t\t\t\t\t\t        @.*@@@*         #@@**@@@@@@@%+  .:--=-=#*##*+%*=+%*%" << endl;
    cout << "\t\t\t\t\t\t\t       =*-@@@@@%-.   .=%@@#  +@%..::==*==#*%@@@@@##@@@@:@@@+" << endl;
    cout << "\t\t\t\t\t\t\t       *-*@@@@@@@@@%@@@@#%%+===-==+#*%%@@@=:-@@@@  #@@@:@@@+" << endl;
    cout << "\t\t\t\t\t\t\t       %.#@@@@%++++#@#+-:-==+#*%%#@@*  #@%   @@@ # -@@@:@@@*" << endl;
    cout << "\t\t\t\t\t\t\t       %:#@@@:     .-=-#=#%@@@    @@*  =@+   @@@ #  %@@=*@@@." << endl;
    cout << "\t\t\t\t\t\t\t       +--*+::--:+=#*#%@@@  @@  @#@@*   @    @@*    .@@@:@@@%" << endl;
    cout << "\t\t\t\t\t\t\t    .:-==--#+#*%%@#@@* .%@  @@    @@*        @@*@@%%%%%%*:=*+=" << endl;
    cout << "\t\t\t\t\t\t\t:=+: **%%@@@#*#@@  @@*  .@  @@  @@@@*-@-+%@@@###++*==*=+-:" << endl;
    cout << "\t\t\t\t\t\t\t #%%#-@@@@  *@%@@  @@* =    @@    %@%@@*###=+--=-=." << endl;
    cout << "\t\t\t\t\t\t\t :@@@**@@*  @@@@@  @@* @    @@+#@##*#==     =%*:#+" << endl;
    cout << "\t\t\t\t\t\t\t  #@@@:@@=  @@@@@  @@* @@##@@@%=*---:==---+@@:-%-" << endl;
    cout << "\t\t\t\t\t\t\t  =@@@-@@*  @@+@@  @@%#@@##+== :=*#@@@@@@@%=-#+." << endl;
    cout << "\t\t\t\t\t\t\t  +@@@-@@@%=._@@@@@*#+*+=    .=%@@@@@@@*==+*=" << endl;
    cout << "\t\t\t\t\t\t\t  *@@@:@@@@%%*#-*++=-:@@=#@@@@@@@%#*=:-*%+:" << endl;
    cout << "\t\t\t\t\t\t\t                -*-=-::.=+++++++==+++++++-" << endl;
    cout << "\t\t\t\t\t\t\t                    ::.=++++++==+++++-" << endl;
    cout << "\t\t\t\t\t\t\t                       :-=+***++-:" << endl;
    SetConsoleTextAttribute(h,14);
    cout << "\n\n\n\n\t\t\t\t\t\t\t\tLoading";
    char x = (char)219;
    for (int i = 0; i < 35; ++i) {
        Sleep(88);
        SetConsoleTextAttribute(h, i);
        cout << x;
    }
    SetConsoleTextAttribute(h, 9);
    system("cls");
}

void welcome_admin_interface()
{
    current_date_and_time();
    cout << "\t\t\t\t\t\t                                    :=+##%%%%%%%%%%%#*=:" << endl;
    cout << "\t\t\t\t\t\t                                 -*@@@@@@@@@@@@@@@@@@@@#:" << endl;
    cout << "\t\t\t\t\t\t                               -%@@@@@@@@@@@@@@@@@@@%@@%#+-" << endl;
    cout << "\t\t\t\t\t\t                             .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t\t                             %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t\t                            %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t\t                           +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t\t                          .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t\t                          +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%" << endl;
    cout << "\t\t\t\t\t\t                          #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t\t                          %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t\t                          #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t\t                          -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t\t                           %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t\t                          :%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t\t                          *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t\t                          +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t\t                          .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t\t                           +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:" << endl;
    cout << "\t\t\t\t\t\t                            *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%." << endl;
    cout << "\t\t\t\t\t\t                             :+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+" << endl;
    cout << "\t\t\t\t\t\t                               +@@@@@@@@@@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t\t                                %@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t\t                                 %@@@@@@@@@@@@@@@@@@@@@@@+" << endl;
    cout << "\t\t\t\t\t\t                                  #@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t\t                                   =@@@@@@@@@@@@@@@@@@@:" << endl;
    cout << "\t\t\t\t\t\t                                   .@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t\t                                   #@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t\t                              .:-*@@@@@@@@@@@@@@@@@@@@@%+=:." << endl;
    cout << "\t\t\t\t\t\t                        .-+*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*=:" << endl;
    cout << "\t\t\t\t\t\t                    -+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*=." << endl;
    cout << "\t\t\t\t\t\t                :+%@@@@@@@@@@@@@@@@@@@@@@@@%++#@@@@@@@@@@@@@@@@@@@@@@@@@*-" << endl;
    cout << "\t\t\t\t\t\t             .=%@@@@@@@@@@@@@@@@@@@@@@@@@=.    .=%@@@@@@@@@@@@@@@@@@@@@@@@@*:" << endl;
    cout << "\t\t\t\t\t\t           .+@@@@@@@@@@@@@@@@@@@@@@@@@@%         .%@@@@@@@@@@@@@@@@@@@@@@@@@@#:" << endl;
    cout << "\t\t\t\t\t\t          =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=.  .-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t\t         +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t\t         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=    :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t\t        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*      +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t\t        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.       %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t\t        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*        =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t\t         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:" << endl;
    cout << "\t\t\t\t\t\t         -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%          %@@@@@@@@@@@@@@@@@@@@@@@@@@@#=" << endl;
    cout << "\t\t\t\t\t\t           -*@@@@@@@@@@@@@@@@@@@@@@@@@@#          *@@@@@@@@@@@@@@@@@@@@@@%*+:" << endl;
    cout << "\t\t\t\t\t\t              .-=*#@@@@@@@@@@@@@@@@@@@@@+=-------=%@@@@@@@@@@@@@@@%#*=-." << endl;
    cout << "\t\t\t\t\t\t                     .::-=++**##%%%%%%%%%%%%%%%%%%%%%##**++=--:." << endl;
    SetConsoleTextAttribute(h,10);
    Sleep(200);
    cout << "\n\t\t\t        -##= =##- +##         =@@.                                             =###:       -@@:              --  %" << endl;
    Sleep(400);
    cout << "\t\t\t         @@% @@@%.@@* -*#%#*: =@@. -*#%#*: =#%%#=  *#=*%#=+#%*. .+#%#*-       :@@%@@.  :*%##@@: ##=#%#=*##+  ##- *#=*##+" << endl;
    Sleep(400);
    cout << "\t\t\t         +@@*@*@@#@@:-@@*  @@.=@@.-@@-    *@%  %@* %@%  @@  @@+ @@#  @@-      %@# @@#  @@*  @@:.@@  %@@  @@: @@+ %@%  @@:" << endl;
    Sleep(400);
    cout << "\t\t\t          @@@@.=@@@# -@@=-+##.=@@.-@@-    *@%  %@* %@#  @@  @@+ @@#--##-     *@@@@@@@= @@*  @@:.@@  #@%  @@: @@+ %@%  @@:" << endl;
    Sleep(400);
    cout << "\t\t\t          =**+  ***:  :*###*: -**  -*###+. =*##*=  +*+  **  **- .+###*=     :**-   *** :*##=**. **  +**  **. **- **=  **:" << endl;
    Sleep(800);
    cout << "\t\t\t\t\t";
    SetConsoleTextAttribute(h,9);
}

void system_interface()
{
    current_date_and_time();
    SetConsoleTextAttribute(h,12);
    cout << "\t                        .:::." << endl;
    cout << "\t                    .+%@@@@@@@*-" << endl;
    cout << "\t     :+#@@@@%*-    *@@+:    .-#@%:" << endl;
    cout << "\t    *@@+:..:=#@%: #@#          -@@:" << endl;
    cout << "\t   #@*        -@@-@@.           *@*" << endl;
    cout << "\t  .@@.         %@+@@.           *@*" << endl;
    cout << "\t   @@=        :@@:#@#          -@@:" << endl;
    cout << "\t   .%@*:    .+@@=  *@%+:    .-#@%:" << endl;
    cout << "\t    :@@@@@@@@@@@%%%%@@@@@@@@@@@-     .=#%=\t\t\t\t\t                         :+####=. ## =:      *#: ####### ::          =      +." << endl;
    cout << "\t   *@@@@@@@@@@@@@@@@@@@@@@@@@@@#  .=#@@@@@.\t\t\t\t\t                       :#@%+=+*%* @@ #@#:    #@: @@      :@+       .#%     =@%" << endl;
    cout << "\t  .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*#@@@@@@@@.\t\t\t\t\t                      .@@+        @@ #@@@%-  #@: @@      :@@#.    =@@%    -@@@#" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                      =@@.        @@ *@% #@% %@: @@@@@@# :@@@@=  *@@@%   :@@=#@*" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                      .%@*.       @@ *@#  :#@@@: @@      :@%  @#@@  @%  .@@%  @@+" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                       .*@@####@# @% *@#    :#@- @@      :@%  =@%: +@# .%@*=+++@@=" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                         :+####=. += -+=      :: ####### .++       -+= -+=     :++" << endl;
    cout << "\t  .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*#@@@@@@@@." << endl;
    cout << "\t   *@@@@@@@@@@@@@@@@@@@@@@@@@@@#  .=#@@@@@." << endl;
    cout << "\t    :*%%@@@@@@@@@@@@@@@@@@@%%*-      .=#%=" << endl;
    cout << "\n\n\n";
    SetConsoleTextAttribute(h,9);
}

int SystemFile::TicketID() {
    int z = 0;
    ifstream xin;
    xin.open("TicketID.txt");
    string temp;
    while (getline(xin,temp)){
        try {
            std::stoi(temp);
        } catch (std::exception& e) {
            continue;
        }
        z = stoi(temp);
    }
    ofstream f_out;
    f_out.open("LastID.txt");
    f_out << z;
    f_out.close();
    ifstream fin;
    fin.open("LastID.txt");
    int x;
    fin >> x;
    fin.close();
    if (x < 1000){
        f_out.open("LastID.txt");
        x = 1000;
        f_out << x;
        f_out.close();
    }
    return x;
}

void SystemFile::insert_ticket(string movie_name, int number_of_individuals, string show_time, string chair_number, double price)
{
    int ID = TicketID() + 1;
    ofstream outID;
    outID.open("TicketID.txt", ios::app);
    outID << ID << endl;
    ofstream outName;
    outName.open("MovieName.txt", ios::app);
    outName << movie_name << endl;
    ofstream out_num_of_ind;
    out_num_of_ind.open("NumberOfIndividuals.txt", ios::app);
    out_num_of_ind << number_of_individuals << endl;
    ofstream out_show_time;
    out_show_time.open("ShowTimeInTicket.txt", ios::app);
    out_show_time << show_time << endl;
    ofstream outPeople;
    outPeople.open("ChairNumbers.txt", ios::app);
    outPeople << chair_number << endl;
    ofstream outPrice;
    outPrice.open("TicketPrice.txt", ios::app);
    outPrice << price << endl;
    get_number_of_ticket(1);
}

void SystemFile::insert_movie(string movie_name, string show_time1, string show_time2, string show_time3, string show_time4) {
    ofstream out_movie, out_chair;
    out_movie.open("Movie_ShowTime.txt", ios::app);
    out_chair.open("ChairNumberInHall.txt", ios::app);
    out_movie << "#" << endl << movie_name << endl << show_time1 << endl << show_time2 << endl << show_time3 << endl << show_time4 << endl;
    out_chair << "#" << endl << "@" << endl << "@" << endl << "@" << endl << "@" << endl;
}

void SystemFile::display_tickets()
{
    SetConsoleTextAttribute(h,148);
    cout << "\t\t\t\t\t\t   ID          Name of Movie      Number of People      Show Time       Price of Ticket";
    SetConsoleTextAttribute(h,9);
    cout << "\n\t\t\t\t\t\t***************************************************************************************";
    cout << "\n";
    int n = get_number_of_ticket(0);
    int ID;
    ifstream inID;
    inID.open("TicketID.txt");
    string movie_name;
    ifstream inName;
    inName.open("MovieName.txt");
    int number_of_individuals = 0;
    ifstream in_num_ind;
    in_num_ind.open("NumberOfIndividuals.txt");
    string show_time;
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");
    double Price = 0.0;
    ifstream inPrice;
    inPrice.open("TicketPrice.txt");
    for (int i = 0; i < n; i++){
        inID >> ID;
        getline(inName,movie_name);
        in_num_ind >> number_of_individuals;
        in_show_time >> show_time;
        inPrice >> Price;
        if (i+1 < 10) {
            cout << "\t\t\t\t\t\t" << i + 1 << "- " << ID << "\t\t" << movie_name;
            if (movie_name.length()<=7) {
                cout << "\t\t\t" << number_of_individuals << "\t\t  "
                     << show_time << "\t\t     " << Price << " EGP" << endl;
            } else{
                cout << "\t\t" << number_of_individuals << "\t\t  "
                            << show_time << "\t\t     " << Price << " EGP" << endl;
            }
        }else{
            cout << "\t\t\t\t\t\t" << i + 1 << "- " << ID << "\t" << movie_name;
            if (movie_name.length()<=7) {
                cout << "\t\t\t" << number_of_individuals << "\t\t  "
                     << show_time << "\t\t     " << Price << " EGP" << endl;
            } else{
                cout << "\t\t" << number_of_individuals << "\t\t  "
                     << show_time << "\t\t     " << Price << " EGP" << endl;
            }
        }
    }
    cout << "\t\t\t\t\t\t***************************************************************************************";
    cout << "\n\t\t\t\t\t\t --->The number of Tickets is : ";
    SetConsoleTextAttribute(h,10);
    cout << get_number_of_ticket(0) << endl;
    SetConsoleTextAttribute(h,9);
}

void SystemFile::display_last_ticket()
{
    int n = get_number_of_ticket(0);
    int ID;
    ifstream inID;
    inID.open("TicketID.txt");
    string movie_name;
    ifstream inName;
    inName.open("MovieName.txt");
    int number_of_individuals = 0;
    ifstream inPlace;
    inPlace.open("NumberOfIndividuals.txt");
    string show_time;
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");
    string chair_number;
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");
    double Price = 0.0;
    ifstream inPrice;
    inPrice.open("TicketPrice.txt");

    for (int i = 0; i < n; i++)
    {
        inID >> ID;
        getline(inName,movie_name);
        inPlace >> number_of_individuals;
        in_show_time >> show_time;
        in_chair_number >> chair_number;
        inPrice >> Price;
    }
    cout<<"\n\n\n\n\t\t\t________________________________________________________________________\n";
    cout<<"\t\t\t|                                                                       ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|   Dear Customer,                                                      ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                      Congratulation!! Your tickets has been booked.   ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                                                                       ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                  THE DETAILS:                                         ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                            MOVIE Name: ";
    SetConsoleTextAttribute(h,6);
    cout << movie_name;
    SetConsoleTextAttribute(h,9);
    if (movie_name.length()<7) {
        cout <<"\t\t\t\t";
        SetConsoleTextAttribute(h,4);
        cout << "|";
        SetConsoleTextAttribute(h,9);
        cout << "\n";
    } else{
        cout <<"\t\t\t";
        SetConsoleTextAttribute(h,4);
        cout << "|";
        SetConsoleTextAttribute(h,9);
        cout << "\n";
    }
    cout<<"\t\t\t|                            Number of individual: ";
    SetConsoleTextAttribute(h,6);
    cout << number_of_individuals <<"\t\t\t";
    SetConsoleTextAttribute(h,9);
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                            SHOW STARTS: ";
    SetConsoleTextAttribute(h,6);
    cout <<show_time<<"\t\t\t\t";
    SetConsoleTextAttribute(h,9);
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                            THE SEAT NUMBERS ARE: ";
    if (chair_number.length() < 4){
        SetConsoleTextAttribute(h,6);
       cout <<chair_number<<"\t\t\t";
        SetConsoleTextAttribute(h,4);
        cout << "|";
        SetConsoleTextAttribute(h,9);
        cout << "\n";
    }else if (chair_number.length() < 13){
        SetConsoleTextAttribute(h,6);
        cout <<chair_number<<"\t\t";
        SetConsoleTextAttribute(h,4);
        cout << "|";
        SetConsoleTextAttribute(h,9);
        cout << "\n";
    } else{
        SetConsoleTextAttribute(h,6);
        cout <<chair_number<<"\t";
        SetConsoleTextAttribute(h,4);
        cout << "|";
        SetConsoleTextAttribute(h,9);
        cout << "\n";
    }
    cout<<"\t\t\t|                            Price of ticket: ";
    SetConsoleTextAttribute(h,6);
    cout << Price << " EGP\t\t\t";
    SetConsoleTextAttribute(h,9);
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                                                     ";
    SetConsoleTextAttribute(h,148);
    cout << "QR CODE";
    SetConsoleTextAttribute(h,9);
    cout << "           ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                                                       ..++>>>         ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                                                       ..__***         ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                                                       &%^>>>>         ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|                                                       :::::::         ";
    SetConsoleTextAttribute(h,4);
    cout << "|";
    SetConsoleTextAttribute(h,9);
    cout << "\n";
    cout<<"\t\t\t|";
    SetConsoleTextAttribute(h,4);
    cout << "_______________________________________________________________________|\n";\
    SetConsoleTextAttribute(h,9);
}

void SystemFile::display_last_information_ticket()
{
    int n = get_number_of_ticket(0);
    int ID;
    ifstream inID;
    inID.open("TicketID.txt");
    string movie_name;
    ifstream inName;
    inName.open("MovieName.txt");
    int number_of_individuals = 0;
    ifstream inPlace;
    inPlace.open("NumberOfIndividuals.txt");
    string show_time;
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");
    string chair_number;
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");
    double Price = 0.0;
    ifstream inPrice;
    inPrice.open("TicketPrice.txt");

    for (int i = 0; i < n; i++){
        inID >> ID;
        getline(inName,movie_name);
        inPlace >> number_of_individuals;
        in_show_time >> show_time;
        in_chair_number >> chair_number;
        inPrice >> Price;
    }
    SetConsoleTextAttribute(h,10);
    cout << "\t\t\t\t\t #@#@#@#@ Here Is The Information About Your Tickets Booking @#@#@#@#\n" << endl;
    SetConsoleTextAttribute(h,9);
    cout << "\t\t\t --->MOVIE Name: ";
    SetConsoleTextAttribute(h,6);
    cout << movie_name << endl;
    SetConsoleTextAttribute(h,9);
    cout << "\t\t\t --->Number of individual: ";
    SetConsoleTextAttribute(h,6);
    cout << number_of_individuals << endl;
    SetConsoleTextAttribute(h,9);
    cout << "\t\t\t --->SHOW STARTS: ";
    SetConsoleTextAttribute(h,6);
    cout << show_time << endl;
    SetConsoleTextAttribute(h,9);
    cout << "\t\t\t --->THE SEAT NUMBERS ARE: ";
    SetConsoleTextAttribute(h,6);
    cout << chair_number << endl;
    SetConsoleTextAttribute(h,9);
    cout << "\t\t\t --->Price of ticket: ";
    SetConsoleTextAttribute(h,6);
    cout << Price << " EGP" << endl;
    SetConsoleTextAttribute(h,9);
}

void SystemFile::display_movie() {
    cout << "\t\t\t*************************************************************************************************************************************" <<endl;
    cout << "\t\t\t*";
    SetConsoleTextAttribute(h,148);
    cout << "         Movie Names           Show Time (1)            Show Time (2)          Show Time (3)             Show Time (4)             ";
    SetConsoleTextAttribute(h,9);
    cout << "*" << endl;
    string x;
    int i = 0,a = 0;
    bool r = false;
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    while (getline(in_x, x)){
        if (r){
            cout << "\t\t\t*\t";
            SetConsoleTextAttribute(h,4);
            cout << "[" << i << "]";
            SetConsoleTextAttribute(h,9);
            cout << " ";
            r = false;
        }
        if (x == "#"){
            if (a == 0)
            {
                cout << "\t\t\t*************************************************************************************************************************************";
            }
            cout << endl;
            i++;
            r = true;
            a = 0;
            continue;
        }else{
            if (i<10 && a == 0)
            {
                cout << "  ";
            } else if (a == 0)
            {
                cout << " ";
            } else{
                cout << "  ";
            }
            if (x.length() < 10) {
                cout << x << "\t            ";
            }else
            {
                cout << x << "\t    ";
            }
            if(a == 4)
            {
                cout << "*";
            }
            a++;
        }
    }
    cout << endl << "\t\t\t*************************************************************************************************************************************" << endl;
    cout << "\t\t\t---> ";
    SetConsoleTextAttribute(h,10);
    cout << get_number_of_movie(1);
    SetConsoleTextAttribute(h,9);
    cout << " films in theaters" << endl;
}

void SystemFile::display_movie_name_only()
{
    cout << "\t\t\t\t\t\t\t\t\t*************************************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t*";
    SetConsoleTextAttribute(h, 148);
    cout << "             Movie Names           ";
    SetConsoleTextAttribute(h, 9);
    cout << "*" << endl;
    string x;
    int i = 0, a = 0;
    bool r = false;
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    while (getline(in_x, x)) {
        if (r) {
            cout << "\t\t\t\t\t\t\t\t\t*\t";
            SetConsoleTextAttribute(h, 4);
            cout << "[" << i << "]";
            SetConsoleTextAttribute(h, 9);
            cout << " ";
            r = false;
        }
        if (x == "#") {
            if (a == 0)
            {
                cout << "\t\t\t\t\t\t\t\t\t*************************************";
            }
            cout<< endl;
            i++;
            r = true;
            a = 0;
            continue;
        }
        else {
            if (i < 10 && a == 0) {
                if (x.length() < 10) {
                    cout << "  " << x << "\t            *";
                }
                else {
                    cout << "  " << x << "\t    *";
                }
            }
            else if (a == 0) {
                if (x.length() < 10) {
                    cout << " " << x << "\t            *";
                }
                else {
                    cout << " " << x << "\t    *";
                }
            }
            a++;
        }
    }
    cout << endl << "\t\t\t\t\t\t\t\t\t*************************************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t---> " << get_number_of_movie(1) << " films in theaters" << endl;
}

void SystemFile::search_for_movie_and_show_time_by_number(int num_movie, int num_show_time, string &movie_name, string &show_time){
    string x;
    int i = 1, z = 0;
    bool r = true;
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    while (getline(in_x, x)){
        if (i == num_movie)
        {
            if (r)
            {
                movie_name = x;
                r = false;
            }
            if (z == num_show_time)
            {
                show_time = x;
                break;
            }
            z++;
            continue;
        }
        if(x == "#")
        {
            i++;
        }
    }
}

void SystemFile::search_for_movie_and_show_time_by_name(int &num_movie, int &num_show_time, string movie_name,string show_time) {
    string z;
    int x = 0, y = 0;
    bool r = false;
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    while (getline(in_x, z)) {
        if (z == "#"){
            x++;
        }
        if (z == movie_name){
            num_movie = x;
            r = true;
            continue;
        }
        if (r){
            y++;
            if (z == show_time){
                num_show_time = y;
                break;
            }
        }
    }
}

bool SystemFile::find_ticket_id(string ID) {
    ifstream getID;
    getID.open("TicketID.txt");
    string line;
    while (getline(getID, line))
    {
        if (ID == line)
        {
            getID.close();
            return true;
        }
    }
    getID.close();
    return false;
}

void SystemFile::delete_movie(int pos){
    string x;
    ofstream Out_x;
    Out_x.open("Temp_Movie_ShowTime.txt", ios::app);
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    int i = 0,z = get_number_of_movie(1);
    while (getline(in_x, x)){
        if(x == "#" && i == z-1 && i == pos-1){
            i++;
            continue;
        }
        if (i != pos ){
            Out_x << x << endl;
        }
        if(x == "#")
        {
            i++;
        }
    }
    in_x.close();
    Out_x.close();
    remove("Movie_ShowTime.txt");
    rename("Temp_Movie_ShowTime.txt", "Movie_ShowTime.txt");
}

int SystemFile::get_number_of_movie(int Case){
    if (Case == 0){
        ifstream in;
        in.open("NumberOfMovie.txt");
        int x;
        in >> x;
        return x;
    }else if (Case == 1){
        string x;
        ifstream in_x;
        in_x.open("Movie_ShowTime.txt");
        ofstream Out_x;
        Out_x.open("NumberOfMovie.txt");
        int count = 0;
        while (getline(in_x, x)){
            if(x == "#")
            {
                count++;
            }
        }
        Out_x << count;
        in_x.close();
        Out_x.close();
        return count;
    }
    return 0;
}

int SystemFile::get_number_of_ticket(int Case){
    if (Case == 0){
        ifstream in;
        in.open("NumberOfTicket.txt");
        int x;
        in >> x;
        return x;
    }else if (Case == 1){
        ifstream in;
        in.open("NumberOfTicket.txt");
        int x;
        in >> x;
        ofstream out;
        out.open("NumberOfTicket.txt");
        int y;
        y = x + 1;
        out << y;
        return x;
    }else if (Case == -1){
        ifstream in;
        in.open("NumberOfTicket.txt");
        int x;
        in >> x;
        ofstream out;
        out.open("NumberOfTicket.txt");
        int y;
        y = x - 1;
        out << y;
        return x;
    }
}

void SystemFile::Delete_ticket(string remove_ID){
    int count = 0;
    bool r = true;
    ifstream getID;
    getID.open("TicketID.txt");
    string line, mn, st;
    while (getline(getID, line))
    {
        if (remove_ID == line)
        {
            r = false;
            break;
        }
        count++;
    }
    getID.close();

    if (r){
        return;
    }

    string ID;
    ofstream Out_ID;
    Out_ID.open("TempTicketID.txt", ios::app);
    ifstream in_ID;
    in_ID.open("TicketID.txt");

    string movie_name;
    ofstream Out_movie_name;
    Out_movie_name.open("TempMovieName.txt", ios::app);
    ifstream in_movie_name;
    in_movie_name.open("MovieName.txt");

    string number_of_individuals;
    ofstream Out_number_of_individuals;
    Out_number_of_individuals.open("TempNumberOfIndividuals.txt", ios::app);
    ifstream in_number_of_individuals;
    in_number_of_individuals.open("NumberOfIndividuals.txt");

    string show_time;
    ofstream Out_show_time;
    Out_show_time.open("TempShowTimeInTicket.txt", ios::app);
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");

    string chair_number;
    ofstream Out_chair_number;
    Out_chair_number.open("TempChairNumbers.txt", ios::app);
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");

    string price;
    ofstream Out_Price;
    Out_Price.open("TempTicketPrice.txt", ios::app);
    ifstream in_Price;
    in_Price.open("TicketPrice.txt");

    int i = 0;
    while (getline(in_ID, ID)){
        if (i == count){
            i++;
            continue;
        }else{
            Out_ID << ID << endl;
            i++;
        }
    }
    in_ID.close();
    Out_ID.close();
    remove("TicketID.txt");
    rename("TempTicketID.txt", "TicketID.txt");

    i = 0;
    while (getline(in_movie_name, movie_name)){
        if (i == count){
            i++;
            mn = movie_name;
            continue;
        }else{
            Out_movie_name << movie_name << endl;
            i++;
        }
    }
    in_movie_name.close();
    Out_movie_name.close();
    remove("MovieName.txt");
    rename("TempMovieName.txt", "MovieName.txt");

    i = 0;
    while (getline(in_number_of_individuals, number_of_individuals)){
        if (i == count){
            i++;
            continue;
        }else{
            Out_number_of_individuals << number_of_individuals << endl;
            i++;
        }
    }
    in_number_of_individuals.close();
    Out_number_of_individuals.close();
    remove("NumberOfIndividuals.txt");
    rename("TempNumberOfIndividuals.txt", "NumberOfIndividuals.txt");

    i = 0;
    while (getline(in_show_time, show_time)){
        if (i == count){
            i++;
            st = show_time;
            continue;
        }else{
            Out_show_time << show_time << endl;
            i++;
        }
    }
    in_show_time.close();
    Out_show_time.close();
    remove("ShowTimeInTicket.txt");
    rename("TempShowTimeInTicket.txt", "ShowTimeInTicket.txt");

    i = 0;
    while (getline(in_chair_number, chair_number)){
        if (i == count){
            i++;
            continue;
        }
        else{
            Out_chair_number << chair_number << endl;
            i++;
        }
    }
    in_chair_number.close();
    Out_chair_number.close();
    remove("ChairNumbers.txt");
    rename("TempChairNumbers.txt", "ChairNumbers.txt");

    i = 0;
    while (getline(in_Price, price)){
        if (i == count){
            i++;
            continue;
        }else{
            Out_Price << price << endl;
            i++;
        }
    }
    in_Price.close();
    Out_Price.close();
    remove("TicketPrice.txt");
    rename("TempTicketPrice.txt", "TicketPrice.txt");

    int mvn, stn;
    int a=0, b=0;
    bool n = false;
    search_for_movie_and_show_time_by_name(mvn,stn,mn,st);
    string z;
    ofstream out_ch_n;
    out_ch_n.open("TempChairNumberInHall.txt", ios::app);
    ifstream in_ch_n;
    in_ch_n.open("ChairNumberInHall.txt");
    while (getline(in_ch_n,z)){
        if (z == "#"){
            a++;
        }
        if (a == mvn && z == "@"){
            b++;
            out_ch_n << z << endl;
            continue;
        }
        if (a == mvn && b == stn){
            if (z == remove_ID){
                n = true;
                continue;
            }
            if (stoi(z) >= 1000 && n){
                out_ch_n << z << endl;
                continue;
            }
            if (n){
                H[mvn-1][stn-1].chair[stoi(z)] = 0;
                continue;
            }
        }
        out_ch_n << z << endl;
    }
    in_ch_n.close();
    out_ch_n.close();
    remove("ChairNumberInHall.txt");
    rename("TempChairNumberInHall.txt", "ChairNumberInHall.txt");
    get_number_of_ticket(-1);
}

void SystemFile::delete_last_ticket(){
    int count = 0;
    bool r = true;
    ifstream getID;
    getID.open("TicketID.txt");
    string line, remove_ID = to_string(TicketID()), mn, st;
    while (getline(getID, line))
    {
        if (remove_ID == line)
        {
            r = false;
            break;
        }
        count++;
    }
    getID.close();

    if (r){
        return;
    }

    string ID;
    ofstream Out_ID;
    Out_ID.open("TempTicketID.txt", ios::app);
    ifstream in_ID;
    in_ID.open("TicketID.txt");

    string movie_name;
    ofstream Out_movie_name;
    Out_movie_name.open("TempMovieName.txt", ios::app);
    ifstream in_movie_name;
    in_movie_name.open("MovieName.txt");

    string number_of_individuals;
    ofstream Out_number_of_individuals;
    Out_number_of_individuals.open("TempNumberOfIndividuals.txt", ios::app);
    ifstream in_number_of_individuals;
    in_number_of_individuals.open("NumberOfIndividuals.txt");

    string show_time;
    ofstream Out_show_time;
    Out_show_time.open("TempShowTimeInTicket.txt", ios::app);
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");

    string chair_number;
    ofstream Out_chair_number;
    Out_chair_number.open("TempChairNumbers.txt", ios::app);
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");

    string price;
    ofstream Out_Price;
    Out_Price.open("TempTicketPrice.txt", ios::app);
    ifstream in_Price;
    in_Price.open("TicketPrice.txt");

    int i = 0;
    while (getline(in_ID, ID)){
        if (i == count){
            i++;
            continue;
        }else{
            Out_ID << ID << endl;
            i++;
        }
    }
    in_ID.close();
    Out_ID.close();
    remove("TicketID.txt");
    rename("TempTicketID.txt", "TicketID.txt");

    i = 0;
    while (getline(in_movie_name, movie_name)){
        if (i == count){
            i++;
            mn = movie_name;
            continue;
        }else{
            Out_movie_name << movie_name << endl;
            i++;
        }
    }
    in_movie_name.close();
    Out_movie_name.close();
    remove("MovieName.txt");
    rename("TempMovieName.txt", "MovieName.txt");

    i = 0;
    while (getline(in_number_of_individuals, number_of_individuals)){
        if (i == count){
            i++;
            continue;
        }else{
            Out_number_of_individuals << number_of_individuals << endl;
            i++;
        }
    }
    in_number_of_individuals.close();
    Out_number_of_individuals.close();
    remove("NumberOfIndividuals.txt");
    rename("TempNumberOfIndividuals.txt", "NumberOfIndividuals.txt");

    i = 0;
    while (getline(in_show_time, show_time)){
        if (i == count){
            i++;
            st = show_time;
            continue;
        }else{
            Out_show_time << show_time << endl;
            i++;
        }
    }
    in_show_time.close();
    Out_show_time.close();
    remove("ShowTimeInTicket.txt");
    rename("TempShowTimeInTicket.txt", "ShowTimeInTicket.txt");

    i = 0;
    while (getline(in_chair_number, chair_number)){
        if (i == count){
            i++;
            continue;
        }
        else{
            Out_chair_number << chair_number << endl;
            i++;
        }
    }
    in_chair_number.close();
    Out_chair_number.close();
    remove("ChairNumbers.txt");
    rename("TempChairNumbers.txt", "ChairNumbers.txt");

    i = 0;
    while (getline(in_Price, price)){
        if (i == count){
            i++;
            continue;
        }else{
            Out_Price << price << endl;
            i++;
        }
    }
    in_Price.close();
    Out_Price.close();
    remove("TicketPrice.txt");
    rename("TempTicketPrice.txt", "TicketPrice.txt");

    int mvn, stn;
    int a=0, b=0;
    bool n = false;
    search_for_movie_and_show_time_by_name(mvn,stn,mn,st);
    string z;
    ofstream out_ch_n;
    out_ch_n.open("TempChairNumberInHall.txt", ios::app);
    ifstream in_ch_n;
    in_ch_n.open("ChairNumberInHall.txt");
    while (getline(in_ch_n,z)){
        if (z == "#"){
            a++;
        }
        if (a == mvn && z == "@"){
            b++;
            out_ch_n << z << endl;
            continue;
        }
        if (a == mvn && b == stn){
            if (z == remove_ID){
                n = true;
                H[mvn-1][stn-1].chair[stoi(z)] = 0;
                continue;
            }
            if (stoi(z) >= 1000 && n){
                out_ch_n << z << endl;
                continue;
            }
            if (n){
                H[mvn-1][stn-1].chair[stoi(z)] = 0;
                continue;
            }
        }
        out_ch_n << z << endl;
    }
    in_ch_n.close();
    out_ch_n.close();
    remove("ChairNumberInHall.txt");
    rename("TempChairNumberInHall.txt", "ChairNumberInHall.txt");
    get_number_of_ticket(-1);
}

void SystemFile::reset_data_in_ticket_file_system(){
    ofstream Out_ID;
    Out_ID.open("TempTicketID.txt", ios::app);
    Out_ID.close();
    remove("TicketID.txt");
    rename("TempTicketID.txt", "TicketID.txt");

    ofstream Out_movie_name;
    Out_movie_name.open("TempMovieName.txt", ios::app);
    Out_movie_name.close();
    remove("MovieName.txt");
    rename("TempMovieName.txt", "MovieName.txt");

    ofstream Out_number_of_individuals;
    Out_number_of_individuals.open("TempNumberOfIndividuals.txt", ios::app);
    Out_number_of_individuals.close();
    remove("NumberOfIndividuals.txt");
    rename("TempNumberOfIndividuals.txt", "NumberOfIndividuals.txt");

    ofstream Out_show_time;
    Out_show_time.open("TempShowTimeInTicket.txt", ios::app);
    Out_show_time.close();
    remove("ShowTimeInTicket.txt");
    rename("TempShowTimeInTicket.txt", "ShowTimeInTicket.txt");

    ofstream Out_chair_number;
    Out_chair_number.open("TempChairNumbers.txt", ios::app);
    Out_chair_number.close();
    remove("ChairNumbers.txt");
    rename("TempChairNumbers.txt", "ChairNumbers.txt");

    ofstream Out_Price;
    Out_Price.open("TempTicketPrice.txt", ios::app);
    Out_Price.close();
    remove("TicketPrice.txt");
    rename("TempTicketPrice.txt", "TicketPrice.txt");

    ofstream Out_last_ID;
    Out_last_ID.open("TempLastID.txt", ios::app);
    Out_last_ID.close();
    remove("LastID.txt");
    rename("TempLastID.txt", "LastID.txt");

    ofstream Out_Number_Of_Ticket;
    Out_Number_Of_Ticket.open("TempNumberOfTicket.txt", ios::app);
    Out_Number_Of_Ticket << 0;
    Out_Number_Of_Ticket.close();
    remove("NumberOfTicket.txt");
    rename("TempNumberOfTicket.txt", "NumberOfTicket.txt");

    ofstream Out_ch_n;
    Out_ch_n.open("TempChairNumberInHall.txt", ios::app);
    Out_ch_n.close();
    string chair_num;
    int x=0, y=0;
    ifstream in_chair_num;
    in_chair_num.open("ChairNumberInHall.txt");
    while (getline(in_chair_num, chair_num)) {
        if (chair_num == "#"){
            x++;
            y=0;
            continue;
        }
        if (chair_num == "@"){
            y++;
            continue;
        }
        try {
            std::stoi(chair_num);
        } catch (std::exception& e) {
            continue;
        }
        H[x-1][y-1].chair[stoi(chair_num)] = 0;
    }
    in_chair_num.close();
    remove("ChairNumberInHall.txt");
    rename("TempChairNumberInHall.txt", "ChairNumberInHall.txt");
    Out_ch_n.open("ChairNumberInHall.txt", ios::app);
    for (int i = 0; i < get_number_of_movie(1); ++i) {
        Out_ch_n << "#" << endl << "@" << endl << "@" << endl << "@" << endl << "@" << endl;
    }
}

void SystemFile::reset_all_system_data() {
    reset_data_in_ticket_file_system();
    ofstream Out_Movie_ShowTime;
    Out_Movie_ShowTime.open("TempMovie_ShowTime.txt", ios::app);
    Out_Movie_ShowTime.close();
    remove("Movie_ShowTime.txt");
    rename("TempMovie_ShowTime.txt", "Movie_ShowTime.txt");

    ofstream Out_test_pass;
    Out_test_pass.open("TempTestPass.txt", ios::app);
    Out_test_pass.close();
    remove("TestPass.txt");
    rename("TempTestPass.txt", "TestPass.txt");
}

void SystemFile::store_chair_number(int chair_number, int num_movie, int num_show_time) {
    int x=0,y=0;
    string chair_num;
    ofstream Out_chair_num;
    Out_chair_num.open("TempChairNumberInHall.txt", ios::app);
    ifstream in_chair_num;
    in_chair_num.open("ChairNumberInHall.txt");
    while (getline(in_chair_num, chair_num)){
        if (chair_num == "#"){
            x++;
        }
        Out_chair_num << chair_num << endl;
        if (x == num_movie){
            if (chair_num == "@"){
                y++;
            }
            if (y == num_show_time){
                Out_chair_num << chair_number << endl;
                y++;
            }
        }
    }
    in_chair_num.close();
    Out_chair_num.close();
    remove("ChairNumberInHall.txt");
    rename("TempChairNumberInHall.txt", "ChairNumberInHall.txt");
}

void SystemFile::separate_chair_ticket(int num_movie, int num_show_time) {
    int x=0,y=0;
    int id = TicketID()+1;
    string chair_num;
    ofstream Out_chair_num;
    Out_chair_num.open("TempChairNumberInHall.txt", ios::app);
    ifstream in_chair_num;
    in_chair_num.open("ChairNumberInHall.txt");
    while (getline(in_chair_num, chair_num)){
        if (chair_num == "#"){
            x++;
        }
        Out_chair_num << chair_num << endl;
        if (x == num_movie){
            if (chair_num == "@"){
                y++;
            }
            if (y == num_show_time){
                Out_chair_num << id << endl;
                y++;
            }
        }
    }
    in_chair_num.close();
    Out_chair_num.close();
    remove("ChairNumberInHall.txt");
    rename("TempChairNumberInHall.txt", "ChairNumberInHall.txt");
}

void SystemFile::insert_chair_number_in_memory(int num_movie, int num_show_time) {
    int x=0, y=0;
    string chair_num;
    ifstream in_chair_num;
    in_chair_num.open("ChairNumberInHall.txt");
    while (getline(in_chair_num, chair_num)){
        if (chair_num == "#"){
            x++;
        }
        if (x == num_movie+1){
            if (chair_num == "@"){
                y++;
            }
            if (y == num_show_time+1){
                try {
                    std::stoi(chair_num);
                } catch (std::exception& e) {
                    continue;
                }
                int z = stoi(chair_num);
                if (z < 1000) {
                    H[num_movie][num_show_time].chair[z] = 1;
                }
            }
        }
        if (x > num_movie+1){
            break;
        }
    }
}

bool SystemFile::check_password(){
    ifstream in;
    int counter = 3;
    string x;
    in.open("AdminPassword.txt");
    in >> x;
    string str;
    while (counter)
    {
        if (counter == 3)
        {
            cout << "\t\t\t---->if you want to exit Enter '";
            SetConsoleTextAttribute(h,12);
            cout << "x";
            SetConsoleTextAttribute(h,9);
            cout << "' or '";
            SetConsoleTextAttribute(h,12);
            cout << "X";
            SetConsoleTextAttribute(h,9);
            cout << "' :)" << endl;
        }
        cout << "\t\t\t-Please enter The Password (you have ";
        SetConsoleTextAttribute(h,10);
        cout << counter;
        SetConsoleTextAttribute(h,9);
        cout << " Attempts left) : ";
        str = takePasswdFromUser();
        if (x == str)
        {
            system("cls");
            system_interface();
            SetConsoleTextAttribute(h,10);
            cout << "\t\t\t\t\t\t        Correct Password :) " << endl;
            SetConsoleTextAttribute(h,9);
            return true;
        }else if (str == "x"||str == "X")
        {
            break;
        }else{
            system("cls");
            system_interface();
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\t\t\t\t        Wrong Password :( " << endl;
            SetConsoleTextAttribute(h,9);
        }
        counter--;
    }
    return false;
}

void SystemFile::check_corruption_in_the_system_file_and_fix_it_at_first_time_run() {
    ofstream f;
    f.open("CheckFiles.txt", ios::app);
    f.close();
    string x;
    ifstream F;
    F.open("CheckFiles.txt");
    while (getline(F,x)){
        return;
    }
    F.close();
    f.open("CheckFiles.txt");
    f << "Hi My Name is Adham Elagaty";
    f.close();
    reset_all_system_data();
}

void SystemFile::check_new_admin() {
    ofstream f;
    f.open("TestPass.txt", ios::app);
    f.close();
    string x;
    ifstream F;
    F.open("TestPass.txt");
    while (getline(F,x)){
        return;
    }
    F.close();
    f.open("TestPass.txt");
    f << "Hi My Name is Adham Elagaty";
    f.close();
    ofstream out;
    string z,y;
    bool m = false;
    out.open("AdminPassword.txt");
    do {
        system("cls");
        system_interface();
        SetConsoleTextAttribute(h,10);
        cout << "\t\t\t\t\t\t\t\t\t\t Create a Password :)" << endl;
        SetConsoleTextAttribute(h,9);
        if (m)
        {
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\t   ---->Error! The passwords do not match :(" << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t-Enter New Password : ";
        z = takePasswdFromUser();
        cout << "\t\t\t-Enter New Password Again : ";
        y = takePasswdFromUser();
        m = true;
    } while (z!=y);
    out << z;
    SetConsoleTextAttribute(h,10);
    cout << "\n\t\t\t\t#@#@#@#@  Password Create successfully :)  @#@#@#@#" << endl;
    SetConsoleTextAttribute(h,9);
    system ("pause");
}

void SystemFile::modify_password() {
    if (check_password()){
        ofstream out;
        string x,y;
        bool m = false;
        out.open("AdminPassword.txt");
        do {
            system("cls");
            system_interface();
            if (m)
            {
                SetConsoleTextAttribute(h,12);
                cout << "\t\t\t   ---->Error! The passwords do not match :(" << endl;
                SetConsoleTextAttribute(h,9);
            }
            cout << "\t\t\t-Enter New Password : ";
            x = takePasswdFromUser();
            cout << "\t\t\t-Enter New Password Again : ";
            y = takePasswdFromUser();
            m = true;
        } while (x!=y);
        out << x;
        SetConsoleTextAttribute(h,10);
        cout << "\n\t\t\t\t#@#@#@#@  Password Updated successfully :)  @#@#@#@#" << endl;
        SetConsoleTextAttribute(h,9);
    }
    else
    {
        SetConsoleTextAttribute(h,12);
        cout << "\n\t\t\t\t#@#@#@#@  No change in Password :(  @#@#@#@#" << endl;
        SetConsoleTextAttribute(h,9);
    }
}

Hall::Hall() {
    standard_ticket_price = 155.00;
    premium_ticket_price = 170.00;
}

void Hall::display() {
    int x = 0,y = 0;
    bool r = true;
    current_date_and_time();
    SetConsoleTextAttribute(h,9);
    cout<<"\n\t\t\t   ______________________________________________________________________________________________________________";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t SCREEN THIS WAY\n\n\n";
    cout << "\n\t\t\t\t" ;
    for (int i=1 ; i<239 ; i++) {
        if(i<10){
            if(chair[i]==0) {
                SetConsoleTextAttribute(h,148);
                cout << "[00" << i  << "] ";
                SetConsoleTextAttribute(h,9);
            }
            else{
                SetConsoleTextAttribute(h,132);
                cout << "[ X ] ";
                SetConsoleTextAttribute(h,9);
            }
        }
        else if (i<100) {
            if(chair[i]==0) {
                SetConsoleTextAttribute(h,148);
                cout << "[0" << i << "] ";
                SetConsoleTextAttribute(h,9);
            }
            else{
                SetConsoleTextAttribute(h,132);
                cout << "[ X ] ";
                SetConsoleTextAttribute(h,9);
            }
        }
        else{
            if(chair[i]==0) {
                if (i<141)
                {
                    SetConsoleTextAttribute(h,148);
                    cout << "[" << i << "] ";
                    SetConsoleTextAttribute(h,9);
                }else{
                    SetConsoleTextAttribute(h,164);
                    cout << "[" << i << "] ";
                    SetConsoleTextAttribute(h,9);
                }
            }
            else{
                SetConsoleTextAttribute(h,132);
                cout << "[ X ] ";
                SetConsoleTextAttribute(h,9);
            }
        }
        x++;
        if(x == 4 && r){
            cout << "\t";
            x = 0;
            y++;
            r = false;
        }else if(x == 6 && !r){
            cout << "\t   ";
            x = 0;
            y++;
            r = true;
        }if (y == 3){
            y = 0;
            r = true;
            cout << "\n\n\t\t\t\t";
        }
    }
    cout<<"\n\t\t\t   ______________________________________________________________________________________________________________\n";
    SetConsoleTextAttribute(h,132);
    cout << "\t\t\t\t\t\t\tUnavailable";
    SetConsoleTextAttribute(h,9);
    cout << "\t     ";
    SetConsoleTextAttribute(h,164);
    cout << "Premium";
    SetConsoleTextAttribute(h,9);
    cout << "\t\t";
    SetConsoleTextAttribute(h,148);
    cout << "Standard\n";
    SetConsoleTextAttribute(h,9);
}

void Hall::Interface(double &total_ticket_price, string &number_of_chair, int &number_of_individuals, int num_movie, int num_show_time, bool &t) {
    int num = 0 , c;
    number_of_individuals = 0;
    bool r = false, R = false, NC = false, CT = false;
    t = true;
    total_ticket_price = 0;
    number_of_individuals = 0;
    string a="y";
    while (a=="y" || a=="Y" || a=="yes" || a=="Yes" || a=="YES" || a=="yES" ||a=="yEs" ||a=="YeS") {
        system("cls");
        display();
        if (R){
            SetConsoleTextAttribute(h,12);
            cout << "Error! Enter correct choice :(" << endl;
            R = false;
            SetConsoleTextAttribute(h,9);
        }
        if (num+number_of_individuals > 5){
            SetConsoleTextAttribute(h,12);
            cout << "Error! The maximum number of chairs per ticket is five :)" << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout<<endl<<"Enter number of chairs:  ";
        string NUM;
        SetConsoleTextAttribute(h,15);
        cin >> NUM;
        SetConsoleTextAttribute(h,9);
        try {
            std::stoi(NUM);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            num = 0;
            R = true;
            continue;
        }
        num = stoi(NUM);
        SetConsoleTextAttribute(h,9);
        if (num+number_of_individuals > 5){
            continue;
        }
        number_of_individuals+=num;
        for (int i=0 ;i<num;i++) {
            t = false;
            system("cls");
            display();
            if (R){
                SetConsoleTextAttribute(h,12);
                cout << "Error! Enter correct choice :(" << endl;
                R = false;
                SetConsoleTextAttribute(h,9);
            }
            if (NC){
                SetConsoleTextAttribute(h,12);
                cout << "-Error! No Chair with This Number :(" << endl;
                NC = false;
                SetConsoleTextAttribute(h,9);
            }
            if (CT){
                SetConsoleTextAttribute(h,12);
                cout<<"-Error! Chair already taken :("<<endl;
                CT = false;
                SetConsoleTextAttribute(h,9);
            }
            cout<<i+1<<"- Choose chair:   ";
            SetConsoleTextAttribute(h,15);
            string C;
            cin >> C;
            try {
                std::stoi(C);
            } catch (std::exception& e) {
                SetConsoleTextAttribute(h,9);
                R = true;
                i--;
                continue;
            }
            c = stoi(C);
            SetConsoleTextAttribute(h,9);
            if (c > 238){
                NC = true;
                i--;
                continue;
            }
            if (chair[c] == 1){
                CT = true;
                i--;
                continue;
            }
            chair[c]=1;
            f.store_chair_number(c,num_movie,num_show_time);
            if (c<141)
            {
                total_ticket_price+=standard_ticket_price;
            }else{
                total_ticket_price+=premium_ticket_price;
            }
            if (i == num-1)
            {
                number_of_chair += to_string(c);
            }
            else if(i == 0 && r){
                number_of_chair += ","+(to_string(c))+",";
                r = false;
            }
            else{
                number_of_chair += (to_string(c)+",");
            }
            system("cls");
        }
        if (number_of_individuals == 5){
            break;
        }
        do {
            system("cls");
            display();
            if (r){
                SetConsoleTextAttribute(h,12);
                cout << "Error! Enter correct choice :(" << endl;
                SetConsoleTextAttribute(h,9);
            }
            cout<<"Do you want to Choose more chairs :) ? (";
            SetConsoleTextAttribute(h,10);
            cout << "y";
            SetConsoleTextAttribute(h,9);
            cout << "/";
            SetConsoleTextAttribute(h,12);
            cout << "n";
            SetConsoleTextAttribute(h,9);
            cout << ")" << endl;
            SetConsoleTextAttribute(h,15);
            cin>>a;
            SetConsoleTextAttribute(h,1);
            r = true;
        }while(a!="y" && a!="Y" && a!="yes" && a!="Yes" && a!="YES" && a!="yES" && a!="yEs" && a!="YeS" && a!="n" && a!="N" && a!="no" && a!="No" && a!="NO" && a!="nO");
        if (a =="y" || a=="Y" || a=="yes" || a=="Yes" || a=="YES" || a=="yES" || a=="yEs" || a=="YeS"){
            num = 0;
        }
    }
    if (num != 0 && !t) {
        f.separate_chair_ticket(num_movie, num_show_time);
    }
}

void Employee::booking_ticket() {
    int num_movie, num_show_time, number_of_individuals;
    double price;
    bool R = false, t;
    string movie_name, show_time, chair_number;
    do {
        system("cls");
        system_interface();
        f.display_movie();
        if (R)
        {
            SetConsoleTextAttribute(h,12);
            cout << "\n\t\t\tError! Enter correct choice :(" << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\n\t\t\t-Enter number of Movie do you want: ";
        SetConsoleTextAttribute(h,15);
        string NM;
        cin >> NM;
        try {
            std::stoi(NM);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            R = true;
            continue;
        }
        num_movie = stoi(NM);
        SetConsoleTextAttribute(h,9);
        cout << "\n\t\t\t-Enter number of Show Time do you want: ";
        SetConsoleTextAttribute(h,15);
        string NS;
        cin >> NS;
        try {
            std::stoi(NS);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            R = true;
            continue;
        }
        num_show_time = stoi(NS);
        SetConsoleTextAttribute(h,9);
        R = true;
    } while (num_movie > f.get_number_of_movie(0) || num_show_time > 4 || num_movie < 0 || num_show_time < 0);
    system("cls");
    f.search_for_movie_and_show_time_by_number(num_movie+1,num_show_time,movie_name, show_time);
    f.insert_chair_number_in_memory(num_movie-1,num_show_time-1);
    H[num_movie-1][num_show_time-1].Interface(price,chair_number,number_of_individuals,num_movie,num_show_time,t);
    f.insert_ticket(movie_name,number_of_individuals,show_time,chair_number,price);
    bool r = false;
    string a;
    if (!t) {
        do {
            system("cls");
            system_interface();
            f.display_last_information_ticket();
            cout << "Do you want to complete the reservation? (";
            SetConsoleTextAttribute(h,10);
            cout << "y";
            SetConsoleTextAttribute(h,9);
            cout << "/";
            SetConsoleTextAttribute(h,12);
            cout << "n";
            SetConsoleTextAttribute(h,9);
            cout << ")" << endl;
            if (r) {
                SetConsoleTextAttribute(h,12);
                cout << "Error! Enter correct choice :(" << endl;
                SetConsoleTextAttribute(h,9);
            }
            cout << "---> Enter Answer: ";
            SetConsoleTextAttribute(h, 15);
            cin >> a;
            SetConsoleTextAttribute(h, 9);
            r = true;
        } while (a != "y" && a != "Y" && a != "yes" && a != "Yes" && a != "YES" && a != "yES" && a != "yEs" &&
                 a != "YeS" && a != "n" && a != "N" && a != "no" && a != "No" && a != "NO" && a != "nO");
    }
    if (a =="y" || a=="Y" || a=="yes" || a=="Yes" || a=="YES" || a=="yES" || a=="yEs" || a=="YeS")
    {
        system("cls");
        system_interface();
        f.display_last_ticket();
        system("pause");
    }else
    {
        f.delete_last_ticket();
    }
}

void Employee::display_movies_currently_showing_in_cinema() {
    int choice;
    bool r1 = false;
    do {
        system("cls");
        system_interface();
        f.display_movie_name_only();
        SetConsoleTextAttribute(h,6);
        cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[1] Display Show time.    ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[2] Back.                 ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        SetConsoleTextAttribute(h,9);
        if (r1){
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\tError! Enter correct choice :( ." << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t----> Enter Your Choice : ";
        SetConsoleTextAttribute(h,15);
        string CHOICE;
        cin >> CHOICE;
        try {
            std::stoi(CHOICE);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            r1 = true;
            continue;
        }
        choice = stoi(CHOICE);
        SetConsoleTextAttribute(h,9);
        if (choice == 1){
            int ch;
            bool r2 = false;
            r1 = false;
            do {
                system("cls");
                system_interface();
                f.display_movie();
                SetConsoleTextAttribute(h,6);
                cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "\t\t\t&   ";
                SetConsoleTextAttribute(h,9);
                cout << "* to Back enter [1].    ";
                SetConsoleTextAttribute(h,13);
                cout << "&" << endl;
                cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                SetConsoleTextAttribute(h,9);
                if (r2)
                {
                    SetConsoleTextAttribute(h,12);
                    cout << "\t\t\tError! Enter correct choice :( ." << endl;
                    SetConsoleTextAttribute(h,9);
                }
                cout << "\t\t\t----> Enter Your Choice : ";
                SetConsoleTextAttribute(h,15);
                string CH;
                cin >> CH;
                try {
                    std::stoi(CH);
                } catch (std::exception& e) {
                    SetConsoleTextAttribute(h,9);
                    r2 = true;
                    continue;
                }
                ch = stoi(CH);
                SetConsoleTextAttribute(h,9);
                r2 = true;
            } while (ch != 1);
            continue;
        } else if (choice == 2){
            return;
        }
        r1 = true;
    } while (choice != 2);
}

void Employee::view_ticket_booked() {
    int ch;
    bool r2 = false;
    do {
        system("cls");
        system_interface();
        f.display_tickets();
        SetConsoleTextAttribute(h,6);
        cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t&   ";
        SetConsoleTextAttribute(h,9);
        cout << "* to Back enter [1].    ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        SetConsoleTextAttribute(h,9);
        if (r2)
        {
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\tError! Enter correct choice :( ." << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t----> Enter Your Choice : ";
        SetConsoleTextAttribute(h,15);
        string CH;
        cin >> CH;
        try {
            std::stoi(CH);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            r2 = true;
            continue;
        }
        ch = stoi(CH);
        SetConsoleTextAttribute(h,9);
        r2 = true;
    } while (ch != 1);
}

void Employee::display_last_ticket() {
    int ch;
    bool r2 = false;
    do {
        system("cls");
        system_interface();
        f.display_last_ticket();
        SetConsoleTextAttribute(h,6);
        cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t&   ";
        SetConsoleTextAttribute(h,9);
        cout << "* to Back enter [1].    ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        SetConsoleTextAttribute(h,9);
        if (r2)
        {
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\tError! Enter correct choice :( ." << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t----> Enter Your Choice : ";
        SetConsoleTextAttribute(h,15);
        string CH;
        cin >> CH;
        try {
            std::stoi(CH);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            r2 = true;
            continue;
        }
        ch = stoi(CH);
        SetConsoleTextAttribute(h,9);
        r2 = true;
    } while (ch!= 1);
}

void Admin::display_and_edit_movie() {
    int choice;
    bool r = false;
    do{
        system("cls");
        system_interface();
        f.display_movie();
        SetConsoleTextAttribute(h,6);
        cout << "\n\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[1] Add new movie.          ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[2] Delete movie.           ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[3] Back                    ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        SetConsoleTextAttribute(h,9);
        if (r){
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\t\t\t\t\t\t\tError! Enter correct choice :(" << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t\t\t\t\t\t\t----> Enter Your Choice: ";
        SetConsoleTextAttribute(h,15);
        string CHOICE;
        cin >> CHOICE;
        try {
            std::stoi(CHOICE);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            r = true;
            continue;
        }
        choice = stoi(CHOICE);
        SetConsoleTextAttribute(h,9);
        if(choice==1){
            r = false;
            system("cls");
            system_interface();
            string movie_name,show_time1,show_time2,show_time3,show_time4;
            SetConsoleTextAttribute(h,13);
            cout << "\t\t\t\t\t\t\t\t #@#@#@#@ Enter a New Movie :) @#@#@#@#" << endl;
            SetConsoleTextAttribute(h,9);
            cout <<"\t\t\t\t\t-Enter movie name : ";
            SetConsoleTextAttribute(h,15);
            cin.ignore();
            getline(cin,movie_name);
            SetConsoleTextAttribute(h,9);
            cout << "\t\t\t\t\t-Enter first show time : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,show_time1);
            SetConsoleTextAttribute(h,9);
            cout << "\t\t\t\t\t-Enter second show time : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,show_time2);
            SetConsoleTextAttribute(h,9);
            cout << "\t\t\t\t\t-Enter third show time : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,show_time3);
            SetConsoleTextAttribute(h,9);
            cout << "\t\t\t\t\t-Enter fourth show time : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,show_time4);
            SetConsoleTextAttribute(h,9);
            f.insert_movie( movie_name,  show_time1,  show_time2,  show_time3,  show_time4);
            continue;
        }else if(choice==2){
            int pos;
            do {
                system("cls");
                system_interface();
                f.display_movie();
                if (r){
                    SetConsoleTextAttribute(h,12);
                    cout << "\t\t\t Error! Enter correct choice :(";
                    SetConsoleTextAttribute(h,9);
                }
                cout<<"\n\t\t\t-Enter number of film do you want delete :";
                SetConsoleTextAttribute(h,15);
                string POS;
                cin >> POS;
                try {
                    std::stoi(POS);
                } catch (std::exception& e) {
                    SetConsoleTextAttribute(h,9);
                    r = true;
                    continue;
                }
                pos = stoi(POS);
                if (pos > 0 && pos <= f.get_number_of_movie(1)){
                    r = false;
                    break;
                }
                SetConsoleTextAttribute(h,9);
                r = true;
            } while (true);
            SetConsoleTextAttribute(h,9);
            f.delete_movie(pos);
            continue;
        }
        r = true;
    }
    while(choice!=3);
}

void Admin::display_and_edit_ticket() {
    int choice = 4;
    bool r = false;
    string movie_name; int number_of_individuals; string show_time; string chair_number; double price;
    do {
        system("cls");
        system_interface();
        f.display_tickets();
        SetConsoleTextAttribute(h,6);
        cout << "\n\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[1] Ticket booking.         ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[2] Delete ticket.          ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t\t\t\t\t\t\t&  ";
        SetConsoleTextAttribute(h,9);
        cout << "[3] Back                    ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        SetConsoleTextAttribute(h,9);
        if (r){
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\t\t\t\t\t\t\tError! Enter correct choice :(" << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t\t\t\t\t\t\t----> Enter Your Choice: ";
        SetConsoleTextAttribute(h,15);
        string CHOICE;
        cin >> CHOICE;
        try {
            std::stoi(CHOICE);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            r = true;
            continue;
        }
        choice = stoi(CHOICE);
        SetConsoleTextAttribute(h,9);
        if(choice==1){
            r = false;
            booking_ticket();
            continue;
        }else if(choice==2){
            string T;
            do {
                string t;
                system("cls");
                system_interface();
                f.display_tickets();
                if (r){
                    SetConsoleTextAttribute(h,12);
                    cout << "\t\t Error! Enter correct choice :(" << endl;
                    SetConsoleTextAttribute(h,9);
                }
                cout<<"\t\t Enter id to remove a ticket : ";
                SetConsoleTextAttribute(h,15);
                cin >> T;
                try {
                    std::stoi(T);
                } catch (std::exception& e) {
                    SetConsoleTextAttribute(h,9);
                    r = true;
                    continue;
                }
                if (f.find_ticket_id(T))
                {
                    r = false;
                    break;
                    SetConsoleTextAttribute(h,9);
                }
                SetConsoleTextAttribute(h,9);
                r = true;
            } while (true);
            f.Delete_ticket(T);
            continue;
        }
        r = true;
    }while(choice != 3);
}

void Admin::display_last_ticket() {
    int ch;
    bool r2 = false;
    do {
        system("cls");
        system_interface();
        f.display_last_ticket();
        SetConsoleTextAttribute(h,6);
        cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t&   ";
        SetConsoleTextAttribute(h,9);
        cout << "[1] Delete last Ticket. ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        SetConsoleTextAttribute(h,6);
        cout << "\t\t\t&   ";
        SetConsoleTextAttribute(h,9);
        cout << "[2] Back.               ";
        SetConsoleTextAttribute(h,13);
        cout << "&" << endl;
        cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        SetConsoleTextAttribute(h,9);
        if (r2)
        {
            SetConsoleTextAttribute(h,12);
            cout << "\t\t\tError! Enter correct choice :(" << endl;
            SetConsoleTextAttribute(h,9);
        }
        cout << "\t\t\t----> Enter Your Choice : ";
        SetConsoleTextAttribute(h,15);
        string CH;
        cin >> CH;
        try {
            std::stoi(CH);
        } catch (std::exception& e) {
            SetConsoleTextAttribute(h,9);
            r2 = true;
            continue;
        }
        ch = stoi(CH);
        SetConsoleTextAttribute(h,9);
        if (ch == 1)
        {
            r2 = false;
            f.delete_last_ticket();
            continue;
        }
        r2 = true;
    } while (ch!= 2);
}

void Admin::rest_and_delete_all_ticket_file() {
    system("cls");
    system_interface();
    if (f.check_password())
    {
        f.reset_data_in_ticket_file_system();
        SetConsoleTextAttribute(h,10);
        cout << "\n\t\t\t\t#@#@#@#@  All Ticket System File Data Reset successfully :)  @#@#@#@#" << endl;
        SetConsoleTextAttribute(h,9);
        system("pause");
    }else{
        SetConsoleTextAttribute(h,12);
        cout << "\n\t\t\t\t#@#@#@#@  Error! No change in Ticket System File Data :(  @#@#@#@#" << endl;
        SetConsoleTextAttribute(h,9);
        system("pause");
    }
}

bool Admin::rest_and_delete_all_system_file() {
    system("cls");
    system_interface();
    if (f.check_password())
    {
        f.reset_all_system_data();
        SetConsoleTextAttribute(h,10);
        cout << "\n\t\t\t\t#@#@#@#@  All Ticket System File Data Reset successfully :)  @#@#@#@#" << endl;
        SetConsoleTextAttribute(h,9);
        system("pause");
        return true;
    }else{
        SetConsoleTextAttribute(h,12);
        cout << "\n\t\t\t\t#@#@#@#@  Error! No change System File Data :(  @#@#@#@#" << endl;
        SetConsoleTextAttribute(h,9);
        system("pause");
        return false;
    }
}

void Admin::modify_password() {
    system("cls");
    system_interface();
    f.modify_password();
    system("pause");
}
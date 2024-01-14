#include <iostream>
#include <string>
#include <windows.h>

class Bank {
private:
    int total;
    std::string id;

    struct Person {
        std::string name, ID, address;
        int contact, cash;
    } person[100];

public:
    Bank() {
        total = 0;
    }

    void choice();
    void perData();
    void show();
    void update();
    void search();
    void transactions();
    void del();
};

int main() {
    Bank b;
    b.choice();
    return 0;
}

void Bank::choice() {
    char ch;
    while (true) {
        std::cout << "\n\nPRESS..!!" << std::endl;
        std::cout << "1. Create new account" << std::endl;
        std::cout << "2. View customers list" << std::endl;
        std::cout << "3. Update information of existing account" << std::endl;
        std::cout << "4. Check the details of an existing account" << std::endl;
        std::cout << "5. For transactions" << std::endl;
        std::cout << "6. Remove existing account" << std::endl;
        std::cout << "7. Exit" << std::endl;
        ch = _getch();
        system("CLS");
        switch (ch) {
            case '1':
                perData();
                break;
            case '2':
                if (total == 0) {
                    std::cout << "No data is entered" << std::endl;
                } else {
                    show();
                }
                break;
            case '3':
                if (total == 0)
                    std::cout << "No data is entered" << std::endl;
                else
                    update();
                break;
            case '4':
                if (total == 0)
                    std::cout << "No data is entered" << std::endl;
                else
                    search();
                break;
            case '5':
                if (total == 0)
                    std::cout << "No data is entered" << std::endl;
                else
                    transactions();
                break;
            case '6':
                if (total == 0)
                    std::cout << "No data is entered" << std::endl;
                else
                    del();
                break;
            case '7':
                exit(0);
                break;
            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
    }
}

void Bank::perData() {
    std::cout << "Enter data of person " << total + 1 << std::endl;
    std::cout << "Enter name: ";
    std::cin >> person[total].name;
    std::cout << "ID: ";
    std::cin >> person[total].ID;
    std::cout << "Address: ";
    std::cin >> person[total].address;
    std::cout << "Contact: ";
    std::cin >> person[total].contact;
    std::cout << "Total Cash: ";
    std::cin >> person[total].cash;
    total++;
}

void Bank::show() {
    for (int i = 0; i < total; i++) {
        std::cout << "Data of person " << i + 1 << std::endl;
        std::cout << "Name: " << person[i].name << std::endl;
        std::cout << "ID: " << person[i].ID << std::endl;
        std::cout << "Address: " << person[i].address << std::endl;
        std::cout << "Contact: " << person[i].contact << std::endl;
        std::cout << "Cash: " << person[i].cash << std::endl;
    }
}

void Bank::update() {
    std::cout << "Enter id of student whose data you want to update" << std::endl;
    std::cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            std::cout << "Previous data" << std::endl;
            std::cout << "Data of person " << i + 1 << std::endl;
            std::cout << "Name: " << person[i].name << std::endl;
            std::cout << "ID: " << person[i].ID << std::endl;
            std::cout << "Address: " << person[i].address << std::endl;
            std::cout << "Contact: " << person[i].contact << std::endl;
            std::cout << "Cash: " << person[i].cash << std::endl;
            std::cout << "\nEnter new data" << std::endl;
            std::cout << "Enter name: ";
            std::cin >> person[i].name;
            std::cout << "ID: ";
            std::cin >> person[i].ID;
            std::cout << "Address: ";
            std::cin >> person[i].address;
            std::cout << "Contact: ";
            std::cin >> person[i].contact;
            std::cout << "Total Cash: ";
            std::cin >> person[i].cash;
            break;
        }
        if (i == total - 1) {
            std::cout << "No such record found" << std::endl;
        }
    }
}

void Bank::search() {
    std::cout << "Enter id of student whose data you want to search" << std::endl;
    std::cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            std::cout << "Name: " << person[i].name << std::endl;
            std::cout << "ID: " << person[i].ID << std::endl;
            std::cout << "Address: " << person[i].address << std::endl;
            std::cout << "Contact: " << person[i].contact << std::endl;
            std::cout << "Cash: " << person[i].cash << std::endl;
            break;
        }
        if (i == total - 1) {
            std::cout << "No such record found" << std::endl;
        }
    }
}

void Bank::transactions() {
    int cash;
    char ch;
    std::cout << "Enter id of student whose data you want to transaction" << std::endl;
    std::cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            std::cout << "Name: " << person[i].name << std::endl;
            std::cout << "Address: " << person[i].address << std::endl;
            std::cout << "Contact: " << person[i].contact << std::endl;
            std::cout << "\nExisting Cash " << person[i].cash << std::endl;
            std::cout << "Press 1 to deposit" << std::endl;
            std::cout << "Press 2 to withdraw" << std::endl

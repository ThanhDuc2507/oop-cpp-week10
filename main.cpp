
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    void input() {
        cout << "Nhap ID: ";
        getline(cin, id);

        cout << "Nhap ten mon an: ";
        getline(cin, name);

        cout << "Nhap gia: ";
        cin >> price;

        quantity = 0;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() {
        cout << id << " - " << name
             << " - " << price
             << " (" << quantity << ")" << endl;
    }

    void updatePrice() {
        cout << "Nhap gia moi cho " << name << ": ";
        cin >> price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Cap nhat gia thanh cong!\n";
    }
};

int main() {
    const int n = 3;
    Food foods[n];

    cout << "=== NHAP THONG TIN 3 MON AN ===\n";

    for (int i = 0; i < n; i++) {
        cout << "\nMon an thu " << i + 1 << ":\n";
        foods[i].input();
    }

    cout << "\n=== DANH SACH MON AN ===\n";

    for (int i = 0; i < n; i++) {
        foods[i].display();
    }

    string searchName;
    cout << "\nNhap ten mon an can tim: ";
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (foods[i].name == searchName) {
            cout << "\nTim thay mon an:\n";
            foods[i].display();
            found = true;

            cout << "\nBan co muon cap nhat gia? (1: Co, 0: Khong): ";
            int choice;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == 1) {
                foods[i].updatePrice();

                cout << "\nThong tin sau khi cap nhat:\n";
                foods[i].display();
            }

            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!\n";
    }

    cout << "\n=== DANH SACH MON AN CUOI CUNG ===\n";

    for (int i = 0; i < n; i++) {
        foods[i].display();
    }

    return 0;
}

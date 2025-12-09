#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

#include "Add.h"

struct Item {
    int id;
    string nama;
    double harga;
};



// Fungsi ini kini hanya memerlukan 'baris' yang dipilih
void Front_page(const vector<Item>& table, int baris) {
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "=========================\n\n";
    for (int i = 0; i < table.size(); i++) {

        bool selected = (i == baris);

        if (selected)
            SetConsoleTextAttribute(hConsole, 0x70);
        else
            SetConsoleTextAttribute(hConsole, 7);

        cout << table[i].id << " ";
        cout << table[i].nama << "\n";
    }


    SetConsoleTextAttribute(hConsole, 7); 
    cout << "\n=========================";
}


int main() {

    Add add;

    vector<Item> table = { {1, "Lihat Senarai Item"},
                            {2, "Tambah Item Baru"},
                            {3, "Padam Item"},
                            {4, "Update Item"}
    };

    int baris = 0;
    char ch;

    while (true) {
        Front_page(table, baris);
        ch = _getch();

        if (ch == 27) break; // ESC

        if (ch == 0 || ch == -32) {
            switch (_getch()) {
            case 72: baris = (baris == 0 ? table.size() - 1 : baris - 1); break; // UP
            case 80: baris = (baris + 1) % table.size(); break;              // DOWN
            }
        }

        if (ch == 13) {
            system("cls");
            
            if (baris == 0) {
                //cout << table[baris].nama;
                add.show();
            }
            else if (baris == 1) {
                cout << table[baris].nama;
            }
            else if (baris == 2) {
                cout << table[baris].nama;
            }
            else if (baris == 3) {
                cout << table[baris].nama;
            }

            _getch();
        }
    }


    cout << "\nProgram tamat.\n";
    return 0;
}
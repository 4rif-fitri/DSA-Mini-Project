#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;
#include "List.h"

class Add {
public:
    struct Item {
        int id;
        string nama;
        double harga;
    };
    Listt<string,double> x;



    void Front_page(const vector<Item>& table, int baris) {
        system("cls");

        //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        //cout << "=========================\n\n";
        //for (int i = 0; i < table.size(); i++) {

        //    bool selected = (i == baris);

        //    if (selected)
        //        SetConsoleTextAttribute(hConsole, 0x70);
        //    else
        //        SetConsoleTextAttribute(hConsole, 7);

        //    //cout << table[i].id << "  ";
        //    //cout << table[i].nama <<  " ";
        //    //cout << table[i].harga << "\n";

        //}

            x.printData(baris);



        //SetConsoleTextAttribute(hConsole, 7);
        cout << "\n=========================";
    }

	void show() {
        for (int i = 1; i < 4; i++)
        {
            x.AddToFront();
        }
		system("cls");
		cout << "=========================\n";
		cout << "=========== ADD =========\n";
		cout << "=========================\n";

        vector<Item> table = { {1, "Papaya", 10},
                        {2, "Durian", 3.1},
                        {3, "Rambutan",50},
                        {4, "Nangka", 50}
        };
		int baris = 1;
		char ch;

        while (true) {
            Front_page(table, baris);
            ch = _getch();

            if (ch == 27) {
                cout << "\ntekan lagi esc";
                break;
            }
            if (ch == 0 || ch == -32) {
                switch (_getch()) {
                case 72: 
                    baris = (baris == 0 ? table.size() - 1 : baris);       
                    break;
                case 80: 
                    baris = (baris + 1) % table.size(); 
                    break;
                }
            }

        }
    }
};
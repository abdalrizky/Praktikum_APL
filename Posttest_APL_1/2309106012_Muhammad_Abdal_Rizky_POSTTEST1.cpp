// Nama: Muhammad Abdal Rizky
// NIM: 2309106012

#include <iostream>
using namespace std;

struct
{
    string username;
    string password;
} login = {"Muhammad Abdal Rizky", "2309106012"};

int main()
{
    system("cls");
    cout << "Silakan login terlebih dahulu." << endl;

    int loginAttempt = 0;
    while (loginAttempt < 3)
    {
        string usernameInput, passwordInput;

        cout << "Username: ";
        getline(cin, usernameInput);

        cout << "Password: ";
        getline(cin, passwordInput);

        if (usernameInput == login.username && passwordInput == login.password) {
            system("cls");
            cout << "Login Berhasil" << endl;
            break;
        }
        else {
            cout << "Username atau password salah." << endl;
            loginAttempt++;
        }
    }
    
    if (loginAttempt == 3) {
        cout << "Kamu sudah mencoba login sebanyak 3 kali. Program dihentikan." << endl;
        return 0;
    }
    
    char repeat;
    do {
        cout << "Selamat datang di Program Konversi Mata Uang" << endl;
        cout << "[1] Rupiah ke Dollar, Euro, Yen" << endl;
        cout << "[2] Dollar ke Rupiah, Euro, Yen" << endl;
        cout << "[3] Euro ke Rupiah, Dollar, Yen" << endl;
        cout << "[4] Yen ke Rupiah, Dollar, Euro" << endl;
        cout << "[5] Keluar dari program" << endl;

        int choice;
        cout << "Pilih konversi >> ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore();
            system("cls");
            cout << "Pilihan tidak valid." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                double rupiah;

                do {
                    cout << "Masukkan jumlah Rupiah >> ";
                    cin >> rupiah;
                } while (rupiah < 0);
                
                cout << "\nBerikut hasil konversi " << rupiah << " rupiah ke beberapa mata uang." << endl;
                cout << "Dollar: " << rupiah / 15701.95 << endl;
                cout << "Euro: " << rupiah / 17043.68 << endl;
                cout << "Yen: " << rupiah / 104.61 << endl;

                break;
            case 2:
                double dollar;

                do {
                    cout << "Masukkan jumlah Dollar >> ";
                    cin >> dollar;
                } while (dollar < 0);

                cout << "\nBerikut hasil konversi " << dollar << " dollar ke beberapa mata uang." << endl;
                cout << "Rupiah: " << dollar * 15701.95 << endl;
                cout << "Euro: " << dollar / 1.09 << endl;
                cout << "Yen: " << dollar * 150.10 << endl;
                break;

            case 3:
                double euro;

                do {
                    cout << "Masukkan jumlah Euro >> ";
                    cin >> euro;
                } while (euro < 0);

                cout << "\nBerikut hasil konversi " << euro << " euro ke beberapa mata uang." << endl;
                cout << "Rupiah: " << euro * 17043.68 << endl;  
                cout << "Dollar: " << euro * 1.09 << endl;
                cout << "Yen: " << euro * 162.93 << endl;
                break;
            case 4:
                double yen;
                
                do {
                    cout << "Masukkan jumlah Yen >> ";
                    cin >> yen;
                } while (euro < 0);

                cout << "\nBerikut hasil konversi " << yen << " yen ke beberapa mata uang." << endl;
                cout << "Rupiah: " << yen * 104.61 << endl;
                cout << "Dollar: " << yen / 150.10 << endl;
                cout << "Euro: " << yen / 162.93 << endl;
                break;
            case 5:
                cout << "Program diakhiri. Terima kasih telah menggunakan program konversi mata uang." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        
        do {
            cout << "Apakah kamu ingin mengulang program? (y/n) >> ";
            cin >> repeat;
            
        } while (repeat != 'y' && repeat != 'n');

        if (repeat == 'y') {
            system("cls");
        }
        
    } while (repeat != 'n');

    cout << "Program diakhiri. Terima kasih telah menggunakan program konversi mata uang." << endl;

    return 0;
}

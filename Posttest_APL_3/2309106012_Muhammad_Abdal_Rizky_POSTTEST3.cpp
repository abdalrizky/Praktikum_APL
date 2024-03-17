// Nama: Muhammad Abdal Rizky
// NIM: 2309106012

#include <iostream>
using namespace std;

struct
{
    string username;
    string password;
} login = {"Muhammad Abdal Rizky", "2309106012"};

string corporations[10] = {
    "PT Telkom Indonesia",
    "PT Pertamina",
    "PT Bank Mandiri",
    "PT Bank Rakyat Indonesia",
    "PT Bank Negara Indonesia",
    "PT Bank Tabungan Negara",
    "PT Perusahaan Listrik Negara",
};

int currentAmountOfCorporations = 7;

// Fungsi Rekursif
int showCorporations(int index = 0)
{
    if (index >= currentAmountOfCorporations)
        return 0;

    cout << index + 1 << ". " << corporations[index] << endl;
    return showCorporations(index + 1);
}

bool loginCredentialCheck(string usernameInput, string passwordInput)
{
    if (usernameInput == login.username && passwordInput == login.password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void addCorporation()
{
    system("cls");
    cout << "Tambah Perusahaan Baru" << endl;
    cout << endl;
    cout << "Masukkan nama perusahaan >> ";
    cin.ignore();
    getline(cin, corporations[currentAmountOfCorporations]);
    currentAmountOfCorporations++;

    cout << endl;
    cout << "==============================================" << endl;
    cout << "Perusahaan berhasil ditambahkan." << endl;
    cout << "==============================================" << endl;
    cout << endl;
}

void updateCorporation()
{
    system("cls");
    showCorporations();
    cout << endl;

    cout << "Pilih nomor urut perusahaan yang ingin diubah >> ";
    int choice;
    cin >> choice;

    cout << "Masukkan nama perusahaan baru >> ";
    cin.ignore();
    getline(cin, corporations[choice - 1]);

    cout << endl;
    cout << "==============================================" << endl;
    cout << "Perusahaan berhasil diperbarui." << endl;
    cout << "==============================================" << endl;
    cout << endl;
}

void deleteCorporation()
{
    system("cls");
    showCorporations();
    cout << endl;

    cout << "Pilih nomor urut perusahaan yang ingin dihapus >> ";
    int choice;
    cin >> choice;

    for (int i = choice - 1; i < currentAmountOfCorporations; i++)
    {
        corporations[i] = corporations[i + 1];
    }
    currentAmountOfCorporations--;

    cout << endl;
    cout << "==============================================" << endl;
    cout << "Perusahaan berhasil dihapus." << endl;
    cout << "==============================================" << endl;
    cout << endl;
}

void showMainMenu()
{
    system("cls");
    cout << "Selamat datang di Program CRUD Perusahaan BUMN" << endl;
    cout << "==============================================" << endl;
    cout << "[1] Tampilkan seluruh perusahaan" << endl;
    cout << "[2] Tambahkan perusahaan baru" << endl;
    cout << "[3] Ubah nama perusahaan" << endl;
    cout << "[4] Hapus perusahaan" << endl;
    cout << "[5] Keluar dari program" << endl;
    cout << "==============================================" << endl;
}

void mainMenuHandler(int choice)
{
    switch (choice)
    {
    case 1:
        system("cls");
        if (currentAmountOfCorporations > 0)
        {
            cout << "Berikut ditampilkan perusahaan BUMN yang terdaftar: " << endl;
            showCorporations();
            cout << endl;
            cin.ignore();
            break;
        }
        else
        {
            cout << "Belum ada perusahaan yang terdaftar." << endl;
            cout << endl;
            cin.ignore();
            break;
        }

    case 2:
        addCorporation();
        break;

    case 3:
        updateCorporation();
        break;

    case 4:
        deleteCorporation();
        break;

    case 5:
        cout << "==============================================" << endl;
        cout << "Terima kasih telah menggunakan program ini." << endl;
        cout << "==============================================" << endl;
        exit(0);
        break;

    default:
        break;
    }
}

void loginHandler()
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

        if (loginCredentialCheck(usernameInput, passwordInput))
        {
            system("cls");
            cout << "Login Berhasil" << endl;
            break;
        }
        else
        {
            cout << "Username atau password salah." << endl;
            loginAttempt++;
            if (loginAttempt == 3)
            {
                cout << "Kamu sudah mencoba login sebanyak 3 kali. Program dihentikan." << endl;
                exit(0);
            }
        }
    }
}

int main()
{
    int choice;

    loginHandler();

    do
    {
        showMainMenu();

        cout << "Pilih menu >> ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5)
        {
            cin.clear();
            cin.ignore();
            continue;
        }

        mainMenuHandler(choice);

        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();

    } while (choice != 5);

    return 0;
}

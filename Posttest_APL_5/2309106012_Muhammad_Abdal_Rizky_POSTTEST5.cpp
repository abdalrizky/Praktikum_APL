// Nama: Muhammad Abdal Rizky
// NIM: 2309106012

#include <iostream>
using namespace std;

struct
{
    string username;
    string password;
} login = {"Muhammad Abdal Rizky", "2309106012"};

struct Location
{
    string city;
    string province;
};

struct Corporation
{
    string name;
    string sector;
    Location *location;
};

Corporation corporations[10] = {
    {"PT Telkom Indonesia", "Telekomunikasi", new Location {"Bandung", "Jawa Barat"}},
    {"PT Pertamina", "Energi", new Location {"Jakarta", "DKI Jakarta"}},
    {"PT Bank Mandiri", "Perbankan", new Location {"Jakarta", "DKI Jakarta"}},
    {"PT Bank Rakyat Indonesia", "Perbankan", new Location {"Jakarta", "DKI Jakarta"}},
    {"PT Bank Negara Indonesia", "Perbankan", new Location {"Jakarta", "DKI Jakarta"}},
    {"PT Bank Tabungan Negara", "Perbankan", new Location {"Jakarta", "DKI Jakarta"}},
    {"PT Perusahaan Listrik Negara", "Energi", new Location {"Jakarta", "DKI Jakarta"}},
};

int currentAmountOfCorporations = 7;

int showCorporations(Corporation *corporations, int *currentAmountOfCorporations, int index = 0)
{
    if (index >= *currentAmountOfCorporations)
        return 0;

    Corporation corporation = corporations[index];

    cout << index + 1 << ". " << corporation.name << endl;
    cout << "   Sektor: " << corporation.sector << endl;
    cout << "   Lokasi: " << corporation.location->city << ", " << corporation.location->province << endl;

    return showCorporations(corporations, currentAmountOfCorporations, index + 1);
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
    cout << "Tambah Perusahaan Baru (Kosongkan semua apabila ingin membatalkan)" << endl;
    cout << endl;

    string name, sector, city, province;

    cout << "Masukkan nama perusahaan >> ";
    cin.ignore();
    getline(cin, name);

    cout << "Masukkan sektor perusahaan >> ";
    getline(cin, sector);

    cout << "Masukkan kota perusahaan >> ";
    getline(cin, city);

    cout << "Masukkan provinsi perusahaan >> ";
    getline(cin, province);

    if (name == "" || sector == "" || city == "" || province == "")
    {
        cout << endl;
        cout << "==============================================" << endl;
        cout << "Proses dibatalkan." << endl;
        cout << "==============================================" << endl;
        cout << endl;
    }
    else
    {
        corporations[currentAmountOfCorporations].name = name;
        corporations[currentAmountOfCorporations].sector = sector;
        corporations[currentAmountOfCorporations].location = new Location {city, province};
        currentAmountOfCorporations++;

        cout << endl;
        cout << "==============================================" << endl;
        cout << "Perusahaan berhasil ditambahkan." << endl;
        cout << "==============================================" << endl;
        cout << endl;
    }
}

void updateCorporation()
{
    system("cls");
    showCorporations(corporations, &currentAmountOfCorporations);
    cout << endl;

    cout << "Pilih nomor urut perusahaan yang ingin diubah >> ";
    int choice;
    cin >> choice;

    try
    {
        if (choice < 1 || choice > currentAmountOfCorporations || cin.fail())
        {
            throw -1;
        }
    }
    catch (int e)
    {
        cout << "Nomor urut perusahaan tidak valid." << endl;
        cin.ignore();
        return;
    }

    string newName, newSector, newCity, newProvince;

    cout << "Masukkan nama perusahaan baru (Kosongkan jika tidak diubah) >> ";
    cin.ignore();
    getline(cin, newName);
    if (newName != "")
    {
        corporations[choice - 1].name = newName;
    }

    cout << "Masukkan sektor perusahaan baru (Kosongkan jika tidak diubah) >> ";
    getline(cin, newSector);
    if (newSector != "")
    {
        corporations[choice - 1].sector = newSector;
    }

    cout << "Masukkan kota perusahaan baru (Kosongkan jika tidak diubah) >> ";
    getline(cin, newCity);
    if (newCity != "")
    {
        corporations[choice - 1].location->city = newCity;
    }

    cout << "Masukkan provinsi perusahaan baru (Kosongkan jika tidak diubah) >> ";
    getline(cin, newProvince);
    if (newProvince != "")
    {
        corporations[choice - 1].location->province = newProvince;
    }

    cout << endl;
    cout << "==============================================" << endl;
    cout << "Perusahaan berhasil diperbarui." << endl;
    cout << "==============================================" << endl;
    cout << endl;
}

void deleteCorporation()
{
    system("cls");
    showCorporations(corporations, &currentAmountOfCorporations);
    cout << endl;

    cout << "Pilih nomor urut perusahaan yang ingin dihapus >> ";
    int choice;
    cin >> choice;

    try
    {
        if (choice < 1 || choice > currentAmountOfCorporations || cin.fail())
        {
            throw -1;
        }
    }
    catch (int e)
    {
        cout << "Nomor urut perusahaan tidak valid." << endl;
        cin.ignore();
        return;
    }

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
    cin.ignore();
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
            showCorporations(corporations, &currentAmountOfCorporations);
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

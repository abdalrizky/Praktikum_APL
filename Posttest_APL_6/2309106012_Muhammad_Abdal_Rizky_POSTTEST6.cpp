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
    double revenue;
    int branchAmount;
};

Corporation corporations[10] = {
    {"PT Telkom Indonesia", "Telekomunikasi", new Location{"Bandung", "Jawa Barat"}, 25.66, 10},
    {"PT Pertamina", "Energi", new Location{"Jakarta", "DKI Jakarta"}, 548.29, 30},
    {"PT Bank Mandiri", "Perbankan", new Location{"Jakarta", "DKI Jakarta"}, 105.86, 20},
    {"PT Bank Rakyat Indonesia", "Perbankan", new Location{"Jakarta", "DKI Jakarta"}, 19.07, 15},
    {"PT Bank Negara Indonesia", "Perbankan", new Location{"Jakarta", "DKI Jakarta"}, 7.77, 45},
    {"PT Pupuk Indonesia", "Pertanian", new Location{"Jakarta", "DKI Jakarta"}, 56.02, 70},
    {"PT Perusahaan Listrik Negara", "Energi", new Location{"Jakarta", "DKI Jakarta"}, 12.45, 225},
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
    cout << "   Pendapatan per tahun: " << corporation.revenue << " triliun" << endl;
    cout << "   Jumlah cabang: " << corporation.branchAmount << " cabang" << endl;
    cout << "==============================================" << endl;

    return showCorporations(corporations, currentAmountOfCorporations, index + 1);
}

bool loginCredentialCheck(string &usernameInput, string &passwordInput)
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
    double revenue;
    int branchAmount;

    cout << "Masukkan nama perusahaan >> ";
    cin.ignore();
    getline(cin, name);

    cout << "Masukkan sektor perusahaan >> ";
    getline(cin, sector);

    cout << "Masukkan kota perusahaan >> ";
    getline(cin, city);

    cout << "Masukkan provinsi perusahaan >> ";
    getline(cin, province);

    cout << "Masukkan pendapatan perusahaan >> ";
    cin >> revenue;

    cout << "Masukkan jumlah cabang perusahaan >> ";
    cin >> branchAmount;

    if (name == "" || sector == "" || city == "" || province == "" || revenue == 0 || branchAmount == 0)
    {
        cout << endl;
        cout << "==============================================" << endl;
        cout << "Proses dibatalkan." << endl;
        cout << "==============================================" << endl;
        cout << endl;
        cin.ignore();
    }
    else
    {
        corporations[currentAmountOfCorporations].name = name;
        corporations[currentAmountOfCorporations].sector = sector;
        corporations[currentAmountOfCorporations].location = new Location{city, province};
        corporations[currentAmountOfCorporations].revenue = revenue;
        corporations[currentAmountOfCorporations].branchAmount = branchAmount;
        currentAmountOfCorporations++;

        cout << endl;
        cout << "==============================================" << endl;
        cout << "Perusahaan berhasil ditambahkan." << endl;
        cout << "==============================================" << endl;
        cout << endl;
        cin.ignore();
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
    double newRevenue;
    int newBranchAmount;

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

    cout << "Masukkan pendapatan perusahaan baru (Kosongkan jika tidak diubah) >> ";
    cin >> newRevenue;
    if (newRevenue != 0)
    {
        corporations[choice - 1].revenue = newRevenue;
    }

    cout << "Masukkan jumlah cabang perusahaan baru (Kosongkan jika tidak diubah) >> ";
    cin >> newBranchAmount;
    if (newBranchAmount != 0)
    {
        corporations[choice - 1].branchAmount = newBranchAmount;
    }

    cout << endl;
    cout << "==============================================" << endl;
    cout << "Perusahaan berhasil diperbarui." << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cin.ignore();
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

// Sorting huruf
Corporation *selectionSortByName(Corporation corporations[], int currentAmountOfCorporations, bool isAscending)
{
    int i, j, minIndex;
    Corporation temp;

    Corporation *sortedCorporations = new Corporation[currentAmountOfCorporations];
    for (i = 0; i < currentAmountOfCorporations; i++)
    {
        sortedCorporations[i] = corporations[i];
    }

    for (i = 0; i < currentAmountOfCorporations - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < currentAmountOfCorporations; j++)
        {
            if (isAscending)
            {
                if (sortedCorporations[j].name < sortedCorporations[minIndex].name)
                {
                    minIndex = j;
                }
            }
            else
            {
                if (sortedCorporations[j].name > sortedCorporations[minIndex].name)
                {
                    minIndex = j;
                }
            }
        }

        temp = sortedCorporations[i];
        sortedCorporations[i] = sortedCorporations[minIndex];
        sortedCorporations[minIndex] = temp;
    }
    return sortedCorporations;
}

// Sorting angka
Corporation *bubbleSortByRevenue(Corporation corporations[], int currentAmountOfCorporations, bool isAscending)
{
    int i, j;
    Corporation temp;

    Corporation *sortedCorporations = new Corporation[currentAmountOfCorporations];
    for (i = 0; i < currentAmountOfCorporations; i++)
    {
        sortedCorporations[i] = corporations[i];
    }

    for (i = 0; i < currentAmountOfCorporations - 1; i++)
    {
        for (j = 0; j < currentAmountOfCorporations - i - 1; j++)
        {
            if (isAscending)
            {
                if (sortedCorporations[j].revenue > sortedCorporations[j + 1].revenue)
                {
                    temp = sortedCorporations[j];
                    sortedCorporations[j] = sortedCorporations[j + 1];
                    sortedCorporations[j + 1] = temp;
                }
            }
            else
            {
                if (sortedCorporations[j].revenue < sortedCorporations[j + 1].revenue)
                {
                    temp = sortedCorporations[j];
                    sortedCorporations[j] = sortedCorporations[j + 1];
                    sortedCorporations[j + 1] = temp;
                }
            }
        }
    }

    return sortedCorporations;
}

// Sorting angka
Corporation *shellSortByBranchAmount(Corporation corporations[], int currentAmountOfCorporations, bool isAscending)
{

    int gap, i, j;
    Corporation temp;

    Corporation *sortedCorporations = new Corporation[currentAmountOfCorporations];
    for (int i = 0; i < currentAmountOfCorporations; i++)
    {
        sortedCorporations[i] = corporations[i];
    }

    for (gap = currentAmountOfCorporations / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < currentAmountOfCorporations; i += 1)
        {
            temp = sortedCorporations[i];

            if (isAscending)
            {
                for (j = i; j >= gap && sortedCorporations[j - gap].branchAmount > temp.branchAmount; j -= gap)
                    sortedCorporations[j] = sortedCorporations[j - gap];
            }
            else
            {
                for (j = i; j >= gap && sortedCorporations[j - gap].branchAmount < temp.branchAmount; j -= gap)
                    sortedCorporations[j] = sortedCorporations[j - gap];
            }

            sortedCorporations[j] = temp;
        }
    }

    return sortedCorporations;
}

// Binary search (data terurut ascending)
void binarySearchByName()
{
    string name;
    cout << "Masukkan nama perusahaan yang ingin dicari >> ";
    cin.ignore();
    getline(cin, name);

    // Data diurutkan ascending menggunakan selection sort
    Corporation *sortedCorporations = selectionSortByName(corporations, currentAmountOfCorporations, true);

    int left = 0;
    int right = currentAmountOfCorporations - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (sortedCorporations[mid].name == name)
        {
            cout << "==============================================" << endl;
            cout << "Perusahaan ditemukan pada indeks ke-" << mid << endl;
            cout << "==============================================" << endl;
            cout << "Nama Perusahaan: " << sortedCorporations[mid].name << endl;
            cout << "Sektor: " << sortedCorporations[mid].sector << endl;
            cout << "Lokasi: " << sortedCorporations[mid].location->city << ", " << sortedCorporations[mid].location->province << endl;
            cout << "Jumlah cabang: " << sortedCorporations[mid].branchAmount << " cabang" << endl;
            cout << "==============================================" << endl;
            return;
        }
        else if (sortedCorporations[mid].name > name)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << "Tidak ditemukan" << endl;
}

// Interpolation search (data terurut descending)
void interpolationSearchByBranchAmount()
{
    int branchAmount;
    cout << "Masukkan jumlah cabang perusahaan yang ingin dicari >> ";
    cin.ignore();
    cin >> branchAmount;

    // Data diurutkan descending menggunakan shell sort
    Corporation *sortedCorporations = shellSortByBranchAmount(corporations, currentAmountOfCorporations, false);

    int low = 0;
    int high = currentAmountOfCorporations - 1;

    while (low <= high && branchAmount <= sortedCorporations[low].branchAmount && branchAmount >= sortedCorporations[high].branchAmount)
    {
        if (low == high)
        {
            if (sortedCorporations[low].branchAmount == branchAmount)
            {
                cout << "==============================================" << endl;
                cout << "Perusahaan ditemukan pada indeks ke-" << low << endl;
                cout << "==============================================" << endl;
                cout << "Nama Perusahaan: " << sortedCorporations[low].name << endl;
                cout << "Sektor: " << sortedCorporations[low].sector << endl;
                cout << "Lokasi: " << sortedCorporations[low].location->city << ", " << sortedCorporations[low].location->province << endl;
                cout << "Jumlah cabang: " << sortedCorporations[low].branchAmount << " cabang" << endl;
                cout << "==============================================" << endl;
            }
            else
            {
                cout << "Tidak ditemukan" << endl;
            }
            return;
        }

        int pos = low + (((double)(high - low) / (sortedCorporations[low].branchAmount - sortedCorporations[high].branchAmount)) * (branchAmount - sortedCorporations[high].branchAmount));

        if (sortedCorporations[pos].branchAmount == branchAmount)
        {
            cout << "==============================================" << endl;
            cout << "Perusahaan ditemukan pada indeks ke-" << pos << endl;
            cout << "==============================================" << endl;
            cout << "Nama Perusahaan: " << sortedCorporations[pos].name << endl;
            cout << "Sektor: " << sortedCorporations[pos].sector << endl;
            cout << "Lokasi: " << sortedCorporations[pos].location->city << ", " << sortedCorporations[pos].location->province << endl;
            cout << "Jumlah cabang: " << sortedCorporations[pos].branchAmount << " cabang" << endl;
            cout << "==============================================" << endl;
            return;
        }
        if (sortedCorporations[pos].branchAmount < branchAmount)
        {
            high = pos - 1;
        }
        else
        {
            low = pos + 1;
        }
    }
    cout << "Tidak ditemukan" << endl;
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
    cout << "[5] Urutkan perusahaan berdasarkan nama dengan Selection Sort (Z-A)" << endl;
    cout << "[6] Urutkan perusahaan berdasarkan pendapatan dengan Bubble Sort (A-Z)" << endl;
    cout << "[7] Urutkan perusahaan berdasarkan jumlah cabang dengan Shell Sort (A-Z)" << endl;
    cout << "[8] Cari perusahaan dengan Binary Search" << endl;
    cout << "[9] Cari perusahaan dengan Interpolation Search" << endl;
    cout << "[10] Keluar dari program" << endl;
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
    {
        system("cls");
        Corporation *sortedCorporations = selectionSortByName(corporations, currentAmountOfCorporations, false);
        cout << "Berhasil diurutkan berdasarkan nama perusahaan secara descending (Z-A). Berikut hasilnya." << endl;
        showCorporations(sortedCorporations, &currentAmountOfCorporations);
        cout << endl;
        cin.ignore();
        break;
    }
    case 6:
    {
        system("cls");
        cout << "Data diurutkan berdasarkan jumlah pendapatan perusahaan secara ascending (A-Z). Berikut hasilnya." << endl;
        Corporation *sortedCorporations = bubbleSortByRevenue(corporations, currentAmountOfCorporations, true);
        showCorporations(sortedCorporations, &currentAmountOfCorporations);
        cout << endl;
        cin.ignore();
        break;
    }
    case 7:
    {
        system("cls");
        cout << "Data diurutkan berdasarkan jumlah cabang perusahaan secara ascending (A-Z). Berikut hasilnya." << endl;
        Corporation *sortedCorporations = shellSortByBranchAmount(corporations, currentAmountOfCorporations, true);
        showCorporations(sortedCorporations, &currentAmountOfCorporations);
        cout << endl;
        cin.ignore();
        break;
    }
    case 8:
        system("cls");
        binarySearchByName();
        cout << endl;
        break;
    case 9:
        system("cls");
        interpolationSearchByBranchAmount();
        cout << endl;
        cin.ignore();
        break;
    case 10:
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

        if (cin.fail() || choice < 1 || choice > 10)
        {
            cin.clear();
            cin.ignore();
            continue;
        }

        mainMenuHandler(choice);

        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();

    } while (choice != 10);

    return 0;
}

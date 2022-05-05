
// Mateusz Wabinski_2_rok_4_semestr_nr_indeksu_146326_Grupa_D1

#include <iostream>
#include <fstream>

using namespace std;

const string PLIK_Z_GRAFIKA = "test.bmp";

int main()
{
    ofstream file;
    file.open("meta.ps1");
    string instrukcje;
    instrukcje = "$image = New-Object -ComObject Wia.ImageFile\n";
    instrukcje += "$image.loadfile(\"" + PLIK_Z_GRAFIKA + "\")\n";
    instrukcje += "$image | select -property * -ExcludeProperty FormatID,FileData,ARGBData,Properties,FileExtension";
    file << instrukcje << endl;
    file.close();

    cout << "wczytuje metadane pliku " << PLIK_Z_GRAFIKA << " ..." << endl << endl;

    system("powershell -ExecutionPolicy Bypass -F meta.ps1");

    remove("meta.ps1");
}

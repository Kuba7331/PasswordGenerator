#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

class Password {
private:
	int choice; 
public:
	string password, line, platformName, network_service, network_service2;
    string blank = "";
	string* passwordPointer = &password;
	string* networkServicePointer = &network_service;
	int length;
	int none = 0;
	int lineNumber = 1;
	int x = 0;
	int maxTabelSize = 999;
	char chars[72] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','w','x','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','W','X','X','Y','Z' ,'0','1','2','3','4','5','6','7','8','9','.','!','@','#','$','%','^','&','*','(',')' };
	int getLength() {
		return length;
	}
	string getPassword() {                        //metody GET i SET
		return password;
	}
	string getPlatformName() {
		return platformName;
	}
	string getNetworkService() {
		return network_service;
	}
	void setNetworkService(string network_service) {
		this->network_service = network_service;
	}
	void setPlatformName(string platformName) {
		this->platformName = platformName;	
	}
	void setLength(int length) {
		this->length = length;
	}
	void setPassword(string password) {
		this->password = password;
	}
	void generatePassword() {                      //funkcja generujaca haslo
		srand(time(NULL));
		for (int x = 1; x <= getLength(); x++) {
			int i = rand() % 46;
			password = password + chars[i];
		}
		setPassword(password);
	}
	int gettingData(int var) {                                  //ogolna funkcja do pobierania jakichkolwiek danych, z obsluga bledow
		while (true) {
			if (!(cin >> var)) {
				cin.clear();
				cin.ignore();
				cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
				getchar(); getchar();
				system("cls");
				continue;
			}
			return var;
		}
	}
	string gettingDataString(string var) {                                  //ogolna funkcja do pobierania jakichkolwiek danych, z obsluga bledow, o typie string
		while (true) {
			if (!(cin >> var)) {
				cin.clear();
				cin.ignore();
				cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
				getchar(); getchar();
				system("cls");
				continue;
			}
			return var;
		}
	}
		string savePassword() {                        //funckja zapisujaca haslo do pliku
			fstream plik;
			plik.open("password.txt", ios::out | ios::app );
			if (!(plik.good() == true)) {
				cout << "Wystapil problem z otwarciem pliku!" << endl;
			}
			while (true) {
				cout << "Czy chcesz zapisac to haslo?" << endl;
				cout << "1. Tak" << endl;
				cout << "2. Nie" << endl;
				if (!(cin >> choice)) {
					cin.clear();
					cin.ignore();
					cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
					getchar(); getchar();
					system("cls");
					continue;
				}
				break;
			}
			switch (choice) {                                                
			case 1:
				plik << "Platforma: " << getPlatformName() << endl;
				plik << "Haslo: " << getPassword() << endl;
				cout << "Haslo, i platforma zostalo zapisane w pliku." << endl;
				cout << "Prosze nacisnac jakiekolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
				getchar(); getchar();
				system("cls");
				plik.close();
				setPassword(blank);
				break;
			case 2:
				setPassword(blank);

				break;
			}
			return getPassword();
		}
		string getFromFilePassword() {                   //funkcja odczytujaca haslo z pliku, do ktorego haslo zostalo zapisane
			fstream file;
			int choice2;
			file.open("password.txt", ios::in);
			if (!(file.good() == true)) {
				cout << "Wystapil problem z otwarciem pliku!" << endl;
			}
			system("cls");
			while (getline(file, line)) {
				cout << line << endl;
			}
			file.close();
			while (true) {
				cout << "Czy chcesz usunac dane z pliku?" << endl;
				cout << "1. Tak" << endl;
				cout << "2. Nie" << endl;
				if (!(cin >> choice2)) {
					cin.clear();
					cin.ignore();
					cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
					getchar(); getchar();
					system("cls");
					continue;
				}

				switch (choice2) {
				case 1:
					remove("password.txt");
					cout << "Dane zostale usuniete." << endl;
					cout << "Prosze nacisnac jakikolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
					getchar(); getchar();
					system("cls");
					return getPassword();
					break;
				case 2:
					break;
				}
				break;
			}
			cout << "Prosze nacisnac jakikolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
			getchar(); getchar();
			system("cls");
			return getPassword();
		}
		void readAndGetTwoLinesFromFile() {
			fstream file3;
			file3.open("password.txt", ios::in);
			if (!(file3.good() == true)) {
				cout << "Wystapil problem z otwarciem pliku!" << endl;
				cout << "Prosze nacisnac jakikolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
				getchar(); getchar();
				system("cls");
			}

				passwordPointer = new string[maxTabelSize];
				networkServicePointer = new string[maxTabelSize];
				while (getline(file3, line)) {
					switch (lineNumber) {
					case 1:
						networkServicePointer[x] = line;
						break;
					case 2:
						passwordPointer[x] = line;
						break;
					}
					if (lineNumber == 2) {
						lineNumber = 0;
						x++;
					}
					lineNumber++;
				}
				while (true) {
					cout << "Prosze podac nazwe uslugi sieciowej, do ktorej jest potrzebne haslo:" << endl;
					if (!(cin >> network_service2)) {
						cin.clear();
						cin.ignore();
						cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
						getchar(); getchar();
						system("cls");
						continue;
					}
					for (int i = 0; i <= x; i++) {
						if ((networkServicePointer[i] == "Platforma: " + network_service2)) {
							cout << networkServicePointer[i] << endl;
							cout << passwordPointer[i] << endl;
							cout << "Prosze nacisnac jakikolwiek przycisk, aby wrocic do menu." << endl;
							getchar(); getchar();
							system("cls");
							break;
						}
						if (networkServicePointer[i] != "Platforma: " + network_service2) {
							none++;
						}
						if (none >= x) {
							cout << "Podana usluga sieciowa, nie jest zapisana, lub zostala blednie wpisana, prosze wpisac nazwe uslugi ponownie." << endl;
							cout << "Prosze nacisnac jakikolwiek przycisk, aby wrocic z powrotem do menu." << endl;
							getchar(); getchar();
							system("cls");
							none = 0;
							break;

						}
					}
					break;
				
			}
			file3.close();
			delete[] networkServicePointer;
			delete[] passwordPointer;

		}

	};

int main()
{
	Password password;
	string platformName;
	int number, choice;
	while (true) {
		cout << "Witaj w generatorze hasel, prosze wybrac jedna z opcji" << endl;          //struktura menu
		cout << "1. Wygenerowanie hasla." << endl;
		cout << "2. Odczytanie ostatnich zapisanych hasel." << endl;
		cout << "3. Odczytanie konkretnego hasla do konkretnej uslugi sieciowej." << endl;
		cout << "4. Wyjscie z programu." << endl;
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore();
			cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
			getchar(); getchar();
			system("cls");
			continue;
		}
		switch (choice) {                                 //backend menu
		case 1:
			cout << "Prosze podac, do jakiej platformy sieciowej  ma zostac wygenerowane haslo." << endl;
			if (!(cin >> platformName)) {
				cin.clear();
				cin.ignore();
				cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
				cout << "Prosze nacisnac jakikolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
				getchar(); getchar();
				system("cls");
				continue;
			}
			cout << "Prosze podac dlugosc hasla." << endl;
			if (!(cin >> number)) {
				cin.clear();
				cin.ignore();
				cout << "Wystapil blad, podczas pobierania danych, prosze podac dane ponownie!" << endl;
				cout << "Prosze nacisnac jakikolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
				getchar(); getchar();
				system("cls");
				continue;
			}
			password.setPlatformName(platformName);
			password.setLength(number);                 //wywolywanie funkcji potrzebnych do dzialania
			password.generatePassword();
			cout << "Platforma, do ktorej zapisane zostalo haslo: " << password.getPlatformName() << endl;
			cout << "Twoje wygenerowane haslo to: " << password.getPassword() << endl;
			password.savePassword();
			system("cls");
			break;
		case 2:
			password.getFromFilePassword();                //wywolanie funkcji odczytania hasla
			break;
		case 3:                         //wywolanie funkcji odczytania konkretnego hasla, przypietego do konkretnej uslugi sieciowej
			password.readAndGetTwoLinesFromFile();
			break;
		case 4:
			exit(0);                    //wyjscie z programu
		}
	}
}

//TO-DO:
// 1. ODCZYT HASEL PO NAZWIE, DO KTORYCH SA PRZYPISANE.
// 2. ZMIEN KOD TAK, ABY PROGRAM MOGL OD RAZU WCZYTAC CALA ZAWARTOSC PLIKU, ZEBY TEGO NIE ROBIL CO KAZDA PROSBE ODCZYTANIA CZEGOKOLWIEK Z PLIKU.
// 3. NAPRAW PROBLEM Z POBOREM DANYCH ZE ZNAKAMI BIALYMI. <- nie da sie
// 4. DODAJ DZIALANIE NA WSKAZNIKACH, W RAZIE ODCZYTU WIELU HASEL Z PLIKU, (KONKRETNYCH HASEL), DO USPRAWNIENIA APLIKACJI.
// 5. NAUCZ SIE WYKRYWANIE PASSWORD BOXOW, ABY MOC TO WYKORZYSTAC W PRZYSZLOSCI W TYM KODZIE.


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
	string password, line;
	int length;
	char chars[46] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','w','x','x','y','z','0','1','2','3','4','5','6','7','8','9','.','!','@','#','$','%','^','&','*','(',')' };
	int getLength() {
		return length;
	}
	string getPassword() {                        //metody GET i SET
		return password;
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
		string savePassword() {                        //funckja zapisujaca haslo do pliku
			fstream plik;
			plik.open("password.txt", ios::out);
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
				plik << "Haslo: " << getPassword() << endl;
				cout << "Haslo zostalo zapisane w pliku." << endl;
				cout << "Prosze nacisnac jakiekolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
				getchar(); getchar();
				system("cls");
				plik.close();
				break;
			case 2:
				break;
			}
			return getPassword();
		}
		string getFromFilePassword() {                   //funkcja odczytujaca haslo z pliku, do ktorego haslo zostalo zapisane
			fstream file;
			file.open("password.txt", ios::in);
			if (!(file.good() == true)) {
				cout << "Wystapil problem z otwarciem pliku!" << endl;
			}
			system("cls");
			cout << "Dane z pliku: " << endl;
			while (getline(file, line)) {
				cout << line << endl;
			}
			file.close();
			cout << "Prosze nacisnac jakikolwiek przycisk, poza przyciskami znakow bialych, aby wrocic do menu." << endl;
			getchar(); getchar();
			return getPassword();
		}

	};



int main()
{
	Password password;
	int number, choice, choicev2;
	while (true) {
		cout << "Witaj w generatorze hasel, prosze wybrac jedna z opcji" << endl;          //struktura menu
		cout << "1. Wygenerowanie hasla." << endl;
		cout << "2. Odczytanie ostatnich zapisanych hasel." << endl;
		cout << "3. Wyjscie z programu." << endl;
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
			password.setLength(number);                 //wywolywanie funkcji potrzebnych do dzialania
			password.generatePassword();
			cout << "Twoje wygenerowane haslo to: " << password.getPassword() << endl;
			password.savePassword();
			system("cls");
			break;
		case 2:
			password.getFromFilePassword();                //wywolanie funkcji odczytania hasla
			break;
		case 3:
			exit(0);                    //wyjscie z programu
		}
	}
}

//TO-DO:
// 1. ZROB ODCZYT Z PLIKU CALEGO
// 2. DODAJ MOZLIWOSC ZAPISYWANIA DO CZEGO SA DANE HASLA
// 3. ODCZYT HASEL PO NAZWIE, DO KTORYCH SA PRZYPISANE
// 4. NAPRAW PROBLEM Z POBOREM DANYCH ZE ZNAKAMI BIALYMI. <- nie da sie
// 5. DODAJ DZIALANIE NA WSKAZNIKACH, W RAZIE ODCZYTU WIELU HASEL Z PLIKU, (KONKRETNYCH HASEL), DO USPRAWNIENIA APLIKACJI

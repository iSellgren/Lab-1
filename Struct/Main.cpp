#include "Structs.h"
#undef max





int main()
{
	system("chcp 1252");
	setlocale(LC_ALL, "Se");
	system("CLS");
	std::vector<person> personer;
	std::wifstream file("names.txt");
	std::locale swedish("swedish");
	std::locale::global(swedish);

	person p;
		//stoppar in det som finns i file genom instr�mnings operatorn
		while(file >> p)
			personer.push_back(p);

	int choice = 0;
	size_t count = 0;
	std::wstring lookfor = L" ";
	std::vector<person> matched_persons;
	
	bool MenuOn = true;
	while (MenuOn != false) {
		system("CLS");
		std::wcout << "#######################################\n";
		std::wcout << " 1 - S�k del av personnamn.\n";
		std::wcout << " 2 - S�k st�der.\n";
		std::wcout << " 3 - Exit.\n";
		std::wcout << " V�lj alternativ och tryck Enter: \n";
		std::wcout << "#######################################\n";

		std::cin >> choice;
		if (!std::cin)

			std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		switch (choice)
		{
		case 1:
			system("CLS");
			std::wcout << "S�k del av personnamn!\n";
			std::wcout << "Skriv namnet du s�ker!\n";
			std::wcin >> lookfor;
			size_t count;
			count = find_in_names(personer, lookfor);
			std::wcout << "Det finns " << count << " Personer inneh�llande " << lookfor << std::endl;
			Sleep(3000);

			break;

		case 2:

			system("CLS");
			std::wcout << "S�k st�der.\n";
			std::wcout << "Skriv staden du s�ker!\n";
			std::wcin >> lookfor;
			matched_persons = find_in_city(personer, lookfor);
			if (matched_persons.size() == 0)
				std::wcout << "Det finns ingen person som bor i " << lookfor << std::endl;
			for (size_t i = 0; i < matched_persons.size(); i++)
				std::wcout << "Personen som hittades �r " << matched_persons[i].name << ", bor i " << matched_persons[i].adress.city << std::endl;
			Sleep(3000);

			break;

		case 3:
			std::wcout << "Du valde att avsluta programmet\n";

			Sleep(3000);
			MenuOn = 0;

			break;

		default:

			std::wcout << "Fel inmatning.\n";
			std::wcout << "V�lj igen.\n";
			std::cin >> choice;

			break;
		}choice = 0;


	}
	return 0;

}
#include "Structs.h"


std::wistream& operator>>(std::wistream& in, person & p)
{
	std::wstring zip1, zip2;
	std::wstring zips;
	std::wstring city;

	std::getline(in, p.name);
	std::getline(in, p.id);
	std::getline(in, p.adress.street, L',');
	in >> zip1;
	in >> zip2;
	// tittar så att det finns något i zip1 och zip2.
	if (!(zip1.empty() && zip2.empty()))
		p.adress.zip = stoi(zip1 + zip2);
	in >> city;
	p.adress.city = city;
	// ignorerar de mellanslag som kom efter ortsnamnen. 
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	return in;
}

size_t find_in_names(const std::vector<person> & personer, std::wstring name_part)
{
	// Omvandlar hela name_part strängen till stora bokstäver.
	std::transform(name_part.begin(), name_part.end(), name_part.begin(), ::towupper);

	//räknar hur många personer som har en del av strängen i sitt namn.
	return std::count_if(personer.begin(), personer.end(), [name_part](const person & p)
	{
		std::wstring x = p.name;
		std::transform(x.begin(), x.end(), x.begin(), ::towupper);

		return x.find(name_part) != std::wstring::npos;
	});

}

std::vector<person> find_in_city(const std::vector<person> & haystack, std::wstring city)
{	//Gör en vector som ska innehålla matchande personer
	std::vector<person>matched_persons;
	std::transform(city.begin(), city.end(), city.begin(), ::towupper);

	for (auto p : haystack)
	{
		std::transform(p.adress.city.begin(), p.adress.city.end(), p.adress.city.begin(), ::towupper);
		if (p.adress.city == city)
		{	// Matchande personer stoppas in i vectorn.
			matched_persons.push_back(p);
		}

	}

	return matched_persons;
}
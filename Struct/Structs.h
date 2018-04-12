#ifndef  structs_h
#define structs_h

#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include <locale>
#include<Windows.h>
#include <stdio.h>
#include <ctype.h>
#undef max
// Skapar en struct för location
struct location {
	std::wstring street, city;
	int zip;

};

//Skapar en struct för person
struct person {
	std::wstring name, id;
	location adress;
};
//inströmnings operatorn
std::wistream& operator>>(std::wistream& in, person & p);

// Letar i p.name efter den substräng som användaren matat in. 
size_t find_in_names(const std::vector<person> & personer, std::wstring name_part);

// Letar efter exakt matchning av staden som sökes, samt att man stoppar in den matchande personen i vectorn matched_persons. 
std::vector<person> find_in_city(const std::vector<person> & haystack, std::wstring city);



#endif // !1

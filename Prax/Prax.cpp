// Prax.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


#define log(x) std::cout<< "*****"<<x<<"******" <<std::endl



int main() {

	int n;
	std::cin >> n;

	std::map<std::string, std::string> countries/* = { {"RUSSIA", "MOSCOW"}}*/;

	

	for (int i = 1; i <= n; i++)
	{
		std::string command;
		std::cin >> command;

		std::string country, capital, old_country, new_capital , new_country, old_capital;

		if (command == "CHANGE_CAPITAL") {
			std::cin >> country >> capital;
			if (countries.empty()) {
				countries.emplace(country, capital);
				std::cout << "Introduce new country " << country << " with capital " << capital << "\n";
			}
			else {

				if (countries[country] == "") {
					countries[country] = capital;
					std::cout << "Introduce new country " << country << " with capital " << capital << "\n";
				}

				else if (countries[country] == capital) {
					std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
				}

				else if (countries[country] != capital && countries[country] != "") {
					old_capital = countries[country];
					
					countries.erase(country);
					countries.emplace(country, capital);
					std::cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << std::endl;
				}
			}
		}
		else if (command == "RENAME") {
			std::cin >> country >> new_country;
			if (new_country == country  || countries[country].empty() || !(countries[new_country].empty())) {
				if(countries[country].empty() )
					countries.erase(country);
				std::cout << "Incorrect rename, skip" <<  std::endl;
			}
			else {
				capital = countries[country];
				countries[new_country] = countries[country];
				countries.erase(country);
				std::cout << "Country " << country << " with capital " << capital << " has been renamed to " << new_country << std::endl;
			}


			
		}
		else if (command == "ABOUT") {
			std::cin >> country;
			if (countries[country].empty()) {
				countries.erase(country);
				std::cout << "Country " << country << " doesn't exist" << std::endl;
			}
			else {
				capital = countries[country];
				std::cout << "Country " << country << " has capital " << capital << std::endl;
			}
		}
		else if (command == "DUMP") {
				if (countries.empty()) {
					std::cout << "There are no countries in the world" << std::endl;
				}
				else {

					for (const auto& elem : countries) {

						std::cout << elem.first << "/" << elem.second << " ";

					}
					std::cout<<std::endl;
				}
		}
	}

	//std::cout << "*************************************" << '\n';
	//for (const auto& e : countries) {
	//	std::cout << "Country Name: " << e.first << ". " << "Capital: " << e.second << std::endl;
	//	
	//}

	//std::cout << countries.size();

	



	return 0;
}
	





	

	







	
	








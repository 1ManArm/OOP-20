#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <random>
//библиотеки, облегчающие обработку коллекций и в принципе работу с данными
#include <algorithm>
#include <functional>

bool IsMore(int a, int b) {
	return a > b;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::list<int> coll1;
	std::vector<int> coll2;

	std::random_device rd;
	std::mt19937 generator(15);
	std::uniform_int_distribution<int> provider(10, 99);

	for (size_t i = 0; i < 20; i++) {
		coll1.push_back(provider(generator));
		coll2.push_back(provider(generator));
	}
	int count{};
	/*for (const auto& node : coll1) {
		for (const auto& el : coll2) {
			if (el == node) {
				count++;
				break;
			}
		}
	}*/
	for (const auto& node : coll1) {
		count+= std::count(coll2.begin(), coll2.end(), node);
	}
	std::cout << count << " duplicated elements in collections\n";
	for (const auto& node : coll1) {
		std::cout << node << ' ';
	}
	std::cout << '\n';

	for (const auto& node : coll2) {
		std::cout << node << ' ';
	}
	std::cout << '\n';

	if (count > 0) {
		for (const auto& node : coll1) {
			auto it = std::find(coll2.begin(), coll2.end(), node);
			if (it != coll2.end()) {
				coll2.erase(it);
			}
		}
		for (const auto& node : coll1) {
			std::cout << node << ' ';
		}
		std::cout << '\n';

		for (const auto& node : coll2) {
			std::cout << node << ' ';
		}
		std::cout << '\n';
	}
	//min, max, min_max, sort, shuffle, split
	//std::sort(coll2.begin(), coll2.end(), IsMore);
	//сортировка по возрастанию для типов, которые имеют реализованный оператор <

	//подача сохраненного lambda-выражения
	auto lamb = [](int a, int b)->bool {
		return a > b;
	};
	std::sort(coll2.begin(), coll2.end(), lamb);
	std::sort(coll2.begin(), coll2.end(), [](int a, int b)->bool {
		return a > b; });
	for (const auto& el : coll2) {
		std::cout << '\n';
	}
	std::cout << "\n";

	auto search = std::find_if(coll2.begin(), coll2.end(),
		[](int a)->bool {return a>30; });
	//find - полное соответствие
	//find_if - по нужному условию
	if (search != coll2.end()) {
		std::cout << *search << '\n';
	}



	return 0;
}
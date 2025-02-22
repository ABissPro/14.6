#include <iostream>

int main()
{
	system("chcp 1251"); // Установить кодировку
	int a[4][4];
	int b[4][4];
	std::cout << "Введите числа первой матрицы:\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; ++j) {			
			std::cin >> a[i][j];
		}
	}
	std::cout << "Введите числа второй матрицы:\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; ++j) {
			std::cin >> b[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; ++j) {
			if (a[i][j] != b[i][j]) {
				std::cout << "Найдено несовпадение\n";
				break;
			}
			count++;
		}
	}

	if (count == 16) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; ++j) {
				if (i != j) {
					a[i][j] = 0;
				}
				std::cout << a[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}



}
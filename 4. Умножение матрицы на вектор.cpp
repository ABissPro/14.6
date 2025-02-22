#include <iostream>
#include <vector>

int main()
{
	system("chcp 1251"); // Установить кодировку
	float a[4][4];
	std::vector<float> b;
	float c[4][4];

	std::cout << "Введите числа матрицы\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {			
			std::cin >> a[i][j];
		}		
	}
	std::cout << "Введите числа вектора\n";
	for (int i = 0; i < 4; i++) {
		float temp;
		std::cin >> temp;
		b.push_back(temp);
	}

	std::cout << "Результат:\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = a[i][j] * b[j];
			std::cout << c[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
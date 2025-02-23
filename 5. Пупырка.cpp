#include <iostream>
void inicialization(bool pupyrka[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            pupyrka[i][j] = true;
        }
    }
}

void output(bool pupyrka[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (pupyrka[i][j]) {
                std::cout << 'o';
            }
            else {
                std::cout << 'x';
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void pop(bool pupyrka[12][12], int a, int b, int k, int n, int count, int pop_count) {
    if (a < 0 || a > 11 || b < 0 || b > 11 ||
        k < 0 || k > 11 || n < 0 || n > 11) {
        std::cerr << "Ошибка: координаты вне допустимого диапазона." << std::endl;
        return;
    }
    int poppedCount = 0;  // Количество лопнувших пузырей
    for (int i = a; i <= k; i++) {
        for (int j = b; j <= n; j++) {
            if (pupyrka[i][j]) {
                std::cout << "Pop!\n";
                poppedCount++;
                pupyrka[i][j] = false;
                
            }
        }
    }  
    output(pupyrka);
}

bool areAllBubblesPopped(const bool pupyrka[12][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (pupyrka[i][j]) {  //если найден хотя бы один целый пузырёк
                return false;       //не все пузырьки лопнуты
            }
        }
    }
    return true;  //все пузырьки лопнуты
}

int main()
{
    system("chcp 1251"); // Установить кодировку
    bool pupyrka[12][12];
    int a, b; //координаты начала
    int k, n; //координаты конца
    int count = 0;
    int pop_count = 0;
    //инициализация
    inicialization(pupyrka);
    while (pupyrka) {
        output(pupyrka);
        std::cout << "Введите координаты начала: ";
        std::cin >> a >> b;
        std::cout << "Введите координаты конца: ";
        std::cin >> k >> n;
        //вывод переместился внутрь функции pop
        pop(pupyrka, a, b, k, n, count, pop_count);
        if (areAllBubblesPopped(pupyrka)) {
            std::cout << "Все пузырьки лопнуты!\n";
            break;
        }

    }        
}
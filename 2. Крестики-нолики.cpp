#include <iostream>

// инициализация игрового поля
void initialize_game_board(char game[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game[i][j] = ' ';
        }
    }
}

//отображение игрового поля
void display_game_board(char game[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << game[i][j] << '|';
        }
        std::cout << '\n';
    }
}

//ход игрока
void get_player_move(char game[3][3], char& gamer_name) {
    int i, j;
    do {
        std::cout << "Введите адрес ячейки для хода: ";
        std::cin >> i >> j;
        i--; j--; // привидение координат к индексам массива
        if (i >= 0 && i < 3 && j >= 0 && j < 3 && game[i][j] == ' ') {
            game[i][j] = gamer_name;
            break;
        }
        else {
            std::cout << "Эта клетка занята или находится вне доски. Попробуйте снова.\n";
        }
    } while (true);
}

//Проверка на наличие победителя
bool check_for_winner(char game[3][3], char gamer_name) {
    //строки
    for (int i = 0; i < 3; i++) {
        if (game[i][0] == gamer_name && game[i][1] == gamer_name && game[i][2] == gamer_name) {
            return true;
        }
    }
    //столбцы
    for (int j = 0; j < 3; j++) {
        if (game[0][j] == gamer_name && game[1][j] == gamer_name && game[2][j] == gamer_name) {
            return true;
        }
    }
    //диагонали?
    if ((game[0][0] == gamer_name && game[1][1] == gamer_name && game[2][2] == gamer_name) ||
        (game[0][2] == gamer_name && game[1][1] == gamer_name && game[2][0] == gamer_name)) {
        return true;
    }
    return false;
}


int main() {
    system("chcp 1251"); // Установка кодировки 

    char game[3][3];  
    char gamer_name = 'x'; // Первый игрок - крестик
    int count = 0; 

    initialize_game_board(game);

    //игровой цикл
    while (count != 9) {
        display_game_board(game);

        get_player_move(game, gamer_name);

        if (check_for_winner(game, gamer_name)) {
            std::cout << "Игра окончена! Игрок '" << gamer_name << "' победил!\n";
            break;
        }

        gamer_name = (gamer_name == 'x') ? 'o' : 'x';
        count++;

        std::cout << "Ходов осталось: " << 9 - count << std::endl;
    }

    if (count == 9) {
        std::cout << "Ничья!\n";
    }

    return 0;
}

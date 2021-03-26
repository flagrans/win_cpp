#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void invert(int size, ...) { // Перегруженная функция invert, для 5-го задания
    va_list vl;
    va_start(vl, size);
    for (int i = 0; i < size; ++i) {
        std::cout << !va_arg(vl, int) << " "; // Тут если в va_arg(vl, int) передать bool то компилятор ругается, вопрос почему?
    }                                         // А с int хоть и работает трюк с отрицанием (!), но как-то не правильно получается
     std::cout << std::endl;                   // Хотелось бы прояснить этот момент
     va_end(vl);
 }

/**************************** Попробуйте №5 ****************************************/
//void ps (int i) {
//    int sq = 0;
//    for (int k = 1; k <= i; ++k) {
//        sq += i;
//    }
//    std::cout << i << "*" << i << " = " << sq << std::endl;
//}

bool bsort(double x, double y) {
    return (x<y);
}
/**************************** Упражнение №11 ***************************************/
bool checkNatural(int x) {
    for (int i = 2; i < x; i++) {
        if (!(x % i)) return false;
    }
    return true;
}
/**************************** Упражнение №17 ***************************************/
std::string modaString (std::vector<std::string> is) {
    std::string mod = "";
    int kol = 0;
    for (std::string i : is) {
        int temp = 0;
        for (size_t k = 0; k < is.size(); k++) {
            if (i == is[k]) temp++;
        }
        if (temp > kol) {
            mod = i;
            kol = temp;
        }
    }
    return mod;
}

std::string maxString (std::vector<std::string> is) {
    std::string max = is[0];
    for (std::string i : is) {
        if (i > max) max = i;
    }
    return max;
}

std::string minString (std::vector<std::string> is) {
    std::string min = is[0];
    for (std::string i : is) {
        if (i < min) min = i;
    }
    return min;
}
/**************************** Упражнение №19 ***************************************/
bool checkName (std::string st, std::vector<std::string> names) {
    for (std::string i : names) {
        if (i == st) return false;
    }
    return true;
}
int findName (std::string st, std::vector<std::string> names) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == st) return i;
    }
    return -1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

/**************************** Попробуйте №1 ****************************************/
//    std::string st="";
//    double x;
//    std::cin >> x >> st;
//    if (st == "bc") {
//        std::cout << x << " биткоинов = " << x * 48999.90 << " $" << std::endl;
//    } else if (st == "lc") {
//        std::cout << x << " лайткоинов = " << x * 180.56 << " $" << std::endl;
//    } else if (st == "rb") {
//        std::cout << x << " рублей = " << x * 0.014 << " $" << std::endl;
//    } else {
//        std::cout << "Я не знаю такой валюты!!!" << std::endl;
//    }
/**************************** Попробуйте №2 ****************************************/
//        char st;
//        double x;
//        std::cin >> x >> st;
//        switch (st) {
//        case 'b':
//            std::cout << x << " биткоинов = " << x * 48999.90 << " $" << std::endl;
//            break;
//        case 'l':
//            std::cout << x << " лайткоинов = " << x * 180.56 << " $" << std::endl;
//            break;
//        case 'r':
//            std::cout << x << " рублей = " << x * 0.014 << " $" << std::endl;
//            break;
//        case 'f':
//            std::cout << x << " фунтов = " << x * 0.014 << " $" << std::endl;
//            break;
//        case 'a':
//            std::cout << x << " австралийских долларов = " << x * 0.78 << " $" << std::endl;
//            break;
//        default:
//            std::cout << "Я не знаю такой валюты!!!" << std::endl;
//        }
/**************************** Попробуйте №3 ****************************************/
//    int c = 'a';
//    int i = 0;
//    while (c < 123) {
//        std::cout << char('a' + i) << " " << ('a' + i) << std::endl;
//        c++;
//        i++;
//    }
/**************************** Попробуйте №4 ****************************************/
//    for (int i = 'a'; i < 123; i++) {
//        std::cout << char(i) << " " << i << std::endl;
//    }
//    for (int i = 'A'; i < 91; i++) {
//        std::cout << char(i) << " " << i << std::endl;
//    }
//    for (int i = '0'; i < 58; i++) {
//        std::cout << char(i) << " " << i << std::endl;
//    }
//**************************** Попробуйте №5 ****************************************/
//    for (int i = 0; i < 100; ++i) {
//        ps(i);
//    }
//**************************** Попробуйте №6 ****************************************/
//    std::vector <std::string> w = {"fuck", "hi"};
//    for (std::string temp; std::cin >> temp;) {
//        bool pr = true;
//        for(std::string w1 : w) {
//            if (temp == w1) {
//                std::cout << "BLEEP" << std::endl;
//                pr = false;
//                break;
//            }
//        }
//        if (pr) std::cout << temp << std::endl;
//    }


/**************************** Упражнение №2 ****************************************/
//    std::vector<double> w;
//    for(double temp; std::cin >> temp;) {
//        w.push_back(temp);
//    }
//    sort(w.begin(), w.end(), bsort);
//    if (w.size() % 2) {
//        std::cout << w[(w.size() / 2)] << std::endl;
//    } else {
//        std::cout << (w[w.size() / 2] + w[w.size() / 2 - 1]) / 2 << std::endl;
//    }
//    std::cout << "SIZE = " << w.size()/2 << std::endl;
/**************************** Упражнение №3 ****************************************/
//    std::vector<double> w;
//    double itog = 0;
//    for(double temp; std::cin >> temp;) {
//        w.push_back(temp);
//        itog += temp;
//    }
//    std::cout << "Общее расстояние = " << itog << std::endl;
//    std::cout << "Среднее расстояние = " << itog / w.size() << std::endl;
//    sort(w.begin(), w.end(), bsort);
//    std::cout << "Минимальное расстояние = " << *w.begin() << std::endl;
//    std::cout << "Максимальное расстояние = " << *(w.end()-1) << std::endl;
/**************************** Упражнение №4 ****************************************/

/**************************** Упражнение №5 ****************************************/
//    double x = 0, y = 0;
//    char op = ' ';
//    std::cout << "Введите 2 числа и действие: ";
//    std::cin >> x >> y >> op;
//    switch (op) {
//    case '+':
//        std::cout << "Сумма " << x << " и " << y << " равна " << x + y << std::endl;
//        break;
//    case '-':
//        std::cout << "Разность " << x << " и " << y << " равна " << x - y << std::endl;
//        break;
//    case '*':
//        std::cout << "Произведение " << x << " и " << y << " равно " << x * y << std::endl;
//        break;
//    case '/':
//        std::cout << "Деление " << x << " и " << y << " равно " << x / y << std::endl;
//        break;
//    default:
//        std::cout << "Я не знаю такого действия!!!" << std::endl;
//    }
/**************************** Упражнение №6 ****************************************/
//    std::vector<std::string> w = {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
//    for (int temp; std::cin >> temp;) {
//        std::cout << w[temp] << std::endl;
//    }

//    std::vector<std::string> w = {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
//    for (std::string temp; std::cin >> temp;) {
//        for (size_t i = 0; i < w.size(); i++) {
//            if (w[i] == temp) {
//                std::cout << i << std::endl;
//                break;
//            }
//        }
//    }
/**************************** Упражнение №7 ****************************************/

    // Не понял задания

/**************************** Упражнение №8,9 **************************************/
//    int sum = 0, current = 0, t1, t2, t3;
//    bool b1 = true, b2 = true, b3 = true;
//    for (int i = 1; i <= 64; i++) {
//        std::cout << "№ клетки - " << i << std::endl;
//        std::cout << "Зерна на предыдущих клетках - " << sum << std::endl;
//        current = pow(2, i);
//        sum += current;
//        if (sum > 1000 && b1 == true) {
//            t1 = i;
//            b1 = false;
//        }
//        if (sum > 1000000 && b2 == true) {
//            t2 = i;
//            b2 = false;
//        }
//        if (sum > 1000000000 && b3 == true) {
//            t3 = i;
//            b3 = false;
//        }
//        std::cout << "Зерна на текущей клетке - " << current << std::endl;
//    }
//    std::cout << "1000 - " << t1 << " клетка" << std::endl;
//    std::cout << "1000000 - " << t2 << " клетка" << std::endl;
//    std::cout << "1000000000 - " << t3 << " клетка" << std::endl;
/**************************** Упражнение №10 ***************************************/
//    srand(time(0));
//    char pv;
//    std::cin >> pv;
//    char com = rand() % 3;
//    switch(pv) {
//    case 'k':
//        if (com == 0) {
//            std::cout << "У компьютера - камень" << std::endl;
//            std::cout << "Ничья!!!" << std::endl;
//        } else if(com == 1) {
//            std::cout << "У компьютера - ножницы" << std::endl;
//            std::cout << "Вы выиграли!!!" << std::endl;
//        } else {
//            std::cout << "У компьютера - бумага" << std::endl;
//            std::cout << "Вы проиграли!!!" << std::endl;
//        }
//        break;
//    case 'n':
//        if (com == 0) {
//            std::cout << "У компьютера - камень" << std::endl;
//            std::cout << "Вы проиграли!!!" << std::endl;
//        } else if(com == 1) {
//            std::cout << "У компьютера - ножницы" << std::endl;
//            std::cout << "Ничья!!!" << std::endl;
//        } else {
//            std::cout << "У компьютера - бумага" << std::endl;
//            std::cout << "Вы выиграли!!!" << std::endl;
//        }
//        break;
//    case 'b':
//        if (com == 0) {
//            std::cout << "У компьютера - камень" << std::endl;
//            std::cout << "Вы выиграли!!!" << std::endl;
//        } else if(com == 1) {
//            std::cout << "У компьютера - ножницы" << std::endl;
//            std::cout << "Вы проиграли!!!" << std::endl;
//        } else {
//            std::cout << "У компьютера - бумага" << std::endl;
//            std::cout << "Ничья!!!" << std::endl;
//        }
//        break;
//    default:
//        std::cout << "Неверное значение!!!" << std::endl;
//    }
/**************************** Упражнение №11 ***************************************/
//    std::vector<int> natural;
//    for (int i = 2; i <= 100; i++) {
//        if(checkNatural(i)) natural.push_back(i);
//    }
//    for (int i : natural) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//    for (int i = 2; i <= 100; i++) {
//        if(checkNatural(i)) std::cout << i << " ";
//    }
//    std::cout << std::endl;
/**************************** Упражнение №12 ***************************************/
//    std::vector<int> natural;
//    int max;
//    std::cin >> max;
//    for (int i = 2; i <= max; i++) {
//        if(checkNatural(i)) natural.push_back(i);
//    }
//    for (int i : natural) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//    for (int i = 2; i <= 100; i++) {
//        if(checkNatural(i)) std::cout << i << " ";
//    }
//    std::cout << std::endl;
/**************************** Упражнение №13 ***************************************/
//    std::vector<int> nums;
//    std::vector<int> result;
//    for (int i = 0; i <= 100; i++) {
//        nums.push_back(i);
//    }
//    for (int i = 2; i <= 100; i++) {
//        for (int p = (i * i); p <= 100; p += i) {
//            nums[p] = 0;
//        }
//    }
//    for (int i : nums) {
//        if (i > 1 && i != 0) {
//            result.push_back(i);
//            std::cout << i << std::endl;
//        }
//    }
/**************************** Упражнение №14 ***************************************/
//    int max;
//    std::cin >> max;
//    std::vector<int> nums;
//    std::vector<int> result;
//    for (int i = 0; i <= max; i++) {
//        nums.push_back(i);
//    }
//    for (int i = 2; i <= max; i++) {
//        for (int p = (i * i); p <= max; p += i) {
//            nums[p] = 0;
//        }
//    }
//    for (int i : nums) {
//        if (i > 1 && i != 0) {
//            result.push_back(i);
//            std::cout << i << std::endl;
//        }
//    }
/**************************** Упражнение №15 ***************************************/
//    unsigned int n;
//    std::cin >> n;
//    std::vector<int> nums;
//    int tempN = 2;
//    while (nums.size() < n) {
//        if (checkNatural(tempN)) nums.push_back(tempN);
//        tempN++;
//    }
//    for (int i : nums) {
//        std::cout << i << std::endl;
//    }
/**************************** Упражнение №16 ***************************************/
//    int mod = 0;
//    int kol = 0;
//    std::vector<int> is = {1, 4, 4, 2, 7, 7, 3, 4, 7, 4, 3, 7, 1, 7, 3};
//    for (int i : is) {
//        int temp = 0;
//        for (size_t k = 0; k < is.size(); k++) {
//            if (i == is[k]) temp++;
//        }
//        if (temp > kol) {
//            mod = i;
//            kol = temp;
//        }
//    }
//    std::cout << mod << std::endl;
/**************************** Упражнение №17 ***************************************/
//    std::vector<std::string> is = {"ab", "всем", "привет", "ab", "от", "bc", "меня", "ab"};
//    std::cout << "Мода - " << modaString(is) << std::endl;
//    std::cout << "Наибольшая строка - " << maxString(is) << std::endl;
//    std::cout << "наименьшая строка - " << minString(is) << std::endl;
/**************************** Упражнение №18 ***************************************/
    //Квадратное уравнение
/**************************** Упражнение №19 ***************************************/
//    std::vector<std::string> names;
//    std::vector<int> score;
//    std::string st = "";
//    int ss = 0;
//    std::cin >> st >> ss;
//    names.push_back(st);
//    score.push_back(ss);
//    while (st != "NoName" && ss != 0) {
//        std::cin >> st >> ss;
//        if (!checkName(st, names)) {
//            std::cout << "Имя уже есть, попробуйте еще раз!" << std::endl;
//            continue;
//        }
//        names.push_back(st);
//        score.push_back(ss);
//    }
//    for (size_t i = 0; i < names.size(); i++) {
//        std::cout << names[i] << " - " << score[i] << std::endl;
//    }
/**************************** Упражнение №20 ***************************************/
//    std::vector<std::string> names;
//    std::vector<int> score;
//    std::string st = "";
//    int ss = 0;
//    std::cin >> st >> ss;
//    names.push_back(st);
//    score.push_back(ss);
//    while (st != "NoName" && ss != 0) {
//        std::cin >> st >> ss;
//        if (!checkName(st, names)) {
//            std::cout << "Имя уже есть, попробуйте еще раз!" << std::endl;
//            continue;
//        }
//        names.push_back(st);
//        score.push_back(ss);
//    }
//    std::cout << std::endl << "Введите имя:" << std::endl;
//    std::cin >> st;
//    int te = findName(st, names);
//    if (te != -1) {
//        std::cout << "Баллы = " << score[te] << std::endl;
//    } else {
//        std::cout << "Имя не найдено." << std::endl;
//    }
/**************************** Упражнение №21 ***************************************/
    std::vector<std::string> names;
    std::vector<int> score;
    std::string st = "";
    int ss = 0;
    std::cin >> st >> ss;
    names.push_back(st);
    score.push_back(ss);
    while (st != "NoName" && ss != 0) {
        std::cin >> st >> ss;
        if (!checkName(st, names)) {
            std::cout << "Имя уже есть, попробуйте еще раз!" << std::endl;
            continue;
        }
        names.push_back(st);
        score.push_back(ss);
    }
    std::cout << std::endl << "Введите баллы: ";
    std::cin >> ss;
    for (int i = 0; i < names.size(); i++) {
        if (ss == score[i]) std::cout << names[i] << std::endl;
    }

/******************************** The End ******************************************/
    return 0;
}

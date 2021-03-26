#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>
#include <algorithm>

/**************************** Задание №7 ****************************************/
double length_to_m (double x, std::string st) {
    double tmp = 0.0;
    if (st == "m") {
        tmp = x;
    }
    if (st == "cm") {
        tmp = x/100;
    }
    if (st == "in") {
        tmp = x*2.54/100;
    }
    if (st == "ft") {
        tmp = x*2.54*12/100;
    }
    return tmp;
}
/**************************** Задание №11 ****************************************/
bool bsort(double x, double y) {
    return (x<y);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

/**************************** Задание №1 ****************************************/
//    int x1 = 0, x2 = 0;
//    while (std::cin >> x1 >> x2) {
//        std::cout << x1 << ' ' << x2 << std::endl;
//    }
/**************************** Задание №2 ****************************************/
//    int x1 = 0, x2 = 0;
//    while (std::cin >> x1 >> x2) {
//        if (x1 > x2) {
//            std::cout << "Наименьшее значение: " << x2 << std::endl;
//            std::cout << "Наибольшее значение: " << x1 << std::endl;
//        } else {
//            std::cout << "Наименьшее значение: " << x1 << std::endl;
//            std::cout << "Наибольшее значение: " << x2 << std::endl;
//        }
//    }
/**************************** Задание №3 ****************************************/
//    int x1 = 0, x2 = 0;
//    while (std::cin >> x1 >> x2) {
//        if (x1 == x2) {
//            std::cout << "Числа равны" << std::endl;
//        } else if (x1 > x2) {
//            std::cout << "Наименьшее значение: " << x2 << std::endl;
//            std::cout << "Наибольшее значение: " << x1 << std::endl;
//        } else {
//            std::cout << "Наименьшее значение: " << x1 << std::endl;
//            std::cout << "Наибольшее значение: " << x2 << std::endl;
//        }
//    }
/**************************** Задание №4 ****************************************/
//    double x1 = 0.0, x2 = 0.0;
//    while (std::cin >> x1 >> x2) {
//        if (x1 == x2) {
//            std::cout << "Числа равны" << std::endl;
//        } else if (x1 > x2) {
//            std::cout << "Наименьшее значение: " << x2 << std::endl;
//            std::cout << "Наибольшее значение: " << x1 << std::endl;
//        } else {
//            std::cout << "Наименьшее значение: " << x1 << std::endl;
//            std::cout << "Наибольшее значение: " << x2 << std::endl;
//        }
//    }
/**************************** Задание №5 ****************************************/
//    double x1 = 0.0, x2 = 0.0;
//    while (std::cin >> x1 >> x2) {
//        if (x1 == x2) {
//            std::cout << "Числа равны" << std::endl;
//        } else if (abs(x1 - x2) < 0.01) {
//            std::cout << "Числа почти равны" << std::endl;
//        } else if (x1 > x2) {
//            std::cout << "Наименьшее значение: " << x2 << std::endl;
//            std::cout << "Наибольшее значение: " << x1 << std::endl;
//        } else {
//            std::cout << "Наименьшее значение: " << x1 << std::endl;
//            std::cout << "Наибольшее значение: " << x2 << std::endl;
//        }
//    }
/**************************** Задание №6 ****************************************/
//    double x = 0.0, min = 0.0, max = 0.0;
//    std::cin >> x;
//    std::cout << x << std::endl;
//    min = x;
//    max = x;
//    while (std::cin >> x) {
//        std::cout << x << std::endl;
//        if (x > max) {
//            max = x;
//            std::cout << "Наибольшее среди введенных" << std::endl;
//        }
//        if (x < min) {
//            min = x;
//            std::cout << "Наименьшее среди введенных" << std::endl;
//        }
//    }
/**************************** Задание №7,8 **************************************/
//    double x = 0.0, min = 0.0, max = 0.0;
//    std::string st;
//    std::cin >> x >> st;
//    if (st == "m" || st == "cm" || st == "in" || st == "ft") {
//        std::cout << x << st << std::endl;
//        min = length_to_m(x, st);
//        max = min;
//    } else {
//        std::cout << "Не верные единицы измерения, попробуйте еще раз!" << std::endl;
//    }
//    while (std::cin >> x >> st){
//        if (st == "m" || st == "cm" || st == "in" || st == "ft") {
//            std::cout << x << st << std::endl;
//            x = length_to_m(x ,st);
//            if (x > max) {
//                max = x;
//                std::cout << "Наибольшее среди введенных" << std::endl;
//            }
//            if (x < min) {
//                min = x;
//                std::cout << "Наименьшее среди введенных" << std::endl;
//            }
//        } else {
//            std::cout << "Не верные единицы измерения, попробуйте еще раз!" << std::endl;
//        }
//    }
/**************************** Задание №8 ****************************************/
/**************************** Задание №9 ****************************************/
//    double x = 0.0, min = 0.0, max = 0.0, sum = 0.0;
//    int count = 0;
//    std::string st;
//    std::cin >> x >> st;
//    if (st == "m" || st == "cm" || st == "in" || st == "ft") {
//        std::cout << x << st << std::endl;
//        count++;
//        min = length_to_m(x, st);
//        sum += min;
//        max = min;
//    } else {
//        std::cout << "Не верные единицы измерения, попробуйте еще раз!" << std::endl;
//    }
//    while (std::cin >> x >> st){
//        if (st == "m" || st == "cm" || st == "in" || st == "ft") {
//            std::cout << x << st << std::endl;
//            x = length_to_m(x ,st);
//            count++;
//            sum += x;
//            if (x > max) {
//                max = x;
//                std::cout << "Наибольшее среди введенных" << std::endl;
//            }
//            if (x < min) {
//                min = x;
//                std::cout << "Наименьшее среди введенных" << std::endl;
//            }
//        } else {
//            std::cout << "Не верные единицы измерения, попробуйте еще раз!" << std::endl;
//        }
//    }
//    std::cout << "Количество введенных значений = " << count << std::endl;
//    std::cout << "Общее расстояние = " << sum << std::endl;
/**************************** Задание №10,11 *************************************/
    double x = 0.0, min = 0.0, max = 0.0;
    std::string st;
    std::vector <double> v;
    std::cin >> x >> st;
    if (st == "m" || st == "cm" || st == "in" || st == "ft") {
        std::cout << x << st << std::endl;
        min = length_to_m(x, st);
        v.push_back(min);
        max = min;
    } else {
        std::cout << "Не верные единицы измерения, попробуйте еще раз!" << std::endl;
    }
    while (std::cin >> x >> st){
        if (st == "m" || st == "cm" || st == "in" || st == "ft") {
            std::cout << x << st << std::endl;
            x = length_to_m(x ,st);
            v.push_back(x);
            if (x > max) {
                max = x;
                std::cout << "Наибольшее среди введенных" << std::endl;
            }
            if (x < min) {
                min = x;
                std::cout << "Наименьшее среди введенных" << std::endl;
            }
        } else {
            std::cout << "Не верные единицы измерения, попробуйте еще раз!" << std::endl;
        }
    }
   std::sort(v.begin(), v.end(), bsort);
   for (double x : v) {
       std::cout << x << " ";
   }
   std::cout << std::endl;
/**************************** Задание №11 ***************************************/
    return 0;
}

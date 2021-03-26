#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Привет мир!" << std::endl;
    std::string st;
    //std::cin >> st;
    //std::cout << st << std::endl;

    return 0;
}

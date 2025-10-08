// main.cpp — Task1_StudentsNoFives (wide, UTF-16 console)
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>   // _setmode, _O_U16TEXT

struct Student {
    int num;
    std::wstring name;
    int inf, math, phys, prog;
};

int main() {
    // 1) Увімкнути wide-режим для консолі (stdin/stdout у UTF-16)
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    // 2) Дані з умови
    std::vector<Student> s = {
        {1,  L"Іванчук С.О.",      4,3,3,4},
        {2,  L"Панченко І.А.",     5,4,4,5},
        {3,  L"Заєць О.М.",        3,4,4,4},
        {4,  L"Вельбицький П.О.",  4,3,3,2},
        {5,  L"Сидоренко В.П.",    2,3,3,2},
        {6,  L"Кравченко З.І.",    3,5,4,5},
        {7,  L"Якубів Р.Н.",       5,4,4,3},
        {8,  L"Зоренко П.М.",      4,2,3,3},
        {9,  L"Береста Г.С.",      4,5,5,5},
        {10, L"Дячик Н.С.",        5,5,4,4}
    };

    // 3) Вивід заголовка
    using std::wcout; using std::left; using std::setw;
    wcout << L"Студенти без жодної '5':\n";
    wcout << left << setw(4) << L"№"
        << setw(22) << L"Прізвище"
        << setw(6) << L"Інф"
        << setw(6) << L"В.М."
        << setw(6) << L"Фіз"
        << setw(6) << L"Прог" << L"\n";

    // 4) Фільтр та підрахунок
    int cnt = 0;
    for (const auto& x : s) {
        bool no5 = (x.inf != 5 && x.math != 5 && x.phys != 5 && x.prog != 5);
        if (no5) {
            wcout << left << setw(4) << x.num
                << setw(22) << x.name
                << setw(6) << x.inf
                << setw(6) << x.math
                << setw(6) << x.phys
                << setw(6) << x.prog << L"\n";
            ++cnt;
        }
    }

    wcout << L"\nКількість студентів без оцінок '5': " << cnt << L"\n";
    return 0;
}

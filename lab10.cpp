#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

int* make_mas(int n)
{
    int* mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 100;
    }
    return mas;
}

void print_mas(int* mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int* del_elem(int* mas, int& n, int del_num)
{
    if (del_num < 1 || del_num > n)
    {
        cout << "Неверный номер" << endl;
        return mas;
    }
    int* new_mas = new int[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != del_num - 1)
        {
            new_mas[j] = mas[i];
            j++;
        }
    }
    delete[] mas;
    n = n - 1;
    return new_mas;
}

int* add_elems(int* mas, int& n, int add_num, int k)
{
    if (add_num < 1 || add_num > n + 1 || k <= 0)
    {
        cout << "Неверные параметры" << endl;
        return mas;
    }
    int* new_mas = new int[n + k];
    int pos = add_num - 1;
    for (int i = 0; i < pos; i++)
    {
        new_mas[i] = mas[i];
    }
    for (int i = 0; i < k; i++)
    {
        new_mas[pos + i] = rand() % 100;
    }
    for (int i = pos; i < n; i++)
    {
        new_mas[i + k] = mas[i];
    }
    delete[] mas;
    n = n + k;
    return new_mas;
}

void free_mas(int* mas)
{
    delete[] mas;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(0));
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* mas = make_mas(n);
    cout << "Исходный массив:" << endl;
    print_mas(mas, n);

    int del_num;
    cout << "Введите номер элемента для удаления (1.." << n << "): ";
    cin >> del_num;
    mas = del_elem(mas, n, del_num);
    cout << "Массив после удаления:" << endl;
    print_mas(mas, n);

    int add_num, k;
    cout << "Введите номер позиции для добавления (1.." << n + 1 << "): ";
    cin >> add_num;
    cout << "Введите количество добавляемых элементов K: ";
    cin >> k;
    mas = add_elems(mas, n, add_num, k);
    cout << "Массив после добавления:" << endl;
    print_mas(mas, n);

    free_mas(mas);
    return 0;
}

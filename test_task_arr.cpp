#include <iostream>
#include <algorithm>
using namespace std;

void foo(int a[], int b[], int count_a, int count_b){ // Ищем в массиве a элементы массива b
    //Сортировка 
    sort(a, a + count_a);
    sort(b, b + count_b);
    cout << endl;
    for (int i = 0; i < count_a; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
    for (int i = 0; i < count_b; i++) {
        cout << b[i] << ", ";
    }
    cout << endl;

    // Бинарный поиск
    cout << "Пересичение: ";
    for (int i = 0; i < count_b; i++) {
        int l = 0;
        int r = count_a ;
        int mid;
        while (l < r) {
            mid = (l + r) / 2; // Находим средний индекс
            if (a[mid] > b[i]) // Проверяем в какой части находится
                r = mid;
            else
                l = mid + 1;
        }
        r--;
        if (b[i] == a[r]) { cout << b[i] << ", "; }
    }  
}




int main()
{
    setlocale(LC_ALL, "rus");
    int ka = 0;
    int kb = 0;
    int a[] = { 2, 4, 3, 5, 6, 7 };
    int b[] = { 9, 2, 7, 6 };

    for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
        cout << a[i] << ", ";
        ka++;
    }
    cout << endl;
    for (int i = 0; i < sizeof(b) / sizeof(*b); i++) {
        cout << b[i] << ", ";
        kb++;
    }
    cout << endl << endl;;

    cout << ka << " " << kb << endl;

    foo(a, b, ka, kb);

}


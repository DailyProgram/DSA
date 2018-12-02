#include <iostream>
using namespace std;

// функция с алгоритмом двоичного поиска
int Search_Binary(int arr[], int N, int key) {
  int m = 0; //середина вектора
  int l = 0; //нижняя граница
  int u = N; //верхняя границв
  while (true) {
    m = (l + u) / 2;
    if (key < arr[m]) // если искомое меньше значения в ячейке
      u = m - 1; // смещаем правую границу поиска
    else if (key > arr[m]) // если искомое больше значения в ячейке
      l = m + 1; // смещаем левую границу поиска
    else         // иначе (значения равны)
      return m; // функция возвращает индекс ячейки

    if (l > u) // если границы сомкнулись
      return -1;
  }
}

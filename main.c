#include <stdio.h>
#include <stdlib.h>

/*
Ращупкин Евгений КЭ-203
2 (28) вариант
Lab6
Бинарный поиск

1. Поиск в линейных структурах
Написать программу, которая:
-запрашивает у пользователя размер массива и ключ поиска;
-формирует массив случайных чисел;
-возвращает количество совпадений и их номера.
Реализовать программу с помощью следующих алгоритмов: бинарный поиск (для варианта 2).
*/

//Вывод массива
void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Заполнение массива случайными элементами
void RandArr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

//Поиск совпадения по левому элементом
int LeftBinarySearch(int key, int *arr, int size)
{
    int left = 0, right = size;
    while (abs(right - left) > 1)
    {
        int middle = (left + right) / 2;
        if (key <= arr[middle])
            right = middle;
        else
            left = middle;
    }
    if (arr[right] == key)
        return right;
    else
        return -1;
}

//Поиск совпадения по правому элементом
int RightBinarySearch(int key, int *arr, int size)
{
    int left = 0, right = size;
    while (abs(right - left) > 1)
    {
        int middle = (left + right) / 2;
        if (key >= arr[middle])
            left = middle;
        else
            right = middle;
    }
    if (arr[left] == key)
        return left;
    else
        return -1;
}

//Быстрая сортировка
void qsortRecursive(int *arr, int size)
{
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = arr[size / 2];

    //Делим массив
    do
    {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (arr[i] < mid)
        {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (arr[j] > mid)
        {
            j--;
        }

        //Меняем элементы местами
        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    //Рекурсивные вызовы
    if (j > 0)
    {
        //Слева
        qsortRecursive(arr, j + 1);
    }
    if (i < size)
    {
        //Справа
        qsortRecursive(&arr[i], size - i);
    }
}

int main()
{
    int n;
    int key;

    printf("Len of arr: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    RandArr(arr, n);
    PrintArray(arr, n);

    printf("Sorted:\n");
    qsortRecursive(arr, n);
    PrintArray(arr, n);

    printf("Key: ");
    scanf("%d", &key);
    int i_start = LeftBinarySearch(key, arr, n);
    int i_finish = RightBinarySearch(key, arr, n);
    if (i_start == -1)
    {
        printf("No matching");
    }
    else if (i_start == i_finish)
    {
        printf("arr[%d] = %d \n", i_start, arr[i_start]);
    }
    else
    {
        printf("arr[%d] = %d \n", i_start, arr[i_start]);
        printf("...\n");
        printf("arr[%d] = %d \n", i_finish, arr[i_finish]);
        printf("%d matching\n", i_finish - i_start + 1);
    }

    free(arr);
    return 0;
}
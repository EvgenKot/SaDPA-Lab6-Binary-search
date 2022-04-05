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


void PrintArray(int *arr, int n){
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}




void RandArr(int *arr, int size){
    int i;
    for (i = 0; i < size; i++){
        arr[i] = rand();
    }
    
}



int main() {
    int n;

    printf("Len of arr: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    RandArr (arr, n);
    PrintArray (arr, n);


    free(arr);
    return 0;
}
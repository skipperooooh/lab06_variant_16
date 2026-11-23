#include <stdio.h>
#include "array_algorithms.h"

int main(void)
{
    int a[MAX_ARRAY_SIZE];
    int b[MAX_ARRAY_SIZE]; // максимально возможный размер массива
    int c[MAX_ARRAY_SIZE];
    int n;                 // размер массива(вводимый)
    int M;                 // порог шума

    printf("Enter capacity of array:\n"); // ввод размера массива

    if (scanf("%d", &n) != 1|| n <= 0 || n > MAX_ARRAY_SIZE) // проверка ввода n на размер и на корректность ввода
    {
        printf("Incorrect n.\n");
        return 1;
    }

    printf("Enter elements:\n"); // ввод элементов массива
    for (int i = 0; i < n; i++)
    {
        if(scanf("%d", &a[i]) != 1)
        {
        printf("Incorrect element of array.\n");
        return 1;
        }
    }

    printf("Default array: \n"); // вывод изначального массива
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n\n");

    copy_array(a, b, n); // сохраняем копию исходного массмива через новый массив
    

    printf("Enter maximum level of noise(M)\n"); // ввод максимально допустимого уровня шума
    if(scanf("%d", &M) != 1)
    {
        printf("Incorrect M.\n");
        return 1;
    }

    int number = linear_search(a, n, M); // функция линейного поиска элементов, превышающий максимум
    if (number == -1)
    {
        printf("No elements exceed M (in default array)\n");
    }
    else
    {
        printf("Number of the first element that is more than max(default array): %d\n\n", number + 1);
    }

    selection_sort(b, n); // сортируем выбором

    printf("Sorted array: \n"); // вывод массива после сортировки выбором
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", b[i]);
    }
    printf("\n\n");

    if (is_sorted(b, n) == 0) //проверка сортировки на верность
    {
        printf("Array is not sorted\n");
        return 1;
    }
    else
    {
        printf("Array is sorted. All correct\n");
    }

    int number1 = binary_search(b,n,M);//бинарный поиск
    if (number1 == -1)
    {
        printf("No elements exceed M (in sorted array)\n");
        printf("Total exceeds: 0\n");
    }
    else
    {
        printf("Number of the first element that is more than max(in sorted array): %d\n", number1 + 1);
        printf("Total exceeds: %d\n", (n - number1));
    }


    printf(" --- LVLS --\n");
    copy_array(a, c, n);
    bubble_sort(c, n);

    printf("Sorted array(bubble): \n"); // вывод массива после сортировки пузырьком
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", c[i]);
    }
    printf("\n\n");



    return 0;
}

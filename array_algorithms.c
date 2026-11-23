#include "array_algorithms.h"

void copy_array(const int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}
int linear_search(int a[], int n, int M) // линейный поиск элементов выше максимума
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] > M)
        {
            return i;
        }
    }
    return -1;
}

void selection_sort(int b[], int n) // сортировка выбором
{
    for (int i = 0; i < n; i++) // двигамся слева направо по массиву и пропускаем уже отсортированные элементы
    {
        int min_index = i;
        for (int j = i; j < n; j++) // ищем самый маленький элемент массива
        {
            if (b[j] < b[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i) // сохраняем в новый отсортированный массив
        {
            int temp = b[i];
            b[i] = b[min_index];
            b[min_index] = temp;
        }
    }
}

int is_sorted(const int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int binary_search(const int b[], int n, int M)
{
    int left = 0;
    int right = n - 1;
    int result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (b[mid] > M)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

void bubble_sort(int c[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for(int j = 0; j < n - i - 1; j++)
        {   
            if (c[j] > c[j+1])
            {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    
    }
}
#include <stdio.h>
#include "array_algorithms.h"
#include "tests.h"

#define ANALYSIS_SIZE 10

/* stats[0]: comparisons of elements. stats[1]: value assignments in swaps. */
void measure_selection_sort(int a[], int n, int stats[])
{
    stats[0] = 0;
    stats[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i; j < n; j++)
        {
            stats[0]++;
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
            stats[1] += 3;
        }
    }
}

void measure_bubble_sort(int a[], int n, int stats[])
{
    stats[0] = 0;
    stats[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            stats[0]++;
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                stats[1] += 3;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

int run_experiment_case(const int original[], int n)
{
    int selection[ANALYSIS_SIZE];
    int bubble[ANALYSIS_SIZE];
    int original_selection[ANALYSIS_SIZE];
    int original_bubble[ANALYSIS_SIZE];
    int selection_stats[2];
    int bubble_stats[2];

    copy_array(original, selection, n);
    copy_array(original, bubble, n);
    copy_array(original, original_selection, n);
    copy_array(original, original_bubble, n);

    measure_selection_sort(selection, n, selection_stats);
    measure_bubble_sort(bubble, n, bubble_stats);
    selection_sort(original_selection, n);
    bubble_sort(original_bubble, n);

    if (!is_sorted(selection, n) || !is_sorted(bubble, n))
    {
        printf("FAIL: result is not sorted.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (selection[i] != bubble[i] || selection[i] != original_selection[i]
            || bubble[i] != original_bubble[i])
        {
            printf("FAIL: sorting results differ.\n");
            return 1;
        }
    }

    printf("  Selection: %3d comparisons, %3d moves\n",
           selection_stats[0], selection_stats[1]);
    printf("  Bubble:    %3d comparisons, %3d moves\n",
           bubble_stats[0], bubble_stats[1]);
    printf("  Sorted arrays match.\n");
    return 0;
}

int main(void)
{
    int ascending[ANALYSIS_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int descending[ANALYSIS_SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int nearly_sorted[ANALYSIS_SIZE] = {1, 2, 3, 4, 6, 5, 7, 8, 9, 10};
    int failures = 0;

    printf("Lab 6 / Variant 16 / Sorting experiment (n = %d)\n", ANALYSIS_SIZE);
    printf("Ascending:\n");
    failures += run_experiment_case(ascending, ANALYSIS_SIZE);
    printf("Descending:\n");
    failures += run_experiment_case(descending, ANALYSIS_SIZE);
    printf("Nearly sorted:\n");
    failures += run_experiment_case(nearly_sorted, ANALYSIS_SIZE);
    printf("\nExperiment: %d failed.\n\n", failures);

    int test_result = run_algorithm_tests();
    if (failures != 0 || test_result != 0)
    {
        return 1;
    }
    return 0;
}

#include <stdio.h>
#include "tests.h"
#include "array_algorithms.h"

int check_case(int id, int original[], const int expected_sorted[], int n, int M,
               int expected_linear, int expected_binary, int expected_count)
{
    int by_selection[MAX_ARRAY_SIZE];
    int by_bubble[MAX_ARRAY_SIZE];
    int count_linear = 0;

    copy_array(original, by_selection, n);
    copy_array(original, by_bubble, n);
    selection_sort(by_selection, n);
    bubble_sort(by_bubble, n);

    if (!is_sorted(by_selection, n) || !is_sorted(by_bubble, n))
    {
        printf("T%d FAIL: array is not sorted.\n", id);
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (by_selection[i] != by_bubble[i] || by_selection[i] != expected_sorted[i])
        {
            printf("T%d FAIL: wrong sorted values at index %d.\n", id, i);
            return 1;
        }
        if (original[i] > M)
        {
            count_linear++;
        }
    }

    int first_original = linear_search(original, n, M);
    int first_sorted = binary_search(by_selection, n, M);
    if (first_original != expected_linear || first_sorted != expected_binary
        || binary_search(by_bubble, n, M) != first_sorted)
    {
        printf("T%d FAIL: wrong search index.\n", id);
        return 1;
    }

    int count_binary = 0;
    if (first_sorted != -1)
    {
        count_binary = n - first_sorted;
    }
    if (count_binary != count_linear || count_binary != expected_count)
    {
        printf("T%d FAIL: wrong number of exceedances.\n", id);
        return 1;
    }

    printf("T%d PASS\n", id);
    return 0;
}

int run_algorithm_tests(void)
{
    int t1[] = {45, 72, 60, 82, 53, 68};
    int sorted_t1[] = {45, 53, 60, 68, 72, 82};
    int t2[] = {70, 60, 80, 60, 70, 80, 70};
    int sorted_t2[] = {60, 60, 70, 70, 70, 80, 80};
    int t3[] = {65, 58, 60, 65, 61};
    int sorted_t3[] = {58, 60, 61, 65, 65};
    int t4[] = {66};
    int t5[MAX_ARRAY_SIZE];
    int sorted_t5[MAX_ARRAY_SIZE];
    int t6[] = {50, 60, 65, 68, 70};
    int t10[] = {64, 60, 65, 71};
    int sorted_t10[] = {60, 64, 65, 71};
    int failures = 0;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        t5[i] = MAX_ARRAY_SIZE - i;
        sorted_t5[i] = i + 1;
    }

    /* Expected search indices start at zero, as in the original functions. */
    printf("Automatic tests:\n");
    failures += check_case(1, t1, sorted_t1, 6, 65, 1, 3, 3);
    failures += check_case(2, t2, sorted_t2, 7, 70, 2, 5, 2);
    failures += check_case(3, t3, sorted_t3, 5, 65, -1, -1, 0);
    failures += check_case(4, t4, t4, 1, 65, 0, 0, 1);
    failures += check_case(5, t5, sorted_t5, MAX_ARRAY_SIZE, 50, 0, 50, 50);
    failures += check_case(6, t6, t6, 5, 49, 0, 0, 5);
    failures += check_case(10, t10, sorted_t10, 4, 65, 3, 3, 1);
    printf("Automatic tests: %d/7 passed.\n", 7 - failures);

    return failures;
}

#include <stdio.h>
#include "sort_algo_comparator.h"
#include "sort_algo.h"

int main() {
    sort_algo_comparator *comparator = sort_algo_comparator_create();
    sort_algo_comparator_read_data(comparator, "data.txt");

    const int TIMEOUT = 15;

    // sort_algo_comparator_sort(comparator, bubble_sort_v1_0, "Bubble Sort (original v1.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, bubble_sort_v2_0, "Bubble Sort (optimized v2.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, bubble_sort_v2_1, "Bubble Sort (optimized v2.1)", TIMEOUT);

    // sort_algo_comparator_sort(comparator, selection_sort_v1_0, "Selection Sort (original v1.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, selection_sort_v2_0, "Selection Sort (optimized v2.0)", TIMEOUT);

    // sort_algo_comparator_sort(comparator, insertion_sort_v1_0, "Insertion Sort (original v1.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, insertion_sort_v2_0, "Insertion Sort (optimized v2.0)", TIMEOUT);

    sort_algo_comparator_sort(comparator, shell_sort_v1_0, "Shell Sort (original v1.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, shell_sort_hibbard, "Shell Sort (Hibbard)", TIMEOUT);
    sort_algo_comparator_sort(comparator, shell_sort_sedgewick, "Shell Sort (Sedgewick)", TIMEOUT);

    sort_algo_comparator_sort(comparator, merge_sort_v1_0, "Merge Sort (original v1.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, merge_sort_v2_0, "Merge Sort (optimized v2.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, merge_sort_v3_0, "Merge Sort (optimized v3.0)", TIMEOUT);

    sort_algo_comparator_sort(comparator, quick_sort_v1_0, "Quick Sort (original v1.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, quick_sort_v2_0, "Quick Sort (optimized v2.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, quick_sort_v2_1, "Quick Sort (optimized v2.1)", TIMEOUT);
    sort_algo_comparator_sort(comparator, quick_sort_v2_2, "Quick Sort (optimized v2.2)", TIMEOUT);
    sort_algo_comparator_sort(comparator, quick_sort_v3_0, "Quick Sort (optimized v3.0)", TIMEOUT);

    sort_algo_comparator_destroy(comparator);
    return 0;
}
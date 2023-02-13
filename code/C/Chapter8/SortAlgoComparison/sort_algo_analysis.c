#include <stdio.h>
#include "sort_algo_comparator.h"
#include "sort_algo.h"

int main() {
    sort_algo_comparator *comparator = sort_algo_comparator_create();
    sort_algo_comparator_read_data(comparator, "data.txt");

    const int TIMEOUT = 15;

    // sort_algo_comparator_sort(comparator, bubble_sort, "Bubble Sort (original v1.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, bubble_sort_opt_v1, "Bubble Sort (optimized v2.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, bubble_sort_opt_v2, "Bubble Sort (optimized v2.1)", TIMEOUT);

    // sort_algo_comparator_sort(comparator, selection_sort, "Selection Sort (original v1.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, selection_sort_opt, "Selection Sort (optimized v2.0)", TIMEOUT);

    // sort_algo_comparator_sort(comparator, insertion_sort, "Insertion Sort (original v1.0)", TIMEOUT);
    // sort_algo_comparator_sort(comparator, insertion_sort_opt, "Insertion Sort (optimized v2.0)", TIMEOUT);

    sort_algo_comparator_sort(comparator, shell_sort, "Shell Sort (original v1.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, shell_sort_opt_hibbard, "Shell Sort (Hibbard)", TIMEOUT);
    sort_algo_comparator_sort(comparator, shell_sort_opt_sedgewick, "Shell Sort (Sedgewick)", TIMEOUT);

    sort_algo_comparator_sort(comparator, merge_sort, "Merge Sort (original v1.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, merge_sort_opt_v1, "Merge Sort (optimized v2.0)", TIMEOUT);
    sort_algo_comparator_sort(comparator, merge_sort_opt_v2, "Merge Sort (optimized v3.0)", TIMEOUT);

    sort_algo_comparator_destroy(comparator);
    return 0;
}
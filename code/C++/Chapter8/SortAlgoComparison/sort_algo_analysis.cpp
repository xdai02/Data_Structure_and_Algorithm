#include <iostream>
#include "sort_algo_comparator.h"
#include "sort_algo.h"

using namespace std;

int main() {
    SortAlgoComparator<int> *comparator = new SortAlgoComparator<int>();
    comparator->read_data("data.txt");

    comparator->sort(bubble_sort, "Bubble Sort (original)");
    comparator->sort(bubble_sort_opt_v1, "Bubble Sort (optimized v1.0)");
    comparator->sort(bubble_sort_opt_v2, "Bubble Sort (optimized v2.0)");

    comparator->sort(selection_sort, "Selection Sort (original)");
    comparator->sort(selection_sort_opt, "Selection Sort (optimized)");

    comparator->sort(insertion_sort, "Insertion Sort (original)");
    comparator->sort(insertion_sort_opt, "Insertion Sort (optimized)");

    comparator->sort(shell_sort, "Shell Sort (original)");
    comparator->sort(shell_sort_opt_hibbard, "Shell Sort (Hibbard)");
    comparator->sort(shell_sort_opt_sedgewick, "Shell Sort (Sedgewick)");

    return 0;
}
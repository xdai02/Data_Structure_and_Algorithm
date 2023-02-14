from sort_algo_comparator import SortAlgoComparator
from sort_algo import *

def main():
    comparator = SortAlgoComparator()
    comparator.read_data('data.txt')

    comparator.sort(bubble_sort_v1_0, "Bubble Sort (original v1.0)")
    comparator.sort(bubble_sort_v2_0, "Bubble Sort (optimized v2.0)")
    comparator.sort(bubble_sort_v2_1, "Bubble Sort (optimized v2.1)")

    comparator.sort(selection_sort_v1_0, "Selection Sort (original v1.0)")
    comparator.sort(selection_sort_v2_0, "Selection Sort (optimized v2.0)")

    comparator.sort(insertion_sort_v1_0, "Insertion Sort (original v1.0)")
    comparator.sort(insertion_sort_v2_0, "Insertion Sort (optimized v2.0)")

    comparator.sort(shell_sort_v1_0, "Shell Sort (original v1.0)")
    comparator.sort(shell_sort_hibbard, "Shell Sort (Hibbard)")
    comparator.sort(shell_sort_sedgewick, "Shell Sort (Sedgewick)")

    comparator.sort(merge_sort_v1_0, "Merge Sort (original v1.0)")
    comparator.sort(merge_sort_v2_0, "Merge Sort (optimized v2.0)")
    comparator.sort(merge_sort_v3_0, "Merge Sort (optimized v3.0)")

    comparator.sort(quick_sort_v1_0, "Quick Sort (original v1.0)")
    comparator.sort(quick_sort_v2_0, "Quick Sort (optimized v2.0)")
    comparator.sort(quick_sort_v2_1, "Quick Sort (optimized v2.1)")
    comparator.sort(quick_sort_v2_2, "Quick Sort (optimized v2.2)")
    comparator.sort(quick_sort_v3_0, "Quick Sort (optimized v3.0)")

if __name__ == '__main__':
    main()
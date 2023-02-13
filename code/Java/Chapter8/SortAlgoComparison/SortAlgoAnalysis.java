import java.io.IOException;

public class SortAlgoAnalysis {
    public static void main(String[] args) throws IOException, InterruptedException {
        SortAlgoComparator<Integer> comparator = new SortAlgoComparator(Integer.class);
        comparator.readData("data.txt");

        final int TIMEOUT = 15;
        SortAlgo sortAlgo = SortAlgo.getInstance(Integer.class);

        // comparator.sort(SortAlgo::bubbleSort, "Bubble Sort (original v1.0)", TIMEOUT);
        // comparator.sort(SortAlgo::bubbleSortOptV1, "Bubble Sort (optimized v2.0)", TIMEOUT);
        // comparator.sort(SortAlgo::bubbleSortOptV2, "Bubble Sort (optimized v2.1)", TIMEOUT);

        // comparator.sort(SortAlgo::selectionSort, "Selection Sort (original v1.0)", TIMEOUT);
        // comparator.sort(SortAlgo::selectionSortOpt, "Selection Sort (optimized v2.0)", TIMEOUT);

        // comparator.sort(SortAlgo::insertionSort, "Insertion Sort (original v1.0)", TIMEOUT);
        // comparator.sort(SortAlgo::insertionSortOpt, "Insertion Sort (optimized v2.0)", TIMEOUT);

        comparator.sort(SortAlgo::shellSort, "Shell Sort (original v1.0)", TIMEOUT);
        comparator.sort(SortAlgo::shellSortOptHibbard, "Shell Sort (Hibbard)", TIMEOUT);
        comparator.sort(SortAlgo::shellSortOptSedgewick, "Shell Sort (Sedgewick)", TIMEOUT);

        comparator.sort(SortAlgo::mergeSort, "Merge Sort (original v1.0)", TIMEOUT);
        comparator.sort(SortAlgo::mergeSortOptV1, "Merge Sort (optimized v2.0)", TIMEOUT);
        comparator.sort(SortAlgo::mergeSortOptV2, "Merge Sort (optimized v3.0)", TIMEOUT);
    }
}

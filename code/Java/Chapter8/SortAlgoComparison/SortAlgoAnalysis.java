import java.io.IOException;

public class SortAlgoAnalysis {
    public static void main(String[] args) throws IOException, InterruptedException {
        SortAlgoComparator<Integer> comparator = new SortAlgoComparator(Integer.class);
        comparator.readData("data.txt");

        final int TIMEOUT = 15;

        comparator.sort(SortAlgo::bubbleSort, "Bubble Sort (original)", TIMEOUT);
        comparator.sort(SortAlgo::bubbleSortOptV1, "Bubble Sort (optimized v1.0)", TIMEOUT);
        comparator.sort(SortAlgo::bubbleSortOptV2, "Bubble Sort (optimized v2.0)", TIMEOUT);

        comparator.sort(SortAlgo::selectionSort, "Selection Sort (original)", TIMEOUT);
        comparator.sort(SortAlgo::selectionSortOpt, "Selection Sort (optimized)", TIMEOUT);

        comparator.sort(SortAlgo::insertionSort, "Insertion Sort (original)", TIMEOUT);
        comparator.sort(SortAlgo::insertionSortOpt, "Insertion Sort (optimized)", TIMEOUT);

        comparator.sort(SortAlgo::shellSort, "Shell Sort (original)", TIMEOUT);
        comparator.sort(SortAlgo::shellSortOptHibbard, "Shell Sort (Hibbard)", TIMEOUT);
        comparator.sort(SortAlgo::shellSortOptSedgewick, "Shell Sort (Sedgewick)", TIMEOUT);
    }
}

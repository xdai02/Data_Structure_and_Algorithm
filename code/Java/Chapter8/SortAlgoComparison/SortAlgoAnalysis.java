import java.io.IOException;

public class SortAlgoAnalysis {
    public static void main(String[] args) throws IOException, InterruptedException {
        SortAlgoComparator<Integer> comparator = new SortAlgoComparator(Integer.class);
        comparator.readData("data.txt");

        final int TIMEOUT = 15;
        SortAlgo sortAlgo = SortAlgo.getInstance(Integer.class);

        // comparator.sort(SortAlgo::bubbleSortV10, "Bubble Sort (original v1.0)", TIMEOUT);
        // comparator.sort(SortAlgo::bubbleSortV20, "Bubble Sort (optimized v2.0)", TIMEOUT);
        // comparator.sort(SortAlgo::bubbleSortV21, "Bubble Sort (optimized v2.1)", TIMEOUT);

        // comparator.sort(SortAlgo::selectionSortV10, "Selection Sort (original v1.0)", TIMEOUT);
        // comparator.sort(SortAlgo::selectionSortV20, "Selection Sort (optimized v2.0)", TIMEOUT);

        // comparator.sort(SortAlgo::insertionSortV10, "Insertion Sort (original v1.0)", TIMEOUT);
        // comparator.sort(SortAlgo::insertionSortV20, "Insertion Sort (optimized v2.0)", TIMEOUT);

        comparator.sort(SortAlgo::shellSortV10, "Shell Sort (original v1.0)", TIMEOUT);
        comparator.sort(SortAlgo::shellSortHibbard, "Shell Sort (Hibbard)", TIMEOUT);
        comparator.sort(SortAlgo::shellSortSedgewick, "Shell Sort (Sedgewick)", TIMEOUT);

        comparator.sort(SortAlgo::mergeSortV10, "Merge Sort (original v1.0)", TIMEOUT);
        comparator.sort(SortAlgo::mergeSortV20, "Merge Sort (optimized v2.0)", TIMEOUT);
        comparator.sort(SortAlgo::mergeSortV30, "Merge Sort (optimized v3.0)", TIMEOUT);
    
        comparator.sort(SortAlgo::quickSortV10, "Quick Sort (original v1.0)", TIMEOUT);
        comparator.sort(SortAlgo::quickSortV20, "Quick Sort (optimized v2.0)", TIMEOUT);
        comparator.sort(SortAlgo::quickSortV21, "Quick Sort (optimized v2.1)", TIMEOUT);
        comparator.sort(SortAlgo::quickSortV22, "Quick Sort (optimized v2.2)", TIMEOUT);
        comparator.sort(SortAlgo::quickSortV30, "Quick Sort (optimized v3.0)", TIMEOUT);
    }
}

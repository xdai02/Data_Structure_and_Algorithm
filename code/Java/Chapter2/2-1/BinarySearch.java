public class BinarySearch {
    public static void main(String[] args) {
        Integer[] arr = {7, 9, 20, 34, 40, 85, 91, 93};
        Integer key = 34;
        System.out.println("index = " + binarySearch(arr, key));
    }

    public static <T extends Comparable<T>> int binarySearch(T[] arr, T key) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid].compareTo(key) == 0) {
                return mid;
            } else if (arr[mid].compareTo(key) < 0) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
}
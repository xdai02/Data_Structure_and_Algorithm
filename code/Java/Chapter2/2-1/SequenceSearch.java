public class SequenceSearch {
    public static void main(String[] args) {
        Integer[] arr = {40, 9, 20, 93, 7, 34, 85, 91};
        Integer key = 34;
        System.out.println("index = " + sequenceSearch(arr, key));
    }

    public static <T> int sequenceSearch(T[] arr, T key) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].equals(key)) {
                return i;
            }
        }
        return -1;
    }
}
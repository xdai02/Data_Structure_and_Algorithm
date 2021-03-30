import java.util.Arrays;

public class HeapSort {
    public static void main(String[] args) {
        int[] arr = new int[] {5, 8, 6, 3, 9, 2, 1, 7};
        System.out.print("����ǰ��");
        System.out.println(Arrays.toString(arr));
        heapSort(arr);
        System.out.print("�����");
        System.out.println(Arrays.toString(arr));
    }

    /**
     * �³�����
     * @param arr �������Ķ�
     * @param parentIndex Ҫ�³��ĸ����
     * @param length �ѵ���Ч��С
     */
    public static void downAdjust(int[] arr, int parentIndex, int length) {
        // ���游����ֵ���������ĸ�ֵ
        int temp = arr[parentIndex];
        int childIndex = 2 * parentIndex + 1;

        while(childIndex < length) {
            // ������Һ��ӣ����Һ��Ӵ������ӵ�ֵ����λ���Һ���
            if(childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex]) {
                childIndex++;
            }
            // ��������С���κ�һ�����ӵ�ֵ��ֱ������
            if(temp >= arr[childIndex]) {
                break;
            }
            // ������������������ֵ����
            arr[parentIndex] = arr[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        arr[parentIndex] = temp;
    }

    /**
     * ������
     * @param arr �������Ķ�
     */
    public static void heapSort(int[] arr) {
        // ���������鹹���ɶ����
        for(int i = (arr.length-2) / 2; i >= 0; i--) {
            downAdjust(arr, i, arr.length);
        }

        // ѭ��ɾ���Ѷ�Ԫ�أ��Ƶ�����β�������ڶѲ����µĶѶ�
        for(int i = arr.length - 1; i > 0; i--) {
            // ���һ��Ԫ�غ͵�һ��Ԫ�ؽ���
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            // �³���������
            downAdjust(arr, 0, i);
        }
    }
}
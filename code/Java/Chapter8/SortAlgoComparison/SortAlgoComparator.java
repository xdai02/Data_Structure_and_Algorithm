import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.concurrent.TimeUnit;
import java.util.function.Function;

public class SortAlgoComparator<T extends Number & Comparable<T>> {
    private T[] data;
    private Class clazz;

    public SortAlgoComparator(Class clazz) {
        this.clazz = clazz;
    }

    public int readData(String filename) {
        int count = 0;

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));

            String line;
            while ((line = reader.readLine()) != null) {
                String[] tokens = line.split("\\s");
                count += tokens.length;
            }

            reader.close();
            reader = new BufferedReader(new FileReader(filename));

            data = (T[]) Array.newInstance(clazz, count);
            int i = 0;

            while ((line = reader.readLine()) != null) {
                String[] tokens = line.split("\\s");
                for (String token : tokens) {
                    if (clazz == Integer.class) {
                        data[i] = (T) Integer.valueOf(token);
                    } else if (clazz == Double.class) {
                        data[i] = (T) Double.valueOf(token);
                    } else {
                        throw new ClassCastException();
                    }
                    i++;
                }
            }
        } catch (IOException e) {
            return 0;
        }

        return count;
    }

    public void sort(Function<T[], T[]> sort, String algoName, int timeout) {
        // make a copy of data
        T[] data = (T[]) Array.newInstance(clazz, this.data.length);
        System.arraycopy(this.data, 0, data, 0, this.data.length);

        System.out.println(algoName + " started...");

        try {
            long startTime = System.currentTimeMillis();
            runWithTimeout(() -> sort.apply(data), timeout);
            long endTime = System.currentTimeMillis();
            System.out.printf("%s: %.3f seconds\n", algoName, (endTime - startTime) / 1000.0);
        } catch (InterruptedException e) {
            System.out.println(algoName + " timed out");
        }
    }

    private void runWithTimeout(Runnable function, int timeout) throws InterruptedException {
        Thread functionThread = new Thread(function);
        functionThread.start();
        functionThread.join(TimeUnit.SECONDS.toMillis(timeout));

        if (functionThread.isAlive()) {
            functionThread.interrupt();
            throw new InterruptedException();
        }
    }
}

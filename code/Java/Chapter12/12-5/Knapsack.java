public class Knapsack {
    public static class Item {
        double weight;
        double value;

        public Item(double weight, double value) {
            this.weight = weight;
            this.value = value;
        }
    }

    public static void main(String[] args) {
        Item[] items = {
                new Item(2, 3),
                new Item(3, 4),
                new Item(4, 5),
                new Item(5, 8),
                new Item(9, 10)
        };
        int capacity = 20;
        System.out.println(knapsack(items, capacity));
    }

    public static int knapsack(Item[] items, int capacity) {
        int[][] values = new int[items.length + 1][capacity + 1];

        for (int i = 1; i <= items.length; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (items[i - 1].weight > j) {
                    values[i][j] = values[i - 1][j];
                } else {
                    values[i][j] = Math.max(
                            values[i - 1][j - (int) items[i - 1].weight] + (int) items[i - 1].value,
                            values[i - 1][j]
                    );
                }
            }
        }

        return values[items.length][capacity];
    }
}
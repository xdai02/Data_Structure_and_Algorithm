import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Knapsack {
    public static class Item implements Comparable<Item> {
        double weight;
        double value;
        double unitValue;

        public Item(double weight, double value) {
            this.weight = weight;
            this.value = value;
            this.unitValue = value / weight;
        }

        @Override
        public int compareTo(Item obj) {
            return Double.valueOf(this.unitValue).compareTo(obj.unitValue);
        }

        @Override
        public String toString() {
            return "Item(weight=" + weight + ", value=" + value + ", unitValue=" + unitValue + ")";
        }
    }

    public static Item[] knapsack(Item[] items, int capacity) {
        Arrays.sort(items, Collections.reverseOrder());

        ArrayList<Item> selectedItems = new ArrayList<Item>();
        double selectedWeight = 0;

        for (Item item : items) {
            if (selectedWeight + item.weight <= capacity) {
                selectedWeight += item.weight;
                selectedItems.add(item);
            } else {
                double portion = (capacity - selectedWeight) / item.weight;
                item.weight *= portion;
                item.value *= portion;
                selectedItems.add(item);
                break;
            }
        }

        return selectedItems.toArray(new Item[selectedItems.size()]);
    }

    public static void main(String[] args) {
        Item[] items = {
                new Item(10, 20),
                new Item(5, 30),
                new Item(15, 15),
                new Item(10, 25),
                new Item(20, 10)
        };
        int capacity = 30;

        Item[] selectedItems = knapsack(items, capacity);
        for (Item item : selectedItems) {
            System.out.println(item);
        }
    }
}

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Knapsack {
	/**
	 * 物品内部类
	 */
	private static class Item implements Comparable<Item> {
		int type;			// 物品类型
		double weight;		// 重量
		double value;		// 价值
		double unitValue;	// 单位价值
		
		public Item(int type, double weight, double value) {
			this.type = type;
			this.weight = weight;
			this.value = value;
			this.unitValue = this.value / this.weight;
		}

		public void setWeight(double weight) {
			this.weight = weight;
		}
		
		@Override
		/**
		 * 降序排序
		 */
		public int compareTo(Item obj) {
			return Double.valueOf(obj.unitValue).compareTo(this.unitValue);
		}
	}
	
	public static void main(String[] args) {
		double capacity = 30;		// 背包容量
		int[] itemType = {1, 2, 3, 4, 5};
		double[] itemWeight = {10, 5, 15, 10, 30};
		double[] itemValue = {20, 30, 15, 25, 10};
		
		// 初始化物品
		List<Item> items = new ArrayList<Item>();
		for(int i = 0; i < itemType.length; i++) {
			Item item = new Item(itemType[i], itemWeight[i], itemValue[i]);
			items.add(item);
		}
		
		// 物品按照单价降序排列
		Collections.sort(items);
		
		// 背包选择
		List<Item> selectItems = new ArrayList<Item>();
		double curWeight = 0;		// 当前背包重量
		for(Item item : items) {
			if(curWeight + item.weight <= capacity) {
				curWeight += item.weight;
				selectItems.add(item);
			} else {
				item.setWeight(capacity - curWeight);
				selectItems.add(item);
				break;
			}
		}
		
		// 输出选择结果
		for(Item item : selectItems) {
			System.out.println("物品" + item.type + "，重量：" + item.weight);
		}
	}
}

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Knapsack {
	/**
	 * ��Ʒ�ڲ���
	 */
	private static class Item implements Comparable<Item> {
		int type;			// ��Ʒ����
		double weight;		// ����
		double value;		// ��ֵ
		double unitValue;	// ��λ��ֵ
		
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
		 * ��������
		 */
		public int compareTo(Item obj) {
			return Double.valueOf(obj.unitValue).compareTo(this.unitValue);
		}
	}
	
	public static void main(String[] args) {
		double capacity = 30;		// ��������
		int[] itemType = {1, 2, 3, 4, 5};
		double[] itemWeight = {10, 5, 15, 10, 30};
		double[] itemValue = {20, 30, 15, 25, 10};
		
		// ��ʼ����Ʒ
		List<Item> items = new ArrayList<Item>();
		for(int i = 0; i < itemType.length; i++) {
			Item item = new Item(itemType[i], itemWeight[i], itemValue[i]);
			items.add(item);
		}
		
		// ��Ʒ���յ��۽�������
		Collections.sort(items);
		
		// ����ѡ��
		List<Item> selectItems = new ArrayList<Item>();
		double curWeight = 0;		// ��ǰ��������
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
		
		// ���ѡ����
		for(Item item : selectItems) {
			System.out.println("��Ʒ" + item.type + "��������" + item.weight);
		}
	}
}

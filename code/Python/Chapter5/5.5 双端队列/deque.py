class Deque:
	def __init__(self):
		self.data = []

	def is_empty(self):
		return not self.data

	def add_front(self, val):
		self.data.insert(0, val)

	def add_rear(self, val):
		self.data.append(val)

	def remove_front(self):
		if not self.is_empty():
			return self.data.pop(0)

	def remove_rear(self):
		if not self.is_empty():
			return self.data.pop()

	def get_front(self):
		if not self.is_empty():
			return self.data[0]

	def get_rear(self):
		if not self.is_empty():
			return self.data[len(self.data)-1]

def main():
	deque = Deque()
	deque.add_front(11)			# 11
	deque.add_front(22)			# 22 11
	deque.remove_rear()			# 22
	deque.add_rear(33)			# 22 33
	deque.add_rear(44)			# 22 33 44
	deque.remove_front()		# 33 44
	print(deque.get_front())
	print(deque.get_rear())

if __name__ == "__main__":
	main()

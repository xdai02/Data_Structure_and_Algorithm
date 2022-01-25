"""
    （百钱买百鸡）
    公鸡5文钱1只，母鸡3文钱1只，小鸡1文钱3只。
    如果用100文钱买100只鸡，那么公鸡、母鸡和小鸡各应该买多少只？
"""

def buy(n, money):
    """
        百钱买百鸡
        x=公鸡，y=母鸡，z=小鸡
        Args:
            n (int): 鸡数
            money (int): 钱
    """
    for x in range(n//5+1):
        for y in range(n//3+1):
            z = n - x - y
            if z > 0 and z % 3 == 0 and 5*x + 3*y + z//3 == money:
                print("公鸡：%3d\t母鸡：%3d\t小鸡：%3d" % (x, y, z))

def main():
    buy(100, 100)

if __name__ == "__main__":
    main()
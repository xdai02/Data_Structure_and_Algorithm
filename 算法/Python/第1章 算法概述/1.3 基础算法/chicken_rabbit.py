"""
    （鸡兔同笼）
    上有三十五头，下有九十四足，问鸡兔各几何？
"""

def count(head, foot):
    """
        鸡兔同笼
        Args:
            head (int): 头数
            foot (int): 脚数
    """
    for chicken in range(head+1):
        rabbit = head - chicken
        if chicken*2 + rabbit*4 == foot:
            print("鸡：%2d\t兔：%2d" % (chicken, rabbit))

def main():
    count(35, 94)

if __name__ == "__main__":
    main()
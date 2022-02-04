move = 0            # 移动次数

def hanoi(n, src, mid, dst):
    global move
    """
        汉诺塔算法
        把 n 个盘子从 src 借助 mid 移到 dst

        Args:
            n (int): 层数
            src (str): 起点柱子
            mid (str): 临时柱子
            dst (str): 目标柱子
    """
    if n == 1:
        print("%d号盘：%c -> %c" % (n, src, dst))
        move += 1
    else:
        # 把前 n-1 个盘子从 src 借助 dst 移到 mid
        hanoi(n-1, src, dst, mid)
        # 移动第 n 个盘子
        print("%d号盘：%c -> %c" % (n, src, dst))
        move += 1
        # 把刚才的 n-1 个盘子从 mid 借助 src 移到 dst
        hanoi(n-1, mid, src, dst)

def main():
    hanoi(4, 'A', 'B', 'C')
    print("步数 ==> %d" % move)

if __name__ == "__main__":
    main()
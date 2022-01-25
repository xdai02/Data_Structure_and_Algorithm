import random
import math

def montePI(n):
    """
        蒙特卡洛算法计算PI
        Args:
            n (int): 样本数量
    """
    cnt = 0
    for _ in range(n):
        x = random.random()     # [0, 1)
        y = random.random()     # [0, 1)
        if math.sqrt(x**2 + y**2) <= 1:
            cnt += 1
    return 4.0 * cnt / n

def main():
    print(montePI(10000000))

if __name__ == "__main__":
    main()
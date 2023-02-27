COINS = [2, 5, 7]
INF = 2147483647

def get_min_coins(price):
    # 0元钱只需要0枚硬币
    if price == 0:
        return 0
    # 初始化为无穷大
    coin_num = INF
    # 最后一枚硬币是2元
    if price >= 2:
        coin_num = min(get_min_coins(price-2) + 1, coin_num)
    # 最后一枚硬币是5元
    if price >= 5:
        coin_num = min(get_min_coins(price-5) + 1, coin_num)
    # 最后一枚硬币是7元
    if price >= 7:
        coin_num = min(get_min_coins(price-7) + 1, coin_num)
    return coin_num

def main():
    price = 27
    print(get_min_coins(price))

if __name__ == "__main__":
    main()
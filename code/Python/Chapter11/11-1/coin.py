def get_min_coins(coins, price):
    """
        最少硬币找零
        Args:
            coins (list): 硬币面值
            price (int): 找零数量
    """
    solution = []
    coins = sorted(coins, reverse=True)
    for coin in coins:
        num = price // coin
        solution += [coin] * num
        price -= coin * num
        if price <= 0:
            break
    return solution

def main():
    coins = [1, 5, 10, 25, 100]
    price = 46
    print(get_min_coins(coins, price))

if __name__ == "__main__":
    main()
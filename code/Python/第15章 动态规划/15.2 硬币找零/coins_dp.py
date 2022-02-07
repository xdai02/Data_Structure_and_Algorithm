INF = 2147483647

def get_min_coins(coins, price):
    f = [INF] * (price + 1)

    f[0] = 0
    for i in range(1, price+1):
        for j in range(len(coins)):
            if i >= coins[j] and f[i - coins[j]] != INF:
                f[i] = min(f[i - coins[j]] + 1, f[i])
        
    if f[price] == INF:
        f[price] = -1
    return f[price]

def main():
    coins = [2, 5, 7]
    price = 27
    print(get_min_coins(coins, price))

if __name__ == "__main__":
    main()
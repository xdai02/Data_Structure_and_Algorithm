def get_min_coins(coins, price):
    solution = []
    
    for coin in reversed(coins):
        while price >= coin:
            solution.append(coin)
            price -= coin
    
    return solution

coins = [1, 5, 10, 25, 100]
price = 36
print(get_min_coins(coins, price))
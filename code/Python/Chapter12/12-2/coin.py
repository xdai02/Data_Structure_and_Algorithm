import math

def get_min_coins_recursive(coins, price):
    if price <= 0:
        return 0
    
    min_coins = math.inf
    for coin in coins:
        if price >= coin:
            min_coins = min(get_min_coins_recursive(coins, price - coin) + 1, min_coins)

    return min_coins

def get_min_coins_dp(coins, price):
    dp = [math.inf] * (price + 1)
    dp[0] = 0
    
    for i in range(1, price+1):
        for j in range(len(coins)):
            if i >= coins[j] and dp[i - coins[j]] != math.inf:
                dp[i] = min(dp[i - coins[j]] + 1, dp[i])
    
    return dp[price]

coins = [2, 5, 7]
price = 27
print(get_min_coins_recursive(coins, price))
print(get_min_coins_dp(coins, price))
def max_profit(prices):
    profit = 0
    for i in range(len(prices) - 1):
        if prices[i] < prices[i+1]:
            profit += prices[i+1] - prices[i]
    return profit

def main():
    prices = [7, 1, 5, 3, 6, 4]
    print(max_profit(prices))

if __name__ == "__main__":
    main()
import random
import math

def monte_pi(n):
    cnt = 0
    for _ in range(n):
        x = random.random()     # [0, 1)
        y = random.random()     # [0, 1)
        if math.sqrt(x**2 + y**2) <= 1:
            cnt += 1
    return 4.0 * cnt / n

print(monte_pi(10000000))
def buy(n, money):
    for x in range(n//5+1):
        for y in range(n//3+1):
            z = n - x - y
            if z > 0 and z % 3 == 0 and 5*x + 3*y + z//3 == money:
                print("x = %d, y = %d, z = %d" % (x, y, z))

buy(100, 100)
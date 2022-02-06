def distribute(children, cookies):
    children.sort()
    cookies.sort()
    child = 0
    cookie = 0
    while child < len(children) and cookie < len(cookies):
        if children[child] <= cookies[cookie]:
            child += 1
        cookie += 1
    return child

def main():
    children = [1, 2]
    cookies = [1, 2, 3]
    print(distribute(children, cookies))

if __name__ == "__main__":
    main()
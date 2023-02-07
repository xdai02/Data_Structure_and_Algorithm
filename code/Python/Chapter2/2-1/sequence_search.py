def sequence_search(lst, key):
    for i in range(len(lst)):
        if lst[i] == key:
            return i
    return -1

lst = [40, 9, 20, 93, 7, 34, 85, 91]
key = 34
print("index =", sequence_search(lst, key))
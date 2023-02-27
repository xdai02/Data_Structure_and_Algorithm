def select_activity(a, s, f):
    activity = []
    n = len(s)
    activity.append(a[0])
    k = 0
    for i in range(1, n):
        if s[i] >= f[k]:
            activity.append(a[i])
            k = i
    return activity

def main():
    # 活动集合
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    # 活动开始时间集合
    s = [1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
    # 活动结束时间集合
    f = [4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]
    print("选择活动：%s" % select_activity(a, s, f))

if __name__ == "__main__":
    main()
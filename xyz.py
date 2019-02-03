from collections import Counter
T = int(input())
while T:
    N, K = map(int, input().split())
    arr = [*map(int, input().split())]
    d = dict(Counter(arr))
    flag = False
    for key, val in d.items():
        if val == K:
            print(key, end=" ")
            flag = True
    if flag == False:
        print(-1, end=" ")
    print()
    d.clear()
    arr.clear()
    T -= 1
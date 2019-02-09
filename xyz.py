T = int(input())

while T:
    N, Q = map(int, input().split())
    arr = [*map(int, input().split())]
    arr = sorted(set(arr))
    while Q:
        K = int(input())
        try:
            print(arr.index(K)+1)
        except:
            print(-1)
        Q -= 1
    arr.clear()
    T -= 1
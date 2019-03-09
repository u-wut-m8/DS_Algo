T = int(input())
while T:
    N, d = input().split()
    for _ in range(len(N)):
        if N[:_] + N[_:+1] + d < N:
            N = N[:_] + N[_:+1] + d
    print(N)
    T -= 1
N = int(input())

stairs = [0]*(N+1)

stairs[1] = 1
stairs[2] = 2
stairs[3] = 4

for _ in range(4, N+1):
    stairs[_] = stairs[_-1] + stairs[_-2] + stairs[_-3]

print(stairs[N])
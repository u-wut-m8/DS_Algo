m, n  = [*map(int, input().split(" "))]
arr1 = [[0]*m]*n
for i in range(n):
    for j in range(m):
        arr1[i][j] = int(input())

p, q  = [*map(int, input().split(" "))]
arr2 = [[0]*p]*q
for i in range(p):
    for j in range(q):
        arr2[i][j] = int(input())
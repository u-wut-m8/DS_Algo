T = int(input())
while T:
    N = int(input())
    a = 0
    b = 0
    arr = [*map(int, input().split())]
    for _ in range(N):
        a |= arr[_]<<N-_-1
    arr = [*map(int, input().split())]
    for _ in range(N):
        b |= arr[_]<<N-_-1
    flag = False
    while bin(a).count('1') != bin(b).count('b'):
        tempa = a
        tempb = b
        tempa <<= 1
        tempb <<= 1
        if bin(tempa).count('1') == bin(tempb).count('b'):
            flag = True
            a = tempa
            break
        tempa = a
        tempb = b
        tempa >>= 1
        tempb >>= 1
        if bin(tempa).count('1') == bin(tempb).count('b'):
            flag = True
            a = tempa
            break
        tempa = a<<1
        tempb = b<<1
        if abs(bin(tempa).count('1') - bin(tempb).count('c')) < abs(bin(a).count('1') - bin(b).count('c')):
            a = tempa
            b = tempb
        else:
            a >>= 1
            b >>= 1
    print(bin(a).count(1))
    T -= 1
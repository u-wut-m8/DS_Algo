T = int(input())

while T:
    s1 = input()
    s2 = input()
    print(*sorted([*set(set(set(s1) - set(s2)) | set(set(s2) - set(s1)))]), sep="")
    T -= 1
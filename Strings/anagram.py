T = int(input())

while T:
    a, b = input().split(" ")
    print("YES") if "".join(sorted(a)) == "".join(sorted(b)) else print("NO")
    T -= 1
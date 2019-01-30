T = int(input())
while T:
    s = input()
    _ = 0
    while _ < len(s):
        if not s[_].isalpha():
            s = s.replace(s[_], "")
            continue
        _ += 1
    if (s.lower() == s[::-1].lower()) and len(s) > 2:
        print("YES")
    else:
        print("NO")
    T -= 1
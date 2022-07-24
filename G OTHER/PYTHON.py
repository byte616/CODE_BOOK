while True:
    s=input()
    if s=='0':
        break
    a,b=map(int,s.split())
    print(b//a,end=' ')
    if b%a:
        print(b%a)
    else:
        print()

x = [int(x) for x in input().split()]
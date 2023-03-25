def gcd(n,m):
    if n%m==0:
        return m
    else:
        return gcd(m,n%m)

n = int(input("n="))
m = int(input("m="))
print("最大公约数是{}".format(gcd(n,m)))

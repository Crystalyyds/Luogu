n = input()
n = int(n)
i=2
print("%d=" %n,end='')
while n>i:
    if n%i==0:
        print("%d*"%i,end='')
        n/=i
    else:
        i+=1
print(i)

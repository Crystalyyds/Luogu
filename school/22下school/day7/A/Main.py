n =input()
n=int(n)
cnt=0
x =1
while x<=n:
    if x!=0 :
        if x%2==0 or x%3==0 or x%5==0 or x%7==0:
            x+=1
        else:
            cnt+=1
            x+=1
print(cnt)

def add():
    f = open("D:/Code/algorithm/FuckPython/Experment/二/test.txt",'a',encoding="utf8")
    a = input("姓名和号码，中间：间隔")
    f.write("{}\n".format(a))
    f.close()
    
def Finduser(user):
    keys=False;
    f = open("D:/Code/algorithm/FuckPython/Experment/二/test.txt",'r',encoding="utf8")
    rs = f.readlines()
    for line in rs :
        y= line.rfind(n)
        if y!=-1:
            print("查找到某人={}".format(line))
            keys = True
            break
    if keys==False:
        print("Not Found")
    f.close
    
def menu():
    print("1添加")
    print("2查询")
    print("0退出")
    
    
if __name__=='__main__':
    menu()
    print("_________________________")
    op =int( input("输入你的选择"))
    while op!=0:
        print("_________________________")
        if(op==1):
            add()
        elif op==2:
            n= input("输入查找的人")
            Finduser(n)
        elif op == 0:
            print("退出")
        else:
            op =int(input("错误输入，重新输入"))
        menu()
        print("_________________________")
        op =int(input("继续输入"))

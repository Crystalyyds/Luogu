def add():
    f = open("D:/Code/algorithm/FuckPython/Experment/��/test.txt",'a',encoding="utf8")
    a = input("�����ͺ��룬�м䣺���")
    f.write("{}\n".format(a))
    f.close()
    
def Finduser(user):
    keys=False;
    f = open("D:/Code/algorithm/FuckPython/Experment/��/test.txt",'r',encoding="utf8")
    rs = f.readlines()
    for line in rs :
        y= line.rfind(n)
        if y!=-1:
            print("���ҵ�ĳ��={}".format(line))
            keys = True
            break
    if keys==False:
        print("Not Found")
    f.close
    
def menu():
    print("1���")
    print("2��ѯ")
    print("0�˳�")
    
    
if __name__=='__main__':
    menu()
    print("_________________________")
    op =int( input("�������ѡ��"))
    while op!=0:
        print("_________________________")
        if(op==1):
            add()
        elif op==2:
            n= input("������ҵ���")
            Finduser(n)
        elif op == 0:
            print("�˳�")
        else:
            op =int(input("�������룬��������"))
        menu()
        print("_________________________")
        op =int(input("��������"))

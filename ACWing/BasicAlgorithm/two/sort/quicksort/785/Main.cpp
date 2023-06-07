#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
const int T = 1000;
struct Student
{
  int id;
  string name;
  int math, english, physics;
  double average;
  bool k;
  int n;
} arr[T], brr[T], crr[T];
int idx;

bool fun(Student x, Student y)
{
  return x.math > y.math;
}
bool fun1(Student x, Student y)
{
  return x.english > y.english;
}
bool fun2(Student x, Student y)
{
  return x.physics > y.physics;
}
bool fun3(Student x, Student y)
{
  return x.average > y.average;
}

void fun4(Student brr[], int l, int r)
{
  if (l >= r)
    return;
  int i = l;
  int j = r;
  Student mid = brr[(l + r) / 2];
  while (i <= j)
  {
    while (brr[i].average > mid.average)
      i++;
    while (brr[j].average < mid.average)
      j--;
    if (i <= j)
    {
      swap(brr[i], brr[j]);
      i++;
      j--;
    }
  }
  fun4(brr, l, j);
  fun4(brr, i, r);
}

void menu()
{
  printf("===========================\n");
  printf("|      1.插入              |\n");
  printf("|      2.删除              |\n");
  printf("|      3.修改              |\n");
  printf("|      4.高数排序          |\n");
  printf("|      5.英语排序          |\n");
  printf("|      6.大物排序          |\n");
  printf("|      7.总排序            |\n");
  printf("|      8.不及格            |\n");
  printf("|      9.保存              |\n");
  printf("|      10.读入             |\n");
  printf("|      11.输出             |\n");
  printf("|      12.清屏             |\n");
  printf("|      0.退出             |\n");
  printf("===========================\n");
}

void add()
{
  printf("输入:\n");
  printf("名字 数学 英语 大物\n");
  int a, b, c;
  string t;
  cin >> t >> a >> b >> c;
  arr[idx].name = t;
  arr[idx].math = a;
  arr[idx].english = b;
  arr[idx].physics = c;
  arr[idx].id = idx + 1;
  arr[idx].average = (a + b + c) / 3.0;
  idx++;
}

void UPdata(int x)
{
  printf("输入:\n");
  printf("名字 数学 英语 大物\n");
  int a, b, c;
  string t;
  cin >> t >> a >> b >> c;
  arr[x - 1].name = t, arr[x - 1].math = a, arr[x - 1].english = b, arr[x - 1].physics = c;
  arr[x - 1].average = (a + b + c) / 3.0;
}

void show()
{
  printf("ID   名字   数学   英语   大物    平均值\n");
  for (int i = 0; i < idx; i++)
  {
    if (!brr[i].k)
      cout << brr[i].id << "    " << brr[i].name << "   " << brr[i].math << "      " << brr[i].english << "     " << brr[i].physics << "        " << brr[i].average << endl;
  }
}

void show1()
{
  printf("ID   排名  名字   数学   英语   大物    平均值\n");
  int y = 1;
  for (int i = 0; i < idx; i++)
  {
    if (!brr[i].k)
    {
      if (i && brr[i].average == brr[i - 1].average)
      {
        brr[i].n = brr[i - 1].n;
      }
      else
      {
        brr[i].n = y;
      }
      y++;
      cout << brr[i].id << "     " << brr[i].n << "    " << brr[i].name << "   " << brr[i].math << "      " << brr[i].english << "     " << brr[i].physics << "        " << brr[i].average << endl;
    }
  }
}

void show2()
{
  printf("不及格\n");
  int m = 0, e = 0, p = 0;
  list<string> lm, le, lp;
  set<string> s;
  for (int i = 0; i < idx; i++)
  {
    if (!brr[i].k)
    {
      if (arr[i].math < 60)
      {
        m++;
        lm.push_back(brr[i].name);
        s.insert(brr[i].name);
      }
      if (arr[i].english < 60)
      {
        e++;
        le.push_back(brr[i].name);
        s.insert(brr[i].name);
      }
      if (arr[i].physics < 60)
      {
        p++;
        lp.push_back(brr[i].name);
        s.insert(brr[i].name);
      }
    }
  }
  printf("一共有%d个人有不及格科目\n", s.size());
  printf("数学不及格->");
  for (auto t : lm)
    cout << t << " ";
  cout << endl;
  printf("英语不及格->");
  for (auto t : le)
    cout << t << " ";
  cout << endl;
  printf("大物不及格->");
  for (auto t : lp)
    cout << t << " ";
  cout << endl;
  printf("总不及格->");
  for (auto t : s)
    cout << t << " ";
  cout << endl;
}

void SaVe()
{
  string fname = "hello.txt";
  fstream f, q;
  q.open(fname, ios::in);
  f.open(fname, ios::out | ios::app);
  string username, head1, head2, head3, head4, head5, head6, head7;
  q >> head1 >> head2 >> head3 >> head4 >> head5 >> head6 >> head7;
  if (head1 != "ID")
    f << "ID 排名 名字 数学 英语 大物 平均值" << endl;
  int y = 1;
  for (int i = 0; i < idx; i++)
  {
    if (!brr[i].k)
    {
      if (i && brr[i].average == brr[i - 1].average)
      {
        brr[i].n = brr[i - 1].n;
      }
      else
      {
        brr[i].n = y;
      }
      y++;
      f << brr[i].id << " " << brr[i].n << " " << brr[i].name << " " << brr[i].math << " " << brr[i].english << " " << brr[i].physics << " " << brr[i].average << endl;
    }
  }
  f.close();
}

void ReaD()
{
  string fname = "hello.txt";
  fstream f;
  f.open(fname, ios::in);
  int i = 0;
  string username, head1, head2, head3, head4, head5, head6, head7;
  int a, b, c, id, num, average;
  f >> head1 >> head2 >> head3 >> head4 >> head5 >> head6 >> head7;
  // cout << head1 << " " << head2 << " " << head3 << " " << head4 << " " << head5 << " " << head6 << " " << head7 << endl;
  while (f >> id >> num >> username >> a >> b >> c >> average >> head1)
  {
    crr[i].name = username, crr[i].math = a, crr[i].english = b, crr[i].physics = c, crr[i].average = average, crr[i].id = i + 1;
    i++;
  }
  memcpy(arr, crr, sizeof crr);
  idx = i;
  // cout << idx << endl;
}

int main()
{
  int op = 0;
  int oo;
  int num = 0;
  do
  {
    // system("cls");
    memcpy(brr, arr, sizeof arr);
    menu();
    printf("输入选择->");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      add();
      // show();
      break;
    case 2:
      show();
      printf("输入删除学生ID->");
      scanf("%d", &oo);
      arr[oo - 1].k = true;
      break;
    case 3:
      show();
      printf("输入删除学生ID->");
      scanf("%d", &oo);
      UPdata(oo);
      break;
    case 4:
      printf("数学排名\n");
      sort(brr, brr + idx, fun);
      show();
      break;
    case 5:
      printf("英语排名\n");
      sort(brr, brr + idx, fun1);
      show();
      break;
    case 6:
      printf("大物排名\n");
      sort(brr, brr + idx, fun2);
      show();
      break;
    case 7:
      printf("总排序\n");
      //            sort(brr, brr + idx, fun3);
      fun4(brr, 0, idx);
      show1();
      break;
    case 8:
      show2();
      break;
    case 9:
      SaVe();
      break;
    case 10:
      ReaD();
      break;
    case 11:
      show();
      break;
    case 12:
      printf("清屏\n");
      system("cls");
      break;
    case 0:
      printf("退出");
      break;
    default:
      printf("错误输入，重新选择\n");
      break;
    }
  } while (op != 0);
  return 0;
}

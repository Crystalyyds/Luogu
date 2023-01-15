    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll n, cnt;
    ll a, b, c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bcd, abcd;
    int main()
    {
        cin >> n;
        a = n / 2;
        b = n / 3;
        c = n / 5;
        d = n / 7;

        ab = n / 6;
        ac = n / 10;
        ad = n / 14;
        bc = n / 15;
        bd = n / 21;
        cd = n / 35;

        abc = n / 30;
        abd = n / 42;
        bcd = n / 105;
        acd = n / 70;

        abcd = n / 210;
        cnt = n - (a + b + c + d - ab - ac - ad - bc - bd - cd + abc + abd + bcd + acd - abcd);
        cout << cnt;
        return 0;
    }
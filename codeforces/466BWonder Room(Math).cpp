#include<bits/stdc++.h>
using namespace std;
long long a, b;

long long n;
// ����Ĺؼ�������һ��Trick
// ʵ���ϱ�����BRUTE FORCE
// ����assume a <= b ������� newa <= newb (��������Լ�����һ��)
// ��ôֻ��Ҫ����newa <= sqrt(6*n)�������, ���Ҽ���newb
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    if (6 * n <= a * b)
        cout << a * b << "\n" << a << " " << b << "\n";
    else {
        bool flag = 0; // ��ʾ������ 
        if (a > b)
        {
            swap(a, b);
            flag = 1;
        }
        
        long long SQ = 1e18, a1, b1, tmpb;
        for(long long i = a; i*i <= 6*n; ++i) {
            tmpb = 6*n / i;
            if (tmpb * i < 6*n) tmpb++;
            
            if (tmpb < b) continue;
            
            if (tmpb * i < SQ) {
                SQ = tmpb * i;
                a1 = i;
                b1 = tmpb;
            }
        }
        
        if (flag)
            swap(a1, b1);
        
        cout << SQ << "\n" << a1 << " " << b1 << "\n";
    }
 
    return 0;
}

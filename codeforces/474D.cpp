#include<bits/stdc++.h>
using namespace std;
// �����ɫ�Ļ�
// ��ôǰ��k�������Ǻ�ɫ
// ���Ƿǳ�������;
// ��ɫ�Ļ��Ͳ��ù�ǰ����;
const int N = 100000 + 5;
int f[N][2]; // 0 represents red, 1 represents white
int mod = 1e9 + 7;
int t, k; 
int sum[N];
int main() {
	scanf("%d%d", &t, &k);
	int a, b;
	// һ��������״̬;
	// int f[100000][2];
	f[0][0] = 1;
	for (int i = 1; i <= 100000; i++) {
		f[i][0] = f[i - 1][0] + f[i - 1][1];
		f[i][0] %= mod;
		if (i < k) {
			f[i][1] = 0;
			continue;
		}
	 	f[i][1] = f[i - k][0] + f[i - k][1];  
	 	f[i][1] %= mod;
	} 
	for (int i = 1; i <= 100000; i++) {
		sum[i] = sum[i - 1] + f[i][0];
		sum[i] %= mod;
		sum[i] += f[i][1];
		sum[i] %= mod;
	}
	while (t--) {
		scanf("%d%d", &a, &b);
		int ans = sum[b] - sum[a - 1];
		if (ans < 0) {
			ans += mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}

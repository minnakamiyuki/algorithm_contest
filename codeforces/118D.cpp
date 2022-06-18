#include <bits/stdc++.h>
using namespace std;
// 118D Caesar's Legions
const int mod = 1e8;
int f[105][105][2]; // 0 ��ʾ ��һ���� footman, 1 ��ʾ��һ����horseman 
// �ؼ�����dp��Ҫ̫��������ά��
// ��������һ����ά��dp;
// ������(n1 + n2) ^ 2 ��ʱ�临�Ӷ�
// ����f[n1][n2]����ά��
// Ȼ����ǰ���һ����horseman ���� footman�����
// ��������ά
// Ȼ����Ҫ�úÿ���״̬ת��
// ����ͨ������ǰ��ŵ�ɸ���һ�����͵����(�ؼ���ת��Ϊ�������������)  
// ���������г�����״̬ת�Ʒ�����ʽ;
// f[n1][n2][0] = f[n1 - 1][n2][1] + f[n1 -2][n2][1]+ ...... + f[n1 - min(n1, k1)][n2][1];
// f[n1][n2][1] = f[n1][n2 - 1][0] + ...... f[n1][n2 - min(n2, k2)][0] 
int n1, n2, k1, k2;
int main() {
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	// ������������� 
	for (int i = 1; i <= k1; i++) {
		f[i][0][0] = 1;
	}
	for (int i = 1; i <= k2; i++) {
		f[0][i][1] = 1;
	}
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			for (int k = 1; k <= min(i, k1); k++) {
				f[i][j][0] += f[i - k][j][1];
				f[i][j][0] %= mod;
			}
			for (int k = 1; k <= min(j, k2); k++) {
				f[i][j][1] += f[i][j - k][0];
				f[i][j][1] %= mod;
			}
		}
	}
	int ans = (f[n1][n2][0] + f[n1][n2][1]) % mod;
	printf("%d", ans);
	return 0;
}

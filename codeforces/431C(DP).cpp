#include<bits/stdc++.h>
using namespace std;

// ��������һ���������
// Ȼ�������Ե�������
int n, k, d; 
// �������dfs�Ļ�,ÿ�μ�һ������Ῠ�ڴ�;
// ���Բ���
// ע������˼��һ��;
// ���ʹ��dp�Ż�
// �ؼ�����dp��״̬���
// f[i][j] ���Ա�ʾ�ܺ�Ϊi, ������Ϊj�ķ�����
// ���i <= j
// f[i][j] = 0;
int mod = 1e9 + 7;
int f[105][105];
// ���ǵ���д״̬ת�Ʒ���;
// f[i][j] = f[i - 1][j] + f[i - 2][j] ..... f[i - j + 1][j]
// f[i - j][1] + ...... f[i - k][1];
// ��Ϊd��һ�������G; 
int main() {
	// ����е�˼·;
	scanf("%d%d%d", &n, &k, &d);
	f[1][1] = 1;
	f[0][1] = 1;
	f[0][d] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j > i) break;
			f[i][1] += f[i - j][1]; 
			f[i][1] %= mod; 
		}
	}
	if (d != 1) {
	for (int i = 1; i < d; i++)
		f[i][d] = 0;
	for (int i = d ; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j > i)
				continue;
			if (j < d) {
				f[i][d] += f[i - j][d];
				f[i][d] %= mod;
			} else {
				f[i][d] += f[i - j][1];
				f[i][d] %= mod;
			}
		}
	}
}
	// ע��𰸵�����,���ҵ�������ʵ������һ��
	// ���趨��״̬����f[i][is] if is == 1,����ͳ�Ƶ���·����>= d�ı�, �������û�� 
	printf("%d", f[n][d]);
	return 0;
}

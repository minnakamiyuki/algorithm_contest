#include<bits/stdc++.h>
using namespace std;
int n;
const int MAX = 500000 + 10;
int a[MAX];
long long sum[MAX];
long long tot = 0;
vector<int> ind; // indices of the tot/3;
// ��ô��Ӧ�ÿ���
int ma = 0; 
int mid(int j) {
	// ��ʾ����< j������;
	int l = 0, r = ma - 1;
	int ans = -1; // ans�ĸ�ֵ��-1ȷ����ȫû�о��������������� 
	// <= j������index 
	// <= ��ȡ��������Ŀ���Ƿ�ֹ������ֱ�������ж�;
	 
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ind[mid] < j) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	} 
	return ans + 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];	
	}
	tot = sum[n];
	if (tot%3 != 0) {
		printf("0");
		return 0;
	}	
	for (int i = 1; i <= n; i++) {
		if (sum[i] == tot / 3) {
			ind.push_back(i);
		}
	}
	ma = ind.size();
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		if (sum[i] == tot / 3 * 2) {
			ans += mid(i);
		}
	}
	printf("%lld", ans);
	return 0;
}


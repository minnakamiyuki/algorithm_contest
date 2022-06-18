#include<bits/stdc++.h>
using namespace std;
int t;

// ����Ĺؼ�����һ��trick
// ע��[l, r] = r - l + 1��һ��trick
// ���ǽ����ǰ������(half-closed interval) 
// ������Pi = [0, i)
// ��ô[l, r] = r - l + 1 == Pr - Pl = r - l 
// ===> Pr - r = Pl - r
// Ȼ��ͳ�ƾͺ���  
int sum[100000 + 5];
 
int main() {
	scanf("%d", &t);
	while(t--) {
		int n;
		string nums;
		cin >> n >> nums;
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + nums[i - 1] - '0';
		}
		// �����������ͳ����
		unordered_map<int, int> ma;
		for (int i = 0; i <= n; i++) {
			int val = sum[i] - i;
			ma[val]++;
		} 
		long long ans = 0;
		// unordered_map��һ�ֱ�����ʽ 
		for (auto& v : ma) {
			long long val = v.second;
			ans += (val) * (val - 1) / 2; 
 		}
 		printf("%lld\n", ans); // ע������������������, �Լ����%lld 
	}
	return 0;
}

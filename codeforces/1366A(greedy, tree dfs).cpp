#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAX = 200000 + 5;
vector<int> ee[MAX];
int depth[MAX], siz[MAX];

// Ϊʲô�������ǶԵ�
// �ú���һ��
// ��ô�����Ѿ�����
//	industry -> tourism  
//  n - k 
//  ���ڵ�
//  how to think about this 

void dfs(int u, int fa) {
	depth[u] = depth[fa] + 1;
	siz[u] = 1;
	for (int i = 0; i < ee[u].size(); i++) {
		int v = ee[u][i];
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}
int arr[MAX];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		// u == from , v == to remember;
		ee[u].push_back(v);
		ee[v].push_back(u); 
	}
	// ����һ�����
	// ��ΪҪѡ��n - k ��Ϊ
	// ע��˴�����1 
	dfs(1, 0); 
	for (int i = 1; i <= n; i++) {
		arr[i] = siz[i] - depth[i]; 
	}
	// ע��һ��sort�������÷� 
	// sort������ҿ��ĵ�ַ 
	// �Լ������˼������, ���Կ���Ϊһ��ʼȫ�ǹ�ҵ��Ȼ��ѡ��n - k ��չtourism, ���������Ǹ�̰�Ŀ������ѡ��
	// �Ż�Ƚ����� 
	sort(arr + 1, arr + 1 + n, greater<int>());
	long long ans = 0;
	for (int i = 1; i <= n - k; i++) {
		ans += arr[i];
	}
	printf("%lld", ans);
	return 0;
}

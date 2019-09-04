#include <bits/stdc++.h>
using namespace std;

const int maxn = 20000;

vector<int> G[maxn];

bool vis[maxn];

int cont = 0;

void dfs(int x)
{
	vis[x] = true;
	cont++;

	for(auto u : G[x]) if(!vis[u]) dfs(u);
}


int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a, b;

		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1);

	if(cont == n) cout << "OK!\n";
	else cout << "NOT CONNECTED!!\n";
}
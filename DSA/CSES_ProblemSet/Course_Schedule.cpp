#include "bits/stdc++.h"
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> //find_by_order(), order_of_key()
#define pb push_back
#define mp make_pair
#define vi vector<long long int >
#define vb vector<bool>
#define vs vector<string>
#define vd vector<double>
#define vvi vector<vector<long long int> >
#define vp vector<pair<long long int , long long int > >
#define seti set<long long int >
#define setc set<char>
#define setd set<double>
#define mod 1000000009
#define endl '\n'
typedef long long int lli;
 

 
void solve()
{
	lli n, m, i, j, c = 0, s = 0;
	cin >> n >> m;
	vi adj[n + 1];
	vi deg(n + 1, 0);
	priority_queue <lli, vector <lli> , greater <lli> > pq;
	for (i = 0; i < m; i++)
	{
		lli u, v;
		cin >> u >> v;
		adj[u].pb(v);
		++deg[v];
	}
	for (i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			pq.push(i);
		}
	}
	vi ans;
	while (!pq.empty())
	{
		lli u = pq.top();
		ans.pb(u);
		pq.pop();
		for (auto it : adj[u])
		{
			--deg[it];
			if (deg[it] == 0)
			{
				pq.push(it);
			}
		}
	}
	if (ans.size() != n)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		for (auto it : ans)
		{
			cout << it << " ";
		}
		cout << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli t = 1;
	//cin>>t;
	while (t--)
		solve();
	return 0;
}

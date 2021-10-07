#include "bits/stdc++.h"
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> //find_by_order(), order_of_key()
#define pb  push_back
#define pf push_front
#define pii pair<long long int, long long int>
#define vi vector<long long int>
#define vii vector<pii>
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
	lli n, m, i, j, c = 0, s = 0, f = 0;
	cin >> n >> m;
	vi adj[n + 1];
	for (i = 0; i < m; i++)
	{
		lli x, y;
		cin >> x >> y;
 
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vi vis(n + 1, 0), dist(n + 1);
	lli par[n + 1];
	par[1] = 0;
	queue <lli> q;
	q.push(1);
	dist[1] = 1;
	vis[1] = 1;
	while (!q.empty())
	{
		lli node = q.front();
		q.pop();
		for (lli child : adj[node])
		{
			if (vis[child] == 0)
			{
				q.push(child);
				dist[child] = dist[node] + 1;
				par[child] = node;
				vis[child] = 1;
			}
		}
	}
	if (dist[n] == 0)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << dist[n] << endl;
		lli cc = n;
		vi ans;
		while (cc != 0)
		{
			ans.pb(cc);
			cc = par[cc];
		}
		reverse(ans.begin(), ans.end());
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

/*
*
*	AUTHOR :- @soham01
*
*/
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
typedef unsigned long long int lli;
 

 
void solve()
{
	lli n, m, i, j, a, b, w, src, c = 0, s = 0, f = 0, x = 0;
	cin >> n >> m;
	vector <pair <lli, lli> > adj[n];
	vi dist(n, 10000000000000009);
	priority_queue<pair <lli, lli> , vector <pair <lli, lli> > , greater <pair <lli, lli> > > pq;
	for (i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		a--;
		b--;
		adj[a].pb({b, w});
		//adj[b].pb({a, w});
	}
	/*cin >> src;
	src--;
	dist[src] = 0;*/
	dist[0] = 0;
 
	pq.push(make_pair(0LL, 0LL));
	while (!pq.empty())
	{
		lli node = pq.top().first;
		lli node_d = pq.top().second;
		pq.pop();
		if (node_d > dist[node]) continue;
		for (auto edge : adj[node])
		{
			lli u = edge.first;
			lli w = edge.second;
			if (node_d + w < dist[u])
			{
				dist[u] = node_d + w;
				pq.push({u, dist[u]});
			}
		}
	}
	
	for (auto it : dist)
	{
		cout << it << " ";
	}
	cout << endl;
 
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*lli t;
	cin >> t;
	while (t--)*/
	solve();
	return 0;
}

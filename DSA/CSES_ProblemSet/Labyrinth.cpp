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
#define vvi vector<vector<long long int> >
#define vp vector<pair<long long int , long long int > >
#define seti set<long long int >
#define setc set<char>
#define setd set<double>
#define mod 1000000009
#define endl '\n'
typedef long long int lli;
 

string ds = "RLDU";
void solve()
{
	lli n, m, i, j, c = 0, f = 0, x = 0;
	cin >> n >> m;
	string s[n];
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	lli sr = 0, sc = 0, er = 0, ec = 0;
	lli vis[n][m], dist[n][m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			vis[i][j] = 0;
			dist[i][j] = 0;
			if (s[i][j] == 'A')
			{
				sr = i;
				sc = j;
			}
			if (s[i][j] == 'B')
			{
				er = i;
				ec = j;
			}
		}
	}
	queue <pair <lli, lli> > q;
	q.push({sr, sc});
	vis[sr][sc] = 1;
	lli dr[4] = {0, 0, 1, -1};
	lli dc[4] = {1, -1, 0, 0};
	vii from[n + 1][m + 1];
	from[sr][sc].pb({0, 0});
	char ch[n + 1][m + 1];
	while (!q.empty())
	{
		lli r = q.front().first;
		lli c = q.front().second;
		q.pop();
 
		for (i = 0; i < 4; i++)
		{
			lli adjr = r + dr[i];
			lli adjc = c + dc[i];
			if (adjr < 0 || adjr >= n || adjc < 0 || adjc >= m ) continue;
			if (vis[adjr][adjc] == 1) continue;
			if (s[adjr][adjc] == '#') continue;
 
			q.push({adjr, adjc});
			dist[adjr][adjc] = dist[r][c] + 1;
			vis[adjr][adjc] = 1;
			pair <lli, lli> p1 = {adjr, adjc};
			pair <lli, lli> p2 = {r, c};
			from[adjr][adjc].pb(p2);
			ch[adjr][adjc] = ds[i];
			//parent[p1] = p2;
 
		}
	}
 
	if (dist[er][ec] == 0)
	{
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << dist[er][ec] << endl;
		string ss;
		lli px = 0, py = 0;
		px = er;
		py = ec;
		pair <lli, lli> pp = {er, ec};
		pair <lli, lli> sol = {sr, sc};
		while (pp != sol)
		{
			ss += ch[pp.first][pp.second];
			pp = from[pp.first][pp.second][0];
		}
		reverse(ss.begin(), ss.end());
		cout << ss << endl;
 
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
 

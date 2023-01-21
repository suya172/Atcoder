#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500 + 10, inf = 0x3f3f3f3f;
int a[N], b[N], dis[510][510], w[N];
int ans[N][N];
vector<int> g[N];
signed main()
{
    int n;
    cin >> n;
    memset(dis, 0x3f, sizeof dis);
    memset(ans, -0x3f, sizeof ans);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        ans[i][i] = w[i];
        dis[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == 'Y')
                g[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        q.push(i);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int j = 0; j < g[x].size(); j++)
            {
                int k = g[x][j];
                if (dis[i][k] > dis[i][x] + 1)
                    dis[i][k] = dis[i][x] + 1, q.push(k);
                if (dis[i][k] == dis[i][x] + 1)
                    ans[i][k] = max(ans[i][k], ans[i][x] + w[k]);
            }
        }
        // for (int j = 1; j <= n; j++)
        //     cout << dis[i][j] << " ";
        // cout << endl;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        if (dis[s][t] >= inf / 2)
            cout << "Impossible" << endl;
        else
            cout << dis[s][t] << " " << ans[s][t] << endl;
    }
}
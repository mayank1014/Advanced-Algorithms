#include <bits/stdc++.h>

using namespace std;

void find_min_cut(int n, int g[4][4])
{
    int g1[n][n];
    //	int a= (100*n)*(n-1);
    //	while(a>0){
    while (n > 2)
    {
        // srand(time(0));
        int u, v;
        cout << "Enter u";
        cin >> u;
        cout << "Enter v";
        cin >> v;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                cnt = 0;

                if (i == u && j == v)
                {
                    g1[i][j] = 0;
                    g1[j][i] = 0;
                }

                else if (i == u || i == v)
                {
                    if (g[u][j] > 0)
                    {
                        cnt += g[u][j];
                    }

                    if (g[v][j] > 0)
                    {
                        cnt += g[v][j];
                    }

                    if (u < j)
                    {
                        g1[u][j] = cnt;
                    }
                    else
                    {
                        g1[j][u] = cnt;
                    }
                    if (v < j)
                    {
                        g1[v][j] = cnt;
                    }
                    else
                    {
                        g1[j][v] = cnt;
                    }
                }

                else if (j == u || j == v)
                {
                    if (g[u][i] > 0)
                        cnt += g[u][i];

                    if (g[v][i] > 0)
                        cnt += g[v][i];

                    if (u < i)
                    {
                        g1[u][i] = cnt;
                    }
                    else
                    {
                        g1[i][u] = cnt;
                    }
                    if (v < i)
                    {
                        g1[v][i] = cnt;
                    }
                    else
                    {
                        g1[i][v] = cnt;
                    }
                }

                else
                {
                    g1[i][j] = g[i][j];
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         //cout << g1[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= j)
                    g1[i][j] = g1[j][i];
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         //cout << g1[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int g2[n - 1][n - 1];
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == v)
                continue;
            b = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == v)
                    continue;
                else
                // if(i!=v and j!=v)
                {
                    g2[a][b] = g1[i][j];
                    b++;
                }
            }
            a++;
        }
        // for (int i = 0; i < (n - 1); i++)
        // {
        //     for (int j = 0; j < (n - 1); j++)
        //     {
        //         //cout << g2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < (n - 1); i++)
        {
            for (int j = 0; j < (n - 1); j++)
            {
                g[i][j] = g2[i][j];
            }
        }

        n = n - 1;
        // a--;
    }
    //	}
    int cut_value = g[0][1];
    cout << "Min cut is : " << cut_value;
}

int main()
{
    int arr[4][4] = {0, 1, 1, 1,
                     1, 0, 1, 0,
                     1, 1, 0, 1,
                     1, 0, 1, 0};

    find_min_cut(4, arr);

    return 0;
}

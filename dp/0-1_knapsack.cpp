#include <bits/stdc++.h>
using namespace std;
static int t[1000][1000];
// using recurion
int solve(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= w)
    {
        return max((val[n - 1] + solve(wt, val, w - wt[n - 1], n - 1)), solve(wt, val, w, n - 1));
    }
    else if (wt[n - 1] > w)
    {
        return solve(wt, val, w, n - 1);
    }
}

// using memoization method
int solve(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (t[n][w] != -1)
    {
        return t[n][w];
    }
    if (wt[n - 1] <= w)
    {
        return t[n][w] = max((val[n - 1] + solve(wt, val, w - wt[n - 1], n - 1)), solve(wt, val, w, n - 1));
    }
    else if (wt[n - 1] > w)
    {
        return t[n][w] = solve(wt, val, w, n - 1);
    }
}

// using tabular method/ top-down approach;
int solve(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {

                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][w];
}
int main()
{
    int test;
    cin >> test;
    while (test > 0)
    {
        int n;
        cin >> n;
        int w;
        cin >> w;
        int wt[n], val[n];

        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }

        memset(t, -1, sizeof(t));
        cout << solve(wt, val, w, n) << endl;

        test--;
    }

    return 0;
}
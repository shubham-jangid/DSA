#include <bits/stdc++.h>
using namespace std;

bool solve(int arr[], int n, int sum, vector<vector<bool>> &table)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0 && sum != 0)
    {
        return false;
    }
    if (table[n][sum] != false)
    {
        return table[n][sum];
    }
    if (arr[n - 1] <= sum)
    {
        return table[n][sum] = solve(arr, n - 1, sum - arr[n - 1], table) || solve(arr, n - 1, sum, table);
    }
    else
        return table[n][sum] = solve(arr, n - 1, sum, table);
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            vector<vector<bool>> table(n + 1, vector<bool>(sum / 2, false));

            if (solve(arr, n, sum / 2, table))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        t--;
    }

    return 0;
}
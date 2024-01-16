#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int tab[10001] = { 0 };
    int coin[100] = { 0 };
    int n, k;

    fill(tab, tab + 10001, INT_MAX);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        if (coin[i] <= k)
            tab[coin[i]] = 1;
    }

    for (int i = 0; i <= k; i++)
        for (int j = 0; j < n; j++)
            if (i - coin[j] >= 0)
                if (tab[i - coin[j]] != INT_MAX)
                    tab[i] = min(tab[i], tab[i - coin[j]] + 1);

    int ans = tab[k];
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}
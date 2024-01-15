#include <iostream>
using namespace std;

int grid[15][15] = { 0 };

int main() {
    int N, M, K;
    int ans;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        grid[i][0] = 1;
    for (int j = 0; j < M; j++)
        grid[0][j] = 1;

    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            if (grid[i - 1][j] != 0 && grid[i][j - 1] != 0)
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];

    if (K == 0)
        ans = grid[N - 1][M - 1];
    else {
        int tmpI = (K - 1) / M;
        int tmpJ = (K - 1 + M) % M;
        ans = grid[tmpI][tmpJ] * grid[N - 1 - tmpI][M - 1 - tmpJ];
    }

    cout << ans;

    return 0;
}
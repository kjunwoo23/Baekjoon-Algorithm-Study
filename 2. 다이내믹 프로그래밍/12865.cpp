#include <iostream>
using namespace std;

int items[100][2] = { 0 };
int N, K;

int memo[101][100001] = { 0 };

int chooseBetterPrice(int start, int leftWeight) {
    if (memo[start][leftWeight] != 0)
        return memo[start][leftWeight];
    if (start == N) return 0;

    int choice1 = 0, choice2 = 0;

    //자신을 가방에 넣는 것
    if (leftWeight >= items[start][0])
        choice1 = chooseBetterPrice(start + 1, leftWeight - items[start][0]) + items[start][1];

    //자신을 가방에 넣지 않는 것
    choice2 = chooseBetterPrice(start + 1, leftWeight);


    int ans = max(choice1, choice2);
    if (memo[start][leftWeight] == 0)
        memo[start][leftWeight] = ans;
    return ans;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> items[i][0] >> items[i][1];

    cout << chooseBetterPrice(0, K);

    return 0;
}
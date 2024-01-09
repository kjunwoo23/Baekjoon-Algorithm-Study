#include <iostream>
using namespace std;

int lenS(int k) {
    if (k == 0) return 3;

    return lenS(k - 1) * 2 + k + 3;
}

int getK(int n) {
    int tmp = 1;
    int cnt = 0;
    while (tmp <= n) {
        tmp *= 2;
        cnt++;
    }
    if (cnt < 2) return 0;
    else    return cnt - 2;
}

char searchMoo(int k, int n) {
    if (n == 1) return 'm';
    if (n == 2) return 'o';
    if (n == 3) return 'o';

    int tmpLen = lenS(k - 1);

    if (n <= tmpLen)
        return searchMoo(k - 1, n);
    else if (n > tmpLen + k + 3)
        return searchMoo(k - 1, n - tmpLen - k - 3);
    else if (n == tmpLen + 1)
        return 'm';
    else
        return 'o';
}


int main() {
    int N;
    cin >> N;
    
    int tmpK = getK(N);

    cout << searchMoo(tmpK, N);
    return 0;
}
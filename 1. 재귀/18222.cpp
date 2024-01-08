#include <iostream>
using namespace std;

//num보다는 작은 가장 큰 2 제곱수
long long getMaxSquare(long long num) {
    long long ans = 1;
    while (ans < num)
        ans *= 2;
    return ans / 2;
}

//재귀
long long 투에모스(long long k) {

    if (k == 1) return 0;

    long long half = getMaxSquare(k);
    return 1 - 투에모스(k - half);
}

int main() {
    long long k;

    cin >> k;

    cout << 투에모스(k);

    return 0;
}
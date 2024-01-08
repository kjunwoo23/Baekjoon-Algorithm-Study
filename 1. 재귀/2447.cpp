#include <iostream>
using namespace std;

int N;
char stars[6561][6561] = { 0 };

void fillStar(int block, int startX, int startY) {

    
    for (int i = startX + block; i < startX + 2 * block; i++)
        for (int j = startY + block; j < startY + 2 * block; j++)
            stars[i][j] = ' ';

    if (block == 1) return;

    fillStar(block / 3, startX, startY);
    fillStar(block / 3, startX + block, startY);
    fillStar(block / 3, startX + 2 * block, startY);

    fillStar(block / 3, startX, startY + block);
    fillStar(block / 3, startX + 2 * block, startY + block);

    fillStar(block / 3, startX, startY + 2 * block);
    fillStar(block / 3, startX + block, startY + 2 * block);
    fillStar(block / 3, startX + 2 * block, startY + 2 * block);
}

void printStar() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << stars[i][j];
        cout << endl;
    }
}

int main() {

    cin >> N;
    fill(stars[0], stars[N], '*');

    fillStar(N / 3, 0, 0);

    printStar();

    return 0;
}
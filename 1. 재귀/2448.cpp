#include <iostream>
using namespace std;

int N;
char stars[6144][6144] = { 0 };

void fillStar(int block, int startX, int startY) {
    
    if (block == 1) {
        //  기본 삼각형
        //  ___*__  
        //  __*_*_
        //  _*****
        stars[startY][startX] = ' ';
        stars[startY + block][startX] = ' ';
        stars[startY + 2 * block][startX] = ' ';
        stars[startY + 3 * block][startX + block] = ' ';

        stars[startY][startX + block] = ' ';
        stars[startY][startX + 2 * block] = ' ';
        stars[startY + block][startX + block] = ' ';
        stars[startY + block][startX + 3 * block] = ' ';
        stars[startY][startX + 4 * block] = ' ';
        stars[startY][startX + 5 * block] = ' ';
        stars[startY + block][startX + 5 * block] = ' ';
        return;
    }
    

    //  왼쪽 비우기
    //  ------
    //  -----*
    //  ----**
    //  ---***
    //  --****
    //  -*****
    for (int i = startY; i < startY + 2 * block; i++)
        for (int j = startX; j < startX + 2 * block; j++)
            if (i + j < startX + startY + 2 * block)
                stars[i][j] = ' ';
    

    //  오른쪽 비우기
    //  *-----
    //  **----
    //  ***---
    //  ****--
    //  *****-
    //  ******
    for (int i = startY; i < startY + 2 * block; i++)
        for (int j = startX + 2 * block; j < startX + 4 * block; j++)
            if (i - startY < j - startX - 2 * block)
                stars[i][j] = ' ';


    //삼각형을 위, 왼, 오 세 부분으로 나누어 재귀
    fillStar(block / 2, startX + block, startY);
    fillStar(block / 2, startX, startY + block);
    fillStar(block / 2, startX + 2 * block, startY + block);
}

void printStar() {
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N * 2; j++)
            cout << stars[i][j];
        cout << endl;
    }
}

int main() {

    cin >> N;
    fill(stars[0], stars[N * 2], '*');

    fillStar(N / 2, 0, 0);

    printStar();

    return 0;
}
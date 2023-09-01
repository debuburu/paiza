#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int getScore(int h, int w, int H, int W, int score, int** s) {
    score += s[h][w];

    if (h+1 >= H) {
        // printf("###1path exit. (%d, %d), score=%d###\n", h, w, score);
        return score;
    }

    int score1 = score, score2 = score, score3 = score;
    if (w-1 >= 0) {
        score1 = getScore(h+1, w-1, H, W, score, s);
        // printf("  (%d, %d) -> (%d, %d), score=%d -> score1=%d\n", h, w, h+1, w-1, score, score1);
    }

    score2 = getScore(h+1, w, H, W, score, s);
    // printf("  (%d, %d) -> (%d, %d), score=%d -> score2=%d\n", h, w, h+1, w, score, score2);

    if (w+1 < W) {
        score3 = getScore(h+1, w+1, H, W, score, s);
        // printf("  (%d, %d) -> (%d, %d), score=%d -> score3=%d\n", h, w, h+1, w+1, score, score3);
    }

    // printf("score1=%d, score2=%d, score3=%d ....... ", score1, score2, score3);
    if (score1 > score2 && score1 > score3) {
        // printf("score1=%d\n", score1);
        return score1;
    } else if (score2 > score3) {
        // printf("score2=%d\n", score2);
        return score2;
    } else {
        // printf("score3=%d\n", score3);
        return score3;
    }
}

int main(void){
    int H, W;

    string str;
    cin >> H >> W;

    int s[H][W];
    for (int h = 0; h < H;h++) {
        for (int w = 0; w < W;w++) {
            cin >> s[h][w];
        }
    }

    int** num = (int**)malloc(H * sizeof(int *));
    for (int h = 0; h < H; h++) {
        num[h] = (int*)malloc(h * sizeof(int));
        for (int w = 0; w < W; w++) {
            num[h][w] = s[h][w];
        }
    }

    int SCORE = 0;

    for (int w = 0; w < W;w++) {
        // printf("start\n");
        int current = 0;
        current = getScore(0, w, H, W, current, num);

        //printf("w=%d, current=%d, SCORE=%d\n", w, current, SCORE);

        if (current > SCORE) {
            SCORE = current;
        }
    }

    free(num);

    cout << SCORE << endl;;

    return 0;
}
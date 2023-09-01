#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int checkPath(int N, int i, int j, int direction_i, int direction_j, int** s) {
    if (i + direction_i < 0 || i + direction_i >= N || j + direction_j < 0 || j + direction_j >= N) {
        //printf("__no check end. check (%d, %d) direction (%d, %d)\n", i, j, direction_i, direction_j);
        return 0;
    }

    int first_num = s[i][j];
    int current_i = i + direction_i, current_j = j + direction_j;

    int point_direction = first_num - s[current_i][current_j];
    if (point_direction != 1 && point_direction != -1) {
        //printf("__point diff is %d. no check end\n", point_direction);
    }

    int score = 2;
    while (current_i + direction_i < N && current_i + direction_i >= 0 && current_j + direction_j < N && current_j + direction_j >= 0) {
        //printf("\tcheck (%d, %d)->(%d, %d) diff=%d-%d=%d\n", current_i, current_j, current_i+direction_i, current_j+direction_j, s[current_i][current_j], s[current_i+direction_i][current_j+direction_j], point_direction);
        if (s[current_i][current_j] - s[current_i+direction_i][current_j+direction_j] == point_direction) {
            score++;
            current_i += direction_i;
            current_j += direction_j;
        } else {
            break;
        }
    }
    //printf("score=%d. check (%d, %d) direction (%d, %d)\n", score, i, j, direction_i, direction_j);
    return score;
}

int main(void){
    int N;

    cin >> N;

    string strs[N];
    int s[N][N];
    for (int i = 0; i < N;i++) {
        cin >> strs[i];

        for (int j = 0; j < N;j++) {
            s[i][j] = strs[i].at(j) - '0';
        }
    }

    int** num = (int**)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        num[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            num[i][j] = s[i][j];
        }
    }

    int max = 1;
    int ret = 0;
    for (int i = 0; i < N;i++) {
        for (int j = 0; j < N;j++) {
            // 右
            ret = checkPath(N, i, j, 1, 0, num);
            if (ret > max) max = ret;

            // 右下
            ret = checkPath(N, i, j, 1, 1, num);
            if (ret > max) max = ret;

            // 下
            ret = checkPath(N, i, j, 0, 1, num);
            if (ret > max) max = ret;

            // 左下
            ret = checkPath(N, i, j, -1, 1, num);
            if (ret > max) max = ret;
        }
    }

    cout << max << endl;;
    for (int i = 0; i < N; i++) {
        free(num[i]);
    }
    free(num);

    return 0;
}
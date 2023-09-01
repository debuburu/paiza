#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct {
    int n;
    int m;
} STATION;

int main(void){
    int N, M;

    string str;
    cin >> N >> M;

    int A[N][M];
    for (int n = 0; n < N;n++) {
        for (int m = 0; m < M;m++) {
            cin >> A[n][m];
        }
    }

    int X;
    cin >> X;

    STATION s[X];
    for (int x = 0; x < X;x++) {
        cin >> s[x].n >> s[x].m;
    }

    int TOTAL = 0;
    STATION current;
    current.n = 1;
    current.m = 1;

    for (int x = 0; x < X;x++) {
        // 別路線は0円で移動
        current.n = s[x].n;

        // 現在地の値段 A[current.n-1][current.m-1]
        // 目的地の値段 A[s[x].n-1][s[x].m-1]
        TOTAL += abs(A[current.n-1][current.m-1] - A[s[x].n-1][s[x].m-1]);
        //printf("current=(%d, %d), next=(%d, %d), total=%d\n", current.n, current.m, s[x].n, s[x].m, TOTAL);
        current.n = s[x].n;
        current.m = s[x].m;
    }

    cout << TOTAL << endl;;

    return 0;
}
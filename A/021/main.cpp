#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int INVALID_ISLAND_ID = -1;
typedef struct {
    int island_id;
} MAP_INFO;

typedef struct _ISLAND_INFO{
    int area;
    int length;

    bool operator<( const _ISLAND_INFO& right ) const {
        return area == right.area ? length < right.length : area < right.area;
    }
} ISLAND_INFO;

int main(void){
    int H, W;

    string str;
    cin >> H >> W;

    string s[H];
    for (int h = 0; h < H;h++) {
        cin >> s[h];
    }

    // 島を見つける
    MAP_INFO map[H+2][W+2];
    int current_island_id = 1;
    for (int h = 0; h < H+2; h++) {
        for (int w = 0; w < W+2; w++) {
            // 外周
            if (h == 0 || w == 0 || h == H+1 || w == W+1) {
                map[h][w].island_id = INVALID_ISLAND_ID;
                continue;
            }

            // 陸
            if (s[h-1][w-1] == '#') {
                // 陸が見つかったら、その上と左をチェックする。右と下はこれから探索するのでチェックしなくていい
                if (map[h-1][w].island_id != INVALID_ISLAND_ID || map[h][w-1].island_id != INVALID_ISLAND_ID) { // 既存の島とつながる
                    if (map[h-1][w].island_id != map[h][w-1].island_id && map[h-1][w].island_id != INVALID_ISLAND_ID 
                        && map[h][w-1].island_id != INVALID_ISLAND_ID) { // 上と左の島のIDが異なる場合、上の島で上書きする
                        int disable_id = map[h][w-1].island_id;
                        map[h][w].island_id = map[h-1][w].island_id;
                        // printf("connect island to %d, (%d, %d), but left=%d, up=%d\n", map[h][w].island_id, h, w, map[h][w-1].island_id, map[h-1][w].island_id);

                        // これまでの島上書き
                        int end_flag = 0;
                        for (int i = 0; i < H+2; i++) {
                            for (int j = 0; j < W+2; j++) {
                                if (i == h && j == w) {
                                    end_flag = 1;
                                    // printf("\tisland overwrite end. (%d, %d)\n", i, j);
                                    break;
                                }
                                // printf("\toverride check. map[%d][%d]=%d, disable=%d\n", i, j, map[i][j].island_id, disable_id);
                                if (map[i][j].island_id == disable_id) {
                                    map[i][j].island_id = map[h][w].island_id;
                                }
                            }
                            if (end_flag) break;
                        }
                    } else { // 上と左の島が同じ
                        if (map[h-1][w].island_id != INVALID_ISLAND_ID)
                            map[h][w].island_id = map[h-1][w].island_id;
                        else 
                            map[h][w].island_id = map[h][w-1].island_id;

                        // printf("connect island to %d, (%d, %d)\n", map[h][w].island_id, h, w);
                    }
                } else { // 新しい島
                    // printf("new island %d, (%d, %d)\n", current_island_id, h, w);
                    map[h][w].island_id = current_island_id;
                    current_island_id++;
                }
            } else { // 陸じゃない
                // printf("\tnot island (%d, %d)\n", h, w);
                map[h][w].island_id = INVALID_ISLAND_ID;
            }
        }
    }

    // 島の面積と海岸線の長さチェック
    vector<ISLAND_INFO> island_info;;
    island_info.reserve(current_island_id-1);
    for(int i = 0; i < current_island_id-1; i++) {
        ISLAND_INFO a;
        a.area = 0;
        a.length = 0;
        island_info.push_back(a);
    }

    for (int h = 1; h < H+1; h++) {
        for (int w = 1; w < W+1; w++) {
            int temp_id = map[h][w].island_id;
            if (temp_id != INVALID_ISLAND_ID) {
                // 面積
                island_info[temp_id-1].area++;

                // 海岸線の長さ
                if (map[h-1][w].island_id == INVALID_ISLAND_ID) island_info[temp_id-1].length++;
                if (map[h][w-1].island_id == INVALID_ISLAND_ID) island_info[temp_id-1].length++;
                if (map[h+1][w].island_id == INVALID_ISLAND_ID) island_info[temp_id-1].length++;
                if (map[h][w+1].island_id == INVALID_ISLAND_ID) island_info[temp_id-1].length++;

            }

            // printf("%2d", map[h][w].island_id);
        }
        // printf("\n");
    }

    sort(island_info.rbegin(), island_info.rend());
    
    for (const ISLAND_INFO& i : island_info) {
        if (i.area == 0) continue;
        cout << i.area << " " << i.length << endl;
    }

    return 0;
}
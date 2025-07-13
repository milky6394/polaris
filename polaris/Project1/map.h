#include "DxLib.h"
#include "func.h"


int Mappixelx(int x) {
    return x * 100;
}
int Mappixely(int y) {
    return y * 100;
}

class MapControler {
public:
    int map[10][10] = 
    { 
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,0,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1}};//map‚ðŠi”[‚·‚é”z—ñ

    MapControler() {
        map[1][1] = 1;
    }


    void MapPracer() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 1) {
                    DrawCircle(Mappixelx(i), Mappixely(j), 10, GetColor(255, 255, 255), TRUE);
                }
            }
        }
    }
};

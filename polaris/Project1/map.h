#include "DxLib.h"
#include "func.h"


int Mappixel(int x) {
    return x * 100;
}

class MapControler {
public:
    int map[10][10] = {};//map‚ðŠi”[‚·‚é”z—ñ

    MapControler() {
        map[9][9] = 1;
    }


    void MapPracer() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] = 5) {
                    DrawCircle(Mappixel(i), Mappixel(j), 10, GetColor(255, 255, 255), TRUE);
                }
            }
        }
    }
};

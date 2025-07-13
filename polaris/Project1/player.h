#include "DxLib.h"
#include "func.h"

class Player {
public:

    int x, y;
    int map[10][10];

    Player() {
        x = 40;
        y = 40;
        map[0][0] = 1;
    }


    void PlayerMove() {
        if (CheckHitKey(KEY_INPUT_UP)) {
            y -= 10;
        }
        if (CheckHitKey(KEY_INPUT_DOWN)) {
            y += 10;
        }
        if (CheckHitKey(KEY_INPUT_LEFT)) {
            x -= 10;
        }
        if (CheckHitKey(KEY_INPUT_RIGHT)) {
            x += 10;
        }
        DrawCircle(x, y, 10, GetColor(255, 255, 255), TRUE);

    }
};

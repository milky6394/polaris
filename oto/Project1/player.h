#include "DxLib.h"

class Player {
public:

    int x, y;


    Player() {
        x = 40;
        y = 40;
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

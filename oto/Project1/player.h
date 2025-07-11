#include "DxLib.h"

class Player {
public:

    int x, y;


    Player() {
        x = 0;
        y = 0;
    }

    void PlayerMove() {
        DrawCircle(x, y, 10, GetColor(255, 255, 255), TRUE);

    }
};

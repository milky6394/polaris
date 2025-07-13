#include "DxLib.h"

bool pushspace = false, pushup = false, pushdown = false, pushright = false, pushleft = false;//各ボタンを長押しできないようにするための変数
bool Space() {
    if (CheckHitKey(KEY_INPUT_SPACE)) {
        if (!pushspace) {
            pushspace = true;
            return true;
        }
    }
    else {
        pushspace = false;
    }
    return false;
}
//spaceキー1回押しの関数

bool Up() {
    if (CheckHitKey(KEY_INPUT_UP)) {
        if (!pushup) {
            pushup = true;
            return true;
        }
    }
    else {
        pushup = false;
    }
    return false;
}
//upキー1回押しの関数

bool Down() {
    if (CheckHitKey(KEY_INPUT_DOWN)) {
        if (!pushdown) {
            pushdown = true;
            return true;
        }
    }
    else {
        pushdown = false;
    }
    return false;
}
//downキー1回押しの関数

bool Right() {
    if (CheckHitKey(KEY_INPUT_RIGHT)) {
        if (!pushright) {
            pushright = true;
            return true;
        }
    }
    else {
        pushright = false;
    }
    return false;
}
//rightキー1回押しの関数

bool Left() {
    if (CheckHitKey(KEY_INPUT_LEFT)) {
        if (!pushleft) {
            pushleft = true;
            return true;
        }
    }
    else {
        pushleft = false;
    }
    return false;
}
//leftキー1回押しの関数

int Playerpixel_X(int x) {
    return 390 + (x * 50);
}
int Playerpixel_Y(int y) {
    return 110 + (y * 50);
}
//playermapの配列座標を画面内座標に変換する関数

class Player {
public:
    int x, y;

    int playermap[10][10] =
    {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} };//playermapを格納する配列


    Player() {
        x = 0;
        y = 0;
        playermap[0][0] = 1;//playerの初期位置設定
    }

    void Player_XY() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (playermap[i][j]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //playerのplayermap内での配列座標を取得する関数

    void PlayerMove() {
        Player_XY();
        if (Up()) {
            playermap[x][y] = 0;
            playermap[x][y - 1] = 1;
        }
        if (Down()) {
            playermap[x][y] = 0;
            playermap[x][y + 1] = 1;
        }
        if (Left()) {
            playermap[x][y] = 0;
            playermap[x - 1][y] = 1;
        }
        if (Right()) {
            playermap[x][y] = 0;
            playermap[x + 1][y] = 1;
        }
        DrawCircle(Playerpixel_X(x), Playerpixel_Y(y), 5, GetColor(255, 0, 0), TRUE);

    }
};

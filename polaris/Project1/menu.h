#include "DxLib.h"

class MenuControler {
public:
    int x, y;
    bool pushup = false, pushdown = false, pushright = false, pushleft = false;//各ボタンを長押しできないようにするための変数

    int menumap[3][10][10] = {{
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    },{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    },{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    }};
    //menuのアイコン位置やカーソルの位置の配列

    MenuControler() {
        x = 0;
        y = 0;
        menumap[1][0][0] = 1;
    }

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
    //キー1回押しの関数

    int Menupixel_X(int x) {
        if (x / 5) {
            return 690 + (x * 50);
        }
        else {
            return 90 + (x * 50);
        }
    }
    int Menupixel_Y(int y) {
        return 110 + (y * 50);
    }
    //画面横に表示する座標へ変換

    void Menu_XY() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (menumap[1][j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //メニュー選択キーの座標を取得

    void MenuCursor() {
        if (Up()) {
            for (int i = y - 1; i >= 0; i--) {
                if (menumap[0][i][x]) {
                    menumap[1][y][x] = 0;
                    menumap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Down()) {
            for (int i = y + 1; i <= 9; i++) {
                if (menumap[0][i][x]) {
                    menumap[1][y][x] = 0;
                    menumap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Right()) {
            for (int i = x + 1; i <= 9; i++) {
                if (menumap[0][y][i]) {
                    menumap[1][y][x] = 0;
                    menumap[1][y][i] = 1;
                    break;
                }
            }
        }
        else if (Left()) {
            for (int i = x - 1; i >= 0; i--) {
                if (menumap[0][y][i]) {
                    menumap[1][y][x] = 0;
                    menumap[1][y][i] = 1;
                    break;
                }
            }
        }
    }
    //上下左右キーを押したときに、その先にアイコンがあった場合移動

    void MenuDraw() {
        Menu_XY();
        MenuCursor();
        DrawTriangle(Menupixel_X(x), Menupixel_Y(y), Menupixel_X(x), Menupixel_Y(y) - 20, Menupixel_X(x) + 10, Menupixel_Y(y) - 10, GetColor(255, 255, 255), true);

    }
};
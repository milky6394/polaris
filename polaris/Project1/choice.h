#include "DxLib.h"

class ChoiceManager {
public:

    int x, y;
    bool pushup, pushdown, pushright, pushleft, pushz;//各ボタンを長押しできないようにするための変数
    int choice;
    int choicenumber;

    int cursor[4][4] = {
    {0,0,0,0},
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,0} };

    int choicemap[4][2][4][4] = { 
    {
   {{0,0,0,0},
    {1,0,0,1},
    {0,0,0,0},
    {0,0,0,0}}
    ,
   {{0,0,0,0},
    {0,0,0,3},
    {0,0,0,0},
    {0,0,0,0}}
    }
    ,
    {
   {{0,0,0,0},
    {1,0,0,1},
    {0,0,0,0},
    {0,0,0,0}}
    ,
   {{0,0,0,0},
    {0,0,0,3},
    {0,0,0,0},
    {0,0,0,0}}
    }
    ,
    {
   {{0,0,0,0},
    {1,0,0,1},
    {0,0,0,0},
    {0,0,0,0}}
    ,
   {{0,0,0,0},
    {0,0,0,4},
    {0,0,0,0},
    {0,0,0,0}}
    }
    ,
    {
   {{0,0,0,0},
    {1,0,0,1},
    {0,0,0,0},
    {0,0,0,0}}
    ,
   {{0,0,0,0},
    {0,0,0,5},
    {0,0,0,0},
    {0,0,0,0}}
    }
    };
    /*
    menuのmapを格納する配列
    1層目：アイコンの描画位置の指定
    2層目：そのマスでの特殊操作
    */

    ChoiceManager() {
        x = 0;
        y = 0;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
        pushz = false;
        choice = 0;
        choicenumber = 0;
    }

    bool Button_Z() {
        if (CheckHitKey(KEY_INPUT_Z)) {
            if (!pushz) {
                pushz = true;
                return true;
            }
        }
        else {
            pushz = false;
        }
        return false;
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

    void ChoiceCursor() {
        if (Up()) {
            for (int i = y - 1; i >= 0; i--) {
                if (choicemap[choice][0][i][x]) {
                    cursor[y][x] = 0;
                    cursor[i][x] = 1;
                    break;
                }
            }
        }
        else if (Down()) {
            for (int i = y + 1; i <= 3; i++) {
                if (choicemap[choice][0][i][x]) {
                    cursor[y][x] = 0;
                    cursor[i][x] = 1;
                    break;
                }
            }
        }
        else if (Right()) {
            for (int i = x + 1; i <= 3; i++) {
                if (choicemap[choice][0][y][i]) {
                    cursor[y][x] = 0;
                    cursor[y][i] = 1;
                    break;
                }
            }
        }
        else if (Left()) {
            for (int i = x - 1; i >= 0; i--) {
                if (choicemap[choice][0][y][i]) {
                    cursor[y][x] = 0;
                    cursor[y][i] = 1;
                    break;
                }
            }
        }
    }
    //上下左右キーを押したときに、その先にアイコンがあった場合移動

    int Choicepixel_X(int x) {
        return 490 + (x * 100);
    }
    int Choicepixel_Y(int y) {
        return 600 + (y * 25);
    }
    //画面横に表示する座標へ変換

    void Choice_XY() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (cursor[j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //メニュー選択キーの座標を取得

    void ChoiceDraw() {
        DrawTriangle(Choicepixel_X(x), Choicepixel_Y(y), Choicepixel_X(x) + 10, Choicepixel_Y(y) - 10, Choicepixel_X(x) - 10, Choicepixel_Y(y) - 10, GetColor(255, 255, 255), true);
    }
    //メニューカーソルを描画する関数

    void ChoiceAction() {
        if (Button_Z()) {
            choicenumber = choicemap[choice][1][y][x];
            choice = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cursor[y][x] = 0;
                }
            }
            cursor[1][0] = 1;
        }
    }
    //menuの配列内でZキーをクリックしたときに行う処理

    void ChoiceAll() {
        ChoiceCursor();
        Choice_XY();
        ChoiceDraw();
        ChoiceAction();
    }
};
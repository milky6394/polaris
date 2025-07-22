#include "DxLib.h"
#include "string.h"

class MenuControler {
public:
    ItemManager* im = new ItemManager();

    int x, y;
    bool pushup, pushdown, pushright, pushleft, pushz;//各ボタンを長押しできないようにするための変数
    bool gameend;
    char menustring[1000] = {};

    int menumap[4][10][10] = {{
    {1,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,1,1},
    {1,0,0,0,0,1,1,1,1,1},
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
    {100,0,0,0,0,0,0,0,0,0},
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
    /*
    menuのmapを格納する配列
    1層目：アイコンの描画位置の指定
    2層目：メニューカーソルの位置
    3層目：そのマスでの特殊操作
    4層目：そのマスに描画する画像
    */
    MenuControler() {
        x = 0;
        y = 0;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
        pushz = false;
        gameend = false;
    }

    ~MenuControler() {
        delete im;
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

    bool MeEnd() {
        return gameend;
    }
    //gameendをplayerへ送る関数

    void MenuAction() {
        if (Button_Z()) {
            switch (menumap[2][y][x]) {
            case 0:

                break;
            case 1:

                break;
            case 100:
                gameend = true;
                break;
            }
        }
    }
    //menuの配列内でZキーをクリックしたときに行う処理

    void MenuString() {
        switch (menumap[2][y][x]) {
        case 0:

            break;
        case 1:
            DrawMenuString(1);
            break;
        case 2:
            DrawMenuString(2);
            break;
        case 3:
            DrawMenuString(3);
            break;
        case 4:
            DrawMenuString(4);
            break;
        case 100:
            DrawMenuString(100);
            break;
        }
    }
    //表示する説明文を選ぶ関数

    void DrawMenuString(int a) {
        for (int i = 0; i < 1000; i++) {
            menustring[i] = im->ItemString[a][i];
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", menustring);
    }
    //menuの配列内の引数の説明文を表示する関数

    void MenuDraw() {
        Menu_XY();
        MenuCursor();
        MenuString();
        MenuAction();
        for (int i = 5; i < 10; i++) {
            for (int j = 5; j < 10; j++) {
                if (menumap[2][j][i] != 0) {
                    DrawGraph(Menupixel_X(i), Menupixel_Y(j), im->graph[menumap[2][j][i]], false);
                    //DrawCircle(Menupixel_X(i), Menupixel_Y(j), menumap[2][j][i]*10, GetColor(255, 255, 255), TRUE);
                }//3層目の数字×10の大きさの〇をその場に描画
            }
        }
        DrawTriangle(Menupixel_X(x), Menupixel_Y(y), Menupixel_X(x), Menupixel_Y(y) - 20, Menupixel_X(x) + 10, Menupixel_Y(y) - 10, GetColor(255, 0, 0), true);
    }
};
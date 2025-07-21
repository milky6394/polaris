#include "DxLib.h"

class ChoiceManager {
public:
    MapControler* mp = new MapControler();

    int x, y;
    int st;
    char String[1000] = {};
    bool pushup, pushdown, pushright, pushleft, pushz;//各ボタンを長押しできないようにするための変数
    bool choice;

    int choicemap[4][4][4] = { {
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
    },{
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    },{
    {0,0,0,1},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    },{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    } };
    /*
    menuのmapを格納する配列
    1層目：アイコンの描画位置の指定
    2層目：メニューカーソルの位置
    3層目：そのマスでの特殊操作
    4層目：そのマスに描画する画像
    */

    ChoiceManager() {
        x = 0;
        y = 0;
        st = 0;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
        pushz = false;
        choice = false;
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
                if (choicemap[0][i][x]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Down()) {
            for (int i = y + 1; i <= 3; i++) {
                if (choicemap[0][i][x]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Right()) {
            for (int i = x + 1; i <= 3; i++) {
                if (choicemap[0][y][i]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][y][i] = 1;
                    break;
                }
            }
        }
        else if (Left()) {
            for (int i = x - 1; i >= 0; i--) {
                if (choicemap[0][y][i]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][y][i] = 1;
                    break;
                }
            }
        }
    }
    //上下左右キーを押したときに、その先にアイコンがあった場合移動

    void ChoiceAction() {
        if (Button_Z()) {
            switch (choicemap[2][y][x]) {
            case 0:

                break;
            case 1:
                choice = false;
                break;
            case 2:
                choice = false;
                break;
            case 100:
                break;
            }
        }
    }
    //menuの配列内でZキーをクリックしたときに行う処理

    void ChoiceString() {
        switch (choicemap[2][y][x]) {
        case 0:

            break;
        case 1:
            DrawChoiceString(1);
            break;
        case 2:
            DrawChoiceString(2);
            break;
        case 3:
            DrawChoiceString(3);
            break;
        case 4:
            DrawChoiceString(4);
            break;
        case 100:
            DrawChoiceString(100);
            break;
        }
    }
    //表示する説明文を選ぶ関数

    void DrawChoiceString(int a) {
        for (int i = 0; i < 1000; i++) {
            //menustring[i] = im->ItemString[a][i];
        }
        //DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", menustring);
    }
    //menuの配列内の引数の説明文を表示する関数

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
                if (choicemap[1][j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //メニュー選択キーの座標を取得

    void StringReset() {
        for (int i = 0; i < 1000; i++) {
            String[i] = {};
        }
    }
    //Stringを初期化する関数

    void ChoiceDraw() {
        //String[st] = im->ItemString[a][st];
        //DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", String);
        DrawTriangle(Choicepixel_X(x), Choicepixel_Y(y), Choicepixel_X(x) + 10, Choicepixel_Y(y) - 10, Choicepixel_X(x) - 10, Choicepixel_Y(y) - 10, GetColor(255, 255, 255), true);
    }

    void ChoiceAll() {
        if (choice) {
            ChoiceCursor();
            Choice_XY();
            ChoiceDraw();
            ChoiceAction();
        }
    }
};
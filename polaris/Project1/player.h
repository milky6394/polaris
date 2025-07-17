#include "DxLib.h"
#include "map.h"
#include "event.h"
#include "menu.h"

class Player {
public:
    MapControler* mp = new MapControler();
    EventControler* ev = new EventControler();
    MenuControler* me = new MenuControler();

    int x, y;//Playerの現在の座標
    int r, g, b;
    bool pushx, pushz, pushup, pushdown, pushright, pushleft;//各ボタンを長押しできないようにするための変数
    int draw;
    bool flag;

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

    int inventory[25] ={};//playermapを格納する配列

    Player() {
        x = 0;
        y = 0;
        r = 255;
        g = 0;
        b = 0;
        playermap[0][0] = 1;//playerの初期位置設定
        draw = 0;
        flag = true;
        pushx = false;
        pushz = false;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
    }

    ~Player() {
        delete mp;
        delete ev;
        delete me;
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
    bool Button_X() {
        if (CheckHitKey(KEY_INPUT_X)) {
            if (!pushx) {
                pushx = true;
                return true;
            }
        }
        else {
            pushx = false;
        }
        return false;
    }
    //キー1回押しの関数

    bool toggle() {
        flag = !flag;
        return !flag;
    }
    //Xキーを押すたびに真偽が入れ替わる関数

    int Playerpixel_X(int x) {
        return 390 + (x * 50);
    }
    int Playerpixel_Y(int y) {
        return 110 + (y * 50);
    }
    //playermapの配列座標を画面内座標に変換する関数

    void Player_XY() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (playermap[j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //playerのplayermap内での配列座標を取得する関数

    void PlayerMove() {
        switch (mp->map[mp->mapnumber][0][y][x]) {
        case 0:
            break;
        case 1:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 2:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 3:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 4:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 5:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 6:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 7:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 8:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 9:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 10:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            break;
        case 11:
            if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 12:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            break;
        case 13:
            if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 14:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            break;
        case 15:
            if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        }
    }
    //playerを移動させる関数 mapの位置によって移動できる方向が異なる

    void Invent(int a) {
        for (int i = 0; i < 25; i++) {
            if (inventory[i] == 0) {
                inventory[i] = a;
                break;
            }
        }
    }
    //inventoryに引数の値を格納する関数
    
    bool Item(int a) {
        for (int i = 0; i < 25; i++) {
            if (inventory[i] == a) {
                return true;
            }
        }
        return false;
    }
    //inventoryに引数のアイテムが入っているか判定する関数

    void MapChange(int a,int b) {
        mp->mapnumber = mp->map[mp->mapnumber][1][y][x] % 100;
        playermap[y][x] = 0;
        playermap[b][a] = 1;
    }
    //100で割った余りのIDのマップに飛ぶ。移動先のマップの初期位置は引数でx,yが指定できる

    void PlayerAction() {
        if (Button_Z()) {
            switch (mp->map[mp->mapnumber][1][y][x]) {
            case 0:

                break;
            case 1:
                r = 255;
                g = 0;
                b = 0;
                break;
            case 2:
                r = 0;
                g = 255;
                b = 0;
                break;
            case 3:
                r = 0;
                g = 0;
                b = 255;
                break;
            case 4:
                Invent(1);
                ItemMenu();
                break;
            case 5:
                Invent(2);
                ItemMenu();
                break;
            case 6:
                Invent(3);
                ItemMenu();
                break;
            case 7:
                EventKey(1);
                Invent(4);
                ItemMenu();
                break;
            case 8:
                EventKey(2);
                break;
            case 100:
                MapChange(9,0);
                break;
            case 101:
                MapChange(0,0);
                break;
            }

        }
    }
    //playerの位置によって特定のアクションを起こせる関数

    void EventKey(int x) {
        draw = x;
    }
    //オブジェクトの説明文などを出すトリガーになる関数。引数の数だけクリックすると戻る

    void ItemMenu() {
        for (int i = 5; i < 10; i++) {
            for (int j = 5; j < 10; j++) {
                me->menumap[2][j][i] = inventory[(i - 5) + ((j - 5) * 5)];
            }
        }
    }
    //playerのインベントリをmenuに反映

    void PlayerDraw() {
        DrawCircle(Playerpixel_X(x), Playerpixel_Y(y), 5, GetColor(r, g, b), TRUE);
    }
    //playerの位置描画関数

    void PlayerAll() {
        mp->MapPracer();
        PlayerDraw();//player描画
        if (Button_X()) {
            toggle();
        }//Xを押したらメニュー切り替え

        if (flag) {
            if (draw > 0) {
                ev->EventDraw();
                if (Button_Z()) {
                    draw--;
                }
            }//Eventが行われているならplayerの処理より優先
            else {
                Player_XY();
                PlayerAction();
                PlayerMove();
            }
        }//Xキーを押したらメニュー表示
        else {
            me->MenuDraw();
        }
    }

};

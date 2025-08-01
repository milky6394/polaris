#pragma once
#include "DxLib.h"
#include "map.h"
#include "menu.h"
#include "choice.h"

class Player {
public:
    MapControler* mp = new MapControler();
    StringControler* sc = new StringControler();
    MenuControler* me = new MenuControler();
    ChoiceManager* co = new ChoiceManager();
    
    int x, y;//Playerの現在の座標
    int nowx, nowy;
    bool pushx, pushz, pushup, pushdown, pushright, pushleft;//各ボタンを長押しできないようにするための変数
    bool flag;
    int playergraph;
    bool movex, movey;

    int playermap[9][9] ={
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0} };//playermapを格納する配列

    int inventory[25] ={};//playermapを格納する配列

    Player() {
        x = 4;
        y = 8;
        playermap[y][x] = 1;//playerの初期位置設定
        flag = true;
        pushx = false;
        pushz = false;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
        movex = false;
        movey = false;
        nowx = 440 + (x * 50);
        nowy = 110 + (y * 50);
        playergraph= LoadGraph("../../Images/character_tip/namakubi_dane.png");
    }

    ~Player() {
        delete mp;
        delete sc;
        delete me;
        delete co;
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
        if (nowx > 440 + (x * 50)) {
            movex = true;
            return nowx -= 5;
        }
        else if (nowx < 440 + (x * 50)) {
            movex = true;
            return nowx += 5;
        }
        else {
            movex = false;
            return nowx;
        }
    }
    int Playerpixel_Y(int y) {
        if (nowy > 110 + (y * 50)) {
            movey = true;
            return nowy -= 5;
        }
        else if (nowy < 110 + (y * 50)) {
            movey = true;
            return nowy += 5;
        }
        else {
            movey = false;
            return nowy;
        }
    }
    //playermapの配列座標を画面内座標に変換する関数

    void Player_XY() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (playermap[j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //playerのplayermap内での配列座標を取得する関数

    void PlayerMove() {
        if (!movex && !movey) {
            switch (mp->map[mp->mapnumber][0][y][x]) {
            case 10:
                break;
            case 11:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                break;
            case 12:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                break;
            case 13:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                break;
            case 14:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                break;
            case 15:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                break;
            case 16:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                break;
            case 17:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                break;
            case 18:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                break;
            case 19:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                break;
            case 20:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                break;
            case 21:
                if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                break;
            case 22:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                break;
            case 23:
                if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                break;
            case 24:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                }
                break;
            case 25:
                if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                }
                break;
            default:
                break;
            }
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
        StringKey(a, a, 1);
        ItemMenu();
    }
    //inventoryに引数の値を格納する関数
    
    bool ItemCheck(int a) {
        for (int i = 0; i < 25; i++) {
            if (inventory[i] == a) {
                return true;
            }
        }
        return false;
    }
    //inventoryに引数のアイテムが入っているか判定する関数

    bool ItemOff(int a) {
        for (int i = 0; i < 25; i++) {
            if (inventory[i] == a) {
                inventory[i] = 0;
                return true;
            }
        }
        return false;
    }
    //inventoryに引数のアイテムが入っているか判定し、入っていたらそれを削除する関数

    void MapChange(int a,int b,int c) {
        mp->mapnumber = c-1;
        playermap[y][x] = 0;
        playermap[b][a] = 1;
        nowx = 440 + (a * 50);
        nowy = 110 + (b * 50);
    }
    //引数cのマップに飛ぶ。移動先のマップの初期位置は引数a,bでx,yが指定できる

    void StringKey(int a,int b,int c) {
        sc->draw = b - a + 1;
        sc->Stringnumber = a;
        sc->StringReset();
        sc->mo = c;
    }
    //a~bの配列に入っているオブジェクトの説明文などを出す関数。引数の数だけクリックすると戻る

    void ItemMenu() {
        for (int i = 5; i < 10; i++) {
            for (int j = 5; j < 10; j++) {
                me->menumap[2][j][i] = inventory[(i - 5) + ((j - 5) * 5)];
            }
        }
    }
    //playerのインベントリをmenuに反映

    bool PlEnd() {
        return me->MeEnd();
    }
    //gameendをmainへ送る関数

    void PlayerDraw() {
        DrawGraph(Playerpixel_X(x), Playerpixel_Y(y), playergraph, true);
    }
    //playerの位置描画関数

    void ChoiceAction() {
        if (co->choicenumber) {
            PlayerAction(co->choicenumber);
            co->choicenumber = 0;
        }
    }
    //choice.hによるActionを反映する関数

    void PlayerAction(int a) {
        while (CheckHitKey(KEY_INPUT_Z)) {}
        if (a / 100000) {
            StringKey((a - 100000) / 100, (a - 100000) % 100, 2);
        }
        else if (a / 10000) {
            MapChange((a % 100) / 10, a % 10, (a - 10000) / 100);
        }
        else if (a / 2000) {
            co->choice = a - 2000;
        }
        else if (a / 1000) {
            Invent(a - 1000);
        }
    }
    //playerの位置によって特定のアクションを起こせる関数

    void PlayerAll() {
        mp->MapPracer();
        Player_XY();
        PlayerDraw();//player描画
        if (Button_X()) {
            toggle();
        }//Xを押したらメニュー切り替え
        if (flag) {
            if (sc->draw > 0) {
                sc->StringAll();
            }//Stringが描画されているならplayerの処理より優先
            else {
                if (co->choice) {
                    co->ChoiceAll();
                    ChoiceAction();
                }
                else {
                    PlayerMove();
                    if (Button_Z()) {
                        PlayerAction(mp->map[mp->mapnumber][1][y][x]);
                    }
                }
            }
        }//Xキーを押したらメニュー表示
        else {
            me->MenuDraw();
        }
    }

};

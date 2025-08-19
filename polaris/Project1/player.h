#pragma once
#include "DxLib.h"
#include "map.h"
#include "menu.h"
#include "branch.h"

class Player {
public:
    MapControler* mp = new MapControler();
    StringControler* sc = new StringControler();
    MenuControler* me = new MenuControler();
    BranchManager* br = new BranchManager();
    
    int x, y;//Playerの現在の座標
    int nowx, nowy;
    bool pushx, pushz, pushup, pushdown, pushright, pushleft;//各ボタンを長押しできないようにするための変数
    bool flag;
    int playergraph;
    int walksound;
    int itemsound;
    bool movex, movey;
    int statechange;
    int gh[12];
    int walkvec;
    bool walkflag;

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

    int inventory[50] ={};//playermapを格納する配列

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
        statechange = 0;
        walkvec = 1;
        walkflag = false;
        playergraph = LoadGraph("../../Images/character_tip/namakubi_dane.png");
        walksound= LoadSoundMem("../../Sound/革靴で歩く.mp3");
        itemsound = LoadSoundMem("../../Sound/決定ボタンを押す28.mp3");
        LoadDivGraph("../../Images/character_tip/20150503142545.png", 12, 3, 4, 20, 28, gh);
    }

    ~Player() {
        delete mp;
        delete sc;
        delete me;
        delete br;
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
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                me->menumap[1][j][i] = 0;
            }
        }
        me->menumap[1][0][0] = 1;
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
        if (CheckHitKey(KEY_INPUT_UP)) {
            walkvec = 10;
        }
        else if (CheckHitKey(KEY_INPUT_DOWN)) {
            walkvec = 1;
        }
        else if (CheckHitKey(KEY_INPUT_RIGHT)) {
            walkvec = 7;
        }
        else if (CheckHitKey(KEY_INPUT_LEFT)) {
            walkvec = 4;
        }
        if (!movex && !movey) {
            switch (mp->map[mp->mapnumber][0][y][x]) {
            case 10:
                break;
            case 11:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 12:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 13:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 14:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 15:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 16:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 17:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 18:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 19:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 20:
                if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 21:
                if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 22:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 23:
                if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 24:
                if (CheckHitKey(KEY_INPUT_UP)) {
                    playermap[y][x] = 0;
                    playermap[y - 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_DOWN)) {
                    playermap[y][x] = 0;
                    playermap[y + 1][x] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            case 25:
                if (CheckHitKey(KEY_INPUT_RIGHT)) {
                    playermap[y][x] = 0;
                    playermap[y][x + 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                else if (CheckHitKey(KEY_INPUT_LEFT)) {
                    playermap[y][x] = 0;
                    playermap[y][x - 1] = 1;
                    PlaySoundMem(walksound, DX_PLAYTYPE_BACK);
                    walkflag = !walkflag;
                }
                break;
            }
        }
    }
    //playerを移動させる関数 mapの位置によって移動できる方向が異なる

    void Invent(int a) {
    for (int i = 0; i < 50; i++) {
        if (inventory[i] == 0) {
            inventory[i] = a;
            break;
        }
    }
    StringKey(a, 1);
    ItemMenu();
}
    //inventoryに引数の値を格納する関数

    bool ItemCheck(int a) {
    for (int i = 0; i < 50; i++) {
        if (inventory[i] == a) {
            return true;
        }
    }
    StringKey(0, 1);
    return false;
}
    //inventoryに引数のアイテムが入っているか判定する関数

    bool ItemOff(int a) {
    for (int i = 0; i < 50; i++) {
        if (inventory[i] == a) {
            inventory[i] = 0;
            ItemMenu();
            return true;
        }
    }
    StringKey(0, 1);
    return false;
}
    //inventoryに引数のアイテムが入っているか判定し、入っていたらそれを削除する関数

    void MapChange(int a, int b, int c) {
    mp->mapnumber = c - 1;
    playermap[y][x] = 0;
    playermap[b][a] = 1;
    nowx = 440 + (a * 50);
    nowy = 110 + (b * 50);
}
    //引数cのマップに飛ぶ。移動先のマップの初期位置は引数a,bでx,yが指定できる

    void StringKey(int a, int b) {
    sc->draw = b;
    sc->Stringnumber = a;
    sc->StringReset();
}
    //a~bの配列に入っているオブジェクトの説明文などを出す関数。引数の数だけクリックすると戻る

    void ItemMenu() {
    for (int i = 5; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            me->menumap[2][j][i] = inventory[(i - 5) + (j * 5)];
        }
    }
}
    //playerのインベントリをmenuに反映

    bool PlEnd() {
    return me->MeEnd();
}
    //gameendをmainへ送る関数

    void PlayerDraw() {
        //DrawGraph(Playerpixel_X(x), Playerpixel_Y(y), playergraph, true);
        if (movex || movey) {
            if (walkflag) {
                DrawGraph(Playerpixel_X(x), Playerpixel_Y(y), gh[walkvec + 1], true);
            }
            else {
                DrawGraph(Playerpixel_X(x), Playerpixel_Y(y), gh[walkvec - 1], true);
            }
        }
        else {
            DrawGraph(Playerpixel_X(x), Playerpixel_Y(y), gh[walkvec], true);
        }
    }
    //playerの位置描画関数

    void BranchAction() {
    if (br->branchnumber) {
        PlayerAction(br->branchnumber);
        br->branchnumber = 0;
    }
}
    //choice.hによるActionを反映する関数
    
    void PlayerAction(int a) {
        while (CheckHitKey(KEY_INPUT_Z)) {}
        if (a / 100000000) {
            br->branch = a - 100000000;
            br->BranchStringKey(a - 100000000);
        }
        else if (a / 20000000) {
            if (ItemOff((a - 20000000) / 100000)) {
                PlayerAction(a % 100000);
            }
        }
        else if (a / 10000000) {
            if (ItemCheck((a - 10000000) / 100000)) {
                PlayerAction(a % 100000);
            }
        }
        else if (a / 10000) {
            StringKey((a - 10000) / 10, a % 10);
        }
        else if (a / 1000) {
            MapChange((a % 100) / 10, a % 10, (a - 1000) / 100);
            if (((a - 1000) / 100) == 6) {
                statechange = 6;
            }
        }
        else if (a / 200) {
            Invent(a - 200);
            mp->map[mp->mapnumber][1][y][x] = 0;
            PlaySoundMem(itemsound, DX_PLAYTYPE_BACK);
        }
        else if (a / 100) {
            Invent(a - 100);
            PlaySoundMem(itemsound, DX_PLAYTYPE_BACK);
        }
    }
    //playerの位置によって特定のアクションを起こせる関数

    void GameDraw() {
        mp->MapPracer();
        Player_XY();
        PlayerDraw();//player描画
    }
    //ゲームの基本描画の関数

    void PlayerAll() {
        GameDraw();
        if (sc->draw > 0) {
            sc->StringAll();
        }//Stringが描画されているならplayerの処理より優先
        else {
            if (br->branch) {
                br->BranchAll();
                BranchAction();
            }
            else {
                if (Button_X()) {
                    toggle();
                }//Xを押したらメニュー切り替え
                if (flag) {
                    PlayerMove();
                    if (Button_Z()) {
                        PlayerAction(mp->map[mp->mapnumber][1][y][x]);
                    }
                }
                else {
                    me->MenuDraw();
                }//Xキーを押したらメニュー表示
            }
        }
    }
};

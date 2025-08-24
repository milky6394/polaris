#pragma once
#include "DxLib.h"

bool gameend = false;

class SettingControler {
public:

    int x, y;
    bool pushup, pushdown, pushz;//各ボタンを長押しできないようにするための変数
    int settingpage;
    bool set;
    int setsound;
    char SetString[30][100] = {
    { "" },
    { "ウィンドウサイズ設定" },
    { "ボリューム設定" },
    { "戻る" },
    { "1920×1080" },
    { "1536×864" },
    { "1280×720" },
    { "1024×576" },
    { "戻る" },
    { "100%" },
    { "80%" },
    { "60%" },
    { "40%" },
    { "20%" },
    { "0%" },
    { "戻る" },
    { "ゲームを終了" },
    { "キャンセル" },

    };

    int settingmap[4][10] = {
    {0,1,0,0,2,0,0,3,0,0},
    {0,4,0,5,0,6,0,7,0,8},
    {0,0,0,9,10,11,12,13,14,15},
    {0,0,0,0,16,0,0,17,0,0}
    };

    int cursormap[10] = {0,0,0,0,0,0,0,0,0,0};//playermapを格納する配列

    SettingControler() {
        x = 4;
        y = 1;
        pushup = false;
        pushdown = false;
        pushz = true;
        settingpage = 0;
        set = false;
        setsound = LoadSoundMem("../../Sound/カーソル移動12.mp3");
    }

    bool Button_Z() {
        if (CheckHitKey(KEY_INPUT_Z)) {
            if (!pushz) {
                pushz = true;
                PlaySoundMem(setsound, DX_PLAYTYPE_BACK);
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
    //キー1回押しの関数

    int Settingpixel_X(int x) {
        return 390 + (x * 50);
    }
    int Settingpixel_Y(int y) {
        return 110 + (y * 50);
    }
    //画面横に表示する座標へ変換

    void Setting_Y() {
        for (int i = 0; i < 10; i++) {
            if (cursormap[i]) {
                y = i;
            }
        }
    }
    //メニュー選択キーの座標を取得

    void SettingCursor() {
        if (Up()) {
            for (int i = y - 1; i >= 0; i--) {
                if (settingmap[settingpage][i]) {
                    cursormap[y] = 0;
                    cursormap[i] = 1;
                    PlaySoundMem(setsound, DX_PLAYTYPE_BACK);
                    break;
                }
            }
        }
        else if (Down()) {
            for (int i = y + 1; i <= 9; i++) {
                if (settingmap[settingpage][i]) {
                    cursormap[y] = 0;
                    cursormap[i] = 1;
                    PlaySoundMem(setsound, DX_PLAYTYPE_BACK);
                    break;
                }
            }
        }
    }
    //上下左右キーを押したときに、その先にアイコンがあった場合移動

    void SettingAction() {
        if (Button_Z()) {
            switch (settingmap[settingpage][y]) {
            case 0:

                break;
            case 1:
                settingpage = 1;
                cursormap[y] = 0;
                cursormap[9] = 1;
                break;
            case 2:
                settingpage = 2;
                cursormap[y] = 0;
                cursormap[9] = 1;
                break;
            case 3:
                set = true;
                break;
            case 4:
                SetWindowSize(1920, 1080);
                break;
            case 5:
                SetWindowSize(1536, 864);
                break;
            case 6:
                SetWindowSize(1280, 720);   
                break;
            case 7:
                SetWindowSize(1024, 576);
                break;
            case 8:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[1] = 1;
                break;
            case 9:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[4] = 1;
                break;
            case 10:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[4] = 1;
                break;
            case 11:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[4] = 1;
                break;
            case 12:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[4] = 1;
                break;
            case 13:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[4] = 1;
                break;
            case 14:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[4] = 1;
                break;
            case 15:
                settingpage = 0;
                cursormap[y] = 0;
                cursormap[4] = 1;
                break;
            case 16:
                gameend = true;
                break;
            case 17:
                set = true;
                break;
            }
        }
    }
    //menuの配列内でZキーをクリックしたときに行う処理

    void DrawSetString() {
        for (int i = 0; i < 10; i++) {
            if (settingmap[settingpage][i]) {
                DrawString(Settingpixel_X(x), Settingpixel_Y(i), SetString[settingmap[settingpage][i]], GetColor(255, 255, 255));
            }
        }
    }

    void SettingDraw() {
        SettingAction();
        Setting_Y();
        SettingCursor();
        DrawSetString();
        DrawTriangle(Settingpixel_X(x), Settingpixel_Y(y), Settingpixel_X(x), Settingpixel_Y(y) - 20, Settingpixel_X(x) + 10, Settingpixel_Y(y) - 10, GetColor(255, 0, 0), true);
    }
};
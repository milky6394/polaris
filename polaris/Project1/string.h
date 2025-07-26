#pragma once
#include "DxLib.h"
#include "item.h"

#define STRINGSPEED 3

class StringControler {
public:
    ItemManager* im = new ItemManager();

    int x, y;
    int st;
    int draw;
    bool pushz;
    int speed;
    int Stringnumber;
    int mo;
    char String[1000] = {};

    char ConvString[300][1000] = {
    { "test" },
    { "さてこれは会話1です" },
    { "会話2です" },
    { "書くのがめんどくさくなってきました会話3です" },
    { "もういいでしょアイテム4です" },
    { "あきた5" },
    { "あきた6" },
    { "あきた7" },
    };

    StringControler() {
        x = 1000;
        y = 650;
        st = 0;
        draw = 0;
        pushz = false;
        Stringnumber = 0;
        speed = 0;
        mo = 0;
    }

    ~StringControler() {
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

    void StringReset() {
        for (int i = 0; i < 1000; i++) {
            String[i] = {};
        }
    }
    //Stringを初期化する関数

    void ItemString(int a) {
        String[st] = im->ItemString[a][st];
        if (st < 999 && speed == 0) {
            st++;
            speed++;
        }
        else {
            speed++;
            if (speed == STRINGSPEED) {
                speed = 0;
            }
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", String);
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }

    void StringDraw(int a) {
        String[st] = ConvString[a][st];
        if (st < 999 && speed == 0) {
            st++;
            speed++;
        }
        else {
            speed++;
            if (speed == STRINGSPEED) {
                speed = 0;
            }
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", String);
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }

    void StringAll() {
        if (mo == 1) {
            ItemString(Stringnumber);
        }
        else if (mo == 2) {
            StringDraw(Stringnumber);
        }
        if (Button_Z()) {
            st = 0;
            StringReset();
            Stringnumber++;
            draw--;
        }
    }
};
#pragma once
#include "DxLib.h"

#define STRINGSPEED 2

class StringControler {
public:

    int x, y;
    int st;
    int draw;
    bool pushz;
    int Stringnumber;
    char String[1000] = {};
    char CheckString[300][1000] = {
    { "" },
    { "ベッドの下から何かファイルが出てきた。\n特化調査書だ！" },
    { "" },
    { "" },
    { "" },
    { "" },
    { "" },
    { "" },
    };

    StringControler() {
        x = 1000;
        y = 650;
        st = 0;
        draw = 0;
        pushz = false;
        Stringnumber = 0;
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
    //キー1回押しの関数

    void StringReset() {
        for (int i = 0; i < 1000; i++) {
            String[i] = {};
        }
    }
    //Stringを初期化する関数

    void ItemString(int a) {
        String[st] = CheckString[a][st];
        if (st < 999) {
            st++;
        }
        DrawString(300, 600, String, GetColor(255, 255, 255));
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }
    //引数で指定したIDのアイテムの説明を表示する関数

    void StringAll() {
        ItemString(Stringnumber);
        if (Button_Z()) {
            st = 0;
            StringReset();
            Stringnumber++;
            draw--;
        }
    }
};
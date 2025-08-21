#pragma once
#include "DxLib.h"

class ItemManager {
public:
    int x, y;
    int st;
    int draw;
    bool pushz;
    int Stringnumber;
    char String[1000] = {};
    int graph[300] = {};

    char ItemString[300][1000] = {
        { "アクションに必要なアイテムを持っていません" },
        { "「カードキー」\n消費することでどこかの部屋に入ることができる。" },
        { "「特化調査書」\nそれぞれの長所を更に伸ばすための資料" },
        { "" },
        { "" },
        { "" },
        { "" },
        { "" },
    };
    char ItemName[300][1000] = {
    { "" },
    { "カードキーを手に入れた" },
    { "特化調査書を手に入れた" },
    { "" },
    { "" },
    { "" },
    { "" },
    { "" },
    };

    ItemManager() {
        x = 1000;
        y = 650;
        st = 0;
        draw = 0;
        pushz = false;
        Stringnumber = 0;
        graph[1] = LoadGraph("../../Images/Items/cardkey.png");
        graph[2] = LoadGraph("../../Images/Items/cardkey.png");
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

    void StringDraw(int a) {
        String[st] = ItemName[a][st];
        if (st < 999) {
            st++;
        }
        DrawString(300, 600, String, GetColor(255, 255, 255));
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }
    //引数で指定したIDのアイテムの説明を表示する関数

    void StringAll() {
        StringDraw(Stringnumber);
        if (Button_Z()) {
            st = 0;
            StringReset();
            Stringnumber++;
            draw--;
        }
    }
};
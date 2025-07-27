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
    { "おはよう、親愛なる僕の隊員くん・・・って、今はまだ一応違うのかな？" },
    { "すごいすごい、何が起こってるの？って顔だね。\n自己紹介してあげよう、僕はCOGMA。" },
    { "Cognitive Management Asistant・・・略してCOGMA！\nこぐまってよんでね。分かりやすいと思うから。" },
    { "僕は君の未来の上司、です。\nこれが終わったらじきに収集命令が来ると思うから、準備しておいてね。" },
    { "あぁ、ここがどこか気になってるってこと？\nその困惑しきっちゃってる顔やめてくれないかなぁ～こわいよ～" },
    { "ここはね、<シェルターα>っていう疑似的な試験場で、\n君の意識だけをいったんお借りして連れてきてる。" },
    { ".  .  .  .  ." },
    { "だって君、ここに来る前は眠っていたでしょ？" },
    { "" },
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
        DrawString(300, 600, String, GetColor(255, 255, 255));
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }

    void StoryDraw(int a) {
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
        DrawString(300, 600, String, GetColor(255, 255, 255));
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }


    void StringAll() {
        if (mo == 1) {
            ItemString(Stringnumber);
        }
        else if (mo == 2) {
            StringDraw(Stringnumber);
        }
        else if (mo == 3) {
            StoryDraw(Stringnumber);
        }
        if (Button_Z()) {
            st = 0;
            StringReset();
            Stringnumber++;
            draw--;
            if (draw == 0 && mo == 3) {

            }
        }
    }
};
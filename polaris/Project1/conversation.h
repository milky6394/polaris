#pragma once
#include "DxLib.h"

#define STRINGSPEED 3

class ConvControler {
public:

    int x, y;
    int st;
    int draw;
    bool pushz;
    int speed;
    int Stringnumber;
    int personnumber;//話者の番号を格納する変数
    int convgraph[10] = {};//話者の画像を格納する変数
    char String[1000] = {};

    char ConvString[300][1000] = {
    { "test" },
    { "おはよう、親愛なる僕の隊員くん・・・って、今はまだ一応違うのかな？\0" },
    { "すごいすごい、何が起こってるの？って顔だね。\n自己紹介してあげよう、僕はCOGMA。" },
    { "Cognitive Management Asistant・・・略してCOGMA！\nこぐまってよんでね。分かりやすいと思うから。" },
    { "僕は君の未来の上司、です。\nこれが終わったらじきに収集命令が来ると思うから、準備しておいてね。" },
    { "あぁ、ここがどこか気になってるってこと？\nその困惑しきっちゃってる顔やめてくれないかなぁ～こわいよ～" },
    { "ここはね、<シェルターα>っていう疑似的な試験場で、\n君の意識だけをいったんお借りして連れてきてる。" },
    { ".  .  .  .  ." },
    { "だって君、ここに来る前は眠っていたでしょ？" },
    { "" },
    { "瞬間、そうだ眠っていたんだ、と思い出した。" },
    { "適当な学校を出て、そのあと自堕落に生きていた俺が" },
    { "ちょっとばかし情報系に強いからって、突然政府からスカウトされた" },
    { "麻薬取締専門の国家機密組織「オルド」" },
    { "この国で蔓延ってる最悪のクスリを、跡形もなく消し去るのが使命で、俺はその1隊員" },
    { "今日もその任務を終えて、自室のベッドに身を預けたところだった" },
    { "" },
    { "" },
    { "" },
    { "" },
    { "" },
    { "" },
    };

    ConvControler() {
        x = 0;
        y = 0;
        st = 0;
        draw = 0;
        pushz = false;
        Stringnumber = 0;
        speed = 0;
        personnumber = 0;
        convgraph[0] = 0;
        convgraph[1] = LoadGraph("../../Images/character_tip/namakubi_dane.png");
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
        st = 0;
    }
    //Stringを初期化する関数

    bool StoryDraw(int a) {
        DrawGraph(x - 100, y, convgraph[personnumber], true);
        DrawString(x, y, String, GetColor(255, 255, 255));
        if (ConvString[a][st] == '\0') {
            return true;
        }
        else {
            if (Button_Z()) {
                while (!(ConvString[a][st] == '\0')) {
                    String[st] = ConvString[a][st];
                    st++;
                }
                return true;
            }
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
            return false;
        }
    }
    //StringKeyで受け取った会話を再生する関数

    void StringKey(int a, int b,int c,int d,int e) {
        draw = b - a + 1;
        Stringnumber = a;
        x = c;
        y = d;
        personnumber = e;
        StringReset();
    }
    //会話イベントの情報を受け取る関数。a~bの会話を座標c,dに話者eで表示する。

    void StringAll() {
        if (StoryDraw(Stringnumber)) {
            if (Button_Z()) {
                if (draw == 1) {
                    draw--;
                }
                else if (draw > 1) {
                    st = 0;
                    StringReset();
                    Stringnumber++;
                    draw--;
                }
            }
            DrawTriangle(1000, y + 50, 1010, y + 40, 990, y + 40, GetColor(255, 255, 255), true);
        }
    }
};
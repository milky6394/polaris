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
    { "���͂悤�A�e���Ȃ�l�̑�������E�E�E���āA���͂܂��ꉞ�Ⴄ�̂��ȁH" },
    { "�������������A�����N�����Ă�́H���Ċ炾�ˁB\n���ȏЉ�Ă����悤�A�l��COGMA�B" },
    { "Cognitive Management Asistant�E�E�E������COGMA�I\n�����܂��Ă��łˁB������₷���Ǝv������B" },
    { "�l�͌N�̖����̏�i�A�ł��B\n���ꂪ�I������炶���Ɏ��W���߂�����Ǝv������A�������Ă����ĂˁB" },
    { "�����A�������ǂ����C�ɂȂ��Ă���Ă��ƁH\n���̍��f������������Ă���߂Ă���Ȃ����Ȃ��`���킢��`" },
    { "�����͂ˁA<�V�F���^�[��>���Ă����^���I�Ȏ�����ŁA\n�N�̈ӎ��������������񂨎؂肵�ĘA��Ă��Ă�B" },
    { ".  .  .  .  ." },
    { "�����ČN�A�����ɗ���O�͖����Ă����ł���H" },
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
    //String������������֐�

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
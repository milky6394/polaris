#pragma once
#include "DxLib.h"

class BranchManager {
public:

    int x;
    bool pushright, pushleft, pushz;//各ボタンを長押しできないようにするための変数
    int branch;
    int branchnumber;
    int st;
    int draw;
    int Stringnumber;
    int branchsound;
    char String[1000] = {};
    char YesString[10] = {"はい"};
    char NoString[10] = {"いいえ"};
    char BranchString[300][1000] = {
    { "test" },
    { "部屋A。カードキーを消費することで入れる。\n※部屋は一度入ると出られません\n入りますか？" },
    { "部屋B。カードキーを消費することで入れる。\n※部屋は一度入ると出られません\n入りますか？" },
    { "部屋C。カードキーを消費することで入れる。\n※部屋は一度入ると出られません\n入りますか？" },
    { "" },
    { "" },
    { "" },
    { "" },
    };

    int cursor[2] = { 0,0 };

    BranchManager() {
        x = 0;
        pushright = false;
        pushleft = false;
        pushz = false;
        branch = 0;
        branchnumber = 0;
        st = 0;
        draw = 0;
        branchsound= LoadSoundMem("../../Sound/カーソル移動12.mp3");
    }

    bool Button_Z() {
        if (CheckHitKey(KEY_INPUT_Z)) {
            if (!pushz) {
                pushz = true;
                PlaySoundMem(branchsound, DX_PLAYTYPE_BACK);
                return true;
            }
        }
        else {
            pushz = false;
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
    //キー1回押しの関数

    void BranchCursor() {
        if (Right()) {
            cursor[0] = 0;
            cursor[1] = 1;
            PlaySoundMem(branchsound, DX_PLAYTYPE_BACK);
        }
        else if (Left()) {
            cursor[1] = 0;
            cursor[0] = 1;
            PlaySoundMem(branchsound, DX_PLAYTYPE_BACK);
        }
    }
    //左右キーを押したときに、その先に移動

    int Branchpixel_X(int x) {
        return 490 + (x * 300);
    }
    //画面横に表示する座標へ変換

    void Branch_X() {
        for (int i = 0; i < 2; i++) {
            if (cursor[i]) {
                x = i;
            }
        }
    }
    //メニュー選択キーの座標を取得

    void BranchDraw() {
        DrawTriangle(Branchpixel_X(x), 650, Branchpixel_X(x) + 10, 650 - 10, Branchpixel_X(x) - 10, 650 - 10, GetColor(255, 255, 255), true);
        DrawString(470, 670, NoString, GetColor(255, 255, 255));
        DrawString(770, 670, YesString, GetColor(255, 255, 255));
    }
    //メニューカーソルを描画する関数

    void BranchAction() {
        if (Button_Z()) {
            if (cursor[1] == 1) {
                branchnumber = branch;
                branch = 0;
                cursor[1] = 0;
                cursor[0] = 1;
            }
            else {
                branchnumber = 0;
                branch = 0;
                cursor[1] = 0;
                cursor[0] = 1;
            }
            st = 0;
            StringReset();
            Stringnumber++;
            draw--;
        }
    }
    //menuの配列内でZキーをクリックしたときに行う処理

    void StringKey(int a) {
        draw = 1;
        Stringnumber = a;
        StringReset();
    }

    void BranchStringKey(int a) {
        switch (a) {
            case 20101348:
                StringKey(1);
                break;
            case 20101448:
                StringKey(2);
                break;
            case 20101548:
                StringKey(3);
                break;
            case 1:

                break;
        }
    }

    void StringReset() {
        for (int i = 0; i < 1000; i++) {
            String[i] = {};
        }
    }
    //Stringを初期化する関数

    void ItemString(int a) {
        String[st] = BranchString[a][st];
        if (st < 999) {
            st++;
        }
        DrawString(500, 550, String, GetColor(255, 255, 255));
    }
    //引数で指定したIDのアイテムの説明を表示する関数

    void StringAll() {
        if (draw > 0) {
            ItemString(Stringnumber);
        }
    }

    void BranchAll() {
        StringAll();
        BranchCursor();
        Branch_X();
        BranchDraw();
        BranchAction();
    }
};
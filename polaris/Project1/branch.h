#pragma once
#include "DxLib.h"

class BranchManager {
public:

    int x;
    bool pushright, pushleft, pushz;//各ボタンを長押しできないようにするための変数
    int branch;//何番目の選択肢を表示するかを制御する変数
    int branchnumber;

    int cursor[2] = { 0,0 };

    BranchManager() {
        x = 0;
        pushright = false;
        pushleft = false;
        pushz = false;
        branch = 0;
        branchnumber = 0;
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
        }
        else if (Left()) {
            cursor[1] = 0;
            cursor[0] = 1;
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
        DrawTriangle(Branchpixel_X(x), 600, Branchpixel_X(x) + 10, 600 - 10, Branchpixel_X(x) - 10, 600 - 10, GetColor(255, 255, 255), true);
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
        }
    }
    //menuの配列内でZキーをクリックしたときに行う処理

    void BranchAll() {
        BranchCursor();
        Branch_X();
        BranchDraw();
        BranchAction();
    }
};
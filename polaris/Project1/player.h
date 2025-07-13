#include "DxLib.h"
#include "func.h"

bool pushspace = false, pushup = false, pushdown = false, pushright = false, pushleft = false;//�e�{�^���𒷉����ł��Ȃ��悤�ɂ��邽�߂̕ϐ�
bool Space() {
    if (CheckHitKey(KEY_INPUT_SPACE)) {
        if (!pushspace) {
            pushspace = true;
            return true;
        }
    }
    else {
        pushspace = false;
    }
    return false;
}
//space�L�[1�񉟂��̊֐�

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
//up�L�[1�񉟂��̊֐�

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
//down�L�[1�񉟂��̊֐�

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
//right�L�[1�񉟂��̊֐�

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
//left�L�[1�񉟂��̊֐�

int x, y;


class Player {
public:


    Player() {
        x = 40;
        y = 40;
    }


    void PlayerMove() {
        if (Up()) {
            y -= 10;
        }
        if (Down()) {
            y += 10;
        }
        if (Left()) {
            x -= 10;
        }
        if (Right()) {
            x += 10;
        }
        DrawCircle(x, y, 5, GetColor(255, 255, 255), TRUE);

    }
};

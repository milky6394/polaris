#include "DxLib.h"
bool pushspace, pushup, pushdown, pushright, pushleft;//�e�{�^���𒷉����ł��Ȃ��悤�ɂ��邽�߂̕ϐ�
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

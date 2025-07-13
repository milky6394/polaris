#include "DxLib.h"

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

int Playerpixel_X(int x) {
    return 390 + (x * 50);
}
int Playerpixel_Y(int y) {
    return 110 + (y * 50);
}
//playermap�̔z����W����ʓ����W�ɕϊ�����֐�

class Player {
public:
    int x, y;

    int playermap[10][10] =
    {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} };//playermap���i�[����z��


    Player() {
        x = 0;
        y = 0;
        playermap[0][0] = 1;//player�̏����ʒu�ݒ�
    }

    void Player_XY() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (playermap[i][j]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //player��playermap���ł̔z����W���擾����֐�

    void PlayerMove() {
        Player_XY();
        if (Up()) {
            playermap[x][y] = 0;
            playermap[x][y - 1] = 1;
        }
        if (Down()) {
            playermap[x][y] = 0;
            playermap[x][y + 1] = 1;
        }
        if (Left()) {
            playermap[x][y] = 0;
            playermap[x - 1][y] = 1;
        }
        if (Right()) {
            playermap[x][y] = 0;
            playermap[x + 1][y] = 1;
        }
        DrawCircle(Playerpixel_X(x), Playerpixel_Y(y), 5, GetColor(255, 0, 0), TRUE);

    }
};

#include "DxLib.h"

class ChoiceManager {
public:

    int x, y;
    int st;
    char String[1000] = {};
    bool pushup, pushdown, pushright, pushleft, pushz;//�e�{�^���𒷉����ł��Ȃ��悤�ɂ��邽�߂̕ϐ�

    int choicemap[4][4][4] = { {
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    },{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    },{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    },{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    } };
    /*
    menu��map���i�[����z��
    1�w�ځF�A�C�R���̕`��ʒu�̎w��
    2�w�ځF���j���[�J�[�\���̈ʒu
    3�w�ځF���̃}�X�ł̓��ꑀ��
    4�w�ځF���̃}�X�ɕ`�悷��摜
    */

    ChoiceManager() {
        x = 1000;
        y = 650;
        st = 0;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
        pushz = false;
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
    //�L�[1�񉟂��̊֐�

    void ChoiceCursor() {
        if (Up()) {
            for (int i = y - 1; i >= 0; i--) {
                if (choicemap[0][i][x]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Down()) {
            for (int i = y + 1; i <= 9; i++) {
                if (choicemap[0][i][x]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Right()) {
            for (int i = x + 1; i <= 9; i++) {
                if (choicemap[0][y][i]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][y][i] = 1;
                    break;
                }
            }
        }
        else if (Left()) {
            for (int i = x - 1; i >= 0; i--) {
                if (choicemap[0][y][i]) {
                    choicemap[1][y][x] = 0;
                    choicemap[1][y][i] = 1;
                    break;
                }
            }
        }
    }
    //�㉺���E�L�[���������Ƃ��ɁA���̐�ɃA�C�R�����������ꍇ�ړ�

    void ChoiceAction() {
        if (Button_Z()) {
            switch (choicemap[2][y][x]) {
            case 0:

                break;
            case 1:

                break;
            case 100:
                break;
            }
        }
    }
    //menu�̔z�����Z�L�[���N���b�N�����Ƃ��ɍs������

    void ChoiceString() {
        switch (choicemap[2][y][x]) {
        case 0:

            break;
        case 1:
            DrawChoiceString(1);
            break;
        case 2:
            DrawChoiceString(2);
            break;
        case 3:
            DrawChoiceString(3);
            break;
        case 4:
            DrawChoiceString(4);
            break;
        case 100:
            DrawChoiceString(100);
            break;
        }
    }
    //�\�������������I�Ԋ֐�

    void DrawChoiceString(int a) {
        for (int i = 0; i < 1000; i++) {
            //menustring[i] = im->ItemString[a][i];
        }
        //DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", menustring);
    }
    //menu�̔z����̈����̐�������\������֐�

    int Choicepixel_X(int x) {
        if (x / 5) {
            return 690 + (x * 50);
        }
        else {
            return 90 + (x * 50);
        }
    }
    int Choicepixel_Y(int y) {
        return 110 + (y * 50);
    }
    //��ʉ��ɕ\��������W�֕ϊ�

    void Choice_XY() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (choicemap[1][j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //���j���[�I���L�[�̍��W���擾

    void StringReset() {
        for (int i = 0; i < 1000; i++) {
            String[i] = {};
        }
    }
    //String������������֐�

    void ChoiceDraw(int a) {
        //String[st] = im->ItemString[a][st];
        if (st < 999) {
            st++;
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", String);
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }
};
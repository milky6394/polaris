#include "DxLib.h"
#include "string.h"

class MenuControler {
public:
    ItemManager* im = new ItemManager();

    int x, y;
    bool pushup, pushdown, pushright, pushleft, pushz;//�e�{�^���𒷉����ł��Ȃ��悤�ɂ��邽�߂̕ϐ�
    bool gameend;
    char menustring[1000] = {};

    int menumap[4][10][10] = {{
    {1,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,1,1},
    {1,0,0,0,0,1,1,1,1,1},
    },{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    },{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {100,0,0,0,0,0,0,0,0,0},
    },{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    }};
    /*
    menu��map���i�[����z��
    1�w�ځF�A�C�R���̕`��ʒu�̎w��
    2�w�ځF���j���[�J�[�\���̈ʒu
    3�w�ځF���̃}�X�ł̓��ꑀ��
    4�w�ځF���̃}�X�ɕ`�悷��摜
    */
    MenuControler() {
        x = 0;
        y = 0;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
        pushz = false;
        gameend = false;
    }

    ~MenuControler() {
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

    int Menupixel_X(int x) {
        if (x / 5) {
            return 690 + (x * 50);
        }
        else {
            return 90 + (x * 50);
        }
    }
    int Menupixel_Y(int y) {
        return 110 + (y * 50);
    }
    //��ʉ��ɕ\��������W�֕ϊ�

    void Menu_XY() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (menumap[1][j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //���j���[�I���L�[�̍��W���擾

    void MenuCursor() {
        if (Up()) {
            for (int i = y - 1; i >= 0; i--) {
                if (menumap[0][i][x]) {
                    menumap[1][y][x] = 0;
                    menumap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Down()) {
            for (int i = y + 1; i <= 9; i++) {
                if (menumap[0][i][x]) {
                    menumap[1][y][x] = 0;
                    menumap[1][i][x] = 1;
                    break;
                }
            }
        }
        else if (Right()) {
            for (int i = x + 1; i <= 9; i++) {
                if (menumap[0][y][i]) {
                    menumap[1][y][x] = 0;
                    menumap[1][y][i] = 1;
                    break;
                }
            }
        }
        else if (Left()) {
            for (int i = x - 1; i >= 0; i--) {
                if (menumap[0][y][i]) {
                    menumap[1][y][x] = 0;
                    menumap[1][y][i] = 1;
                    break;
                }
            }
        }
    }
    //�㉺���E�L�[���������Ƃ��ɁA���̐�ɃA�C�R�����������ꍇ�ړ�

    bool MeEnd() {
        return gameend;
    }
    //gameend��player�֑���֐�

    void MenuAction() {
        if (Button_Z()) {
            switch (menumap[2][y][x]) {
            case 0:

                break;
            case 1:

                break;
            case 100:
                gameend = true;
                break;
            }
        }
    }
    //menu�̔z�����Z�L�[���N���b�N�����Ƃ��ɍs������

    void MenuString() {
        switch (menumap[2][y][x]) {
        case 0:

            break;
        case 1:
            DrawMenuString(1);
            break;
        case 2:
            DrawMenuString(2);
            break;
        case 3:
            DrawMenuString(3);
            break;
        case 4:
            DrawMenuString(4);
            break;
        case 100:
            DrawMenuString(100);
            break;
        }
    }
    //�\�������������I�Ԋ֐�

    void DrawMenuString(int a) {
        for (int i = 0; i < 1000; i++) {
            menustring[i] = im->ItemString[a][i];
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", menustring);
    }
    //menu�̔z����̈����̐�������\������֐�

    void MenuDraw() {
        Menu_XY();
        MenuCursor();
        MenuString();
        MenuAction();
        for (int i = 5; i < 10; i++) {
            for (int j = 5; j < 10; j++) {
                if (menumap[2][j][i] != 0) {
                    DrawGraph(Menupixel_X(i), Menupixel_Y(j), im->graph[menumap[2][j][i]], false);
                    //DrawCircle(Menupixel_X(i), Menupixel_Y(j), menumap[2][j][i]*10, GetColor(255, 255, 255), TRUE);
                }//3�w�ڂ̐����~10�̑傫���́Z�����̏�ɕ`��
            }
        }
        DrawTriangle(Menupixel_X(x), Menupixel_Y(y), Menupixel_X(x), Menupixel_Y(y) - 20, Menupixel_X(x) + 10, Menupixel_Y(y) - 10, GetColor(255, 0, 0), true);
    }
};
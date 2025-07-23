#include "DxLib.h"
#include "map.h"
#include "menu.h"
#include "choice.h"

class Player {
public:
    MapControler* mp = new MapControler();
    StringControler* sc = new StringControler();
    MenuControler* me = new MenuControler();
    ChoiceManager* co = new ChoiceManager();
    
    int x, y;//Player�̌��݂̍��W
    int nowx, nowy;
    int r, g, b;
    bool pushx, pushz, pushup, pushdown, pushright, pushleft;//�e�{�^���𒷉����ł��Ȃ��悤�ɂ��邽�߂̕ϐ�
    int draw;
    bool flag;
    int st;
    int playergraph;

    int playermap[9][9] =
    {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0} };//playermap���i�[����z��

    int inventory[25] ={};//playermap���i�[����z��

    Player() {
        x = 4;
        y = 8;
        r = 255;
        g = 0;
        b = 0;
        playermap[y][x] = 1;//player�̏����ʒu�ݒ�
        draw = 0;
        flag = true;
        pushx = false;
        pushz = false;
        pushup = false;
        pushdown = false;
        pushright = false;
        pushleft = false;
        st = 0;
        nowx = 440 + (x * 50);
        nowy = 110 + (y * 50);
        playergraph= LoadGraph("../../Images/character_tip/namakubi_dane.png");
    }

    ~Player() {
        delete mp;
        delete sc;
        delete me;
        delete co;
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
    bool Button_X() {
        if (CheckHitKey(KEY_INPUT_X)) {
            if (!pushx) {
                pushx = true;
                return true;
            }
        }
        else {
            pushx = false;
        }
        return false;
    }
    //�L�[1�񉟂��̊֐�

    bool toggle() {
        flag = !flag;
        return !flag;
    }
    //X�L�[���������тɐ^�U������ւ��֐�

    int Playerpixel_X(int x) {
        if (nowx > 440 + (x * 50)) {
            return nowx -= 5;
        }
        else if (nowx < 440 + (x * 50)) {
            return nowx += 5;
        }
        else {
            return nowx;
        }
    }
    int Playerpixel_Y(int y) {
        if (nowy > 110 + (y * 50)) {
            return nowy -= 5;
        }
        else if (nowy < 110 + (y * 50)) {
            return nowy += 5;
        }
        else {
            return nowy;
        }
    }
    //playermap�̔z����W����ʓ����W�ɕϊ�����֐�

    void Player_XY() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (playermap[j][i]) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    //player��playermap���ł̔z����W���擾����֐�

    void PlayerMove() {
        switch (mp->map[mp->mapnumber][0][y][x]) {
        case 10:
            break;
        case 11:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 12:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 13:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 14:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 15:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 16:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 17:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 18:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 19:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            else if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 20:
            if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            break;
        case 21:
            if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        case 22:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            break;
        case 23:
            if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            break;
        case 24:
            if (Up()) {
                playermap[y][x] = 0;
                playermap[y - 1][x] = 1;
            }
            else if (Down()) {
                playermap[y][x] = 0;
                playermap[y + 1][x] = 1;
            }
            break;
        case 25:
            if (Right()) {
                playermap[y][x] = 0;
                playermap[y][x + 1] = 1;
            }
            else if (Left()) {
                playermap[y][x] = 0;
                playermap[y][x - 1] = 1;
            }
            break;
        default:
            break;
        }
    }
    //player���ړ�������֐� map�̈ʒu�ɂ���Ĉړ��ł���������قȂ�

    void Invent(int a) {
        for (int i = 0; i < 25; i++) {
            if (inventory[i] == 0) {
                inventory[i] = a;
                break;
            }
        }
        ItemMenu();
    }
    //inventory�Ɉ����̒l���i�[����֐�
    
    bool ItemCheck(int a) {
        for (int i = 0; i < 25; i++) {
            if (inventory[i] == a) {
                return true;
            }
        }
        return false;
    }
    //inventory�Ɉ����̃A�C�e���������Ă��邩���肷��֐�

    bool ItemOff(int a) {
        for (int i = 0; i < 25; i++) {
            if (inventory[i] == a) {
                inventory[i] = 0;
                return true;
            }
        }
        return false;
    }
    //inventory�Ɉ����̃A�C�e���������Ă��邩���肵�A�����Ă����炻����폜����֐�

    void MapChange(int a,int b,int c) {
        mp->mapnumber = c-1;
        playermap[y][x] = 0;
        playermap[b][a] = 1;
        nowx = 440 + (a * 50);
        nowy = 110 + (b * 50);
    }
    //����c�̃}�b�v�ɔ�ԁB�ړ���̃}�b�v�̏����ʒu�͈���a,b��x,y���w��ł���

    void StringKey(int a,int b) {
        draw = b - a + 1;
        st = a;
        sc->st = 0;
        sc->StringReset();
    }
    //a~b�̔z��ɓ����Ă���I�u�W�F�N�g�̐������Ȃǂ��o���֐��B�����̐������N���b�N����Ɩ߂�

    void ItemMenu() {
        for (int i = 5; i < 10; i++) {
            for (int j = 5; j < 10; j++) {
                me->menumap[2][j][i] = inventory[(i - 5) + ((j - 5) * 5)];
            }
        }
    }
    //player�̃C���x���g����menu�ɔ��f

    bool PlEnd() {
        return me->MeEnd();
    }
    //gameend��main�֑���֐�

    void PlayerDraw() {
        //DrawCircle(Playerpixel_X(x), Playerpixel_Y(y), 5, GetColor(r, g, b), TRUE);
        DrawGraph(Playerpixel_X(x), Playerpixel_Y(y), playergraph, false);
    }
    //player�̈ʒu�`��֐�

    void ChoiceAction() {
        if (co->choicenumber) {
            PlayerAction(co->choicenumber);
        }
    }
    //choice.h�ɂ��Action�𔽉f����֐�

    void PlayerAction(int a) {
            if (a / 10000) {
                switch (a % 10000) {
                case 0:
                    StringKey(1, 1);
                    break;
                case 1:
                    StringKey(2, 2);
                    break;
                case 2:
                    StringKey(3, 3);
                    break;
                case 3:
                    StringKey(4, 4);
                    break;
                case 4:
                    StringKey(1, 1);
                    break;
                case 5:
                    StringKey(1, 1);
                    break;
                case 6:
                    StringKey(2, 2);
                    break;
                case 7:
                    StringKey(3, 3);
                    break;
                case 8:
                    StringKey(5, 6);
                    break;
                }
            }
            else if (a / 1000) {
                while(CheckHitKey(KEY_INPUT_Z)){}
                co->choice = a % 1000;
            }
            else if (a / 100) {
                switch (a % 100) {
                case 0:

                    break;
                case 1:
                    Invent(a%100);
                    StringKey(1, 1);
                    break;
                case 2:
                    Invent(a % 100);
                    StringKey(2, 2);
                    break;
                case 3:
                    Invent(a % 100);
                    StringKey(3, 3);
                    break;
                case 4:
                    Invent(a % 100);
                    StringKey(4, 4);
                    break;
                }
            }
            else if (a != 0) {
                switch (a) {
                case 0:
                    break;
                case 1:
                    MapChange(4, 0, a);
                    break;
                case 2:
                    MapChange(4, 8, a);
                    break;
                case 3:
                    MapChange(4, 8, a);
                    break;
                case 4:
                    MapChange(4, 8, a);
                    break;
                case 5:
                    MapChange(4, 8, a);
                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:

                    break;
                case 9:

                    break;
                }
            }
        
    }
    //player�̈ʒu�ɂ���ē���̃A�N�V�������N������֐�

    void PlayerAll() {
        mp->MapPracer();
        PlayerDraw();//player�`��
        if (Button_X()) {
            toggle();
        }//X���������烁�j���[�؂�ւ�

        if (flag) {
            if (draw > 0) {
                sc->EventDraw(st);
                if (Button_Z()) {
                    sc->st = 0;
                    sc->StringReset();
                    st++;
                    draw--;
                }
            }//String���`�悳��Ă���Ȃ�player�̏������D��
            else {
                if (co->choice) {
                    co->ChoiceAll();
                    ChoiceAction();
                }
                else {
                    Player_XY();
                    if (Button_Z()) {
                        PlayerAction(mp->map[mp->mapnumber][1][y][x]);
                    }
                    PlayerMove();
                }
            }
        }//X�L�[���������烁�j���[�\��
        else {
            me->MenuDraw();
        }
    }

};

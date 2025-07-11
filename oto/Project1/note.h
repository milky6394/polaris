#include "DxLib.h"

#define VTLNOTE 149.9//ノーツとノーツの間のピクセル数
#define IDOLNOTE 140.8
#define CHELLYNOTE 152.2
#define KICKNOTE 114.7
#define KNOWNOTE 78.08
#define GRAYNOTE 72.1
#define BLINGNOTE 148.9
#define RGBNOTE 91.47

class Combo {
public:
    static int combo;
    static int miss;
    static int good;
    static int r;
    static int g;
    static int b;
    static int good1;
    static int good2;
    static int good3;
    static int good4;
    static int demo;

    Combo() {
        SetFontSize(60);
    }
    void View() {
        DrawFormatString(540, 350, GetColor(r, g, b), "%d", combo);
        if (combo > 99) {
            r = 150;
        }
        if (combo < 100) {
            r = 0;
        }
        good1--;
        good2--;
        good3--;
        good4--;
    }
};
int Combo::combo = 0;
int Combo::miss = 0;
int Combo::good = 0;
int Combo::r = 0;
int Combo::g = 0;
int Combo::b = 0;
int Combo::good1 = 0;
int Combo::good2 = 0;
int Combo::good3 = 0;
int Combo::good4 = 0;
int Combo::demo = 0;

class Moto {
public:

    Combo* co;

    float x, y;
    int gh;
    int tap, mouse, c;
    bool live;
    static bool kaburi1;
    static bool kaburi2;
    static bool kaburi3;
    static bool kaburi4;
    static bool kaburi9;

    Moto() {
        tap = LoadSoundMem("38.mp3");
        mouse = 0;
        c = 0;
        co = new Combo();
        gh = LoadGraph("Blue.png");
        live = true;
        kaburi1 = false;
        kaburi2 = false;
        kaburi3 = false;
        kaburi4 = false;
    }

    void Al() {
        if (live) {
            DrawGraph(x, y, gh, TRUE);
            if (co->demo == 1 && y > 570) {
                live = false;
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
            }
        }
        y = y + 13;
    }
};
bool Moto::kaburi1 = false;
bool Moto::kaburi2 = false;
bool Moto::kaburi3 = false;
bool Moto::kaburi4 = false;
bool Moto::kaburi9 = false;

class Blue1 : public Moto {
public:
    Blue1(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_D)) {
                if (y > 500 && y < 650 && x == 140 && kaburi1 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    kaburi1 = true;
                    co->combo++;
                    co->good++;
                    co->good1 = 20;
                }
                DrawBox(130, 570, 230, 620, GetColor(180, 180, 230), true);
                kaburi1 = true;
            }
            else if (kaburi1 == true && CheckHitKey(KEY_INPUT_D) == 0) {
                kaburi1 = false;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
    }
};
class Blue2 : public Moto {
public:
    Blue2(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_F)) {
                if (y > 500 && y < 650 && x == 240 && kaburi2 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    kaburi2 = true;
                    co->combo++;
                    co->good++;
                    co->good2 = 20;
                }
                kaburi2 = true;
                DrawBox(230, 570, 330, 620, GetColor(180, 180, 230), true);
            }
            else if (kaburi2 == true && CheckHitKey(KEY_INPUT_F) == 0) {
                kaburi2 = false;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
    }
};
class Blue3 : public Moto {
public:
    Blue3(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_J)) {
                if (y > 500 && y < 650 && x == 340 && kaburi3 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    kaburi3 = true;
                    co->combo++;
                    co->good++;
                    co->good3 = 20;
                }
                kaburi3 = true;
                DrawBox(330, 570, 430, 620, GetColor(180, 180, 230), true);
            }
            else if (kaburi3 == true && CheckHitKey(KEY_INPUT_J) == 0) {
                kaburi3 = false;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
    }
};
class Blue4 : public Moto {
public:
    Blue4(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_K)) {
                if (y > 500 && y < 650 && x == 440 && kaburi4 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    kaburi4 = true;
                    co->combo++;
                    co->good++;
                    co->good4 = 20;
                }
                kaburi4 = true;
                DrawBox(430, 570, 530, 620, GetColor(180, 180, 230), true);
            }
            else if (kaburi4 == true && CheckHitKey(KEY_INPUT_K) == 0) {
                kaburi4 = false;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
    }
};
class Blue5 : public Moto {
public:
    Blue5(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_D) && y > 500 && y < 650 && x == 140) {
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                live = false;
                co->combo++;
                co->good++;
                co->good1 = 20;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
    }
};
class Blue6 : public Moto {
public:
    Blue6(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_F) && y > 500 && y < 650 && x == 240) {
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                live = false;
                co->combo++;
                co->good++;
                co->good2 = 20;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;

            }
        }
        Al();
    }
};
class Blue7 : public Moto {
public:
    Blue7(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_J) && y > 500 && y < 650 && x == 340) {
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                live = false;
                co->combo++;
                co->good++;
                co->good3 = 20;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
    }
};
class Blue8 : public Moto {
public:
    Blue8(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_K) && y > 500 && y < 650 && x == 440) {
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                live = false;
                co->combo++;
                co->good++;
                co->good4 = 20;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
    }
};
class Blue9 : public Moto {
public:
    Blue9(int setX, int setY) {
        x = setX;
        y = setY;
    }
    void All() {
        if (live) {
            if (CheckHitKey(KEY_INPUT_J)) {
                if (y > 500 && y < 650 && x == 340 && kaburi9 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    kaburi9 = true;
                    co->combo++;
                    co->good++;
                    co->good3 = 20;
                }
                kaburi9 = true;
                DrawBox(330, 570, 430, 620, GetColor(180, 180, 230), true);
            }
            else if (kaburi9 == true && CheckHitKey(KEY_INPUT_J) == 0) {
                kaburi9 = false;
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        Al();
        if (y > 676) {
            y = 0;
        }
    }
};

class Green {
public:
    Moto* mo;
    Combo* co;

    int x, y, i, m, n, j;
    bool live;
    int tap;
    int rang1, rang2;

    Green() {
        live = true;
        mo->kaburi1 = false;
        mo->kaburi2 = false;
        mo->kaburi3 = false;
        mo->kaburi4 = false;
        tap = LoadSoundMem("38.mp3");
        rang1 = LoadGraph("long1.png");
        rang2 = LoadGraph("long2.png");
    }
};

class Green1 : public Green {
public:
    Green1(int setX, int setY, int setI, int setM) {
        x = setX;
        y = setY;
        i = setI;
        m = setM;
        switch (m) {
        case 0:
            j = VTLNOTE;
            break;
        case 1:
            j = KNOWNOTE;
            break;
        case 2:
            j = IDOLNOTE;
            break;
        case 3:
            j = KICKNOTE;
            break;
        case 4:
            j = CHELLYNOTE;
            break;
        case 5:
            j = GRAYNOTE;
            break;
        case 6:
            j = BLINGNOTE;
            break;
        }
    }
    void All() {
        if (live) {
            n++;
            if (CheckHitKey(KEY_INPUT_D)) {
                if (y > 500 - (20 + j * (i - 1)) && y < 650 - (20 + j * (i - 1)) && mo->kaburi1 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    mo->kaburi1 = true;
                    co->combo++;
                    co->good++;
                    co->good1 = 20;
                }
                else if (mo->kaburi1 == true && y < 550 && y > 600 - (20 + j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo++;
                        co->good++;
                    }
                }
                mo->kaburi1 = true;
            }
            if (CheckHitKey(KEY_INPUT_D) == 0) {
                if (y > 500 && y < 650 && mo->kaburi1 == true) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    mo->kaburi1 = false;
                    co->combo++;
                    co->good++;
                    co->good1 = 20;
                }
                else if (mo->kaburi1 == true) {
                    mo->kaburi1 = false;
                }
                else if (mo->kaburi1 == false && y < 500 && y > 650 - (j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo = 0;
                        co->miss++;
                        co->r = 255;
                    }
                }
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        if (live) {
            if (co->demo == 1 && y > 570) {
                live = false;
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
            }
            DrawGraph(x, y, rang1, TRUE);
            DrawExtendGraph(x, y + 20, x + 79, y + 20 + (j * (i - 1)), rang2, false);
            DrawGraph(x, y + (j * (i - 1)), rang1, TRUE);
        }
        y = y + 13;
    }
};
class Green2 : public Green {
public:
    Green2(int setX, int setY, int setI, int setM) {
        x = setX;
        y = setY;
        i = setI;
        m = setM;
        switch (m) {
        case 0:
            j = VTLNOTE;
            break;
        case 1:
            j = KNOWNOTE;
            break;
        case 2:
            j = IDOLNOTE;
            break;
        case 3:
            j = KICKNOTE;
            break;
        case 4:
            j = CHELLYNOTE;
            break;
        case 5:
            j = GRAYNOTE;
            break;
        case 6:
            j = BLINGNOTE;
            break;
        }
    }
    void All() {
        if (live) {
            n++;
            if (CheckHitKey(KEY_INPUT_F)) {
                if (y > 500 - (20 + j * (i - 1)) && y < 650 - (20 + j * (i - 1)) && mo->kaburi2 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    mo->kaburi2 = true;
                    co->combo++;
                    co->good++;
                    co->good2 = 20;
                }
                else if (mo->kaburi2 == true && y < 550 && y > 600 - (20 + j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo++;
                        co->good++;
                    }
                }
                mo->kaburi2 = true;
            }
            if (CheckHitKey(KEY_INPUT_F) == 0) {
                if (y > 500 && y < 650 && mo->kaburi2 == true) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    mo->kaburi2 = false;
                    co->combo++;
                    co->good++;
                    co->good2 = 20;
                }
                else if (mo->kaburi2 == true) {
                    mo->kaburi2 = false;
                }
                else if (mo->kaburi2 == false && y < 500 && y > 650 - (j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo = 0;
                        co->miss++;
                        co->r = 255;
                    }
                }
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        if (live) {
            if (co->demo == 1 && y > 570) {
                live = false;
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
            }
            DrawGraph(x, y, rang1, TRUE);
            DrawExtendGraph(x, y + 20, x + 79, y + 20 + (j * (i - 1)), rang2, false);
            DrawGraph(x, y + (j * (i - 1)), rang1, TRUE);
        }
        y = y + 13;
    }
};
class Green3 : public Green {
public:
    Green3(int setX, int setY, int setI, int setM) {
        x = setX;
        y = setY;
        i = setI;
        m = setM;
        switch (m) {
        case 0:
            j = VTLNOTE;
            break;
        case 1:
            j = KNOWNOTE;
            break;
        case 2:
            j = IDOLNOTE;
            break;
        case 3:
            j = KICKNOTE;
            break;
        case 4:
            j = CHELLYNOTE;
            break;
        case 5:
            j = GRAYNOTE;
            break;
        case 6:
            j = BLINGNOTE;
            break;
        }
    }
    void All() {
        if (live) {
            n++;
            if (CheckHitKey(KEY_INPUT_J)) {
                if (y > 500 - (20 + j * (i - 1)) && y < 650 - (20 + j * (i - 1)) && mo->kaburi3 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    mo->kaburi3 = true;
                    co->combo++;
                    co->good++;
                    co->good3 = 20;
                }
                else if (mo->kaburi3 == true && y < 550 && y > 600 - (20 + j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo++;
                        co->good++;
                    }
                }
                mo->kaburi3 = true;
            }
            if (CheckHitKey(KEY_INPUT_J) == 0) {
                if (y > 500 && y < 650 && mo->kaburi3 == true) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    mo->kaburi3 = false;
                    co->combo++;
                    co->good++;
                    co->good3 = 20;
                }
                else if (mo->kaburi3 == true) {
                    mo->kaburi3 = false;
                }
                else if (mo->kaburi3 == false && y < 500 && y > 650 - (j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo = 0;
                        co->miss++;
                        co->r = 255;
                    }
                }
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        if (live) {
            if (co->demo == 1 && y > 570) {
                live = false;
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
            }
            DrawGraph(x, y, rang1, TRUE);
            DrawExtendGraph(x, y + 20, x + 79, y + 20 + (j * (i - 1)), rang2, false);
            DrawGraph(x, y + (j * (i - 1)), rang1, TRUE);
        }
        y = y + 13;
    }
};
class Green4 : public Green {
public:
    Green4(int setX, int setY, int setI, int setM) {
        x = setX;
        y = setY;
        i = setI;
        m = setM;
        switch (m) {
        case 0:
            j = VTLNOTE;
            break;
        case 1:
            j = KNOWNOTE;
            break;
        case 2:
            j = IDOLNOTE;
            break;
        case 3:
            j = KICKNOTE;
            break;
        case 4:
            j = CHELLYNOTE;
            break;
        case 5:
            j = GRAYNOTE;
            break;
        case 6:
            j = BLINGNOTE;
            break;
        }
    }
    void All() {
        if (live) {
            n++;
            if (CheckHitKey(KEY_INPUT_K)) {
                if (y > 500 - (20 + j * (i - 1)) && y < 650 - (20 + j * (i - 1)) && mo->kaburi4 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    mo->kaburi4 = true;
                    co->combo++;
                    co->good++;
                    co->good4 = 20;
                }
                else if (mo->kaburi1 == true && y < 550 && y > 600 - (20 + j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo++;
                        co->good++;
                    }
                }
                mo->kaburi4 = true;
            }
            if (CheckHitKey(KEY_INPUT_K) == 0) {
                if (y > 500 && y < 650 && mo->kaburi4 == true) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    live = false;
                    mo->kaburi4 = false;
                    co->combo++;
                    co->good++;
                    co->good4 = 20;
                }
                else if (mo->kaburi4 == true) {
                    mo->kaburi4 = false;
                }
                else if (mo->kaburi4 == false && y < 500 && y > 650 - (j * (i - 1))) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo = 0;
                        co->miss++;
                        co->r = 255;
                    }
                }
            }
            else if (y > 700) {
                live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        if (live) {
            if (co->demo == 1 && y > 570) {
                live = false;
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
            }
            DrawGraph(x, y, rang1, TRUE);
            DrawExtendGraph(x, y + 20, x + 79, y + 20 + (j * (i - 1)), rang2, false);
            DrawGraph(x, y + (j * (i - 1)), rang1, TRUE);
        }
        y = y + 13;
    }
};

class Red {
public:
    Moto* mo;
    Combo* co;

    int x, y, n, j, tall, wide;
    bool live;
    int tap;
    int neta;

    Red(int setX, int setY) {
        live = true;
        mo->kaburi1 = false;
        mo->kaburi2 = false;
        mo->kaburi3 = false;
        mo->kaburi4 = false;
        tap = LoadSoundMem("38.mp3");
        neta = LoadGraph("Red.png");
        GetGraphSize(neta, &wide, &tall);
    }
    void All() {
        if (live) {
            n++;
            if (CheckHitKey(KEY_INPUT_D)|| CheckHitKey(KEY_INPUT_F)|| CheckHitKey(KEY_INPUT_J)|| CheckHitKey(KEY_INPUT_K)) {
                if (y > 500 - (20 + tall) && y < 650 - (20 + tall) && mo->kaburi1 == false) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
                    mo->kaburi1 = true;
                    co->combo++;
                    co->good++;
                    co->good1 = 20;
                }
                else if (mo->kaburi1 == true && y < 550 && y > 600 - (20 + tall)) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo++;
                        co->good++;
                    }
                }
                mo->kaburi1 = true;
            }
            if (CheckHitKey(KEY_INPUT_D) == 0) {
                if (y > 500 && y < 650 && mo->kaburi1 == true) {
                    PlaySoundMem(tap, DX_PLAYTYPE_BACK);
     //               live = false;
                    mo->kaburi1 = false;
                    co->combo++;
                    co->good++;
                    co->good1 = 20;
                }
                else if (mo->kaburi1 == true) {
                    mo->kaburi1 = false;
                }
                else if (mo->kaburi1 == false && y < 500 && y > 650 - tall) {
                    if (n > j / 13) {
                        n = 1;
                        co->combo = 0;
                        co->miss++;
                        co->r = 255;
                    }
                }
            }
            else if (y > 700) {
   //             live = false;
                co->combo = 0;
                co->miss++;
                co->r = 255;
            }
        }
        if (live) {
            if (co->demo == 1 && y > 570) {
                live = false;
                PlaySoundMem(tap, DX_PLAYTYPE_BACK);
            }
            DrawGraph(x, y, neta, TRUE);
        }
        y = y + 13;
    }
};

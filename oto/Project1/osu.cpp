#include "DxLib.h"
#include "note.h"
#include "live.h"
#include "god.h"
#include "idol.h"
#include "chelly.h"
#include "kick.h"
#include "gray.h"
#include "bling.h"
#include "san.h"

#define SELECT_X 4
#define SELECT_Y 2
#define ZURE 0
#define WINDOW_X 640
#define WINDOW_Y 700

class GameControl {
public:
    Blue1* bl1[3000];
    Blue2* bl2[3000];
    Blue3* bl3[3000];
    Blue4* bl4[3000];
    Blue5* bl5[100];
    Blue6* bl6[100];
    Blue7* bl7[100];
    Blue8* bl8[100];
    Blue9* bl9[10];
    Green1* gr1[3000];
    Green2* gr2[3000];
    Green3* gr3[3000];
    Green4* gr4[3000];
    Red* re[5];
    Combo* co;
    Moto* mo;

    int state;
    int titlegh, cleargh, gamegh, howgh, checkgh, selectgh1, selectgh2;
    int FontHandle;
    int vtl, god, idol, chelly, kick, gray, bling, rgb;
    int black1, black2, black3, black4;
    int selectmusic[SELECT_Y][SELECT_X] = {};
    int trix=180, triy=70;
    int rightok, leftok, upok, downok;
    bool pushright, pushleft, pushup, pushdown, pushFlag;
    int selectx = 0, selecty = 0;
    int volume = 180;
    int longnote;
    bool check = false;

    bool PushRight() {
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
    bool PushLeft() {
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
    bool PushUp() {
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
    bool PushDown() {
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
    bool PushSpace() {
        if (CheckHitKey(KEY_INPUT_SPACE)) {
            if (!pushFlag) {
                pushFlag = true;
                return true;
            }
        }
        else {
            pushFlag = false;
        }
        return false;
    }
    //二回押されること防止
    int keyright() {
        rightok = 0;
        for (int i = 0; i < SELECT_Y; i++) {
            rightok = rightok + selectmusic[i][SELECT_X -1];
        }
        return rightok;
    }
    int keyleft() {
        leftok = 0;
        for (int i = 0; i < SELECT_Y; i++) {
            leftok = leftok + selectmusic[i][0];
        }
        return leftok;
    }
    int keyup() {
        upok = 0;
        for (int i = 0; i < SELECT_X; i++) {
            upok = upok + selectmusic[0][i];
        }
        return upok;
    }
    int keydown() {
        downok = 0;
        for (int i = 0; i < SELECT_X; i++) {
            downok = downok+selectmusic[SELECT_Y -1][i];
        }
        return downok;
    }
    //選択画面の端っこにきたかどうか判定
    void sousax() {
        for (int i = 0; i < SELECT_Y; i++) {
            for (int j = 0; j < SELECT_X; j++) {
                if (selectmusic[i][j])selectx = j;
            }
        }
    }
    void sousay() {
        for (int i = 0; i < SELECT_Y; i++) {
            for (int j = 0; j < SELECT_X; j++) {
                if (selectmusic[i][j])selecty = i;
            }
        }
        if (selecty == 1) {
            triy = 340;
        }
        if (selecty == 0) {
            triy = 70;
        }
    }
    //今カーソルがどこにいるか走査

    GameControl() {
        state = 2;
        titlegh = LoadGraph("Title.png");
        cleargh = LoadGraph("Clear.png");
        gamegh = LoadGraph("Game.png");
        selectgh1 = LoadGraph("Select1.png");
        selectgh2 = LoadGraph("Select2.png");
        howgh = LoadGraph("How.png");
        checkgh = LoadGraph("Check.png");
        FontHandle = CreateFontToHandle(NULL, 40, 3);
        vtl = LoadSoundMem("vtl.mp3");
        god = LoadSoundMem("god.mp3");
        kick = LoadSoundMem("Kick.mp3");
        idol = LoadSoundMem("idol.mp3");
        chelly = LoadSoundMem("chelly.mp3");
        gray = LoadSoundMem("gray.mp3");
        bling = LoadSoundMem("Bling.mp3");
        rgb = LoadSoundMem("sangensyoku.mp3");
    }

    ~GameControl() {
            for (int j = 0; j < 4; j++) {
                for (int i = 0; i < 3000; i++) {
                    switch (j) {
                    case 0:
                        delete bl1[i];
                        break;
                    case 1:
                        delete bl2[i];
                        break;
                    case 2:
                        delete bl3[i];
                        break;
                    case 3:
                        delete bl4[i];
                        break;
                    }
                }
            }
            if (selectmusic[0][0]) {
                delete bl5[0];
                delete bl5[1];
                delete bl6[0];
                delete bl7[0];
                delete bl7[1];
                delete bl8[0];
                delete bl8[1];
            }
            if (selectmusic[0][1]) {
                delete bl6[0];
                delete bl6[1];
                delete bl6[2];
                delete bl6[3];
                delete bl6[4];
                delete bl6[5];
                delete bl6[6];
                delete bl6[7];
                delete bl6[8];
                delete bl6[9];
                delete bl6[10];
                delete bl6[11];
                delete bl7[0];
                delete bl7[1];
                delete bl7[2];
                delete bl7[3];
                delete bl7[4];
                delete bl7[5];
                delete bl7[6];
                delete bl7[7];
                delete bl7[8];
                delete bl7[9];
                delete bl7[10];
                delete bl7[11];
                delete bl7[12];
                delete bl7[13];
                delete bl7[14];
                delete bl7[15];
                delete bl7[16];
                delete bl7[17];
                delete bl7[18];
                delete bl7[19];
            }
            if (selectmusic[1][0]) {
                delete bl5[0];
                delete bl6[0];
                delete bl6[1];
                delete bl7[0];
                delete bl7[1];
                delete bl8[0];
            }

        DeleteSoundMem(vtl);
        DeleteSoundMem(god);
        DeleteSoundMem(idol);
        DeleteSoundMem(chelly);
        DeleteSoundMem(kick);
        DeleteSoundMem(gray);
        DeleteSoundMem(bling);
        DeleteSoundMem(rgb);
        InitGraph();
        DeleteFontToHandle(FontHandle);
    }

    void Game() {
        if (CheckHitKey(KEY_INPUT_UP)) {
            volume = volume+10;
        }
        if (CheckHitKey(KEY_INPUT_DOWN)) {
            volume = volume-10;
        }
        DrawGraph(90, 0, gamegh, TRUE);
        if (CheckHitKey(KEY_INPUT_A)) {
            co->demo = 1;
        }
        if (CheckHitKey(KEY_INPUT_Q)) {
            co->demo = 0;
        }
        //A押したらオートモード　Q押したら戻る
        if (selectmusic[0][0]) {
            ChangeVolumeSoundMem(volume, vtl);
            for (int j = 0; j < LIVE_Y; j++) {
                for (int i = 0; i < LIVE_X; i++) {
                    if (live[i][j] == 1) {
                        switch (j) {
                        case 0:
                            bl1[i]->All();
                            break;
                        case 1:
                            bl2[i]->All();
                            break;
                        case 2:
                            bl3[i]->All();
                            break;
                        case 3:
                            bl4[i]->All();
                            break;
                        }
                    }
                    else if (live[i][j] > 0) {
                        switch (j) {
                        case 0:
                            gr1[i]->All();
                            break;
                        case 1:
                            gr2[i]->All();
                            break;
                        case 2:
                            gr3[i]->All();
                            break;
                        case 3:
                            gr4[i]->All();
                            break;
                        }
                    }
                }
            }
            bl5[0]->All();
            bl5[1]->All();
            bl6[0]->All();
            bl7[0]->All();
            bl7[1]->All();
            bl8[0]->All();
            bl8[1]->All();
            if (gr2[LIVE_X - 1]->live == false) {
                state = 3;
            }
        }
        else if (selectmusic[0][1]) {
            ChangeVolumeSoundMem(volume, god);
            for (int j = 0; j < GOD_Y; j++) {
                for (int i = 0; i < GOD_X; i++) {
                    if (knows[i][j] == 1) {
                        switch (j) {
                        case 0:
                            bl1[i]->All();
                            break;
                        case 1:
                            bl2[i]->All();
                            break;
                        case 2:
                            bl3[i]->All();
                            break;
                        case 3:
                            bl4[i]->All();
                            break;
                        }
                    }
                    else if (knows[i][j] > 0) {
                        switch (j) {
                        case 0:
                            gr1[i]->All();
                            break;
                        case 1:
                            gr2[i]->All();
                            break;
                        case 2:
                            gr3[i]->All();
                            break;
                        case 3:
                            gr4[i]->All();
                            break;
                        }
                    }
                }
            }
            bl6[0]->All();
            bl6[1]->All();
            bl6[2]->All();
            bl6[3]->All();
            bl6[4]->All();
            bl6[5]->All();
            bl6[6]->All();
            bl6[7]->All();
            bl6[8]->All();
            bl6[9]->All();
            bl6[10]->All();
            bl6[11]->All();
            bl7[0]->All();
            bl7[1]->All();
            bl7[2]->All();
            bl7[3]->All();
            bl7[4]->All();
            bl7[5]->All();
            bl7[6]->All();
            bl7[7]->All();
            bl7[8]->All();
            bl7[9]->All();
            bl7[10]->All();
            bl7[11]->All();
            bl7[12]->All();
            bl7[13]->All();
            bl7[14]->All();
            bl7[15]->All();
            bl7[16]->All();
            bl7[17]->All();
            bl7[18]->All();
            bl7[19]->All();
            if (bl1[GOD_X - 1]->live == false) {
                state = 3;
            }
        }
        else if (selectmusic[1][1]) {
            ChangeVolumeSoundMem(volume, idol);
            for (int j = 0; j < IDOL_Y; j++) {
                for (int i = 0; i < IDOL_X; i++) {
                    if (osi[i][j] == 1) {
                        switch (j) {
                        case 0:
                            bl1[i]->All();
                            break;
                        case 1:
                            bl2[i]->All();
                            break;
                        case 2:
                            bl3[i]->All();
                            break;
                        case 3:
                            bl4[i]->All();
                            break;
                        }
                    }
                    else if (osi[i][j] > 0) {
                        switch (j) {
                        case 0:
                            gr1[i]->All();
                            break;
                        case 1:
                            gr2[i]->All();
                            break;
                        case 2:
                            gr3[i]->All();
                            break;
                        case 3:
                            gr4[i]->All();
                            break;
                        }
                    }
                }
            }
            bl5[0]->All();
            bl6[0]->All();
            bl6[1]->All();
            bl7[0]->All();
            bl7[1]->All();
            bl8[0]->All();
            if (bl1[IDOL_X - 1]->live == false) {
                state = 3;
            }
        }
        else if (selectmusic[0][2]) {
            ChangeVolumeSoundMem(volume, chelly);
            for (int j = 0; j < CHELLY_Y; j++) {
                for (int i = 0; i < CHELLY_X; i++) {
                    if (blossom[i][j] == 1) {
                        switch (j) {
                        case 0:
                            bl1[i]->All();
                            break;
                        case 1:
                            bl2[i]->All();
                            break;
                        case 2:
                            bl3[i]->All();
                            break;
                        case 3:
                            bl4[i]->All();
                            break;
                        }
                    }
                    else if (blossom[i][j] > 0) {
                        switch (j) {
                        case 0:
                            gr1[i]->All();
                            break;
                        case 1:
                            gr2[i]->All();
                            break;
                        case 2:
                            gr3[i]->All();
                            break;
                        case 3:
                            gr4[i]->All();
                            break;
                        }
                    }
                }
            }
            if (bl2[CHELLY_X - 1]->live == false) {
                state = 3;
            }
        }
        else if (selectmusic[1][0]) {
            ChangeVolumeSoundMem(volume, kick);
            for (int j = 0; j < KICK_Y; j++) {
                for (int i = 0; i < KICK_X; i++) {
                    if (back[i][j] == 1) {
                        switch (j) {
                        case 0:
                            bl1[i]->All();
                            break;
                        case 1:
                            bl2[i]->All();
                            break;
                        case 2:
                            bl3[i]->All();
                            break;
                        case 3:
                            bl4[i]->All();
                            break;
                        }
                    }
                    else if (back[i][j] > 0) {
                        switch (j) {
                        case 0:
                            gr1[i]->All();
                            break;
                        case 1:
                            gr2[i]->All();
                            break;
                        case 2:
                            gr3[i]->All();
                            break;
                        case 3:
                            gr4[i]->All();
                            break;
                        }
                    }
                }
            }
            if (bl4[KICK_X - 1]->live == false) {
                state = 3;
            }
        }
        else if (selectmusic[0][3]) {
            ChangeVolumeSoundMem(volume, gray);
            for (int j = 0; j < GRAY_Y; j++) {
                for (int i = 0; i < GRAY_X; i++) {
                    if (hai[i][j] == 1) {
                        switch (j) {
                        case 0:
                            bl1[i]->All();
                            break;
                        case 1:
                            bl2[i]->All();
                            break;
                        case 2:
                            bl3[i]->All();
                            break;
                        case 3:
                            bl4[i]->All();
                            break;
                        }
                    }
                    else if (hai[i][j] > 0) {
                        switch (j) {
                        case 0:
                            gr1[i]->All();
                            break;
                        case 1:
                            gr2[i]->All();
                            break;
                        case 2:
                            gr3[i]->All();
                            break;
                        case 3:
                            gr4[i]->All();
                            break;
                        }
                    }
                }
            }
            if (bl1[GRAY_X - 1]->live == false) {
                state = 3;
            }
        }
        else if (selectmusic[1][2]) {
            ChangeVolumeSoundMem(volume, bling);
            for (int j = 0; j < BLING_Y; j++) {
                for (int i = 0; i < BLING_X; i++) {
                    if (bom[i][j] == 1) {
                        switch (j) {
                        case 0:
                            bl1[i]->All();
                            break;
                        case 1:
                            bl2[i]->All();
                            break;
                        case 2:
                            bl3[i]->All();
                            break;
                        case 3:
                            bl4[i]->All();
                            break;
                        }
                    }
                    else if (bom[i][j] > 0) {
                        switch (j) {
                        case 0:
                            gr1[i]->All();
                            break;
                        case 1:
                            gr2[i]->All();
                            break;
                        case 2:
                            gr3[i]->All();
                            break;
                        case 3:
                            gr4[i]->All();
                            break;
                        }
                    }
                }
            }
            if (bl2[BLING_X - 1]->live == false) {
                state = 3;
            }
        }
        else if (selectmusic[1][3]) {
        ChangeVolumeSoundMem(volume, rgb);
        for (int j = 0; j < RGB_Y; j++) {
            for (int i = 0; i < RGB_X; i++) {
                if (san[i][j] == 1) {
                    switch (j) {
                    case 0:
                        bl1[i]->All();
                        break;
                    case 1:
                        bl2[i]->All();
                        break;
                    case 2:
                        bl3[i]->All();
                        break;
                    case 3:
                        bl4[i]->All();
                        break;
                    }
                }
                else if (san[i][j] > 0) {
                    switch (j) {
                    case 0:
                        gr1[i]->All();
                        break;
                    case 1:
                        gr2[i]->All();
                        break;
                    case 2:
                        gr3[i]->All();
                        break;
                    case 3:
                        gr4[i]->All();
                        break;
                    }
                }
            }
        }
        if (bl2[RGB_X - 1]->live == false) {
            state = 3;
        }
        }


        DrawBox(0, 0, 130, WINDOW_Y, GetColor(128, 128, 128), true);
        DrawBox(530, 0, WINDOW_X, WINDOW_Y, GetColor(128, 128, 128), true);
        DrawBox(130, 570, 531, 620, GetColor(255, 0, 255), false);
        DrawLine(130, 0, 130, WINDOW_Y + 1, GetColor(255, 0, 255));
        DrawLine(230, 0, 230, WINDOW_Y + 1, GetColor(255, 0, 255));
        DrawLine(330, 0, 330, WINDOW_Y + 1, GetColor(255, 0, 255));
        DrawLine(430, 0, 430, WINDOW_Y + 1, GetColor(255, 0, 255));
        DrawLine(530, 0, 530, WINDOW_Y + 1, GetColor(255, 0, 255));
        co->View();
        //ノーツ以外の描画
        if (co->good1 > 0) {
            DrawStringToHandle(140, 480 + co->good1, "good", GetColor(255, 255, 255), FontHandle);
        }
        if (co->good2 > 0) {
            DrawStringToHandle(240, 480 + co->good2, "good", GetColor(255, 255, 255), FontHandle);
        }
        if (co->good3 > 0) {
            DrawStringToHandle(340, 480 + co->good3, "good", GetColor(255, 255, 255), FontHandle);
        }
        if (co->good4 > 0) {
            DrawStringToHandle(440, 480 + co->good4, "good", GetColor(255, 255, 255), FontHandle);
        }
        if (black1 > 0) {
            DrawBox(131, 621, 230, 700, GetColor(0, 0, 0), true);
        }
        if (black2 > 0) {
            DrawBox(231, 621, 330, 700, GetColor(0, 0, 0), true);
        }
        if (black3 > 0) {
            DrawBox(331, 621, 430, 700, GetColor(0, 0, 0), true);
        }
        if (black4 > 0) {
            DrawBox(431, 621, 530, 700, GetColor(0, 0, 0), true);
        }
        if (CheckHitKey(KEY_INPUT_D)) {
            black1 = 2;
        }
        if (CheckHitKey(KEY_INPUT_F)) {
            black2 = 2;
        }
        if (CheckHitKey(KEY_INPUT_J)) {
            black3 = 2;
        }
        if (CheckHitKey(KEY_INPUT_K)) {
            black4 = 2;
        }
        //good表示、ロングノーツの下見えなくするやつ
        if (co->demo == 1) {
            DrawStringToHandle(0, 0, "auto", GetColor(255, 255, 255), FontHandle);
        }
        black1--;
        black2--;
        black3--;
        black4--;
        if (CheckHitKey(KEY_INPUT_RETURN)) {
            state = 3;
        }
    }

    void GameClear() {
        check = false;
        DrawGraph(0, 0, cleargh, TRUE);
        if (PushSpace()) {
            StopSoundMem(vtl);
            StopSoundMem(god);
            StopSoundMem(idol);
            StopSoundMem(chelly);
            StopSoundMem(kick);
            StopSoundMem(gray);
            StopSoundMem(bling);
            StopSoundMem(rgb);
            state = 4;
        }
    }

    void Select() {
        if (CheckHitKey(KEY_INPUT_RETURN)) {
            check = true;
        }
        sousax();
        sousay();
        switch (selectx / 2) {
        case 0:
            DrawGraph(0, 0, selectgh1, TRUE);
            break;
        case 1:
            DrawGraph(0, 0, selectgh2, TRUE);
            break;
        }
        //ページで表示画像を変更
        if (PushDown() && keydown() == 0) {
            selectmusic[selecty + 1][selectx] = 1;
            selectmusic[selecty][selectx] = 0;
            StopSoundMem(vtl);
            StopSoundMem(god);
            StopSoundMem(idol);
            StopSoundMem(chelly);
            StopSoundMem(kick);
            StopSoundMem(gray);
            StopSoundMem(bling);
            if (selectmusic[0][0]) {
                SetCurrentPositionSoundMem(1730000, vtl);
                PlaySoundMem(vtl, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][1]) {
                SetCurrentPositionSoundMem(1603000, god);
                PlaySoundMem(god, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][0]) {
                SetCurrentPositionSoundMem(1250000, kick);
                PlaySoundMem(kick, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][1]) {
                SetCurrentPositionSoundMem(1385000, idol);
                PlaySoundMem(idol, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][2]) {
                SetCurrentPositionSoundMem(1371000, chelly);
                PlaySoundMem(chelly, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][3]) {
                SetCurrentPositionSoundMem(2850000, gray);
                PlaySoundMem(gray, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][2]) {
                SetCurrentPositionSoundMem(1497000, bling);
                PlaySoundMem(bling, DX_PLAYTYPE_BACK, false);
            }
        }
        if (PushUp() && keyup() == 0) {
            selectmusic[selecty - 1][selectx] = 1;
            selectmusic[selecty][selectx] = 0;
            StopSoundMem(vtl);
            StopSoundMem(god);
            StopSoundMem(idol);
            StopSoundMem(chelly);
            StopSoundMem(kick);
            StopSoundMem(gray);
            StopSoundMem(bling);
            if (selectmusic[0][0]) {
                SetCurrentPositionSoundMem(1730000, vtl);
                PlaySoundMem(vtl, DX_PLAYTYPE_BACK, false);

            }
            if (selectmusic[0][1]) {
                SetCurrentPositionSoundMem(1603000, god);
                PlaySoundMem(god, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][0]) {
                SetCurrentPositionSoundMem(1250000, kick);
                PlaySoundMem(kick, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][1]) {
                SetCurrentPositionSoundMem(1385000, idol);
                PlaySoundMem(idol, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][2]) {
                SetCurrentPositionSoundMem(1371000, chelly);
                PlaySoundMem(chelly, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][3]) {
                SetCurrentPositionSoundMem(2850000, gray);
                PlaySoundMem(gray, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][2]) {
                SetCurrentPositionSoundMem(1497000, bling);
                PlaySoundMem(bling, DX_PLAYTYPE_BACK, false);
            }
        }
        if (PushRight() && keyright() == 0) {
            selectmusic[selecty][selectx + 1] = 1;
            selectmusic[selecty][selectx] = 0;
            StopSoundMem(vtl);
            StopSoundMem(god);
            StopSoundMem(idol);
            StopSoundMem(chelly);
            StopSoundMem(kick);
            StopSoundMem(gray);
            StopSoundMem(bling);
            if (selectmusic[0][0]) {
                SetCurrentPositionSoundMem(1730000, vtl);
                PlaySoundMem(vtl, DX_PLAYTYPE_BACK, false);

            }
            if (selectmusic[0][1]) {
                SetCurrentPositionSoundMem(1603000, god);
                PlaySoundMem(god, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][0]) {
                SetCurrentPositionSoundMem(1250000, kick);
                PlaySoundMem(kick, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][1]) {
                SetCurrentPositionSoundMem(1385000, idol);
                PlaySoundMem(idol, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][2]) {
                SetCurrentPositionSoundMem(1371000, chelly);
                PlaySoundMem(chelly, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][3]) {
                SetCurrentPositionSoundMem(2850000, gray);
                PlaySoundMem(gray, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][2]) {
                SetCurrentPositionSoundMem(1497000, bling);
                PlaySoundMem(bling, DX_PLAYTYPE_BACK, false);
            }
        }
        if (PushLeft() && keyleft() == 0) {
            selectmusic[selecty][selectx - 1] = 1;
            selectmusic[selecty][selectx] = 0;
            StopSoundMem(vtl);
            StopSoundMem(god);
            StopSoundMem(idol);
            StopSoundMem(chelly);
            StopSoundMem(kick);
            StopSoundMem(gray);
            StopSoundMem(bling);
            if (selectmusic[0][0]) {
                SetCurrentPositionSoundMem(1730000, vtl);
                PlaySoundMem(vtl, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][1]) {
                SetCurrentPositionSoundMem(1603000, god);
                PlaySoundMem(god, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][0]) {
                SetCurrentPositionSoundMem(1250000, kick);
                PlaySoundMem(kick, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][1]) {
                SetCurrentPositionSoundMem(1385000, idol);
                PlaySoundMem(idol, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][2]) {
                SetCurrentPositionSoundMem(1371000, chelly);
                PlaySoundMem(chelly, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[0][3]) {
                SetCurrentPositionSoundMem(2850000, gray);
                PlaySoundMem(gray, DX_PLAYTYPE_BACK, false);
            }
            if (selectmusic[1][2]) {
                SetCurrentPositionSoundMem(1497000, bling);
                PlaySoundMem(bling, DX_PLAYTYPE_BACK, false);
            }
        }
        //ボタン押して端っこじゃなかったら移動
        if (check) {
            DrawBox(0, 0, 640, 700, GetColor(0, 0, 0), true);
            DrawGraph(0, 0, checkgh, TRUE);
            if (CheckHitKey(KEY_INPUT_SPACE)) {
                if (selectmusic[0][0]) {
                    longnote = 0;
                    for (int j = 0; j < LIVE_Y; j++) {
                        for (int i = 0; i < LIVE_X; i++) {
                            if (live[i][j] == 1) {
                                switch (j) {
                                case 0:
                                    bl1[i] = new Blue1(140, ((LIVE * 780) - (i * VTLNOTE) + VTLZ + ZURE));
                                    break;
                                case 1:
                                    bl2[i] = new Blue2(240, ((LIVE * 780) - (i * VTLNOTE) + VTLZ + ZURE));
                                    break;
                                case 2:
                                    bl3[i] = new Blue3(340, ((LIVE * 780) - (i * VTLNOTE) + VTLZ + ZURE));
                                    break;
                                case 3:
                                    bl4[i] = new Blue4(440, ((LIVE * 780) - (i * VTLNOTE) + VTLZ + ZURE));
                                    break;
                                }
                            }
                            else if (live[i][j] > 0) {
                                switch (j) {
                                case 0:
                                    gr1[i] = new Green1(140, ((LIVE * 780) - ((i + live[i][j] - 1) * VTLNOTE)) + VTLZ + ZURE, live[i][j], longnote);
                                    break;
                                case 1:
                                    gr2[i] = new Green2(240, ((LIVE * 780) - ((i + live[i][j] - 1) * VTLNOTE)) + VTLZ + ZURE, live[i][j], longnote);
                                    break;
                                case 2:
                                    gr3[i] = new Green3(340, ((LIVE * 780) - ((i + live[i][j] - 1) * VTLNOTE)) + VTLZ + ZURE, live[i][j], longnote);
                                    break;
                                case 3:
                                    gr4[i] = new Green4(440, ((LIVE * 780) - ((i + live[i][j] - 1) * VTLNOTE)) + VTLZ + ZURE, live[i][j], longnote);
                                    break;
                                }
                            }
                        }
                    }
                    bl5[1] = new Blue5(140, ((LIVE * 780) - (171.5 - 6) * VTLNOTE) + VTLZ + ZURE);
                    bl6[0] = new Blue6(240, ((LIVE * 780) - (587.5 - 6) * VTLNOTE) + VTLZ + ZURE);
                    bl5[0] = new Blue5(140, ((LIVE * 780) - (575.5 - 6) * VTLNOTE) + VTLZ + ZURE);
                    bl7[0] = new Blue7(340, ((LIVE * 780) - (571.5 - 6) * VTLNOTE) + VTLZ + ZURE);
                    bl7[1] = new Blue7(340, ((LIVE * 780) - (603.5 - 6) * VTLNOTE) + VTLZ + ZURE);
                    bl8[0] = new Blue8(440, ((LIVE * 780) - (591.5 - 6) * VTLNOTE) + VTLZ + ZURE);
                    bl8[1] = new Blue8(440, ((LIVE * 780) - (555.5 - 6) * VTLNOTE) + VTLZ + ZURE);
                    //                re[0] = new Red(440, ((LIVE * 780) - 1 * VTLNOTE) + vtlz + zure);
                    SetCurrentPositionSoundMem(24000 * LIVE, vtl);
                    PlaySoundMem(vtl, DX_PLAYTYPE_BACK, false);
                    state = 1;
                }
                else if (selectmusic[0][1]) {
                    longnote = 1;
                    for (int j = 0; j < GOD_Y; j++) {
                        for (int i = 0; i < GOD_X; i++) {
                            if (knows[i][j] == 1) {
                                switch (j) {
                                case 0:
                                    bl1[i] = new Blue1(140, ((KNOWS - 3.5) * 780) - (i * KNOWNOTE) + KNOWSZ + ZURE);
                                    break;
                                case 1:
                                    bl2[i] = new Blue2(240, ((KNOWS - 3.5) * 780) - (i * KNOWNOTE) + KNOWSZ + ZURE);
                                    break;
                                case 2:
                                    bl3[i] = new Blue3(340, ((KNOWS - 3.5) * 780) - (i * KNOWNOTE) + KNOWSZ + ZURE);
                                    break;
                                case 3:
                                    bl4[i] = new Blue4(440, ((KNOWS - 3.5) * 780) - (i * KNOWNOTE) + KNOWSZ + ZURE);
                                    break;
                                }
                            }
                            else if (knows[i][j] > 0) {
                                switch (j) {
                                case 0:
                                    gr1[i] = new Green1(140, ((KNOWS - 3.5) * 780) - ((i + knows[i][j] - 1) * KNOWNOTE) + KNOWSZ + ZURE, knows[i][j], longnote);
                                    break;
                                case 1:
                                    gr2[i] = new Green2(240, ((KNOWS - 3.5) * 780) - ((i + knows[i][j] - 1) * KNOWNOTE) + KNOWSZ + ZURE, knows[i][j], longnote);
                                    break;
                                case 2:
                                    gr3[i] = new Green3(340, ((KNOWS - 3.5) * 780) - ((i + knows[i][j] - 1) * KNOWNOTE) + KNOWSZ + ZURE, knows[i][j], longnote);
                                    break;
                                case 3:
                                    gr4[i] = new Green4(440, ((KNOWS - 3.5) * 780) - ((i + knows[i][j] - 1) * KNOWNOTE) + KNOWSZ + ZURE, knows[i][j], longnote);
                                    break;
                                }
                            }
                        }
                    }
                    bl6[0] = new Blue6(240, ((KNOWS - 3.5) * 780) - 96.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[0] = new Blue7(340, ((KNOWS - 3.5) * 780) - 98.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[1] = new Blue6(240, ((KNOWS - 3.5) * 780) - 100.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[1] = new Blue7(340, ((KNOWS - 3.5) * 780) - 102.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[2] = new Blue6(240, ((KNOWS - 3.5) * 780) - 104.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[2] = new Blue7(340, ((KNOWS - 3.5) * 780) - 106.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[3] = new Blue6(240, ((KNOWS - 3.5) * 780) - 108.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[3] = new Blue7(340, ((KNOWS - 3.5) * 780) - 110.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[4] = new Blue6(240, ((KNOWS - 3.5) * 780) - 114.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[4] = new Blue7(340, ((KNOWS - 3.5) * 780) - 112.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[5] = new Blue6(240, ((KNOWS - 3.5) * 780) - 118.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[5] = new Blue7(340, ((KNOWS - 3.5) * 780) - 116.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[6] = new Blue6(240, ((KNOWS - 3.5) * 780) - 122.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[6] = new Blue7(340, ((KNOWS - 3.5) * 780) - 120.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[7] = new Blue6(240, ((KNOWS - 3.5) * 780) - 126.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[7] = new Blue7(340, ((KNOWS - 3.5) * 780) - 124.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[8] = new Blue7(340, ((KNOWS - 3.5) * 780) - 224.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[9] = new Blue7(340, ((KNOWS - 3.5) * 780) - 226.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[10] = new Blue7(340, ((KNOWS - 3.5) * 780) - 228.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[11] = new Blue7(340, ((KNOWS - 3.5) * 780) - 230.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[12] = new Blue7(340, ((KNOWS - 3.5) * 780) - 232.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[13] = new Blue7(340, ((KNOWS - 3.5) * 780) - 234.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[14] = new Blue7(340, ((KNOWS - 3.5) * 780) - 236.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[15] = new Blue7(340, ((KNOWS - 3.5) * 780) - 238.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[8] = new Blue6(240, ((KNOWS - 3.5) * 780) - 1706.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[16] = new Blue7(340, ((KNOWS - 3.5) * 780) - 1708.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[9] = new Blue6(240, ((KNOWS - 3.5) * 780) - 1710.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[17] = new Blue7(340, ((KNOWS - 3.5) * 780) - 1712.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[10] = new Blue6(240, ((KNOWS - 3.5) * 780) - 1714.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[18] = new Blue7(340, ((KNOWS - 3.5) * 780) - 1716.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl6[11] = new Blue6(240, ((KNOWS - 3.5) * 780) - 1718.5 * KNOWNOTE + KNOWSZ + ZURE);
                    bl7[19] = new Blue7(340, ((KNOWS - 3.5) * 780) - 1720.5 * KNOWNOTE + KNOWSZ + ZURE);
                    SetCurrentPositionSoundMem(24000 * KNOWS, god);
                    PlaySoundMem(god, DX_PLAYTYPE_BACK, false);
                    state = 1;
                }
                else if (selectmusic[1][0]) {
                    longnote = 3;
                    for (int j = 0; j < KICK_Y; j++) {
                        for (int i = 0; i < KICK_X; i++) {
                            if (back[i][j] == 1) {
                                switch (j) {
                                case 0:
                                    bl1[i] = new Blue1(140, ((KICK * 780) - (i * KICKNOTE)) + KICKZ + ZURE);
                                    break;
                                case 1:
                                    bl2[i] = new Blue2(240, ((KICK * 780) - (i * KICKNOTE)) + KICKZ + ZURE);
                                    break;
                                case 2:
                                    bl3[i] = new Blue3(340, ((KICK * 780) - (i * KICKNOTE)) + KICKZ + ZURE);
                                    break;
                                case 3:
                                    bl4[i] = new Blue4(440, ((KICK * 780) - (i * KICKNOTE)) + KICKZ + ZURE);
                                    break;
                                }
                            }
                            else if (back[i][j] > 0) {
                                switch (j) {
                                case 0:
                                    gr1[i] = new Green1(140, ((KICK * 780) - ((i + back[i][j] - 1) * KICKNOTE)) + KICKZ + ZURE, back[i][j], longnote);
                                    break;
                                case 1:
                                    gr2[i] = new Green2(240, ((KICK * 780) - ((i + back[i][j] - 1) * KICKNOTE)) + KICKZ + ZURE, back[i][j], longnote);
                                    break;
                                case 2:
                                    gr3[i] = new Green3(340, ((KICK * 780) - ((i + back[i][j] - 1) * KICKNOTE)) + KICKZ + ZURE, back[i][j], longnote);
                                    break;
                                case 3:
                                    gr4[i] = new Green4(440, ((KICK * 780) - ((i + back[i][j] - 1) * KICKNOTE)) + KICKZ + ZURE, back[i][j], longnote);
                                    break;
                                }
                            }
                        }
                    }
                    SetCurrentPositionSoundMem(24000 * KICK, kick);
                    PlaySoundMem(kick, DX_PLAYTYPE_BACK, false);
                    state = 1;
                }
                else if (selectmusic[1][1]) {
                    longnote = 2;
                    for (int j = 0; j < IDOL_Y; j++) {
                        for (int i = 0; i < IDOL_X; i++) {
                            if (osi[i][j] == 1) {
                                switch (j) {
                                case 0:
                                    bl1[i] = new Blue1(140, ((IDOL * 780) - (i * IDOLNOTE)) + IDOLZ + ZURE);
                                    break;
                                case 1:
                                    bl2[i] = new Blue2(240, ((IDOL * 780) - (i * IDOLNOTE)) + IDOLZ + ZURE);
                                    break;
                                case 2:
                                    bl3[i] = new Blue3(340, ((IDOL * 780) - (i * IDOLNOTE)) + IDOLZ + ZURE);
                                    break;
                                case 3:
                                    bl4[i] = new Blue4(440, ((IDOL * 780) - (i * IDOLNOTE)) + IDOLZ + ZURE);
                                    break;
                                }
                            }
                            else if (osi[i][j] > 0) {
                                switch (j) {
                                case 0:
                                    gr1[i] = new Green1(140, ((IDOL * 780) - ((i + osi[i][j] - 1) * IDOLNOTE)) + IDOLZ + ZURE, osi[i][j], longnote);
                                    break;
                                case 1:
                                    gr2[i] = new Green2(240, ((IDOL * 780) - ((i + osi[i][j] - 1) * IDOLNOTE)) + IDOLZ + ZURE, osi[i][j], longnote);
                                    break;
                                case 2:
                                    gr3[i] = new Green3(340, ((IDOL * 780) - ((i + osi[i][j] - 1) * IDOLNOTE)) + IDOLZ + ZURE, osi[i][j], longnote);
                                    break;
                                case 3:
                                    gr4[i] = new Green4(440, ((IDOL * 780) - ((i + osi[i][j] - 1) * IDOLNOTE)) + IDOLZ + ZURE, osi[i][j], longnote);
                                    break;
                                }
                            }
                        }
                    }
                    bl5[0] = new Blue5(140, ((IDOL * 780) - (495.5 - 6) * IDOLNOTE) + IDOLZ + ZURE);
                    bl6[0] = new Blue6(240, ((IDOL * 780) - (167.5 - 6) * IDOLNOTE) + IDOLZ + ZURE);
                    bl6[1] = new Blue6(240, ((IDOL * 780) - (199.5 - 6) * IDOLNOTE) + IDOLZ + ZURE);
                    bl7[0] = new Blue7(340, ((IDOL * 780) - (175.5 - 6) * IDOLNOTE) + IDOLZ + ZURE);
                    bl7[1] = new Blue7(340, ((IDOL * 780) - (207.5 - 6) * IDOLNOTE) + IDOLZ + ZURE);
                    bl8[0] = new Blue8(440, ((IDOL * 780) - (495.5 - 6) * IDOLNOTE) + IDOLZ + ZURE);
                    SetCurrentPositionSoundMem(24000 * IDOL, idol);
                    PlaySoundMem(idol, DX_PLAYTYPE_BACK, false);
                    state = 1;
                }
                else if (selectmusic[0][2]) {
                    longnote = 4;
                    for (int j = 0; j < CHELLY_Y; j++) {
                        for (int i = 0; i < CHELLY_X; i++) {
                            if (blossom[i][j] == 1) {
                                switch (j) {
                                case 0:
                                    bl1[i] = new Blue1(140, ((CHELLY * 780) - (i * CHELLYNOTE)) + CHELLYZ + ZURE);
                                    break;
                                case 1:
                                    bl2[i] = new Blue2(240, ((CHELLY * 780) - (i * CHELLYNOTE)) + CHELLYZ + ZURE);
                                    break;
                                case 2:
                                    bl3[i] = new Blue3(340, ((CHELLY * 780) - (i * CHELLYNOTE)) + CHELLYZ + ZURE);
                                    break;
                                case 3:
                                    bl4[i] = new Blue4(440, ((CHELLY * 780) - (i * CHELLYNOTE)) + CHELLYZ + ZURE);
                                    break;
                                }
                            }
                            else if (blossom[i][j] > 0) {
                                switch (j) {
                                case 0:
                                    gr1[i] = new Green1(140, ((CHELLY * 780) - ((i + blossom[i][j] - 1) * CHELLYNOTE)) + CHELLYZ + ZURE, blossom[i][j], longnote);
                                    break;
                                case 1:
                                    gr2[i] = new Green2(240, ((CHELLY * 780) - ((i + blossom[i][j] - 1) * CHELLYNOTE)) + CHELLYZ + ZURE, blossom[i][j], longnote);
                                    break;
                                case 2:
                                    gr3[i] = new Green3(340, ((CHELLY * 780) - ((i + blossom[i][j] - 1) * CHELLYNOTE)) + CHELLYZ + ZURE, blossom[i][j], longnote);
                                    break;
                                case 3:
                                    gr4[i] = new Green4(440, ((CHELLY * 780) - ((i + blossom[i][j] - 1) * CHELLYNOTE)) + CHELLYZ + ZURE, blossom[i][j], longnote);
                                    break;
                                }
                            }
                        }
                    }
                    SetCurrentPositionSoundMem(24000 * CHELLY, chelly);
                    PlaySoundMem(chelly, DX_PLAYTYPE_BACK, false);
                    state = 1;
                }
                else if (selectmusic[0][3]) {
                    longnote = 5;
                    for (int j = 0; j < GRAY_Y; j++) {
                        for (int i = 0; i < GRAY_X; i++) {
                            if (hai[i][j] == 1) {
                                switch (j) {
                                case 0:
                                    bl1[i] = new Blue1(140, ((GRAY * 780) - (i * GRAYNOTE)) + GRAYZ + ZURE);
                                    break;
                                case 1:
                                    bl2[i] = new Blue2(240, ((GRAY * 780) - (i * GRAYNOTE)) + GRAYZ + ZURE);
                                    break;
                                case 2:
                                    bl3[i] = new Blue3(340, ((GRAY * 780) - (i * GRAYNOTE)) + GRAYZ + ZURE);
                                    break;
                                case 3:
                                    bl4[i] = new Blue4(440, ((GRAY * 780) - (i * GRAYNOTE)) + GRAYZ + ZURE);
                                    break;
                                }
                            }
                            else if (hai[i][j] > 0) {
                                switch (j) {
                                case 0:
                                    gr1[i] = new Green1(140, ((GRAY * 780) - ((i + hai[i][j] - 1) * GRAYNOTE)) + GRAYZ + ZURE, hai[i][j], longnote);
                                    break;
                                case 1:
                                    gr2[i] = new Green2(240, ((GRAY * 780) - ((i + hai[i][j] - 1) * GRAYNOTE)) + GRAYZ + ZURE, hai[i][j], longnote);
                                    break;
                                case 2:
                                    gr3[i] = new Green3(340, ((GRAY * 780) - ((i + hai[i][j] - 1) * GRAYNOTE)) + GRAYZ + ZURE, hai[i][j], longnote);
                                    break;
                                case 3:
                                    gr4[i] = new Green4(440, ((GRAY * 780) - ((i + hai[i][j] - 1) * GRAYNOTE)) + GRAYZ + ZURE, hai[i][j], longnote);
                                    break;
                                }
                            }
                        }
                    }
                    SetCurrentPositionSoundMem(24000 * GRAY, gray);
                    PlaySoundMem(gray, DX_PLAYTYPE_BACK, false);
                    state = 1;
                }
                else if (selectmusic[1][2]) {
                    longnote = 6;
                    for (int j = 0; j < BLING_Y; j++) {
                        for (int i = 0; i < BLING_X; i++) {
                            if (bom[i][j] == 1) {
                                switch (j) {
                                case 0:
                                    bl1[i] = new Blue1(140, ((BLING * 780) - (i * BLINGNOTE)) + BLINGZ + ZURE);
                                    break;
                                case 1:
                                    bl2[i] = new Blue2(240, ((BLING * 780) - (i * BLINGNOTE)) + BLINGZ + ZURE);
                                    break;
                                case 2:
                                    bl3[i] = new Blue3(340, ((BLING * 780) - (i * BLINGNOTE)) + BLINGZ + ZURE);
                                    break;
                                case 3:
                                    bl4[i] = new Blue4(440, ((BLING * 780) - (i * BLINGNOTE)) + BLINGZ + ZURE);
                                    break;
                                }
                            }
                            else if (bom[i][j] > 0) {
                                switch (j) {
                                case 0:
                                    gr1[i] = new Green1(140, ((BLING * 780) - ((i + bom[i][j] - 1) * BLINGNOTE)) + BLINGZ + ZURE, bom[i][j], longnote);
                                    break;
                                case 1:
                                    gr2[i] = new Green2(240, ((BLING * 780) - ((i + bom[i][j] - 1) * BLINGNOTE)) + BLINGZ + ZURE, bom[i][j], longnote);
                                    break;
                                case 2:
                                    gr3[i] = new Green3(340, ((BLING * 780) - ((i + bom[i][j] - 1) * BLINGNOTE)) + BLINGZ + ZURE, bom[i][j], longnote);
                                    break;
                                case 3:
                                    gr4[i] = new Green4(440, ((BLING * 780) - ((i + bom[i][j] - 1) * BLINGNOTE)) + BLINGZ + ZURE, bom[i][j], longnote);
                                    break;
                                }
                            }
                        }
                    }
                    SetCurrentPositionSoundMem(24000 * BLING, bling);
                    PlaySoundMem(bling, DX_PLAYTYPE_BACK, false);
                    state = 1;
                }
                else if (selectmusic[1][3]) {
                longnote = 7;
                for (int j = 0; j < RGB_Y; j++) {
                    for (int i = 0; i < RGB_X; i++) {
                        if (san[i][j] == 1) {
                            switch (j) {
                            case 0:
                                bl1[i] = new Blue1(140, ((RGB * 780) - (i * RGBNOTE)) + RGBZ + ZURE);
                                break;
                            case 1:
                                bl2[i] = new Blue2(240, ((RGB * 780) - (i * RGBNOTE)) + RGBZ + ZURE);
                                break;
                            case 2:
                                bl3[i] = new Blue3(340, ((RGB * 780) - (i * RGBNOTE)) + RGBZ + ZURE);
                                break;
                            case 3:
                                bl4[i] = new Blue4(440, ((RGB * 780) - (i * RGBNOTE)) + RGBZ + ZURE);
                                break;
                            }
                        }
                        else if (san[i][j] > 0) {
                            switch (j) {
                            case 0:
                                gr1[i] = new Green1(140, ((RGB * 780) - ((i + san[i][j] - 1) * RGBNOTE)) + RGBZ + ZURE, san[i][j], longnote);
                                break;
                            case 1:
                                gr2[i] = new Green2(240, ((RGB * 780) - ((i + san[i][j] - 1) * RGBNOTE)) + RGBZ + ZURE, san[i][j], longnote);
                                break;
                            case 2:
                                gr3[i] = new Green3(340, ((RGB * 780) - ((i + san[i][j] - 1) * RGBNOTE)) + RGBZ + ZURE, san[i][j], longnote);
                                break;
                            case 3:
                                gr4[i] = new Green4(440, ((RGB * 780) - ((i + san[i][j] - 1) * RGBNOTE)) + RGBZ + ZURE, san[i][j], longnote);
                                break;
                            }
                        }
                    }
                }
                SetCurrentPositionSoundMem(24000 * RGB, rgb);
                PlaySoundMem(rgb, DX_PLAYTYPE_BACK, false);
                state = 1;
                }

            }
        }
        //enter押したら曲開始
        else {
            switch (selectx % 2) {
            case 0:
                DrawTriangle(trix, triy, trix - 10, triy - 10, trix + 10, triy - 10, GetColor(255, 255, 255), true);
                break;
            case 1:
                DrawTriangle(trix + 300, triy, trix - 10 + 300, triy - 10, trix + 10 + 300, triy - 10, GetColor(255, 255, 255), true);
                break;
            }
        }
        //矢印のx方向管理
    }

    void Result() {
        DrawFormatString(0, 50, GetColor(255, 255, 255), "Result");
        DrawFormatString(0, 250, GetColor(255, 255, 255), "good %d", co->good);
        DrawFormatString(0, 450, GetColor(255, 255, 255), "miss %d", co->miss);
        DrawFormatString(300, 600, GetColor(255, 255, 255), "push Space");
        if (PushSpace()) {
            state = 2;
            co->good = 0;
            co->miss = 0;
            co->combo = 0;
        }
    }

    void Title() {
        DrawGraph(0, 0, titlegh, TRUE);
        if (PushSpace()) {
            state = 6;
        }
        if (CheckHitKey(KEY_INPUT_P)) {
            WaitTimer(500);
            state = 7;
            bl9[1] = new Blue9(340, 338);
        }
    }

    void How() {
            DrawGraph(0, 170, howgh, TRUE);
        if (PushSpace()) {
            state = 5;
            for (int i = 0; i < 2;i++) {
                for (int j = 0; j < 4;j++) {
                    selectmusic[i][j] = 0;
                }
            }
            selectmusic[0][0] = 1;
            SetCurrentPositionSoundMem(1730000, vtl);
            PlaySoundMem(vtl, DX_PLAYTYPE_BACK, false);
        }
    }

    void Speed() {
        //DrawGraph(90, 0, gamegh, TRUE);
        //DrawBox(0, 0, 130, WINDOW_Y, GetColor(128, 128, 128), true);
        //DrawBox(530, 0, WINDOW_X, WINDOW_Y, GetColor(128, 128, 128), true);
        //DrawBox(130, 570, 531, 620, GetColor(255, 0, 255), false);
        //DrawLine(130, 0, 130, WINDOW_Y + 1, GetColor(255, 0, 255));
        //DrawLine(230, 0, 230, WINDOW_Y + 1, GetColor(255, 0, 255));
        //DrawLine(330, 0, 330, WINDOW_Y + 1, GetColor(255, 0, 255));
        //DrawLine(430, 0, 430, WINDOW_Y + 1, GetColor(255, 0, 255));
        //DrawLine(530, 0, 530, WINDOW_Y + 1, GetColor(255, 0, 255));
        //bl9[1]->All();
        //if (CheckHitKey(KEY_INPUT_UP) && mo->speed < 6) {
        //    mo->speed++;
        //}
        //if (CheckHitKey(KEY_INPUT_DOWN) && mo->speed > 1) {
        //    mo->speed--;
        //}
        //if (CheckHitKey(KEY_INPUT_RETURN)) {
        //    state = 2;
        //}
    }

    void All() {
        if (state == 1)Game();
        if (state == 2)Title();
        if (state == 3)GameClear();
        if (state == 4)Result();
        if (state == 5)Select();
        if (state == 6)How();
        if (state == 7)Speed();
    }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    ChangeWindowMode(TRUE);
    SetGraphMode(WINDOW_X, WINDOW_Y, 32);
    if (DxLib_Init() == -1)return -1;
    SetDrawScreen(DX_SCREEN_BACK);
    GameControl* ga = new GameControl();

    while (ProcessMessage() != -1) {
        int startTime = GetNowCount();
        ScreenFlip();
        ClearDrawScreen();

        ga->All();

        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
        int endTime = GetNowCount();
        WaitTimer((1000 / 60) - (endTime - startTime));
    }
    delete ga;
    DxLib_End();
    return 0;
}
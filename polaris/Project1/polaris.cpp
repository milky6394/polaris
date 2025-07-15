#include "DxLib.h"
#include "player.h"
#include "menu.h"
#include "event.h"

#define WINDOW_X 1280
#define WINDOW_Y 720

class GameControl {
public:
    Player* pl = new Player();
    MapControler* mp = new MapControler();
    MenuControler* me = new MenuControler();
    EventControler* ev = new EventControler();
    bool flag;
    bool pushx;
    GameControl() {
        flag = true;
        pushx = false;
    }

    ~GameControl() {
  
    }
    bool toggle() {
        flag = !flag;
        return !flag;
    }
    //Xキーを押すたびに真偽が入れ替わる関数

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
    //Xキー1回押しの関数

    void All() {
        mp->MapPracer();
        if (Button_X()) {
            toggle();
        }
        if (flag) {
            pl->PlayerAll();
        }
        else {
            me->MenuDraw();
        }
        pl->PlayerDraw();
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
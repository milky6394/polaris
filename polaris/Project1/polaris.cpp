#include "DxLib.h"
#include "player.h"
#include "map.h"



#define WINDOW_X 1280
#define WINDOW_Y 720

class GameControl {
public:
    Player* pl = new Player();
    Map* mp = new Map();

    GameControl() {

    }

    ~GameControl() {
  
    }

    void All() {
        pl->PlayerMove();
        mp->MapPracer();
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
#include "DxLib.h"
#include "player.h"

#define WINDOW_X 1280
#define WINDOW_Y 720

class GameControl {
public:
    Player* pl = new Player();
    
    int gamestate;
    int bright;

    GameControl() {
        gamestate = 1;
        bright = 255;

    }

    ~GameControl() {
        delete pl;
        InitGraph();
    }

    bool DrawClear(int a) {
        SetDrawBright(bright--, bright--, bright--);
        if (bright < -30) {
            gamestate = a;
            bright = 255;
            return true;
        }
        else {
            bright--;
            return false;
        }

    }

    bool GameEnd() {
        return pl->PlEnd();
    }
    //gameendÇplayerÇ©ÇÁéÛÇØéÊÇÈä÷êî

    void All() {
        if (gamestate == 1) {
            pl->StringKey(1, 8, 2);
            gamestate = 2;
        }
        else if (gamestate == 2) {
            pl->PlayerAll();
        }
        else if (gamestate == 3) {
            if (DrawClear(4)) {
                pl->StringKey(9, 12, 2);
            }
        }
        else if (gamestate == 4) {
            pl->PlayerAll();
        }
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

        if (ga->GameEnd() == true)break;//gameendÇ™trueÇ…Ç»Ç¡ÇΩÇÁèIóπ
        int endTime = GetNowCount();
        WaitTimer((1000 / 60) - (endTime - startTime));
    }
    delete ga;
    DxLib_End();
    return 0;
}
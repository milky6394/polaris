#include "DxLib.h"
#include "player.h"
#include "conversation.h"

#define WINDOW_X 1280
#define WINDOW_Y 720

class GameControl {
public:
    Player* pl = new Player();
    ConvControler* cv = new ConvControler();
    
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

    void DrawClear(int a) {
        SetDrawBright(bright, bright, bright);
        if (bright <= 0) {
            gamestate = a;
        }
        else {
            bright-=2;
        }
    }

    void DrawBrighter() {
        SetDrawBright(bright, bright, bright);
        if (bright <= 255) {
            bright+=2;
        }
    }

    bool GameEnd() {
        return pl->PlEnd();
    }
    //gameendÇplayerÇ©ÇÁéÛÇØéÊÇÈä÷êî

    void All() {
        switch (gamestate) {
            case 0:
                break;
            case 1:
                cv->StringKey(1, 8);
                gamestate = 2;
                break;
            case 2:
                cv->StringAll();
                if (cv->draw == 0) {
                    DrawClear(3);
                }
                break;
            case 3:
                DrawBrighter();
                pl->PlayerAll();
                break;
            case 4:
                DrawClear(5);
                break;
            case 5:
                pl->StringKey(9, 12);
                break;
            case 6:
                pl->PlayerAll();
                break;
            case 7:
                break;
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
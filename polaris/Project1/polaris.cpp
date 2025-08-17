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
        if (bright >= 0) {
            bright -= 2;
        }
        else {
            gamestate = a;
        }
    }

    void DrawBrighter() {
        if (bright <= 255) {
            bright+=2;
        }
    }

    bool GameEnd() {
        return pl->PlEnd();
    }
    //gameend‚ğplayer‚©‚çó‚¯æ‚éŠÖ”

    void All() {
        SetDrawBright(bright, bright, bright);
        switch (gamestate) {
            case 0:
                break;
            case 1:
                cv->StringKey(1, 8, 300, 600);
                bright = 255;
                gamestate = 2;
                break;
            case 2:
                cv->StringAll();
                if (cv->draw <= 0) {
                    DrawClear(3);
                }
                break;
            case 3:
                cv->StringKey(10, 15, 300, 300);
                bright = 255;
                gamestate = 4;
                break;
            case 4:
                cv->StringAll();
                if (cv->draw <= 0) {
                    DrawClear(5);
                }
                break;
            case 5:
                DrawBrighter();
                pl->PlayerAll();
                break;
            case 6:
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

        if (ga->GameEnd() == true)break;//gameend‚ªtrue‚É‚È‚Á‚½‚çI—¹
        int endTime = GetNowCount();
        WaitTimer((1000 / 60) - (endTime - startTime));
    }
    delete ga;
    DxLib_End();
    return 0;
}
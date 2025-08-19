#include "DxLib.h"
#include "player.h"
#include "conversation.h"

#define WINDOW_X 1280
#define WINDOW_Y 720
#define STARTSCENE 5

class GameControl {
public:
    Player* pl = new Player();
    ConvControler* cv = new ConvControler();
    
    int gamestate;//ゲームシーンを制御する変数
    int bright;//画面の明るさを制御する変数

    GameControl() {
        gamestate = STARTSCENE;
        bright = 255;
    }

    ~GameControl() {
        delete pl;
        delete cv;
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
    //画面がだんだん暗くなる関数。完全に暗くなった後、引数のシーンに遷移する

    bool DrawBrighter() {
        if (bright <= 255) {
            bright+=2;
            return false;
        }
        else {
            return true;
        }
    }
    //画面がだんだん明るくなる関数

    bool GameEnd() {
        return pl->PlEnd();
    }
    //gameendをplayerから受け取る関数

    void All() {
        SetDrawBright(bright, bright, bright);
        switch (gamestate) {
            case 0:
                cv->StringKey(1, 8, 300, 600, 1);
                bright = 0;
                gamestate = 1;
                break;
            case 1:
                if (DrawBrighter()) {
                    gamestate = 2;
                }
                cv->PersonDraw();
                break;
            case 2:
                cv->StringAll();
                if (cv->draw <= 0) {
                    DrawClear(3);
                }
                break;
            case 3:
                cv->StringKey(10, 15, 300, 300,0);
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
                if (DrawBrighter()) {
                    pl->PlayerAll();
                }
                else {
                    pl->GameDraw();
                }
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

        if (ga->GameEnd() == true)break;//gameendがtrueになったら終了
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;//Escapeを押すと終了
        int endTime = GetNowCount();
        WaitTimer((1000 / 60) - (endTime - startTime));
    }
    delete ga;
    DxLib_End();
    return 0;
}
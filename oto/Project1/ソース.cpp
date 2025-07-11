#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    int x = 320, y = 240;//new
    int vecX = 0, vecY = 0;

    int px = 320, py = 400;

    bool live[5];//new

    live[0] = true;
    live[1] = true;
    live[2] = true;
    live[3] = true;
    live[4] = true;
    //new‚±‚±‚Ü‚Å

    while (ProcessMessage() != -1) {
        int startTime = GetNowCount();
        ScreenFlip();
        ClearDrawScreen();

        DrawCircle(x, y, 20, GetColor(255, 255, 255), TRUE);
        DrawBox(px, py, px + 60, py + 20, GetColor(255, 255, 255), TRUE);

        for (int i = 0; i < 5; i++) {//new
            if (live[i]) {
                DrawBox(80 + i * 100, 100, 80 + (i + 1) * 100 - 10, 140, GetColor(255, 255, 255), TRUE);
                if (x > 80 + i * 100 && x < 80 + (i + 1) * 100 - 10 && y > 100 && y < 140) {
                    live[i] = false;
                    vecX *= -1;
                    vecY *= -1;
                }
            }
        }

        if (vecX != 0 && vecX != 0) {
            if (x > 640)vecX = -1;
            if (x < 0)vecX = 1;
            if (y < 0)vecY = 1;
            if (x > px && x<px + 60 && y > py)vecY = -1;
            if (y > 480) {
                x = 320;
                y = 240;
                vecX = 0;
                vecY = 0;
                for (int i = 0; i < 5; i++) {
                    live[i] = true;
                }
            }
        }
        else {
            DrawFormatString(260, 160, GetColor(255, 255, 255), "PUSH SPACE");
            if (CheckHitKey(KEY_INPUT_SPACE)) {
                vecX = 1;
                vecY = 1;
                for (int i = 0; i < 5; i++)live[i] = true;//new
            }
        }
        if (!live[0] && !live[1] && !live[2] && !live[3] && !live[4]) {//new
            DrawFormatString(260, 120, GetColor(255, 255, 255), "GAME CLEAR!");
            x = 320;
            y = 240;
            vecX = 0;
            vecY = 0;
        }

        x += 5 * vecX;
        y += 5 * vecY;

        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            px += 10;
        }
        if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
            px -= 10;
        }

        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
        int endTime = GetNowCount();
        WaitTimer(1000 / 60 - (endTime - startTime));
    }
    DxLib_End();
    return 0;
}
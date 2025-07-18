#include "DxLib.h"
#include "item.h"

class EventControler {
public:
    int x, y;
    int st;
    char String[1000] = { "¡“ú‚Ì“V‹C‚Í“Ü‚è‚È‚ñ‚¾‚¯‚Ç‚±‚Á‚©‚çæ‚Í‚Ç‚ñ‚ÈŠ´‚¶‚ÉŒ©‚¦‚é‚Ì‚©‚ª‹C‚É‚È‚é‚Ì‚Å‚½‚­‚³‚ñ‘‚¢‚Ä‚İ‚Ü‚·" };

    char NowSt[1000] = {};

    EventControler() {
        x = 1000;
        y = 650;
        st = 0;
    }

    void StringReset() {
        for (int i = 0; i < 1000; i++) {
            NowSt[i] = {};
        }
    }

    void EventDraw() {
        NowSt[st] = String[st];
        if (st < 999) {
            st++;
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", NowSt);
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }
};
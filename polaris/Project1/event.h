#include "DxLib.h"

class EventControler {
public:
    int x, y;
    int st;
    char String[100] = { "�����̓V�C�͓܂�Ȃ񂾂��ǂ��������͂ǂ�Ȋ����Ɍ�����̂����C�ɂȂ�̂ł������񏑂��Ă݂܂�" };

    char NowSt[100] = {};

    EventControler() {
        x = 1000;
        y = 650;
        st = 0;
    }

    void StringReset() {
        for (int i = 0; i < 100; i++) {
            NowSt[i] = {};
        }
    }

    void EventDraw() {
        NowSt[st] = String[st];
        if (st < 99) {
            st++;
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), " %s ", NowSt);
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }
};
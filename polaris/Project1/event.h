#include "DxLib.h"
#include "item.h"

class EventControler {
public:
    ItemManager* im = new ItemManager();

    int x, y;
    int st;
    char String[1000] = {};

    EventControler() {
        x = 1000;
        y = 650;
        st = 0;
    }

    void StringReset() {
        for (int i = 0; i < 1000; i++) {
            String[i] = {};
        }
    }

    void EventDraw(int a) {
        String[st] = im->ItemString[a][st];
        if (st < 999) {
            st++;
        }
        DrawFormatString(300, 600, GetColor(255, 255, 255), "%s", String);
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }
};
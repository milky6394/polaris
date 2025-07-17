#include "DxLib.h"

class EventControler {
public:
    int x, y;

    EventControler() {
        x = 1000;
        y = 600;
    }

    void EventDraw() {
        DrawTriangle(x, y, x + 10, y - 10, x - 10, y - 10, GetColor(255, 255, 255), true);
    }
};
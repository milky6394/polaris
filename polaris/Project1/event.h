#include "DxLib.h"

class EventControler {
public:
    int x, y;
    bool pushz = false;

    EventControler() {
        x = 1000;
        y = 400;
    }

    bool Button_Z() {
        if (CheckHitKey(KEY_INPUT_Z)) {
            if (!pushz) {
                pushz = true;
                return true;
            }
        }
        else {
            pushz = false;
        }
        return false;
    }
    //�L�[1�񉟂��̊֐�

    void EventDraw() {

        DrawTriangle(x, y, x + 10, y - 10, x + 10, y - 10, GetColor(255, 255, 255), true);
    }
};
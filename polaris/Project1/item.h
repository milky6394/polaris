#include "DxLib.h"

class ItemManager {
public:
    int graph;
    char ItemString[300][1000] = {
        { "test" },
        { "���Ă���̓A�C�e��1�ł�" },
        { "���Ă��Ă���̓A�C�e��2�ł�" },
        { "�����̂��߂�ǂ������Ȃ��Ă��܂����A�C�e��3�ł�" },
        { "���������ł���A�C�e��4�ł�" },
        { "������5" },
        { "������6" },
        { "������7" },
    };


    ItemManager() {
        graph = LoadGraph("cardkey.png");
    }

    void All() {
        DrawGraph(100, 100, graph, false);
    }
};
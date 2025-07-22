#include "DxLib.h"

class ItemManager {
public:
    int graph;
    char ItemString[300][1000] = {
        { "test" },
        { "さてこれはアイテム1です" },
        { "さてさてこれはアイテム2です" },
        { "書くのがめんどくさくなってきましたアイテム3です" },
        { "もういいでしょアイテム4です" },
        { "あきた5" },
        { "あきた6" },
        { "あきた7" },
    };


    ItemManager() {
        graph = LoadGraph("cardkey.png");
    }

    void All() {
        DrawGraph(100, 100, graph, false);
    }
};
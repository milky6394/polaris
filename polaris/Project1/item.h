#pragma once
#include "DxLib.h"

class ItemManager {
public:
    int graph[300] = {};
    char ItemString[300][1000] = {
        { "test" },
        { "部屋のカードキー。\n消費することでどこかの部屋に入ることができる。" },
        { "さてさてこれはアイテム2です" },
        { "書くのがめんどくさくなってきましたアイテム3です" },
        { "もういいでしょアイテム4です" },
        { "あきた5" },
        { "あきた6" },
        { "あきた7" },
    };


    ItemManager() {
        graph[1] = LoadGraph("../../Images/Items/cardkey.png");
    }

};
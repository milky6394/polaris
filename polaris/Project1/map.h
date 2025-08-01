#pragma once
#include "DxLib.h"
#include <string>

#define MAPS 6//mapの数を表すマクロ

class MapControler {
public:
    int mapnumber;

    int map[MAPS][2][9][9] = {};
    /*
    mapを格納する配列
    1層目：playerが動ける範囲指定
    2層目：そのマスでの特殊操作
    特殊操作
    1~999：そのIDの会話イベントを開始
    1001~1999：1000を引いたIDのアイテムを取得
    2001~2999：2000を引いたIDの選択肢を表示
    10000~：10000を引いたIDのmapへ飛ぶ。下二桁がxyの座標を表す
    */

    MapControler() {
        mapnumber = 0;
        int c = 0;
        int retu, gyou;
        bool eofFlag;
        FILE* fp = nullptr;
        for (int i = 0; i < MAPS; i++) {
            std::string filename ="../../Maps/map"+std::to_string(i+1)+".csv";
            fopen_s(&fp, filename.c_str(), "r");
            if (fp == nullptr) {
                DebugBreak();  // ファイルが開けなかった
            }
            retu = 0;
            gyou = 0;
            char buf[10];//文字列を格納する
            memset(buf, 0, sizeof(buf));
            eofFlag = false;
            while (true) {
                while (true) {
                    if (fp != nullptr) {
                        c = fgetc(fp);
                    }
                    if (c == EOF) {
                        eofFlag = true;//EndOfFileの時にループを抜ける
                        break;
                    }
                    if (c != ',' && c != '\n') {
                        char oneChar[2] = { (char)c, '\0' };
                        strcat_s(buf, sizeof(buf), oneChar);
                    }
                    else {
                        int num = (int)strtol(buf, nullptr, 10);
                        map[i][0][gyou][retu] = num;//num番目のチップ画像のハンドルを取得
                        memset(buf, 0, sizeof(buf));//bufをリセット
                        break;//区切りか改行ならループを抜ける
                    }
                }
                //1セル分のループを抜けたら
                if (eofFlag)break;
                if (c == ',')retu++;
                if (c == '\n') {//改行だったら行を増やす
                    gyou++;
                    retu = 0;
                }
            }
            if (fp != nullptr) {
                fclose(fp);
            }
        }
        for (int i = 0; i < MAPS; i++) {
            std::string filename = "../../Maps/mapaction" + std::to_string(i + 1) + ".csv";
            fopen_s(&fp, filename.c_str(), "r");
            if (fp == nullptr) {
                DebugBreak();  // ファイルが開けなかった
            }
            retu = 0;
            gyou = 0;
            char buf[10];//文字列を格納する
            memset(buf, 0, sizeof(buf));
            eofFlag = false;
            while (true) {
                while (true) {
                    if (fp != nullptr) {
                        c = fgetc(fp);
                    }
                    if (c == EOF) {
                        eofFlag = true;//EndOfFileの時にループを抜ける
                        break;
                    }
                    if (c != ',' && c != '\n') {
                        char oneChar[2] = { (char)c, '\0' };
                        strcat_s(buf, sizeof(buf), oneChar);
                    }
                    else {
                        int num = (int)strtol(buf, nullptr, 10);
                        map[i][1][gyou][retu] = num;//num番目のチップ画像のハンドルを取得
                        memset(buf, 0, sizeof(buf));//bufをリセット
                        break;//区切りか改行ならループを抜ける
                    }
                }
                //1セル分のループを抜けたら
                if (eofFlag)break;
                if (c == ',')retu++;
                if (c == '\n') {//改行だったら行を増やす
                    gyou++;
                    retu = 0;
                }
            }
            if (fp != nullptr) {
                fclose(fp);
            }
        }
    }

    int Mappixel_X(int x) {
        return 440 + (x * 50);
    }
    int Mappixel_Y(int y) {
        return 110 + (y * 50);
    }
    //引数に与えた配列の座標を画面内座標に変換する関数

    void MapPracer() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (map[mapnumber][0][j][i] != 10) {
                    DrawCircle(Mappixel_X(i), Mappixel_Y(j), 10, GetColor(255, 255, 255), TRUE);
                }
            }
        }
    }
    //mapを描画する関数
};

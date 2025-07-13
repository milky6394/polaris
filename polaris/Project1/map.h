#include "DxLib.h"

class MapControler {
public:
    int map[10][10] = 
    { 
    {9,8,8,8,8,8,8,8,8,7},
    {2,1,1,1,1,1,1,1,1,6},
    {2,1,1,1,1,1,1,1,1,6},
    {2,1,1,1,1,1,1,1,1,6},
    {2,1,1,1,1,1,1,1,1,6},
    {2,1,1,1,1,1,1,1,1,6},
    {2,1,1,1,1,1,1,1,1,6},
    {2,1,1,1,1,1,1,1,1,6},
    {2,1,1,1,1,1,1,1,1,6},
    {3,4,4,4,4,4,4,4,4,5}};//map���i�[����z��

    MapControler() {

    }

    int Mappixel_X(int x) {
        return 390 + (x * 50);
    }
    int Mappixel_Y(int y) {
        return 110 + (y * 50);
    }
    //�����ɗ^�����z��̍��W����ʓ����W�ɕϊ�����֐�

    void MapPracer() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] != 0) {
                    DrawCircle(Mappixel_X(i), Mappixel_Y(j), 10, GetColor(255, 255, 255), TRUE);
                }
            }
        }
    }
    //map��`�悷��֐�
};

#include "DxLib.h"
#include "Keyboard.h"
#include "SceneMgr.h"
#include "Map.h"
#include <math.h>
class Player
{
public:
	int P_x, P_y,P_image;//初期値と画像変数
    int P_Animation;//アニメーションの速さ
	int muki;//1上2左3下4右
    bool Key;//キーが押されているかの判定
};
Player player1;

int image[16];//画像の配列


int x = 0;

int count = 0;

void Player_Initialize() 
{
    Map_Initialize();
	player1.P_x = 320;
	player1.P_y = 240;
    player1.P_Animation = 1;
	player1.muki = 2;
    player1.Key = false;
	LoadDivGraph("画像/キャラクタ10.png", 16, 4, 4, 32, 32, image);

}

void Player_Update() 
{
    player1.Key = false;
	if (Keyboard_Get(KEY_INPUT_A) > 0) {
		player1.muki = 1;
        player1.Key = true;
		
	}
	if (Keyboard_Get(KEY_INPUT_D) > 0) {
		player1.muki = 3;
        player1.Key = true;
		
	}
    if (Keyboard_Get(KEY_INPUT_W) > 0) {
        player1.muki = 0;
        player1.Key = true;
        
    }
    if (Keyboard_Get(KEY_INPUT_S) > 0) {
        player1.muki = 2;
        player1.Key = true;
        
    }
    
    
    
    for (int i = 0; i < player1.P_Animation; i++)
    {
        count++;
    }
    player1.P_image = image[(count % 32) / 8 + player1.muki * 4];
    
    
}

void Player_Draw()
{
    Map_Draw();
	//playerの描画

    DrawGraph(player1.P_x, player1.P_y, player1.P_image, TRUE);
    
	
}

void Player_Finalize()
{

}
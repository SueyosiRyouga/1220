#include "DxLib.h"
#include "Keyboard.h"
#include "SceneMgr.h"
#include "Cave.h"
#include <math.h>
class Meadow
{
public:
	int M_x, M_y;//草原を動かす変数
	int S_x, S_y;//海を動かす変数
	int MAP_x, MAP_y;//マップの広さ
	int ground;
	
	
};
Meadow meadow1;


int horizontalKey = 0;//ADキーの入力チェック1左2右
int verticalKey = 0;//WSキーの入力チェック1上2下
int Map_Limit_x, Map_Limit_y;//マップの上限
int a;
int M_ground[192];
int M_Sea[40];

// 初期化をする
void Map_Initialize()
{
	Cave_Initialize();
	meadow1.M_x = 0;
	meadow1.M_y = 0;
	meadow1.MAP_x = 30;
	meadow1.MAP_y = 30;
	meadow1.S_x = meadow1.M_x + 16 * meadow1.MAP_x + 16;
	meadow1.S_y = 0;
	meadow1.ground;
	LoadDivGraph("画像/海.png", 40, 8, 5, 16, 16, M_Sea);
	LoadDivGraph("画像/草原マップ.png", 192, 16, 12, 32, 32, M_ground);
}


// 動きを計算する
void Map_Update()
{
	
	
}

// 描画する
void Map_Draw()
{
	
	//初期化
	horizontalKey = 0;
	verticalKey = 0;
	//キーの入力
	if (Keyboard_Get(KEY_INPUT_A) > 0) {
		horizontalKey = 1;
	}
	if (Keyboard_Get(KEY_INPUT_D) > 0) {
		horizontalKey = 2;
	}
	if (Keyboard_Get(KEY_INPUT_W) > 0) {
		verticalKey = 1;
	}
	if (Keyboard_Get(KEY_INPUT_S) > 0) {
		verticalKey = 2;
	}

	if (horizontalKey == 1)
	{
		meadow1.M_x++;
		meadow1.S_x++;
	}
	else if (horizontalKey == 2)
	{
		meadow1.M_x--;
		meadow1.S_x--;
	}
	if (verticalKey == 1)
	{
		meadow1.M_y++;
		meadow1.S_y++;
	}
	else if (verticalKey == 2)
	{
		meadow1.M_y--;
		meadow1.S_y--;
	}

	Cave_Draw();
	//マップ移動制限
	/*Map_Limit_x = meadow1.MAP_x;
	Map_Limit_y = meadow1.MAP_y;
	if (meadow1.M_x == 16 * Map_Limit_x)
	{
		horizontalKey = 0;
	}
	if (meadow1.M_y == 16 * Map_Limit_y)
	{
		verticalKey = 0;
	}*/

	//for (int i = 0; i < meadow1.MAP_x; i++)//草原
	//{

	//	for (int j = 0; j < meadow1.MAP_y; j++)
	//	{

	//		DrawGraph(meadow1.M_x + 16 * i, meadow1.M_y + 16 * j, M_ground[0], TRUE);
	//	}
	//}
	//for (int i = 0; i < meadow1.MAP_x; i++)//海
	//{

	//	for (int j = 0; j < meadow1.MAP_y + 1; j++)
	//	{

	//		DrawGraph(meadow1.S_x + 16 * i, meadow1.S_y + 16 * j, M_Sea[39], TRUE);
	//	}
	//}
	
}

// 終了処理をする
void Map_Finalize()
{

}
#include "DxLib.h"
#include "Keyboard.h"
#include "SceneMgr.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define C_MAP_x 10
#define C_MAP_y 10
class CAVE
{
public:
	int C_x, C_y;//�ʒu

	int C_MAP_tayp;//0�����Ȃ��ꏊ 1�� 2�� 3��
};
int white = GetColor(225, 225, 225);




int move_x, move_y;//���A�̔w�i�𓮂����ϐ�
int SPM_Cave[128];//�摜�̊i�[
int SPM_Treasure[16];
int C_horizontalKey = 0;//AD�L�[�̓��̓`�F�b�N1��2�E
int C_verticalKey = 0;//WS�L�[�̓��̓`�F�b�N1��2��

void roomMaker(CAVE array[][C_MAP_y]) {

	int room_StartX = 2 + rand() % (C_MAP_x - 2);
	int room_StartY = 2 + rand() % (C_MAP_y - 2);
	int room_EndX = room_StartX + rand() % (C_MAP_x - room_StartX);
	int room_EndY = room_StartY + rand() % (C_MAP_y - room_StartY);

	for (int i = room_StartX; i < room_EndX; i++) {
		for (int j = room_StartY; j < room_EndY; j++) {
			array[i][j].C_MAP_tayp = 1;
		}
	}
	
}

void Treasure(CAVE array[][C_MAP_y]) {
	int stairs_X = rand() % (C_MAP_x - 5) + 2;
	int stairs_Y = rand() % (C_MAP_y - 5) + 2;

	for (int i = stairs_X - 1; i < stairs_X + 2; i++) {
		for (int j = stairs_Y; j < stairs_X + 2; j++) {

			array[i][j].C_MAP_tayp = 3;
		}
	}
	////�K�i�܂ł̓������
	//for (int k = 1; k < MAPX - 1; k++) {
	//	array[stairs_Y][k].tayp = 0;
	//}
	//for (int l = 1; l < MAPY - 1; l++) {
	//	array[l][stairs_X].tayp = 0;
	//}

	//array[stairs_Y][stairs_X].tayp = 2;




}

//�}�b�v�����֐�
void mapMaker(CAVE arrow[][C_MAP_y]) {
	//������
	for (int i = 0; i < C_MAP_x; i++) {
		for (int j = 0; j < C_MAP_y; j++) {
			arrow[i][j].C_x = { 32 * i };
			arrow[i][j].C_y = { 32 * j };
			arrow[i][j].C_MAP_tayp = 0;
			//arrow[i][j].Flag = 0;
		}
	}

	for (int i = 0; i < C_MAP_x/3 ; i++) {
		roomMaker(arrow);
	}

	Treasure(arrow);
	for (int i = 0; i < C_MAP_x; i++) {
		for (int j = 0; j < C_MAP_y; j++) {
			if (arrow[i][j].C_MAP_tayp == 3)
			{
				if (arrow[i][j].C_MAP_tayp == 0)
				{
					arrow[i][j].C_MAP_tayp == 0;
				}
				
			}
		}
	}
	
	/*EnemyMaker(arrow);

	stairsMaker(arrow);
	arrow[2 + rand() % (MAPY - 2)][2 + rand() % (MAPX - 2)].tayp = 5;*/
}
CAVE cave1[C_MAP_x][C_MAP_y];

// ������������
void Cave_Initialize()
{
	srand((unsigned int)time(NULL));
	mapMaker(cave1);
	LoadDivGraph("�摜/���A�w�i.png", 128, 8, 16, 32, 32, SPM_Cave);
	LoadDivGraph("�摜/��.png", 16, 8, 2, 32, 32, SPM_Treasure);
	
}

// �������v�Z����
void Cave_Update()
{
	
	
}

// �`�悷��
void Cave_Draw()
{
	//������
	C_horizontalKey = 0;
	C_verticalKey = 0;
	
	
	if (Keyboard_Get(KEY_INPUT_A) > 0) {
		C_horizontalKey = 1;
	}
	if (Keyboard_Get(KEY_INPUT_D) > 0) {
		C_horizontalKey = 2;
	}
	if (Keyboard_Get(KEY_INPUT_W) > 0) {
		C_verticalKey = 1;
	}
	if (Keyboard_Get(KEY_INPUT_S) > 0) {
		C_verticalKey = 2;
	}
	if (C_horizontalKey == 1)
	{
		move_x++;
		
	}
	else if (C_horizontalKey == 2)
	{
		move_x--;
		
	}
	if (C_verticalKey == 1)
	{
		move_y++;
		
	}
	else if (C_verticalKey == 2)
	{
		move_y--;
		
	}
	
	//�ǈړ�
	
	for (int i = 0; i < C_MAP_x; i++)//���A
	{
		for (int j = 0; j < C_MAP_y; j++)
		{
			if (cave1[i][j].C_MAP_tayp == 0)
			{
				//DrawFormatString(100, 50, white, "���W[%d,%d]", cave1[i][j]);
				DrawGraph(cave1[i][j].C_x + move_x, cave1[i][j].C_y + move_y, SPM_Cave[3], TRUE);
			}
			if (cave1[i][j].C_MAP_tayp == 1)
			{
				//DrawGraph(cave1[i][j].C_x, cave1[i][j].C_y, SPM_Cave[3], TRUE);
			}
			if (cave1[i][j].C_MAP_tayp == 3)
			{
				//DrawFormatString(100, 50, white, "���W[%d,%d]", cave1[i][j]);
				DrawGraph(cave1[i][j].C_x + move_x, cave1[i][j].C_y + move_y, SPM_Treasure[6], TRUE);
			}
			if (cave1[i][j].C_MAP_tayp == 2)
			{
				DrawGraph(cave1[i][j].C_x + move_x, cave1[i][j].C_y + move_y, SPM_Cave[0], TRUE);
			}
			
		}
	}
	
	
}

// �I������������
void Cave_Finalize()
{

}
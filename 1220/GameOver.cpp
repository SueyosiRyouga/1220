#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"



//�X�V
void GameOver_Update() {
    if (CheckHitKey(KEY_INPUT_H) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
}

//�`��
void GameOver_Draw() {
    int GameOver;
    GameOver = LoadGraph("�摜/�Q�[���I�[�o�[.jpeg");
    DrawRotaGraph(320, 250, 1, 0.0, GameOver, TRUE);

    DrawString(0, 20, "H�L�[�������ƃ^�C�g����ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
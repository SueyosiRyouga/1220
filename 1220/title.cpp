#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"




//�X�V
void title_Update() {
    if (CheckHitKey(KEY_INPUT_H) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�������j���[�ɕύX
    }
    if (CheckHitKey(KEY_INPUT_A) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Clear);//�V�[�������j���[�ɕύX
    }
}

//�`��
void title_Draw() {
    int background;
    background = LoadGraph("�摜/�^�C�g���w�i1.jpg");
    DrawRotaGraph(400, 300, 1, 0.0, background, TRUE);
    DrawString(200, 250, "�A�N�V�����Q�c�Q�[��", GetColor(255, 255, 255));
    DrawString(180, 300, "H�L�[�������ƃQ�[����ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
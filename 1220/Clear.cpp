#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void Clear_Update() {
    if (CheckHitKey(KEY_INPUT_Z) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Clear_Draw() {
    int Clerabackground;
    Clerabackground = LoadGraph("�摜/�N���A�w�i.jfif");
    DrawRotaGraph(320, 250, 1.7, 0.0, Clerabackground, TRUE);
    DrawString(0, 0, "Clear��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Z�L�[�������ƃ^�C�g����ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
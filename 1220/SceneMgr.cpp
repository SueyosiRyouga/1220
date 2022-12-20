#include "DxLib.h"
#include "SceneMgr.h"
#include "Game.h"
#include "Clear.h"
#include "GameOver.h"
#include "title.h"



static eScene mScene = eScene_title;    //�V�[���Ǘ��ϐ�






//�X�V
void SceneMgr_Update() {


    switch (mScene) { //�V�[���ɂ���ď����𕪊�
    case eScene_title:
        title_Update();
        break;
    case eScene_Game:    //���݂̉�ʂ��Q�[���Ȃ�
        Game_Update();   //�Q�[����ʂ̍X�V����������
        break;//�ȉ���
    case eScene_GameOver:    //���݂̉�ʂ����j���[�Ȃ�
        GameOver_Update();   //���j���[��ʂ̍X�V����������
        break;//�ȉ���
    case eScene_Clear:    //���݂̉�ʂ����j���[�Ȃ�
        Clear_Update();   //���j���[��ʂ̍X�V����������
        break;//�ȉ���


    }
}

//�`��
void SceneMgr_Draw() {
    switch (mScene) {      //�V�[���ɂ���ď����𕪊�
    case eScene_title:
        title_Draw();
        break;
    case eScene_Game:   //���݂̉�ʂ��Q�[����ʂȂ�
        Game_Draw();    //�Q�[����ʂ̕`�揈��������
        break;//�ȉ���

    case eScene_GameOver:   //���݂̉�ʂ����j���[��ʂȂ�
        GameOver_Draw();    //���j���[��ʂ̕`�揈��������
        break;//�ȉ���
    case eScene_Clear:    //���݂̉�ʂ����j���[�Ȃ�
        Clear_Draw();   //���j���[��ʂ̍X�V����������
        break;//�ȉ���
    }
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene NextScene) {
    mScene = NextScene;
}




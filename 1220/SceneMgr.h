
#pragma once

typedef enum {
    eScene_title,    //���j���[���
    eScene_Game,    //�Q�[�����
    eScene_GameOver,  //�ݒ���
    eScene_Clear
} eScene;

//�X�V
void SceneMgr_Update();

//�`��
void SceneMgr_Draw();

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);
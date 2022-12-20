#include "DxLib.h"
#include "Keyboard.h"
#include "SceneMgr.h"
#include "Player.h"
#include "Map.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    Player_Initialize();// ������
    // while( ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !Keyboard_Get(KEY_INPUT_ESCAPE)){
        SceneMgr_Update();  //�X�V

        Keyboard_Update();
        

        SceneMgr_Draw();    //�`��
        
    }
    Player_Finalize();  // �I������
    DxLib_End(); // DX���C�u�����I������
    return 0;
}
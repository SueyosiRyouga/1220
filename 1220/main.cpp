#include "DxLib.h"
#include "Keyboard.h"
#include "SceneMgr.h"
#include "Player.h"
#include "Map.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    Player_Initialize();// 初期化
    // while( 裏画面を表画面に反映, メッセージ処理, 画面クリア )
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !Keyboard_Get(KEY_INPUT_ESCAPE)){
        SceneMgr_Update();  //更新

        Keyboard_Update();
        

        SceneMgr_Draw();    //描画
        
    }
    Player_Finalize();  // 終了処理
    DxLib_End(); // DXライブラリ終了処理
    return 0;
}
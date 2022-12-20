
#pragma once

typedef enum {
    eScene_title,    //メニュー画面
    eScene_Game,    //ゲーム画面
    eScene_GameOver,  //設定画面
    eScene_Clear
} eScene;

//更新
void SceneMgr_Update();

//描画
void SceneMgr_Draw();

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene nextScene);
#include "DxLib.h"
#include "SceneMgr.h"
#include "Game.h"
#include "Clear.h"
#include "GameOver.h"
#include "title.h"



static eScene mScene = eScene_title;    //シーン管理変数






//更新
void SceneMgr_Update() {


    switch (mScene) { //シーンによって処理を分岐
    case eScene_title:
        title_Update();
        break;
    case eScene_Game:    //現在の画面がゲームなら
        Game_Update();   //ゲーム画面の更新処理をする
        break;//以下略
    case eScene_GameOver:    //現在の画面がメニューなら
        GameOver_Update();   //メニュー画面の更新処理をする
        break;//以下略
    case eScene_Clear:    //現在の画面がメニューなら
        Clear_Update();   //メニュー画面の更新処理をする
        break;//以下略


    }
}

//描画
void SceneMgr_Draw() {
    switch (mScene) {      //シーンによって処理を分岐
    case eScene_title:
        title_Draw();
        break;
    case eScene_Game:   //現在の画面がゲーム画面なら
        Game_Draw();    //ゲーム画面の描画処理をする
        break;//以下略

    case eScene_GameOver:   //現在の画面がメニュー画面なら
        GameOver_Draw();    //メニュー画面の描画処理をする
        break;//以下略
    case eScene_Clear:    //現在の画面がメニューなら
        Clear_Draw();   //メニュー画面の更新処理をする
        break;//以下略
    }
}

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene NextScene) {
    mScene = NextScene;
}




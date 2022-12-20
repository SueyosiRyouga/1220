#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"




//更新
void title_Update() {
    if (CheckHitKey(KEY_INPUT_H) != 0) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをメニューに変更
    }
    if (CheckHitKey(KEY_INPUT_A) != 0) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Clear);//シーンをメニューに変更
    }
}

//描画
void title_Draw() {
    int background;
    background = LoadGraph("画像/タイトル背景1.jpg");
    DrawRotaGraph(400, 300, 1, 0.0, background, TRUE);
    DrawString(200, 250, "アクション２Ｄゲーム", GetColor(255, 255, 255));
    DrawString(180, 300, "Hキーを押すとゲーム画面に戻ります。", GetColor(255, 255, 255));
}
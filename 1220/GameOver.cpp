#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"



//更新
void GameOver_Update() {
    if (CheckHitKey(KEY_INPUT_H) != 0) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}

//描画
void GameOver_Draw() {
    int GameOver;
    GameOver = LoadGraph("画像/ゲームオーバー.jpeg");
    DrawRotaGraph(320, 250, 1, 0.0, GameOver, TRUE);

    DrawString(0, 20, "Hキーを押すとタイトル画面に戻ります。", GetColor(255, 255, 255));
}
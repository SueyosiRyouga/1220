#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

//更新
void Clear_Update() {
    if (CheckHitKey(KEY_INPUT_Z) != 0) {//Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}

//描画
void Clear_Draw() {
    int Clerabackground;
    Clerabackground = LoadGraph("画像/クリア背景.jfif");
    DrawRotaGraph(320, 250, 1.7, 0.0, Clerabackground, TRUE);
    DrawString(0, 0, "Clear画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Zキーを押すとタイトル画面に戻ります。", GetColor(255, 255, 255));
}
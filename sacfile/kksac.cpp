// kksac.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "SACFile.h";

void read_test();

int main()
{
    std::cout << "Hello Wordld!\n";
    read_test();
}


void read_test() {
 
    std::string fname = "dat/AMM.010202E.T";
    SACFile sf0(fname);
    SACFile sf1("dat/AMM.010202E.Tsc");
    std::ifstream ifs(fname);
    //return ifs.is_open();
   // std::cout << ifs.is_open();
  //  std::cout << sf.getDelta();
    //double data[] = { 1.,2. };
    double* data = sf0.getData();
    std::cout << data[3]<<std::endl;
    data = sf1.getData();
    std::cout << data[3];
    delete data;
    data = sf1.getData();
    std::cout << data[3];

   /* for (int i = 0; i <1; i++)
    {
        std::cout << data[i] << std::endl ;
    }*/


}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します


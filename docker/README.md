# docker版単体ロボットシミュレータのシミュレーション方法
## 想定環境
 * OS
   * Windows 10/home
 * 利用する端末
   * WSL2 および WSL2/docker

## docker版単体ロボットシミュレータ適用手順
* docker を WSL2(Ubuntu 20.04.1 LTS) にインストールしてください．
* ev3rt-athrill-v850e2m を WSL2 上の任意のフォルダで clone してください．
   * 例. $ git clone https://github.com/toppers/ev3rt-athrill-v850e2m.git .
* ev3rt-athrill-v850e2m/docker　に移動してください．
   * 例．$ cd ev3rt-athrill-v850e2m/docker
* 以下のコマンド実行して，docker image を作成してください．
   * $ bash create-image-bt.bash
* 以下のコマンドを実行して，Unity プロジェクトを single-robot として，新規作成してください．
   * $ mkdir unity/single-robot
* 以下のコマンドで，Unityのシミュレータ(Unityバイナリ)をダウンロードしてください．
   * $ bash unity/download.bash single-robot WindowsBinary.zip

## シミュレーション環境の準備
* WSL2 の端末を2個起動して，ev3rt-athrill-v850e2m/docker　に移動してください．
   * 端末A：マイコン側の開発用
   * 端末B：Unity側のシミュレーション実行用
* 端末Aで，以下のように docker コンテナを起動してください．
   * $ bash run.bash
* 端末A(docker)で，EV3RTのサンプルアプリ(base_practice_1)をビルドしてください．
   * \# bash clean_build.bash base_practice_1
* 端末A(docker)で，Athrillのコンフィグ設定してください(利用しているETHERがeth0の場合)．
   * \# bash config/create_config.bash base_practice_1 eth0

## シミュレーション実行
* 端末B(WSL2)で，Unity側のシミュレータを起動してください(利用しているETHERがeth0の場合)．
   * $ $ bash unity/start.bash single-robot eth0
* 端末A(docker)で，athrill を実行してください．
   * \# bash start-athrill.bash base_practice_1



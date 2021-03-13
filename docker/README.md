# docker版単体ロボットシミュレータのシミュレーション方法
## 想定環境
 * OS
   * Windows 10/home
 * 利用する端末
   * WSL2 および WSL2/docker
    * WSL2環境に ifconfig をインストールしてください．
      * sudo apt install net-tools 
  * mruby を利用する方も基本的には同じ方法でインストール/シミュレーションできます．
    * 一部，操作が異なるところについては，[mruby]という表記で説明追記しております． 

## docker版単体ロボットシミュレータ適用手順
* docker を WSL2(Ubuntu 20.04.1 LTS) にインストールしてください．
* ev3rt-athrill-v850e2m を WSL2 上の任意のフォルダで clone してください．
   * 例. $ git clone https://github.com/toppers/ev3rt-athrill-v850e2m.git .
* ev3rt-athrill-v850e2m/docker　に移動してください．
   * 例．$ cd ev3rt-athrill-v850e2m/docker
* 以下のコマンド実行して，docker image を作成してください．
   * $ bash create-image-bt.bash
   * [mruby] $ bash create-image-mruby.bash
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
   * [mruby] $ bash run-mruby.bash
   * [mruby] dockerの初回起動時のみ，mrubyのインストールコマンドを以下のように実行してください．
   * [mruby] # bash mruby/install.bash
* 端末A(docker)で，EV3RTのサンプルアプリ(base_practice_1)をビルドしてください．
   * \# bash clean_build.bash base_practice_1
   * [mruby] \# bash clean_build.bash base_practice_1_mruby.bash
* 端末A(docker)で，Athrillのコンフィグ設定してください(利用しているETHERがeth0の場合)．
   * \# bash config/create_config.bash base_practice_1 eth0
* Bluetoothデバイスを使用する場合は，create_config.bash の代わりに，create_config_bt.bashを使ってください
   * \# bash config/create_config_bt.bash base_practice_1 eth0
   * [mruby] 現時点では未対応．．．

## シミュレーション実行
* 端末B(WSL2)で，Unity側のシミュレータを起動してください(利用しているETHERがeth0の場合)．
   * $ bash unity/start.bash single-robot eth0
* 端末A(docker)で，athrill を実行してください．
   * \# bash start-athrill.bash base_practice_1
   * [mruby] \# bash start-athrill.bash base_practice_1_mruby



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
* WSL2 の端末を3個起動して，ev3rt-athrill-v850e2m/docker　に移動してください．
   * 端末A：箱庭アセット・プロキシ起動用
   * 端末B：マイコン側のプログラム開発用
   * 端末C：Unity側のシミュレーション実行用
* 端末Aでdockerを起動してください．
  * $ sudo service docker start 
* 端末Aで，proxy/proxy_param.jsonの`target_options`を，開発対象のアプリケーション名にしてください．
   * 例：base_practice_1
   * [mruby] base_practice_1_mruby

* 端末Aで，以下のように docker コンテナを起動してください．
   * $ bash run-proxy.bash
* 端末Bで，以下のように 端末Aで起動したdocker コンテナに入ります．
   * $ bash attach.bash
   * [mruby] $ bash attach-mruby.bash
   * [mruby] dockerの初回起動時のみ，mrubyのインストールコマンドを以下のように実行してください．
   * [mruby] # bash mruby/install.bash
* 端末B(docker)で，EV3RTのサンプルアプリ(base_practice_1)をビルドしてください．
   * \# bash clean_build.bash base_practice_1
   * [mruby] \# bash clean_build.bash base_practice_1_mruby.bash

## シミュレーション実行
* 端末C(WSL2)で，Unity側のシミュレータを起動してください(利用しているETHERがeth0, アプリケーション名が base_practice_1の場合)．
   * $ bash unity/start-proxy.bash single-robot eth0 ../sdk/workspace/base_practice_1


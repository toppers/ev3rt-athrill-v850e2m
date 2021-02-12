
# docker版単体ロボットシミュレータ適用手順
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

# シミュレーション環境の準備
* WSL2 の端末を2個起動して，ev3rt-athrill-v850e2m/docker　に移動してください．
   * 端末A：マイコン側の開発用
   * 端末B：Unity側のシミュレーション実行用
* 端末Aで，以下のように docker コンテナを起動してください．
   * $ bash run.bash
* 端末Aで，EV3RTのサンプルアプリ(base_practice_1)をビルドしてください．
   * \# bash clean_build.bash base_practice_1
* 端末Aで，Athrillのコンフィグ設定してください(利用しているETHERがeth0の場合)．
   * \# bash config/create_config.bash base_practice_1 eth0
* 端末Bで，Unityの端末Aで，Athrillのコンフィグ設定してください(利用しているETHERがeth0の場合)．



① unity のシミュレーションを実行してください．
② 以下のコマンドを実行して，docker container を起動してください．
　$ run.bash
③ docker container 上で，以下のコマンドでアプリケーションをビルドしてください．
　# bash clean_build.bash base_practice_1
③ 以下のコマンドでシミュレーションを開始してください．
　# bash start-athrill.bash base_practice_1



# WSL2 の設定
- Unity側のconfig.json 送信先IPアドレス(AthrillIpAddr)
  =>WSL2のIPアドレス(ifconfigの結果)

- athrill側の受信IPアドレス(DEBUG_FUNC_VDEV_RX_IPADDR)
 => WSL2のIPアドレス(ifconfigの結果)

- athrill側の送信IPアドレス(DEBUG_FUNC_VDEV_TX_IPADDR)
 => WSL2の/etc/resolv.confのnameserverのIPアドレス


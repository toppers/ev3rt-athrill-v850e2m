
# 適用手順
⓪  docker を linux にインストールしてください．
① ev3rt-athrill-v850e2m を linux 上の任意のフォルダで clone してください．
② ev3rt-athrill-v850e2m/docker　に移動してください．
③ 以下のコマンド実行して，docker image を作成してください．
　$ bash create-image.bash
⑤ 以下に Unity プロジェクトを single-robot として，新規作成してください．
　 ev3rt-athrill-v850e2m/docker/unity/
⑥ 以下のパッケージをUnityにインポートしてください．
　https://github.com/toppers/hakoniwa-Unity-HackEV/releases
　v2.1-practice のsingle-robot-HackEV-practice.unitypackage
⑦ 以下のコマンドで，unity/single-robot配下にconfig.jsonを配置してください．
　$ cp unity/config_udp.json unity/single-robot/config.json


# シミュレーション実行方法

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


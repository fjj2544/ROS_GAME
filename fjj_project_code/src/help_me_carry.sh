#!/bin/sh
#运行help_me_carry项目
echo "gender recognizition start"
gnome-terminal -x bash -c "roslaunch fjj_nav navi_help.launch"

sleep 10

gnome-terminal -x bash -c "roslaunch fjj_speech help_me_carry.launch"


sleep 1
##这里采用rospack find 的方法非常关键
gnome-terminal -x bash -c " pocketsphinx_continuous -inmic yes -dict `rospack find speech`/voice_library/help_me_carry/help_me_carry.dic -lm `rospack find speech`/voice_library/help_me_carry/help_me_carry.lm"

sleep 1

exit 0

#!/bin/bash
# rm_visiongroup 环境自检 —— 一屏打印 sp_vision_25 规划的全部环境与工具状态
ok()   { echo "[OK  ] $*"; }
miss() { echo "[MISS] $*"; }

echo "== 系统级框架（/opt）=="
[ -d /opt/ros/humble ]              && ok   "ROS2 Humble        -> /opt/ros/humble"              || miss "ROS2 Humble"
[ -d /opt/intel/openvino_2024.6.0 ] && ok   "OpenVINO 2024.6.0  -> /opt/intel/openvino_2024.6.0" || miss "OpenVINO 2024.6"
[ -d /opt/MVS ]                     && ok   "海康 MVS SDK        -> /opt/MVS"                    || miss "海康 MVS SDK"
ldconfig -p | grep -q libMvCameraControl.so && ok "MVS 运行库已注册（ldconfig 可见）" || miss "MVS 运行库未注册"

echo
echo "== apt 依赖 =="
for p in git g++ cmake can-utils libopencv-dev libfmt-dev libeigen3-dev \
         libspdlog-dev libyaml-cpp-dev libusb-1.0-0-dev nlohmann-json3-dev \
         openssh-server screen libceres-dev \
         ros-humble-cv-bridge ros-humble-image-transport ros-humble-sensor-msgs \
         python3-colcon-common-extensions \
         ros-humble-plotjuggler-ros; do
  dpkg -s "$p" >/dev/null 2>&1 && ok "apt: $p" || miss "apt: $p"
done

echo
echo "== 环境接线（~/.bashrc）=="
grep -q "openvino_2024.6.0/setupvars.sh" ~/.bashrc && ok "bashrc: source OpenVINO setupvars.sh" || miss "bashrc: OpenVINO"
grep -q "ros/humble/setup.bash"          ~/.bashrc && ok "bashrc: source ROS2 humble setup.bash" || miss "bashrc: ROS2"
grep -q "ROSDISTRO_INDEX_URL"            ~/.bashrc && ok "bashrc: rosdep 走 USTC 镜像" || miss "bashrc: rosdep 镜像变量"
[ -f /etc/ros/rosdep/sources.list.d/20-default.list ] && ok "rosdep 已 init（源列表指向 USTC）" || miss "rosdep 未 init"
[ -d ~/.ros/rosdep/sources.cache ] && ok "rosdep 缓存已 update" || miss "rosdep 未 update"
command -v rosdep >/dev/null 2>&1 && ok "rosdep 命令可用: $(command -v rosdep)" || miss "rosdep 命令不可用"

echo
echo "== 模型权重 =="
for f in yolo11.xml yolo11.bin yolo11_buff_int8.xml yolo11_buff_int8.bin; do
  [ -f ~/rm_visiongroup/assets/"$f" ] && ok "工程 assets/$f" || miss "工程 assets/$f"
done
for f in yolo11.xml yolo11.bin yolov5.xml yolov8.xml \
         tiny_resnet.onnx best2-sim.onnx demo/demo.avi demo/demo.txt; do
  [ -f ~/sp_vision_25/assets/"$f" ] && ok "参照库 sp_vision_25/assets/$f" || miss "参照库缺 sp_vision_25/assets/$f"
done

echo
echo "== 辅助工具 =="
PJ=$(find /opt/ros/humble/lib -maxdepth 2 -name 'plotjuggler' -type f 2>/dev/null | head -1)
[ -n "$PJ" ] && ok "PlotJuggler 可执行: $PJ" || miss "PlotJuggler（ros-humble-plotjuggler-ros）"

echo
echo "—— 完 ——。NoMachine / GPU 推理栈 / 相机-串口-CAN 的 udev / 开机自启 = 实车 NUC 部署项，WSL 内不做。"

# 交接文档 · rm_visiongroup 自瞄工程

> 上下文工程文档：稳定层记录不轻易变动的信息，易变层随开发进度持续更新。
> 每次完成一个任务后更新易变层；架构、目标等稳定层内容变更需明确讨论。

---

# 稳定层

## 项目目标

参照同济 sp_vision_25（`~/sp_vision_25`，只读参照）的框架与数据流，**自研一套 ROS2 节点化的 RoboMaster 自瞄系统**。有查重要求：只参考接口设计与数学原理，代码结构、命名、实现细节全部重写，不照抄。

数据流主线：`相机取图 → YOLO 四点检测 → PnP 位姿解算 → EKF 整车跟踪 → 瞄准/开火决策 → 指令下发下位机`。

## 硬件清单

| 硬件 | 说明 |
|---|---|
| 相机 | 海康工业相机（MVS SDK 2.1.2），参照机型 MV-CS016-10UC |
| 下位机 | RoboMaster 开发板 C 型（STM32F407），内置 BMI088 IMU |
| 通信 | SocketCAN（can0，1Mbps），下位机↔小电脑 |
| 部署机 | NUC 实体 Ubuntu 22.04（实车） |
| 开发机 | WSL2 Ubuntu-22.04（本机，仅算法开发，不接硬件） |

## 软件环境

Ubuntu 22.04 · ROS2 Humble（`/opt/ros/humble`）· OpenVINO 2024.6.0（`/opt/intel/openvino_2024.6.0`）· 海康 MVS 2.1.2（`/opt/MVS`）· OpenCV/Eigen3/yaml-cpp/fmt/spdlog（apt）· colcon · PlotJuggler。

详细版本与来源见 `README.md` 环境总览；环境自检：`bash ~/rm_visiongroup/tools/env-check.sh`。

模型权重与测试素材在 `assets/`（yolo11 为主模型，`demo/demo.avi` 为自研合成调试视频，由 `tools/make_demo_video.py` 生成）。

## 系统架构

```
┌─────────────┐  /image_raw   ┌──────────────┐  /detector/armors ┌─────────────┐
│ hik_camera  │ ────────────▶ │armor_detector│ ────────────────▶ │armor_solver │
└─────────────┘               └──────────────┘                   └──────┬──────┘
                                                           /solver/armors│
┌─────────────┐  /gimbal/cmd                               ┌───────────▼─┐  /tracker/target  ┌──────────────┐
│ can_bridge  │ ◀───────────────────────────────────────── │aim_decision │ ◀─────────────── │armor_tracker │
└──────┬──────┘                                            └─────────────┘                  └──────────────┘
       │ /gimbal/state（四元数/弹速/模式）──▶ 解算/跟踪/决策各节点
```

| 包 | 职责 | 状态 |
|---|---|---|
| `rm_interfaces` | 自定义消息（7 个 msg） | ✅ 已完成 |
| `hik_camera` | 海康取图/视频文件取图，发 `/image_raw` | ✅ 已完成 |
| `can_bridge` | SocketCAN 收发，发 `/gimbal/state`，收 `/gimbal/cmd` | ⬜ 下一步 |
| `armor_detector` | OpenVINO YOLO 四点检测 | ⬜ |
| `armor_solver` | PnP + 坐标变换（读手眼标定 yaml） | ⬜ |
| `armor_tracker` | EKF 整车估计 + 状态机 | ⬜ |
| `aim_decision` | 选板 + 弹道补偿 + 开火判断 | ⬜ |

约定：包平铺在工作区根（非 src/ 布局，colcon 递归发现）；每节点参数走 yaml；消息边界 = 节点边界。

---

# 易变层

> 最近更新：2026-10-08（hik_camera 双模式完成并验证）

## 负责工作的独立模块

- **rm_interfaces**（已完成）：7 个消息 —— Armor/Armors（2D 检测）、ArmorPose/ArmorPoses（3D 解算）、Target（EKF 整车状态）、GimbalCmd（视觉→下位机）、GimbalState（下位机→视觉）。全部字段已带详细中文注释；两次构建验证通过，`ros2 interface show` 可查。
- **hik_camera**（已完成）：双模式取图节点。抽象基类 `FrameSource` + 两实现 `VideoFileSource`（视频文件，按视频帧率节拍吐帧、可循环）/ `HikSdkSource`（MVS SDK，取流线程 + 最新帧槽位 + 断连每 2s 重连）。CMake 检测 `/opt/MVS` 存在才编译 SDK 模式（`HAS_MVS_SDK` 宏）。参数全走 `config/hik_camera.yaml`（mode/video_path/loop/exposure_ms/gain/frame_rate）。发布 `/image_raw`（bgr8，SensorDataQoS），节点内每 5s 打一次实际发布帧率。
- **can_bridge**（开发中·下一步）：SocketCAN 收发。

## 已解决问题

- 开发环境全部装好（37 项自检 OK），bashrc 已接 ROS2 + OpenVINO。
- 工作空间布局定为平铺式（包直接在 `rm_visiongroup/` 下），colcon 可正常发现。
- `rm_interfaces` 一次编译通过（14s）。
- 构建产物已统一收进 `colcon_build/`（build/install/log），工作区根目录只余源码与文档；新增 `colcon_defaults.yaml` 配置文件。此后环境接入命令变为 `source colcon_build/install/setup.bash`。
- `hik_camera` 构建通过（15s，SDK 模式已编入）；WSL 视频模式验证：1440x1080 / bgr8 / **节点内统计 30.0fps**（= 视频 fps）/ loop 循环正常；SDK 模式 WSL 无硬件下优雅报错退出，待 NUC 实机验证。
- 测试素材定为**自研合成视频**：`tools/make_demo_video.py` 生成 `assets/demo/demo.avi`（1440x1080@30fps 10s，暗背景 + 往返运动的红灯条装甲板 + 数字），不用 sp_vision_25 的素材（用户要求，查重）。

## 当前问题

- 用户 bashrc 里 COLCON 两行环境变量写了两遍（功能无碍，可自行去重）。
- 工作区根目录有个非本工程产物的 `build/`（用户自己建的），不需要时可删，保持根目录整洁。

## TODO（代办事项）

1. ~~工作空间骨架 + rm_interfaces 消息包~~ ✅
2. ~~`hik_camera` 节点（SDK/视频双模式取图，发 `/image_raw`）~~ ✅
3. `can_bridge` 节点（SocketCAN 收发）← 下一步
4. `armor_detector`（OpenVINO YOLO 推理 + 四点后处理）
5. `armor_solver`（PnP + yaw 优化 + 坐标变换）
6. `armor_tracker`（EKF 整车估计 + 状态机）
7. `aim_decision`（选板 + 弹道补偿 + 开火判断）
8. launch 一键启动 + 参数 yaml 整合
9. rosbag 录制回放 + 离线调参
10. （进阶）多线程推理 / 轨迹规划决策

## 决策记录

| 决策 | 结论 | 原因 |
|---|---|---|
| ROS2 形态 | 完整节点化（ament + colcon） | 用户要求；话题解耦便于单模块调试 |
| 检测方案 | YOLO 神经网络（OpenVINO） | 召回率高；用户指定 |
| 相机/通信 | 海康 SDK + SocketCAN | 实车配置 |
| 代码位置 | 独立工作空间 `~/rm_visiongroup` | 与 sp_vision_25 分离，不碰原工程 git |
| 消息分层 | Armor(2D) 与 ArmorPose(3D) 分开 | 检测节点不依赖标定参数，PnP 可用 bag 单独调 |
| GimbalCmd 字段 | 预留 yaw/pitch 速度前馈 | 后续加前馈不改消息 |
| 调试路线 | WSL 用 rosbag/视频，实车部署到 NUC | WSL2 不支持 USB 工业相机与 SocketCAN |
| 构建并行度 | `MAKEFLAGS=-j3` | 本机满核 make 会 OOM |
| 构建产物位置 | 统一收进 `colcon_build/`（build/install/log 三个子目录） | 保持工作区根目录整洁；靠 `colcon_defaults.yaml` + `COLCON_LOG_PATH` 实现 |
| 测试素材 | 自研合成视频（`tools/make_demo_video.py` → `assets/demo/demo.avi`） | 用户要求不用 sp_vision_25 素材，彻底规避查重 |

## 踩过的坑 / 失败的尝试

- **`wsl.exe ... bash -lc` 下 colcon 找不到 ament_cmake**：非交互 shell 不执行 ~/.bashrc 里的 source，必须显式 `source /opt/ros/humble/setup.bash` 再 colcon build。
- **wsl.exe 输出乱码**：WSL 的 localhost 中继提示混入 stdout 且中文为 GBK 乱码；提取结果时加 `2>/dev/null` 并过滤 `wsl:`/localhost 行。
- **colcon 的日志目录不吃 defaults 文件**：`log-base` 写进 colcon_defaults.yaml 无效（该版本甚至没有 `--log-base` 参数），只能用环境变量 `COLCON_LOG_PATH` 指定。
- **WSL 回环下 `ros2 topic hz` 测大图像流严重偏低**：1440x1080 bgr8 @30fps（≈140MB/s）时 hz 只测到 2~23Hz 且伴随丢包提示，是 DDS 回环传输瓶颈而非节点问题；以节点内统计帧率为准（hik_camera 已内置每 5s 帧率日志）。
- **`pkill -f` 会匹配到自身 shell**：`wsl.exe bash -c "...pkill -f hik_camera_node..."` 里整个命令行都含该字符串，把自己杀了（exit 15）。用 `pkill -x <进程名>` 精确匹配。
- sp_vision_25 工作区有未提交本地改动（参照工程，只读不管；本工程改动前需确认 git 状态干净——本工程尚未 git init）。

## AI 工作规范

1. 一次只做一个任务，每步代码量要小、能简洁就简洁。
2. 代码带中文注释，列出来让用户读懂后再确认（现用户已授权直接写入工程）。
3. 参照 sp_vision_25 的框架和数据流，但**不允许照抄代码**（查重）。
4. 需要安装的工具/环境配置：只列出命令，由用户自己安装运行。
5. 不确定的事情先问用户，不擅自决定。
6. 改动前确认工作区干净（git）。
7. 构建验证走 `wsl.exe -d Ubuntu-22.04 -e bash -c "source /opt/ros/humble/setup.bash && ..."`。

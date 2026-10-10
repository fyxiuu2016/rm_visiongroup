# ============================================================
# GimbalCmd —— "云台这么转、开不开火"（决策节点填，发给下位机）
# CAN 节点订阅本消息，打包成 CAN 帧发给 C 板执行
# 对应话题：/gimbal/cmd
# ============================================================

std_msgs/Header header

bool control                # 自瞄要不要接管云台？
                            # false = 交还给操作手（自瞄没把握时）

bool fire                   # 开火吗？true = 打！

float32 yaw                 # 云台应该转到的水平角（弧度）
float32 pitch               # 云台应该转到的俯仰角（弧度）

float32 yaw_velocity        # 预留：yaw 该转多快（速度前馈，让云台更跟手）
float32 pitch_velocity      # 预留：pitch 速度前馈（决策节点后续会填）

float32 distance            # 目标距离（米），给下位机做弹道参考

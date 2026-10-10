# ============================================================
# GimbalState —— "云台现在什么状态"（下位机上报，CAN 节点填）
# 方向反过来：下位机 -> 视觉
# 没有这张表，Armor 的像素位置就是死数据——
# 解算必须知道"拍照那一瞬间相机朝哪"
# 对应话题：/gimbal/state
# ============================================================

std_msgs/Header header

geometry_msgs/Quaternion quaternion
                            # 云台 IMU 四元数 = 云台当前的姿态
                            # 解算节点用它把像素位置换算成现实位置

float32 bullet_speed        # 当前弹速（米/秒）
                            # 弹速影响子弹下坠，决策节点算弹道补偿要用

# ---- 下位机当前模式 ----
uint8 MODE_IDLE = 0         # 空闲：自瞄别干活
uint8 MODE_AUTO_AIM = 1     # 自瞄模式：操作手开了自瞄，干活
uint8 MODE_SMALL_BUFF = 2   # 打小能量机关
uint8 MODE_BIG_BUFF = 3     # 打大能量机关
uint8 MODE_OUTPOST = 4      # 打前哨站
uint8 mode

#!/usr/bin/env python3
"""生成自研调试视频 assets/demo/demo.avi

画面内容：暗背景 + 一块往返运动的"装甲板"（两根红色灯条 + 中央数字），
模拟实车相机视野，供 hik_camera 视频模式及后续 armor_detector 调试用。
仅依赖 opencv-python / numpy（WSL 已有）。

用法: python3 tools/make_demo_video.py
"""

import math
import os

import cv2
import numpy as np

# 输出参数：与实机常用分辨率/帧率对齐
WIDTH, HEIGHT = 1440, 1080
FPS = 30
SECONDS = 10
OUT_PATH = os.path.join(
    os.path.dirname(__file__), "..", "assets", "demo", "demo.avi")


def draw_light_bar(img, center, length, thickness, angle_deg, color):
    """画一根旋转的灯条（填充的旋转矩形）"""
    box = cv2.boxPoints(((float(center[0]), float(center[1])),
                         (float(thickness), float(length)), angle_deg))
    cv2.fillConvexPoly(img, box.astype(np.int32), color)


def main():
    os.makedirs(os.path.dirname(OUT_PATH), exist_ok=True)
    writer = cv2.VideoWriter(
        OUT_PATH, cv2.VideoWriter_fourcc(*"MJPG"), FPS, (WIDTH, HEIGHT))
    if not writer.isOpened():
        raise RuntimeError(f"无法创建视频文件: {OUT_PATH}")

    total = FPS * SECONDS
    for i in range(total):
        t = i / FPS

        # 暗背景 + 轻微随机噪点，模拟工业相机低曝光画面
        frame = np.random.normal(20, 5, (HEIGHT, WIDTH, 3)).clip(0, 255).astype(np.uint8)

        # 装甲板中心：水平往返 + 轻微上下浮动
        cx = WIDTH / 2 + math.sin(2 * math.pi * t / 6.0) * WIDTH * 0.3
        cy = HEIGHT / 2 + math.sin(2 * math.pi * t / 2.5) * 40
        # 板面小角度摆动（模拟云台视角变化）
        angle = 8.0 * math.sin(2 * math.pi * t / 4.0)

        # 两根红色灯条，间距即装甲板宽度
        bar_len, bar_thick, gap = 120, 18, 110
        red = (40, 40, 230)  # BGR
        draw_light_bar(frame, (cx - gap / 2, cy), bar_len, bar_thick, angle, red)
        draw_light_bar(frame, (cx + gap / 2, cy), bar_len, bar_thick, angle, red)

        # 中央数字"1"（哨兵/英雄既视感，后续检测调试可用）
        cv2.putText(frame, "1", (int(cx) - 12, int(cy) + 15),
                    cv2.FONT_HERSHEY_SIMPLEX, 1.2, (200, 200, 200), 3)

        writer.write(frame)

    writer.release()
    size_mb = os.path.getsize(OUT_PATH) / 1e6
    print(f"已生成 {OUT_PATH}: {WIDTH}x{HEIGHT}@{FPS}fps x {SECONDS}s, {size_mb:.1f}MB")


if __name__ == "__main__":
    main()

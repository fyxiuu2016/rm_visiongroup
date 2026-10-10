#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to rm_interfaces__msg__Armor
/// ============================================================
/// Armor —— "我看到一块装甲板"（检测节点填，发给解算节点）
/// 只记录照片上的二维信息，此时还不知道它在现实中哪里
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Armor {
    /// 表头：自带时间戳，记录这一帧是什么时候拍的
    pub header: std_msgs::msg::Header,

    /// 这块板的颜色（填 0 或 1）
    pub color: u8,

    /// 大板还是小板
    pub type_: u8,

    /// 板子上的数字编号：
    /// 1~5 步兵/英雄，6 哨兵，7 前哨站，8 基地（依训练集定义）
    pub number: u8,

    /// 检测程序有多大把握（0~1，0.9 = 九成把握）
    pub confidence: f32,

    /// 板子四个角在照片上的像素位置
    /// [4] = 固定 4 个点，从左上角开始顺时针排列
    pub corners: [geometry_msgs::msg::Point32; 4],

}

impl Armor {
    /// ---- 颜色（常量只是给数字起名字，不占数据空间） ----
    /// 规定：红色在表里写 0
    pub const RED: u8 = 0;

    /// 蓝色写 1
    pub const BLUE: u8 = 1;

    /// ---- 大小（大板血厚、判定区大，打法不同） ----
    /// 小板写 0
    pub const SMALL: u8 = 0;

    /// 大板写 1
    pub const BIG: u8 = 1;

}


impl Default for Armor {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Armor::default())
  }
}

impl rosidl_runtime_rs::Message for Armor {
  type RmwMsg = super::msg::rmw::Armor;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        color: msg.color,
        type_: msg.type_,
        number: msg.number,
        confidence: msg.confidence,
        corners: msg.corners
          .map(|elem| geometry_msgs::msg::Point32::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      color: msg.color,
      type_: msg.type_,
      number: msg.number,
      confidence: msg.confidence,
        corners: msg.corners
          .iter()
          .map(|elem| geometry_msgs::msg::Point32::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      color: msg.color,
      type_: msg.type_,
      number: msg.number,
      confidence: msg.confidence,
      corners: msg.corners
        .map(geometry_msgs::msg::Point32::from_rmw_message),
    }
  }
}


// Corresponds to rm_interfaces__msg__Armors
/// ============================================================
/// Armors —— "这一帧照片里所有的装甲板"（打包发出）
/// 一帧可能看到 0 块、1 块或好几块，所以用数组
/// 对应话题：/detector/armors
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Armors {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Armor 的数组：[] 表示长度不固定
    pub armors: Vec<super::msg::Armor>,

}



impl Default for Armors {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Armors::default())
  }
}

impl rosidl_runtime_rs::Message for Armors {
  type RmwMsg = super::msg::rmw::Armors;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        armors: msg.armors
          .into_iter()
          .map(|elem| super::msg::Armor::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        armors: msg.armors
          .iter()
          .map(|elem| super::msg::Armor::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      armors: msg.armors
          .into_iter()
          .map(super::msg::Armor::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to rm_interfaces__msg__ArmorPose
/// ============================================================
/// ArmorPose —— "这块板在现实中哪里"（解算节点填，发给跟踪节点）
/// 解算 = 拿 Armor 的 4 个像素点 + 相机标定参数，
///        用 PnP 算法算出三维位置和朝向
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmorPose {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// 把检测那张表原样带过来（颜色/编号/置信度），
    /// 下一个节点不用再回头查
    pub armor: super::msg::Armor,

    /// 板子中心的三维坐标 (x, y, z)，单位米
    /// 例如 (2.1, 0.3, -0.1) = 右前方 2 米多
    pub position: geometry_msgs::msg::Point,

    /// 板子朝向角，单位弧度
    /// 正对我们时接近 0，侧对时较大
    pub yaw: f32,

}



impl Default for ArmorPose {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ArmorPose::default())
  }
}

impl rosidl_runtime_rs::Message for ArmorPose {
  type RmwMsg = super::msg::rmw::ArmorPose;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        armor: super::msg::Armor::into_rmw_message(std::borrow::Cow::Owned(msg.armor)).into_owned(),
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        yaw: msg.yaw,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        armor: super::msg::Armor::into_rmw_message(std::borrow::Cow::Borrowed(&msg.armor)).into_owned(),
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
      yaw: msg.yaw,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      armor: super::msg::Armor::from_rmw_message(msg.armor),
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
      yaw: msg.yaw,
    }
  }
}


// Corresponds to rm_interfaces__msg__ArmorPoses
/// ============================================================
/// ArmorPoses —— 一帧中全部解算完的装甲板（打包发出）
/// 对应话题：/solver/armors
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmorPoses {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub armors: Vec<super::msg::ArmorPose>,

}



impl Default for ArmorPoses {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ArmorPoses::default())
  }
}

impl rosidl_runtime_rs::Message for ArmorPoses {
  type RmwMsg = super::msg::rmw::ArmorPoses;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        armors: msg.armors
          .into_iter()
          .map(|elem| super::msg::ArmorPose::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        armors: msg.armors
          .iter()
          .map(|elem| super::msg::ArmorPose::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      armors: msg.armors
          .into_iter()
          .map(super::msg::ArmorPose::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to rm_interfaces__msg__Target
/// ============================================================
/// Target —— "敌车整车在哪、怎么动"（跟踪节点填，发给决策节点）
/// 跟踪节点连续观察很多帧，用 EKF（卡尔曼滤波）估计整车运动状态
/// 有了这些量，决策节点才能预测"0.1 秒后装甲板转到哪"
/// 对应话题：/tracker/target
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Target {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// 还锁定着目标吗？false = 跟丢了，决策节点应停火停控
    pub tracking: bool,

    /// 跟踪的是几号车（敌车可能有多辆，要锁定一辆打）
    pub number: u8,

    /// 这辆车身上有几块板：
    /// 普通车 4 块，平衡步兵 2 块，前哨站 3 块
    /// 知道数量才能算出"下一块板什么时候转过来"
    pub armor_num: u8,

    /// 整车旋转中心的位置（注意：不是某块板，是车中心）
    pub position: geometry_msgs::msg::Point,

    /// 车往哪跑、多快（x/y/z 三个方向的速度）
    pub velocity: geometry_msgs::msg::Vector3,

    /// 车现在转到哪个角度（弧度）
    pub yaw: f32,

    /// 车的旋转角速度（弧度/秒）
    /// 小陀螺的关键：这个值大 = 转得欢
    pub yaw_velocity: f32,

    /// 第 1 组装甲板到旋转中心的距离（米）
    pub radius_1: f32,

    /// 第 2 组（相邻两块板的半径可能不一样）
    pub radius_2: f32,

    /// 两组板之间的高度差（有的车板子一高一低）
    pub dz: f32,

}



impl Default for Target {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Target::default())
  }
}

impl rosidl_runtime_rs::Message for Target {
  type RmwMsg = super::msg::rmw::Target;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        tracking: msg.tracking,
        number: msg.number,
        armor_num: msg.armor_num,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        velocity: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.velocity)).into_owned(),
        yaw: msg.yaw,
        yaw_velocity: msg.yaw_velocity,
        radius_1: msg.radius_1,
        radius_2: msg.radius_2,
        dz: msg.dz,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      tracking: msg.tracking,
      number: msg.number,
      armor_num: msg.armor_num,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
        velocity: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.velocity)).into_owned(),
      yaw: msg.yaw,
      yaw_velocity: msg.yaw_velocity,
      radius_1: msg.radius_1,
      radius_2: msg.radius_2,
      dz: msg.dz,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      tracking: msg.tracking,
      number: msg.number,
      armor_num: msg.armor_num,
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
      velocity: geometry_msgs::msg::Vector3::from_rmw_message(msg.velocity),
      yaw: msg.yaw,
      yaw_velocity: msg.yaw_velocity,
      radius_1: msg.radius_1,
      radius_2: msg.radius_2,
      dz: msg.dz,
    }
  }
}


// Corresponds to rm_interfaces__msg__GimbalCmd
/// ============================================================
/// GimbalCmd —— "云台这么转、开不开火"（决策节点填，发给下位机）
/// CAN 节点订阅本消息，打包成 CAN 帧发给 C 板执行
/// 对应话题：/gimbal/cmd
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GimbalCmd {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// 自瞄要不要接管云台？
    /// false = 交还给操作手（自瞄没把握时）
    pub control: bool,

    /// 开火吗？true = 打！
    pub fire: bool,

    /// 云台应该转到的水平角（弧度）
    pub yaw: f32,

    /// 云台应该转到的俯仰角（弧度）
    pub pitch: f32,

    /// 预留：yaw 该转多快（速度前馈，让云台更跟手）
    pub yaw_velocity: f32,

    /// 预留：pitch 速度前馈（决策节点后续会填）
    pub pitch_velocity: f32,

    /// 目标距离（米），给下位机做弹道参考
    pub distance: f32,

}



impl Default for GimbalCmd {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GimbalCmd::default())
  }
}

impl rosidl_runtime_rs::Message for GimbalCmd {
  type RmwMsg = super::msg::rmw::GimbalCmd;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        control: msg.control,
        fire: msg.fire,
        yaw: msg.yaw,
        pitch: msg.pitch,
        yaw_velocity: msg.yaw_velocity,
        pitch_velocity: msg.pitch_velocity,
        distance: msg.distance,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      control: msg.control,
      fire: msg.fire,
      yaw: msg.yaw,
      pitch: msg.pitch,
      yaw_velocity: msg.yaw_velocity,
      pitch_velocity: msg.pitch_velocity,
      distance: msg.distance,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      control: msg.control,
      fire: msg.fire,
      yaw: msg.yaw,
      pitch: msg.pitch,
      yaw_velocity: msg.yaw_velocity,
      pitch_velocity: msg.pitch_velocity,
      distance: msg.distance,
    }
  }
}


// Corresponds to rm_interfaces__msg__GimbalState
/// ============================================================
/// GimbalState —— "云台现在什么状态"（下位机上报，CAN 节点填）
/// 方向反过来：下位机 -> 视觉
/// 没有这张表，Armor 的像素位置就是死数据——
/// 解算必须知道"拍照那一瞬间相机朝哪"
/// 对应话题：/gimbal/state
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GimbalState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// 云台 IMU 四元数 = 云台当前的姿态
    /// 解算节点用它把像素位置换算成现实位置
    pub quaternion: geometry_msgs::msg::Quaternion,

    /// 当前弹速（米/秒）
    /// 弹速影响子弹下坠，决策节点算弹道补偿要用
    pub bullet_speed: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,

}

impl GimbalState {
    /// ---- 下位机当前模式 ----
    /// 空闲：自瞄别干活
    pub const MODE_IDLE: u8 = 0;

    /// 自瞄模式：操作手开了自瞄，干活
    pub const MODE_AUTO_AIM: u8 = 1;

    /// 打小能量机关
    pub const MODE_SMALL_BUFF: u8 = 2;

    /// 打大能量机关
    pub const MODE_BIG_BUFF: u8 = 3;

    /// 打前哨站
    pub const MODE_OUTPOST: u8 = 4;

}


impl Default for GimbalState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GimbalState::default())
  }
}

impl rosidl_runtime_rs::Message for GimbalState {
  type RmwMsg = super::msg::rmw::GimbalState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        quaternion: geometry_msgs::msg::Quaternion::into_rmw_message(std::borrow::Cow::Owned(msg.quaternion)).into_owned(),
        bullet_speed: msg.bullet_speed,
        mode: msg.mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        quaternion: geometry_msgs::msg::Quaternion::into_rmw_message(std::borrow::Cow::Borrowed(&msg.quaternion)).into_owned(),
      bullet_speed: msg.bullet_speed,
      mode: msg.mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      quaternion: geometry_msgs::msg::Quaternion::from_rmw_message(msg.quaternion),
      bullet_speed: msg.bullet_speed,
      mode: msg.mode,
    }
  }
}



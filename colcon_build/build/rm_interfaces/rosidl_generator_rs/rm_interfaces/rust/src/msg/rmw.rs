#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "rm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__Armor() -> *const std::ffi::c_void;
}

#[link(name = "rm_interfaces__rosidl_generator_c")]
extern "C" {
    fn rm_interfaces__msg__Armor__init(msg: *mut Armor) -> bool;
    fn rm_interfaces__msg__Armor__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Armor>, size: usize) -> bool;
    fn rm_interfaces__msg__Armor__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Armor>);
    fn rm_interfaces__msg__Armor__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Armor>, out_seq: *mut rosidl_runtime_rs::Sequence<Armor>) -> bool;
}

// Corresponds to rm_interfaces__msg__Armor
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// Armor —— "我看到一块装甲板"（检测节点填，发给解算节点）
/// 只记录照片上的二维信息，此时还不知道它在现实中哪里
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Armor {
    /// 表头：自带时间戳，记录这一帧是什么时候拍的
    pub header: std_msgs::msg::rmw::Header,

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
    pub corners: [geometry_msgs::msg::rmw::Point32; 4],

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rm_interfaces__msg__Armor__init(&mut msg as *mut _) {
        panic!("Call to rm_interfaces__msg__Armor__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Armor {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Armor__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Armor__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Armor__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Armor {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Armor where Self: Sized {
  const TYPE_NAME: &'static str = "rm_interfaces/msg/Armor";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__Armor() }
  }
}


#[link(name = "rm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__Armors() -> *const std::ffi::c_void;
}

#[link(name = "rm_interfaces__rosidl_generator_c")]
extern "C" {
    fn rm_interfaces__msg__Armors__init(msg: *mut Armors) -> bool;
    fn rm_interfaces__msg__Armors__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Armors>, size: usize) -> bool;
    fn rm_interfaces__msg__Armors__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Armors>);
    fn rm_interfaces__msg__Armors__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Armors>, out_seq: *mut rosidl_runtime_rs::Sequence<Armors>) -> bool;
}

// Corresponds to rm_interfaces__msg__Armors
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// Armors —— "这一帧照片里所有的装甲板"（打包发出）
/// 一帧可能看到 0 块、1 块或好几块，所以用数组
/// 对应话题：/detector/armors
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Armors {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Armor 的数组：[] 表示长度不固定
    pub armors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Armor>,

}



impl Default for Armors {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rm_interfaces__msg__Armors__init(&mut msg as *mut _) {
        panic!("Call to rm_interfaces__msg__Armors__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Armors {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Armors__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Armors__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Armors__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Armors {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Armors where Self: Sized {
  const TYPE_NAME: &'static str = "rm_interfaces/msg/Armors";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__Armors() }
  }
}


#[link(name = "rm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__ArmorPose() -> *const std::ffi::c_void;
}

#[link(name = "rm_interfaces__rosidl_generator_c")]
extern "C" {
    fn rm_interfaces__msg__ArmorPose__init(msg: *mut ArmorPose) -> bool;
    fn rm_interfaces__msg__ArmorPose__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ArmorPose>, size: usize) -> bool;
    fn rm_interfaces__msg__ArmorPose__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ArmorPose>);
    fn rm_interfaces__msg__ArmorPose__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ArmorPose>, out_seq: *mut rosidl_runtime_rs::Sequence<ArmorPose>) -> bool;
}

// Corresponds to rm_interfaces__msg__ArmorPose
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// ArmorPose —— "这块板在现实中哪里"（解算节点填，发给跟踪节点）
/// 解算 = 拿 Armor 的 4 个像素点 + 相机标定参数，
///        用 PnP 算法算出三维位置和朝向
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmorPose {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// 把检测那张表原样带过来（颜色/编号/置信度），
    /// 下一个节点不用再回头查
    pub armor: super::super::msg::rmw::Armor,

    /// 板子中心的三维坐标 (x, y, z)，单位米
    /// 例如 (2.1, 0.3, -0.1) = 右前方 2 米多
    pub position: geometry_msgs::msg::rmw::Point,

    /// 板子朝向角，单位弧度
    /// 正对我们时接近 0，侧对时较大
    pub yaw: f32,

}



impl Default for ArmorPose {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rm_interfaces__msg__ArmorPose__init(&mut msg as *mut _) {
        panic!("Call to rm_interfaces__msg__ArmorPose__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ArmorPose {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__ArmorPose__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__ArmorPose__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__ArmorPose__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ArmorPose {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ArmorPose where Self: Sized {
  const TYPE_NAME: &'static str = "rm_interfaces/msg/ArmorPose";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__ArmorPose() }
  }
}


#[link(name = "rm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__ArmorPoses() -> *const std::ffi::c_void;
}

#[link(name = "rm_interfaces__rosidl_generator_c")]
extern "C" {
    fn rm_interfaces__msg__ArmorPoses__init(msg: *mut ArmorPoses) -> bool;
    fn rm_interfaces__msg__ArmorPoses__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ArmorPoses>, size: usize) -> bool;
    fn rm_interfaces__msg__ArmorPoses__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ArmorPoses>);
    fn rm_interfaces__msg__ArmorPoses__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ArmorPoses>, out_seq: *mut rosidl_runtime_rs::Sequence<ArmorPoses>) -> bool;
}

// Corresponds to rm_interfaces__msg__ArmorPoses
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// ArmorPoses —— 一帧中全部解算完的装甲板（打包发出）
/// 对应话题：/solver/armors
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmorPoses {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub armors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ArmorPose>,

}



impl Default for ArmorPoses {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rm_interfaces__msg__ArmorPoses__init(&mut msg as *mut _) {
        panic!("Call to rm_interfaces__msg__ArmorPoses__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ArmorPoses {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__ArmorPoses__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__ArmorPoses__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__ArmorPoses__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ArmorPoses {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ArmorPoses where Self: Sized {
  const TYPE_NAME: &'static str = "rm_interfaces/msg/ArmorPoses";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__ArmorPoses() }
  }
}


#[link(name = "rm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__Target() -> *const std::ffi::c_void;
}

#[link(name = "rm_interfaces__rosidl_generator_c")]
extern "C" {
    fn rm_interfaces__msg__Target__init(msg: *mut Target) -> bool;
    fn rm_interfaces__msg__Target__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Target>, size: usize) -> bool;
    fn rm_interfaces__msg__Target__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Target>);
    fn rm_interfaces__msg__Target__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Target>, out_seq: *mut rosidl_runtime_rs::Sequence<Target>) -> bool;
}

// Corresponds to rm_interfaces__msg__Target
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// Target —— "敌车整车在哪、怎么动"（跟踪节点填，发给决策节点）
/// 跟踪节点连续观察很多帧，用 EKF（卡尔曼滤波）估计整车运动状态
/// 有了这些量，决策节点才能预测"0.1 秒后装甲板转到哪"
/// 对应话题：/tracker/target
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Target {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// 还锁定着目标吗？false = 跟丢了，决策节点应停火停控
    pub tracking: bool,

    /// 跟踪的是几号车（敌车可能有多辆，要锁定一辆打）
    pub number: u8,

    /// 这辆车身上有几块板：
    /// 普通车 4 块，平衡步兵 2 块，前哨站 3 块
    /// 知道数量才能算出"下一块板什么时候转过来"
    pub armor_num: u8,

    /// 整车旋转中心的位置（注意：不是某块板，是车中心）
    pub position: geometry_msgs::msg::rmw::Point,

    /// 车往哪跑、多快（x/y/z 三个方向的速度）
    pub velocity: geometry_msgs::msg::rmw::Vector3,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rm_interfaces__msg__Target__init(&mut msg as *mut _) {
        panic!("Call to rm_interfaces__msg__Target__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Target {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Target__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Target__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__Target__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Target {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Target where Self: Sized {
  const TYPE_NAME: &'static str = "rm_interfaces/msg/Target";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__Target() }
  }
}


#[link(name = "rm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__GimbalCmd() -> *const std::ffi::c_void;
}

#[link(name = "rm_interfaces__rosidl_generator_c")]
extern "C" {
    fn rm_interfaces__msg__GimbalCmd__init(msg: *mut GimbalCmd) -> bool;
    fn rm_interfaces__msg__GimbalCmd__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GimbalCmd>, size: usize) -> bool;
    fn rm_interfaces__msg__GimbalCmd__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GimbalCmd>);
    fn rm_interfaces__msg__GimbalCmd__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GimbalCmd>, out_seq: *mut rosidl_runtime_rs::Sequence<GimbalCmd>) -> bool;
}

// Corresponds to rm_interfaces__msg__GimbalCmd
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// GimbalCmd —— "云台这么转、开不开火"（决策节点填，发给下位机）
/// CAN 节点订阅本消息，打包成 CAN 帧发给 C 板执行
/// 对应话题：/gimbal/cmd
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GimbalCmd {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rm_interfaces__msg__GimbalCmd__init(&mut msg as *mut _) {
        panic!("Call to rm_interfaces__msg__GimbalCmd__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GimbalCmd {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__GimbalCmd__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__GimbalCmd__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__GimbalCmd__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GimbalCmd {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GimbalCmd where Self: Sized {
  const TYPE_NAME: &'static str = "rm_interfaces/msg/GimbalCmd";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__GimbalCmd() }
  }
}


#[link(name = "rm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__GimbalState() -> *const std::ffi::c_void;
}

#[link(name = "rm_interfaces__rosidl_generator_c")]
extern "C" {
    fn rm_interfaces__msg__GimbalState__init(msg: *mut GimbalState) -> bool;
    fn rm_interfaces__msg__GimbalState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GimbalState>, size: usize) -> bool;
    fn rm_interfaces__msg__GimbalState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GimbalState>);
    fn rm_interfaces__msg__GimbalState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GimbalState>, out_seq: *mut rosidl_runtime_rs::Sequence<GimbalState>) -> bool;
}

// Corresponds to rm_interfaces__msg__GimbalState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// GimbalState —— "云台现在什么状态"（下位机上报，CAN 节点填）
/// 方向反过来：下位机 -> 视觉
/// 没有这张表，Armor 的像素位置就是死数据——
/// 解算必须知道"拍照那一瞬间相机朝哪"
/// 对应话题：/gimbal/state
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GimbalState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// 云台 IMU 四元数 = 云台当前的姿态
    /// 解算节点用它把像素位置换算成现实位置
    pub quaternion: geometry_msgs::msg::rmw::Quaternion,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !rm_interfaces__msg__GimbalState__init(&mut msg as *mut _) {
        panic!("Call to rm_interfaces__msg__GimbalState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GimbalState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__GimbalState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__GimbalState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { rm_interfaces__msg__GimbalState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GimbalState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GimbalState where Self: Sized {
  const TYPE_NAME: &'static str = "rm_interfaces/msg/GimbalState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__rm_interfaces__msg__GimbalState() }
  }
}



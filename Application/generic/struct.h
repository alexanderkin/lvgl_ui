﻿#ifndef STRUCT_H
#define STRUCT_H

#include "./enum.h"

//通用事件接口，所有事件结构体第一个成员都要是它
typedef struct EventTypeInterface {
    event_type_t event_type;        //事件类型
    windows_t destination;          //事件发送的目的地，指定为EndWindow则是发送到当前活动窗口
} i_event_type_t;

//按键事件
typedef struct KeyEvent {
    i_event_type_t i_event;         //通用事件接口
    key_type_t key_id;              //按键id
} key_event_t;

#endif // STRUCT_H

#ifndef STRUCT_H
#define STRUCT_H

#include <stdint.h>
#include "./enum.h"

//通用事件接口，所有事件类型结构体第一个成员都要是它
typedef struct EventTypeInterface {
    event_type_t event_type;        //事件类型
    windows_t destination;          //事件发送的目的地，指定为EndWindow则是发送到当前活动窗口
} event_type_i;

//按键事件
typedef struct KeyEvent {
    event_type_i ievent;            //通用事件接口
    key_type_t key_id;              //按键id
} key_event_t;

typedef struct LineEditChangeEvent {
    event_type_i ievent;            //通用事件接口
    const char* value;              //值
} line_edit_change_event_t;

#endif // STRUCT_H

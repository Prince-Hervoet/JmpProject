//
// Created by Jammer on 2023-10-27.
//
#include "simple_ctx.h"
#include <cstring>

namespace relaxing {

static void linkJumpToFunc() {

}


void JumpTo(SimpleCtx *current, SimpleCtx *target) {

  // 跳转函数
  JumpTo_asm(current, target);
}
}

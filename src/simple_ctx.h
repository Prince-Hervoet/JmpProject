//
// Created by Jammer on 2023-10-27.
//

#ifndef RELAXING_ROUTINE__SIMPLE_CTX_H_
#define RELAXING_ROUTINE__SIMPLE_CTX_H_
#include <cstddef>
#include <cstring>
#define REGISTER_COUNT 18
#define REGISTER_RSP 13
#define REGISTER_RBP 14
#define REGISTER_RET 15
#define REGISTER_LINK 16

/**
 * registers[0] rbx 0
 * registers[1] rdi 8
 * registers[2] rsi 16
 * registers[3] rdx 24
 * registers[4] rcx 32
 * registers[5] r8  40
 * registers[6] r9  48
 * registers[7] r10 56
 * registers[8] r11 64
 * registers[9] r12 72
 * registers[10] r13 80
 * registers[11] r14 88
 * registers[12] r15 96
 * registers[13] rsp 104
 * registers[14] rbp 112
 * registers[15] ret 120
 * registers[16] link 128
 * registers[17] linkFunc 136
 */

namespace relaxing {

/**
 * 简单上下文结构体
 * 目前存放18个值，用于恢复寄存器等
 */
typedef struct SimpleCtx {
  void *registers[REGISTER_COUNT];
} SimpleCtx;

/**
 * 以下函数实现在汇编文件中，使用C语言编译是为了更好嵌入编译
 */
extern "C" {
extern void JumpTo_asm(relaxing::SimpleCtx *ctx1, relaxing::SimpleCtx *ctx2);
extern void SaveCtx_asm(relaxing::SimpleCtx *ctx);
extern void Test(relaxing::SimpleCtx *ctx1, relaxing::SimpleCtx *ctx2);
}

/**
 * 获取一个ctx结构，并初始化为0
 * @return SimpleCtx*
 */
static inline SimpleCtx *GetSimpleCtx() {
  auto ctx = new SimpleCtx();
  memset(ctx, 0, sizeof(SimpleCtx));
  return ctx;
}

void JumpTo(SimpleCtx *current, SimpleCtx *target);

static inline void TestFunc(relaxing::SimpleCtx *ctx1, relaxing::SimpleCtx *ctx2) {
  Test(ctx1, ctx2);
}

/**
 * 将当前上下文存储到指定上下文结构体中
 * @param ctx
 */
static inline void SaveCtx(SimpleCtx *ctx) {
  SaveCtx_asm(ctx);
}

/**
 * 设置栈指针
 * @param ctx
 * @param sp
 * @param size
 */
static inline void SetCtxSp(SimpleCtx *ctx, char *sp, size_t size) {
  ctx->registers[REGISTER_RSP] = sp + size - 100;
}

/**
 * 设置bp指针
 * @param ctx
 * @param bp
 */
static inline void SetCtxBp(SimpleCtx *ctx, char *bp) {
  ctx->registers[REGISTER_RBP] = bp;
}

/**
 * 设置入口函数地址
 * @param ctx
 * @param func
 */
static inline void SetCtxEntry(SimpleCtx *ctx, void *func) {
  ctx->registers[REGISTER_RET] = func;
}

/**
 * 设置返回链接地址
 * @param ctx
 * @param link
 */
static inline void SetCtxLink(SimpleCtx *ctx, SimpleCtx *link) {
	ctx->registers[REGISTER_LINK] = link;
}

/**
 * 获取栈指针地址
 * @param ctx
 * @return char*
 */
static inline char *GetCtxSp(SimpleCtx *ctx) {
  return (char *) (ctx->registers[13]);
}

}

#endif //RELAXING_ROUTINE__SIMPLE_CTX_H_

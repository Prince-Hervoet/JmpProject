.global SwapCtxAsm
SwapCtxAsm:
    leaq (%rsp),%rax
    movq %rax, 104(%rdi)
    movq %rbx, 0(%rdi)
    movq %rcx, 32(%rdi)
    movq %rdx, 24(%rdi)
    movq 0(%rax), %rax
    movq %rax, 120(%rdi)
    movq %rsi, 16(%rdi)
    movq %rdi, 8(%rdi)
    movq %rbp, 112(%rdi)
    movq %r8, 40(%rdi)
    movq %r9, 48(%rdi)
    movq %r12, 72(%rdi)
    movq %r13, 80(%rdi)
    movq %r14, 88(%rdi)
    movq %r15, 96(%rdi)
    xorq %rax, %rax

    movq 112(%rsi), %rbp
    movq 104(%rsi), %rsp
    movq 96(%rsi), %r15
    movq 88(%rsi), %r14
    movq 80(%rsi), %r13
    movq 72(%rsi), %r12
    movq 48(%rsi), %r9
    movq 40(%rsi), %r8
    movq 8(%rsi), %rdi
    movq 24(%rsi), %rdx
    movq 32(%rsi), %rcx
    movq 0(%rsi), %rbx
    leaq 8(%rsp), %rsp
    pushq 120(%rsi)
    movq 16(%rsi), %rsi
    ret



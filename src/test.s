.global JumpTo_asm, SaveCtx_asm, Test
JumpTo_asm:
    leaq 8(%rsp), %rax
    movq %rax, 104(%rcx)
    movq %rbp, 112(%rcx)
    movq %rbx, 0(%rcx)
    movq %rdi, 8(%rcx)
    movq %rsi, 16(%rcx)
    movq %r8, 40(%rcx)
    movq %r9, 48(%rcx)
    movq %r10, 56(%rcx)
    movq %r11, 64(%rcx)
    movq %r12, 72(%rcx)
    movq %r13, 80(%rcx)
    movq %r14, 88(%rcx)
    movq %r15, 96(%rcx)
    movq (%rsp), %rax
    movq %rax, 120(%rcx)

    movq 104(%rdx), %rax
    movq %rax, %rsp
    movq 112(%rdx), %rbp
    movq 0(%rdx), %rbx
    movq 8(%rdx), %rdi
    movq 16(%rdx), %rsi
    movq 40(%rdx), %r8
    movq 48(%rdx), %r9
    movq 56(%rdx), %r10
    movq 64(%rdx), %r11
    movq 72(%rdx), %r12
    movq 80(%rdx), %r13
    movq 88(%rdx), %r14
    movq 96(%rdx), %r15
    movq 120(%rdx), %rax
    pushq %rax

    retq

SaveCtx_asm:
    leaq (8)(%rsp), %rax
    movq %rax, (104)(%rcx)
    movq (%rsp), %rax
    movq %rax, (120)(%rcx)
    movq %rbp, (112)(%rcx)
    movq %rbx, (0)(%rcx)
    movq %rdi, (8)(%rcx)
    movq %rsi, (16)(%rcx)
    movq %r8, (40)(%rcx)
    movq %r9, (48)(%rcx)
    movq %r10, (56)(%rcx)
    movq %r11, (64)(%rcx)
    movq %r12, (72)(%rcx)
    movq %r13, (80)(%rcx)
    movq %r14, (88)(%rcx)
    movq %r15, (96)(%rcx)

    retq

Test:
    leaq 8(%rsp), %rax
    movq %rax, 104(%rcx)
    movq %rbp, 112(%rcx)
    movq %rbx, 0(%rcx)
    movq %rdi, 8(%rcx)
    movq %rsi, 16(%rcx)
    movq %r8, 40(%rcx)
    movq %r9, 48(%rcx)
    ; movq %r10, 56(%rcx)
    ; movq %r11, 64(%rcx)
    movq %r12, 72(%rcx)
    movq %r13, 80(%rcx)
    movq %r14, 88(%rcx)
    movq %r15, 96(%rcx)
    movq (%rsp), %rax
    movq %rax, 120(%rcx)
    xorq %rax, %rax

    movq 104(%rdx), %rax
    movq %rax, %rsp
    movq 112(%rdx), %rbp
    movq 0(%rdx), %rbx
    movq 8(%rdx), %rdi
    movq 16(%rdx), %rsi
    movq 40(%rdx), %r8
    movq 48(%rdx), %r9
    ; movq 56(%rdx), %r10
    ; movq 64(%rdx), %r11
    movq 72(%rdx), %r12
    movq 80(%rdx), %r13
    movq 88(%rdx), %r14
    movq 96(%rdx), %r15
    movq 120(%rdx), %rax
    pushq %rax
    retq


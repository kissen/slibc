	.text
	.globl	slibc_syscall6
slibc_syscall6:
	pushq   %r10

	movq	%rdi, %rax
	movq	%rsi, %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	movq	%r8, %r10
	movq	%r9, %r8
	movq	16(%rsp), %r9
	syscall

	popq	%r10
	ret

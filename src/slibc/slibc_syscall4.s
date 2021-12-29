	.text
	.globl	slibc_syscall4
slibc_syscall4:
	pushq   %r10

	movq	%rdi, %rax
	movq	%rsi, %rdi
	movq	%rdx, %rsi
	movq	%rcx, %rdx
	movq	%r8, %r10
	syscall

	popq	%r10
	ret

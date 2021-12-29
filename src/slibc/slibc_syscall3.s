	.text
	.globl	slibc_syscall3
slibc_syscall3:
	movq    %rdi, %rax
	movq 	%rsi, %rdi
	movq 	%rdx, %rsi
	movq 	%rcx, %rdx
	syscall
	ret

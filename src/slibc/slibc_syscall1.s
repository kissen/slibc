	.text
	.globl	slibc_syscall1
slibc_syscall1:
	movq    %rdi, %rax
	movq 	%rsi, %rdi
	syscall
	ret

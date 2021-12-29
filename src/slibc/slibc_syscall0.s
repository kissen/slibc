	.text
	.globl	slibc_syscall0
slibc_syscall0:
	movq    %rdi, %rax
	syscall
	ret

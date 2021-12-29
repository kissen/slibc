slibc_syscall2:
	movq    %rdi, %rax
	movq 	%rsi, %rdi
	movq 	%rdx, %rsi
	syscall
	ret

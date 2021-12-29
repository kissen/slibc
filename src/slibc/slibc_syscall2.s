slibc_syscall2:
	movq    %rdi, %rax  // system call number
	movq 	%rsi, %rdi  // first argument
	movq 	%rdx, %rsi  // second argument
	syscall
	ret

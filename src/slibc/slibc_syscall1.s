slibc_syscall1:
	movq    %rdi, %rax  // system call number
	movq 	%rsi, %rdi  // first argument
	syscall
	ret

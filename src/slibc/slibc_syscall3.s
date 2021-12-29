slibc_syscall3:
	movq    %rdi, %rax  // system call number
	movq 	%rsi, %rdi  // first argument
	movq 	%rdx, %rsi  // second argument
	movq 	%rcx, %rdx  // third argument
	syscall
	ret

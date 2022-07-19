// Based on previous work https://git.musl-libc.org/cgit/musl/tree/src/setjmp/x86_64/setjmp.s?h=rs-1.0,
// Copyright 2011-2012 Nicholas J. Kain, modifications for slibc Copyright 2022 Andreas Schärtl,
// licensed under standard MIT License

	.text
	.globl	setjmp
setjmp:
	mov %rbx, (%rdi)
	mov %rbp, 8(%rdi)
	mov %r12, 16(%rdi)
	mov %r13, 24(%rdi)
	mov %r14, 32(%rdi)
	mov %r15, 40(%rdi)
	lea 8(%rsp), %rdx
	mov %rdx, 48(%rdi)
	mov (%rsp), %rdx
	mov %rdx, 56(%rdi)
	xor %eax, %eax
	ret
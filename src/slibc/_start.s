// Based on https://github.com/runtimejs/musl-libc/blob/master/crt/x86_64/crt1.s
// written in 2011 by Nicholas J. Kain. Released to the public domain.

	.text
	.globl	_start
_start:
	xor     %rbp, %rbp
	pop	    %rdi
	mov	    %rsp, %rsi
	call    slibc_start
end:
	jmp     end

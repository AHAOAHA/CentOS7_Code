	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"/dev/pts/1"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movabsq	$11473676690792, %rax
	movq	%rax, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movl	$1, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -4(%rbp)
.L2:
	leaq	-48(%rbp), %rcx
	movl	-4(%rbp), %eax
	movl	$32, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	movl	$1, %edi
	call	sleep
	jmp	.L2
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits

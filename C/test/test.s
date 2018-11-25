	.file	"test.c"
	.globl	test_val
	.data
	.align 4
	.type	test_val, @object
	.size	test_val, 4
test_val:
	.long	1000
	.align 4
	.type	test2_val, @object
	.size	test2_val, 4
test2_val:
	.long	2000
	.section	.rodata
.LC0:
	.string	"hello world"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$10, -4(%rbp)
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.data
	.align 4
	.type	test1_val.2181, @object
	.size	test1_val.2181, 4
test1_val.2181:
	.long	200
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits

	.file	"2done.c"
	.text
	.globl	cmpfunc
	.type	cmpfunc, @function
cmpfunc:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	%eax, %edx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	subl	%eax, %edx
	movl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	cmpfunc, .-cmpfunc
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%lld"
.LC2:
	.string	"%lld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$800048, %rsp
	leaq	-800044(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	jmp	.L4
.L10:
	movq	$0, -800032(%rbp)
	leaq	-800040(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movq	$0, -800024(%rbp)
	jmp	.L5
.L6:
	leaq	-800016(%rbp), %rax
	movq	-800024(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addq	$1, -800024(%rbp)
.L5:
	movq	-800040(%rbp), %rax
	cmpq	%rax, -800024(%rbp)
	jl	.L6
	movq	-800040(%rbp), %rax
	movq	%rax, %rsi
	leaq	-800016(%rbp), %rax
	movl	$cmpfunc, %ecx
	movl	$8, %edx
	movq	%rax, %rdi
	call	qsort
	movq	$0, -800024(%rbp)
	jmp	.L7
.L9:
	movq	-800024(%rbp), %rax
	movq	-800016(%rbp,%rax,8), %rdx
	movq	-800040(%rbp), %rax
	subq	-800024(%rbp), %rax
	cmpq	%rax, %rdx
	jl	.L8
	movq	-800040(%rbp), %rax
	subq	-800024(%rbp), %rax
	cmpq	-800032(%rbp), %rax
	jle	.L8
	movq	-800040(%rbp), %rax
	subq	-800024(%rbp), %rax
	movq	%rax, -800032(%rbp)
.L8:
	addq	$1, -800024(%rbp)
.L7:
	movq	-800040(%rbp), %rax
	cmpq	%rax, -800024(%rbp)
	jl	.L9
	movq	-800032(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
.L4:
	movl	-800044(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -800044(%rbp)
	testl	%eax, %eax
	jne	.L10
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

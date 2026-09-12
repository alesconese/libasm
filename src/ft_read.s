global ft_read

; =======================================
; ssize_t	ft_read(int fd, const void *buf, size_t count);
;
; fd		->	rdi
; *buf		->	rsi
; count		->	rdx
; return	->	rax
; =======================================

extern __errno_location

section .text

ft_read:
	mov		rax, 0						; Load the syscall number for read (0) into rax
	syscall								; Execute the syscall. Arguments are passed in the same registers we received them (rdi, rsi, rdx)
	test	rax, rax					; Perform bitwise AND on the return value to set Sign Flag. SF = 1 if negative (error)
	js		.error						; Jump to error handling if SF = 1 (error returned). Error code stored in rax
	ret									; If no error, return the number of bytes written (in rax)

.error:
	neg		rax							; Negate rax to get positive errno code
	push	rax							; Push errno code to stack temporarily. This also aligns rsp to th 16-byte boundary needed to perform a call to a C library
	call	__errno_location wrt ..plt	; Call __errno_location to save its address in rax. Procedure Linkage Table needed for Position Independent Executable
	pop		rcx							; Pop errno code from stack into rcx. Realign rsp again after the call instruction
	mov		[rax], rcx					; Store errno code at the address returned by __errno_location
	mov		rax, -1						; Set return value to -1 to indicate error
	ret
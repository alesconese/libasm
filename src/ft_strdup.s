global ft_strdup

; =======================================
; char *ft_strdup(const char *s)
;
; *s		->	rdi
; return	->	rax
; =======================================

extern malloc
extern ft_strlen
extern ft_strcpy

section .text

ft_strdup:
	push	rdi					; Save the input to the stack temporarily. This also aligns rsp to th 16-byte boundary needed to perform a call to a C library
	call	ft_strlen			; Get the length of the input, passed in the same register we received it
	mov		rdi, rax			; Move the return value to rdi to be used as the argument for calling malloc
	inc		rdi					; Add 1 to the length to fit the NULL-terminating character ('\0')
	call	malloc wrt ..plt	; Allocate memory for the string + '\0'. Address is returned in rax. Procedure Linkage Table needed for Position Independent Executable
	test	rax, rax			; Perform a test instruction on the return. If malloc failed this will set the zero-flag (ZF)
	jz		.malloc_error		; Jump if malloc returned 0 (NULL)
	mov		rdi, rax			; Save the address returned by malloc on rdi to use as *dst argument for calling ft_strcpy
	mov		rsi, [rsp]			; Retrieve the function input we previously pushed to the stack, with mov instead of pop to avoid misaligning it
	call	ft_strcpy			; Call our strcpy function with the malloc'd address as *dst on rsi and the input string as *src on rsi
	add		rsp, 8				; Shift rsp by 8 bytes so it points to the orginal address before the initial push instruction
	ret							; Return the malloc'd address filled by ft_strcpy

.malloc_error:
	add		rsp, 8				; Shift rsp by 8 bytes so it points to the orginal address before the initial push instruction
	xor		rax, rax			; Reset rax to 0 to return NULL, indicating an error
	ret
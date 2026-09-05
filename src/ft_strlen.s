global ft_strlen

; =======================================
; size_t ft_strlen(const char *s)
;
; *s		->	rdi
; return	->	rax
; =======================================

section .text

ft_strlen:
	mov		rax, -1					; Init rax (our char counter) to -1 to work with the loop logic

.counter:
	inc		rax						; Increase the counter at the start of the loop (set it to 0 the first time)
	cmp		byte [rdi + rax], 0		; Check the content of the current byte of the input string
	jne		.counter				; If it's anything other than 0, loop to go to the next byte
	ret								; Else return the index of the position where 0 is found
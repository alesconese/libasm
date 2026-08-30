global ft_strlen

; =======================================
; size_t ft_strlen(const char *s)
;
; *s		->	rdi
; return	->	rax
; =======================================

section .text

ft_strlen:
	xor		rax, rax		; Init rax to 0

.counter
	cmp		byte [rdi + rax], 0
	inc		rax
	jne		.counter
	ret
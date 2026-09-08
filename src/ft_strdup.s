global ft_strdup

; =======================================
; char *ft_strdup(const char *s)
;
; *s		->	rdi
; return	->	rax
; =======================================

section .text

ft_strdup:


	mov		rax, -1					; Init rax (our char index) to -1 to work with the loop logic

.copy_char:
	inc		rax						; Increase the index at the start of the loop (set it to 0 the first time)
	mov		cl, byte [rsi + rax]	; Copy the source string character at the current index to a tmp register
	mov		byte [rdi + rax], cl	; Then copy from that register to the destination string at the same index
	cmp		byte [rsi + rax], 0		; Check if the copied char is 0 (NULL-Terminating character)
	jne		.copy_char				; If it isnt, jump to the start of the loop
	mov		rax, rdi				; Copy the destination string to rax to return it
	ret
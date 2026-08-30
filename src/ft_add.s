global ft_add

; =======================================
; int ft_add(int a, int b)
;
; a			->	rdi
; b			->	rsi
; return	->	rax
; =======================================

section .text

ft_add:
	xor		rax, rax		; Init rax to 0
    mov     rax, rdi        ; Move 1st parameter (a) into return register rax
    add     rax, rsi        ; Add 2nd parameter (b) to rax
    ret                     ; Return (rax now holds a + b)
global ft_strcmp

; =======================================
; int		ft_strcmp(const char *s1, const char *s2)
;
; *s1		->	rdi
; *s2		->	rsi
; return	->	rax
; =======================================

section .text

ft_strcmp:
	mov		rcx, -1					; Init rax (our char index) to -1 to work with the loop logic

.copy_char:
	inc		rcx						; Increase the index at the start of the loop (set it to 0 the first time)
	movzx	rax, byte [rdi + rcx]	; Copy the char at the current index of s1 into the return register, with zero-extension
	movzx	rdx, byte [rsi + rcx]	; Copy the char at the current index of s1 into the tmp register, with zero-extension 
	cmp		rax, rdx				; Compare the values of the 2 characters
	jne		.diff					; If not the same, jump to the end of the function
	cmp		rax, 0					; Check if they are the same value but it is equal to 0 (NULL-Terminating char)
	jne		.copy_char				; If not 0, jump to the start of the loop to check the next char

.diff:
	sub		rax, rdx				; Calculate the difference in the last checked character, then return the result
	ret								; Will be positive if s1[i]>s2[i], negative if s1[i]<s2[i], or 0 if s1[i]=s2[i]
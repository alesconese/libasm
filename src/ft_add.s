global ft_add

section .text

ft_add:
    mov     rax, rdi        ; Move 1st parameter (a) into return register rax
    add     rax, rsi        ; Add 2nd parameter (b) to rax
    ret                     ; Return (rax now holds a + b)
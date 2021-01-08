; ----------------------------------------------------------------------------------------
;       size_t  ft_strlen(const char *s);
; ----------------------------------------------------------------------------------------

global ft_strlen ;		declaring function
section .text

ft_strlen : 
mov rax, 0 ;
cmp rdi, 0 ;
je exit ;

count :
cmp BYTE [rax + rdi], 0 ;	cmp actual char and '\0'
je exit ;			setting exit value to '0' (je = 0 value)
inc rax ; 			
jmp count

exit : 
ret

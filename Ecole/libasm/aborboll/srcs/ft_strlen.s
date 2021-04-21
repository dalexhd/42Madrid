; ft_strlen Function

;
;  @param	{const char *s}	The string to calculate
;  @desc	Calculates the length of the string pointed to by s,
; 			excluding the terminating null byte ('\0')
;  @returns	Number of characters in the string pointed to by s
;

; ------------------
; C Implementation
; ------------------
; size_t	ft_strlen(const char *s)

section	.text
	global	_ft_strlen

_ft_strlen:
	mov		rax, 0
	jmp		increment

increment:
	cmp		BYTE [rax + rdi], 0
	je		done
	inc		rax
	jmp		increment

done:
	ret
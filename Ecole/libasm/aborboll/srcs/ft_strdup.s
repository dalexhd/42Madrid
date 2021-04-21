; ft_strdup Function

;
;  @param	{const char *s1}	The string
;  @desc	The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.
;			The pointer may subsequently be used as an argument to the function free(3).
;

; ------------------
; C Implementation
; ------------------
; char	*ft_strdup(const char *s1)

section	.text
	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

_ft_strdup:
	call	_ft_strlen
	mov		rcx, rax
	inc		rcx
	push	rdi
	mov		rdi, rcx
	call	_malloc
	cmp		rax, 0
	je		done
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy
	jmp		done

done:
	ret
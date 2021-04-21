; ft_strcpy Function

;
;  @desc	The strcpy() and strncpy() functions return dst.  The stpcpy() and stpncpy() functions return a pointer to the terminating `\0' character of dst.
;           If stpncpy() does not terminate dst with a NUL character, it instead returns a pointer to dst[n] (which does not necessarily refer to a valid memory location.)
;

; ------------------
; C Implementation
; ------------------
; char	*ft_strcpy(char *dst, const char *src)

section	.text
	global	_ft_strcpy

_ft_strcpy:
	mov		rax, rdi
	mov		rcx, 0

compare:
	cmp		byte [rsi + rcx], 0
	je		done
	mov		dl, [rsi + rcx]
	mov		[rax + rcx], dl
	inc		rcx
	jmp		compare
	
done:
	mov		byte[rax + rcx], 0
	ret

; ft_strcmp Function

;
;  @desc	The strcmp() and strncmp() functions lexicographically compare the null-terminated strings s1 and s2.
;

; ------------------
; C Implementation
; ------------------
; int	ft_strcmp(const char *s1, const char *s2)

section	.text
	global	_ft_strcmp

_ft_strcmp:
	mov 	rax, 0
	jmp		compare

compare:
	mov		al, BYTE [rdi]
	mov		bl, BYTE [rsi]
	cmp		al, 0
	je		done
	cmp		bl, 0
	je		done
	cmp		al, bl
	jne		done
	inc		rdi
	inc		rsi
	jmp		compare

done:
	movzx	rax, al
	movzx	rbx, bl
	sub		rax, rbx
	ret
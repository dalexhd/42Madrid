; ft_write Function

;
;  @param	{int fildes}	The file descriptor
;  @param	{const void *buf}	The buffer
;  @param	{size_t *nbyte}	The buffer number
;

; ------------------
; C Implementation
; ------------------
; size_t	ft_write(int fildes, void *buf, size_t nbyte)

section.text:
	global	_ft_write
	extern	___error

_ft_write:
	mov		rax, 0x2000004
	syscall
	jc		error
	jmp		done

error:
	push	rax
	call	___error
	pop		rbx
	mov		[rax], rbx
	mov		rax, -1
	jmp		done

done:
	ret
; ft_read Function

;
;  @param	{int fildes}	The file descriptor
;  @param	{const void *buf}	The buffer
;  @param	{size_t *nbyte}	The buffer number
;

; ------------------
; C Implementation
; ------------------
; size_t	ft_read(int fildes, void *buf, size_t nbyte)


section.text:
	global	_ft_read
	extern	___error

_ft_read:
	mov		rax, 0x2000003
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
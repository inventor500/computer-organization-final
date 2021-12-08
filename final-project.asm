;;  ___                         ____
;; |_ _|___  __ _  __ _  ___   / ___| __ _ _ __   ___  _   _ _ __   __ _
;;  | |/ __|/ _` |/ _` |/ __| | |  _ / _` | '_ \ / _ \| | | | '_ \ / _` |
;;  | |\__ \ (_| | (_| | (__  | |_| | (_| | | | | (_) | |_| | | | | (_| |
;; |___|___/\__,_|\__,_|\___|  \____|\__,_|_| |_|\___/ \__,_|_| |_|\__, |
;;                                                                 |___/
	global swap, average, gcd_iter, gcd_recur, sort
	section .text

swap:
	mov rax, [rdi]
	mov rdx, [rsi]
	mov [rdi], rdx
	mov [rsi], rax
	ret

average:
	xor r8, r8
	xor rax, rax
	jmp sum_average
sum_average:
	add rax, [rdi+8*r8]
	inc r8
	cmp r8, rsi
	je divide_average
	jmp sum_average
divide_average:
	cvtsi2sd xmm0, rax
	cvtsi2sd xmm1, rsi
	divsd xmm0, xmm1
	ret

gcd_iter:
	;; r8 has lesser value, r9 has greater
	cmp rdi, rsi
	cmovl r8, rdi
	cmovl r9, rsi
	cmovg r9, rdi
	cmovg r8, rsi
	;; Special case where rdi or rsi was 0
	cmp r8, 0
	je euclid_iter_0
	jmp euclid_iter
euclid_iter:
	mov rax, r9
	cqo
	idiv r8
	cmp rdx, 0
	je euclid_iter_end
	mov r9, r8
	mov r8, rdx
	jmp euclid_iter
euclid_iter_end:
	mov rax, r8
	ret
euclid_iter_0:
	mov rax, 1
	ret

gcd_recur:
	;; r8 has lesser value, r9 has greater
	cmp rdi, rsi
	cmovl r8, rdi
	cmovl r9, rsi
	cmovg r9, rdi
	cmovg r8, rsi
	cmp r8, 0
	je euclid_recur_0
	jmp euclid_recur
euclid_recur:	
	mov rax, r9
	cqo
	idiv r8
	cmp rdx, 0
	je euclid_recur_end
	mov r9, r8
	mov r8, rdx
	call euclid_recur
euclid_recur_end:
	mov rax, r8
	ret
euclid_recur_0:
	mov rax, 1
	ret

sort:
	;; r9: current position
	mov r9, 1
	jmp sort_outer_loop
sort_outer_loop:
	cmp r9, rsi
	je sort_done
	jmp sort_inner_loop
sort_inner_loop:
	mov rax, [rdi-8+8*r9]
	cmp rax, [rdi+8*r9]
	jg sort_swap
	inc r9
	jmp sort_outer_loop
sort_swap:
	mov r8, [rdi+8*r9]
	mov [rdi-8+8*r9], r8
	mov [rdi+8*r9], rax
	;; If r9 is 1, then there is only one element to the left.
	cmp r9, 1
	je sort_inner_loop
	dec r9
	jmp sort_inner_loop
sort_done:
	ret

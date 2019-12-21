; Fr2md, Farid Rajabi Nia, 11 am
; optima: using sar to devide by two rather than idiv
 

    global threexplusone
    section .text


        
threexplusone:
        xor     rax,rax
	cmp     rdi, 1		;base case for recure
	je  	end		;if yes, go to end of the program
	;push    rdi		;push rdi before call
	jmp 	recure		;else continue
		
recure:
	;pop     rdi
	mov	rsi, rdi
	;push    rdi            ;push rdi before call
	sar  	rsi, 1		;test if even
	jnc  	even		;jump in case even
	;pop	rdi
	imul 	rdi, 3		;num*3
	inc  	rdi		;num*3+1
	;push    rdi		;push rdi before call
	call    threexplusone	
	inc 	rax		;count++
	jmp  	end
	
even:
	;pop    rdi
	sar 	rdi, 1		;divide by 2
	call 	threexplusone	
	inc 	rax		;count++
	jmp 	end

end:
	ret			;return value
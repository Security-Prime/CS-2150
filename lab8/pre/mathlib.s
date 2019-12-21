   
    global product
    global power

    section .text

product:
  
    mov rax, rdi         ; param 1 to rax
    mov rcx, rsi         ; param 2 to rbp       
    xor rdx, rdx         ;  sum
 
loop:
    cmp   rcx, 0         ;param 2 <=0      
    jle   end        

    add   rdx, rax       ;add
    dec   rcx            ;decrement
    jmp   loop           ;loop back

end:
    mov  rax,rdx
    ret  
    


power:
;prologue
              
        xor rdx, rdx         ;  result
                                
        cmp     rsi, 0      ;param 2 <=0
        jg      curse       ;jump into recursion
        mov     rdx, 1      ;base case return 1
        jmp     endl        ;jump to the end

curse:
; recursive body
        dec     rsi         ;decrement        
        call    power       ;call power again after decrement
        mov     rsi,rax
        call    product     ;multiply them together, returns modified rdx
        
endl:
; epilogue
        mov  rax,rdx    
          
        ret

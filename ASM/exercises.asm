-------------- 1 --------------
mov ax,0000
loop aa
cmp ax,0005
jne aa 
ret

a aa
inc ax
jmp (cmp)


-------------- 2 --------------
mov ax,0005
loop aa
cmp ax,0A
jne aa 
ret

a aa
dec ax
jmp (cmp)

-------------- 3 --------------
mov ax,0000
loop aa
cmp ax,0A
jne aa 
ret

a aa
add ax,0002
jmp (cmp)

-------------- 4 --------------
mov ax,2
mov bx,4
add ax,bx
div ax,2
cmp dx,0
jne bb
cmp ax,0B
jne aa
ret

a aa
inc ax
jmp (cmp ax,0B)


-------------- 5 --------------
mov bx,0003
mov cx,0004
loop aa
cmp ah,0C
jne aa
mov ax,0000 
ret

a aa
inc ax
jmp (cmp)

-------------- 6 --------------
mov ax,0004
mov bx,0003
loop aa
cmp ax,FF
jne aa 
ret

a aa
mul bx
inc ax
jmp (cmp)

-------------- 7 --------------

mov ax,5
cmp ah,5
jg aa
mov ax,1234
ret

AA
mov bx,ax
ret

-------------- 8 --------------

mov bx,5
cmp bl,7
jl aa
mov dx,bl
ret

AA
mov dl,bh
ret

3.
mov ax,5
mov bx,5
div bx
cmp al,2
jg aa
mov bx,ab
re

AA
inc bx
ret

-------------- 9 --------------

mov ax,5
mov bx,5
mul bx
cmp ax,35
jl aa	
xchg bh,bl
ret

AA
xchg ah,al
ret

-------------- 10 --------------

mov cx,5
mov dx,5
add cx,dx
cmp dh,0
jge aa
mov bx,2
ret

AA
mov ax,1
ret

-------------- 11 --------------

mov bx,5
mov cx,5
mov dx,5
add dx,bx
add dx,cx
xchg dh,dl
cmp dh,0
jne aa	
mul bx,cx
ret

AA
inc bl
ret

-------------- 12 --------------

mov ax,5
mov bx,3
div bx
cmp ah,0
je aa
mov cx,0
jmp bb

AA
mov cx,1
jmp bb

BB
cmp al,bx
je cc
add cx,4
ret

CC
add cx,2
ret

-------------- 13 --------------

mov ax,5
mov bx,2
div bx
cmp ah,0
je aa
mov cx,0
ret

AA 
mov cx,1
ret

-------------- 14 --------------

mov ax,5
mov bx,5
div bx
cmp ah,0	
je aa
dec ax
ret

AA
inc ax
ret


-------------- 15 --------------

mov ax,5
mov bx,6
cmp ax,bx	
jg aa
mov dx,bx
ret

AA
mov dx,ax
ret

-------------- 16 --------------

mov ax,5
mov bx,6
cmp ax,bx
jl aa
mov dx,bx
	ret

AA
mov dx,ax
ret

-------------- 17 --------------

mov ax,5
mov bx,6
cmp ax,bx
jg aa
ret

AA
xchg ax,bx
ret

-------------- 18 --------------

a
mov ax,0003
mov bx,0009
mul bx
add ax,000a
inc cx
push cx
cmp ax,100
jl (indirizzo add ax,000a)
mov ax,dx
cmp cx,10
jg aa
ret

a aa
pop cx
jmp (indirizzo ret)

-------------- 19 --------------

a
mov ax,0001
mov bx,0005
cmp ax,bx
jl aa
mul bx
mov cx,bx
cmp cx,0019
je bb
mov cx,0000
ret

a aa
inc ax
jmp (indirizzo cmp ax,bx)

a bb
mov cx,sp
ret

-------------- 20 --------------

a
mov ax,0004
mov bx,0002
mov cx,0003
mul cx
mov cx,ax
div bx
cmp ah,0000
je aa
mov sp,cx
mov sp,dx

a aa
mov sp,ax
jmp (indirizzo mov sp,dx)

-------------- 21 --------------

a
mov ax,0004
mov cx,0002
mov bx,0003
add ax,cx
mov dx,ax
inc bx
add dx,bx
cmp dx,f
jl (indirizzo inc bx)
mov ax,0002
div bx
cmp ah,0000
je aa
mul cx
mov ax,cx
ret

a aa
inc bx
jmp (indirizzo mul cx)

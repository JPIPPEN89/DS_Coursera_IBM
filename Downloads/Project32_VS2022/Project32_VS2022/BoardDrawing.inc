
.data

    Space EQU 32
    VertBar EQU 186
    HorizBar EQU 205
    CrossBar EQU 206
    Block EQU 219

    msgLocRow BYTE 18
    msgLocCol BYTE 7

.code

identCells PROC
    pushad

    mov ecx, 9
    mov al, 31h
    mov ebx, 0

    L1:
       mov dh, positions[ebx].row
       mov dl, positions[ebx].col
       call gotoxy

       call writechar

       inc al ;increments the char
       add ebx, CoorSize
    loop L1

    popad
    ret
identCells ENDP


oddLine PROC

    mov ebx, 2
    L2:
        mov ecx, 3
        mov al, Space
        L1:
            call writeChar
        Loop L1

        mov al, VertBar
        call writeChar
    dec ebx
    cmp ebx, 0
    jne L2

  ret
oddLine ENDP



evenLine PROC
    mov ecx, 3
    mov al, HorizBar
    L1:
        call writeChar
    Loop L1

    mov al, CrossBar
    call writeChar

    mov ecx, 3
    mov al, HorizBar
    L2:
        call writeChar
    Loop L2

    mov al, CrossBar
    call writeChar

    mov ecx, 3
    mov al, HorizBar
    L3:
        call writeChar
    Loop L3
  ret
evenLine ENDP




DrawBoard PROC
    call clrscr

    ;fixed location of board, row=10, col=10
    mov dh, 10
    mov dl, 10
    call gotoxy

    call oddLine ;first row

    inc dh
    call gotoxy
    call evenLine ;second row

    inc dh
    call gotoxy
    call oddLine ;third row

    inc dh
    call gotoxy
    call evenLine ;fourth row

    inc dh
    call gotoxy
    call oddLine  ;fifth row

    call identCells

  ret
DrawBoard ENDP

consoleMessage PROC, msg:DWORD
    pushad

    mov dh, msgLocRow
    mov dl, msgLocCol
    call gotoxy

    mov al, Space
    mov ecx, 100
    L1:
      call writechar
    Loop L1

    mov dh, msgLocRow
    mov dl, msgLocCol
    call gotoxy

    mov edx, msg
    call writestring

    popad
    ret
consoleMessage ENDP

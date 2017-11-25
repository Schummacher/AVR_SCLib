;This programm is so dangertous that please don't use this except need am operating system:)

OS:
	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6
	push r7
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	push r16
	push r17
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r28
	push r29
	push r30
	push r31

	;载入堆栈指针
	lds r31, SPH
	lds r30, SPL
	mov r3, r31
	mov r2, r30
	ldi r18, 38
	ldi r19, 0
	add r30, r18
	adc r31, r19
	;将堆栈指针中的数据读入
	ld r16, z+
	ld r17, z+
	;读入FLAG，做匹配
	
	lds r18, a
	dec r18
	brne changed
	sts a+1, r16
	sts a+2, r17
	lds r16, a+3
	lds r17, a+4
	ldi r18, 2
	ldi r28, 0x85
	ldi r29, 0x00
	ldi r26, 0x85
	ldi r27, 0x00
	jmp the_zero
changed:
	sts a+3, r16
	sts a+4, r17
	lds r16, a+1
	lds r17, a+2
	ldi r18, 1
	ldi r28, 0xA5
	ldi r29, 0x00
	ldi r26, 0x65
	ldi r27, 0x00
the_zero:
	sts a, r18
	st -z, r17
	st -z, r16

	ldi r16, 32
loop1:
	pop r17
	st -y, r17
	dec r16
	brne loop1

	ldi r16, 32
loop2:
	ld r17, x+
	push r17
	dec r16
	brne loop2

	pop r31
	pop r30
	pop r29
	pop r28
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r17
	pop r16
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r19
	pop r8
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0

	ret

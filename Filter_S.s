
/*
 * Filter_S.s
 *
 * Created: 2017/9/1 下午 8:59:34
 *  Author: schummacher
 */ 

 #include <avr/io.h>

 .global Filter_Average_ASM_8

 Filter_Average_ASM_8:
	push r30
	push r31
	push r22
	push r23

	movw r30, r24
	subi r24, 0xE0
	sbci r21, 0xFF

	ld r22, Z+
	ld r23, Z+
	movw r4, r22
	ld r22, Z+
	ld r23, Z+
	add r4, r22
	add r5, r23
	cp r30, r24
	cpc r31, r25
	brne .-14

	movw r24, r4
	andi r25, 0xF0
	swap r25
	swap r24
	andi r24, 0x0F
	mov r23, r5
	andi r23, 0x0F
	swap r23
	or r24, r23

	pop r23
	pop r22
	pop r31
	pop r30
	ret
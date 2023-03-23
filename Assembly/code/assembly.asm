.include "/sdcard/codes/m328Pdef.inc"
ldi r16,0b11111100
out DDRD,r16
ldi r16,0b00000001
out DDRB,r16

loop:
 in r17,PIND

;Taking A
ldi r24,0b00000100
mov r18,r17
and r18,r24
ldi r25,0b00000010
loopa:
lsr r18
dec r25
brne   loopa
.DEF A =r18

;Taking B
ldi r24,0b00001000
mov r19,r17
and r19,r24
ldi r25,0b00000011
loopb:
lsr r19
dec r25
brne   loopb
.DEF B =r19

;Taking C
ldi r24,0b00010000
mov r20,r17
and r20,r24
ldi r25,0b00000100
loopc:
lsr r20
dec r25
brne   loopc
.DEF C =r20

;Taking D 
ldi r24,0b00100000
mov r21,r17
and r21,r24
ldi r25,0b00000101
loopd:
lsr r21
dec r25
brne   loopd
.DEF D =r21

;Taking S0
ldi r24,0b01000000
mov r22,r17
and r22,r24
ldi r25,0b00000110
loope:
lsr r22
dec r25
brne	loope
.DEF S0 =r22

;Taking S1
ldi r24,0b10000000
mov r23,r17
and r23,r24
ldi r25,0b00000111
loopf:
lsr r23
dec r25
brne 	loopf
.DEF S1 =r23

mov r24,r22
com r24
.DEF S_0 =r24
mov r25,r23
com r25
.DEF S_1 =r25

and A,S_0
and A,S_1
and B,S0
and B,S_1
and C,S_0
and C,S1
and D,S0
and D,S1
or A,B
or A,C
or A,D

out PORTB,A

rjmp loop

Start:
rjmp Start

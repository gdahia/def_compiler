.data
__K: .word 0
__n: .word 0
__lo: .word 0
__hi: .word 0

.text
_f_print:
lw $a0, 4($sp)
li $v0, 1
syscall
li $v0, 11
li $a0, 0x0a
syscall
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_brute:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $0, 12($fp)
sw $0, 16($fp)
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __n
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_1
b _fi_1
_if_1:
li $a0, 1
b _end_f_brute
_fi_1:
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __K
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sw $a0, 12($fp)
_while_3:
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __K
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $a0, $t1
xori $a0, $a0, 1
beq $a0, $0, _end_while_3
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __lo
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $t1, $a0
xori $a0, $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __hi
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $a0, $t1
xori $a0, $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
sltu $a0, $0, $a0
sltu $t1, $0, $t1
and $a0, $t1, $a0
bne $a0, $0, _if_2
b _fi_2
_if_2:
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_brute
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 16($fp)
_fi_2:
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 12($fp)
b _while_3
_end_while_3:
lw $a0, 16($fp)
b _end_f_brute
_end_f_brute:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 8
addiu $sp, $sp, 16
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_solve:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $0, 20($fp)
sw $0, 24($fp)
lw $a0, 4($fp)
sw $a0, __n
lw $a0, 8($fp)
sw $a0, __K
lw $a0, 12($fp)
sw $a0, __lo
lw $a0, 16($fp)
sw $a0, __hi
lw $a0, __lo
sw $a0, 24($fp)
_while_4:
lw $a0, 24($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __hi
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $a0, $t1
xori $a0, $a0, 1
beq $a0, $0, _end_while_4
lw $a0, 20($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 24($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_brute
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 20($fp)
lw $a0, 24($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 24($fp)
b _while_4
_end_while_4:
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, 20($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_end_f_solve:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 16
addiu $sp, $sp, 24
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_main:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 22
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 17
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 5
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 56
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 42
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 8
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 8
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 119
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 99
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 10
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
_end_f_main:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 0
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

main:
sw $0, __K
sw $0, __n
sw $0, __lo
sw $0, __hi
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall

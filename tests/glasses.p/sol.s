.data

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

_f_solve:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
li $a0, 0
sw $a0, 12($fp)
sw $0, 16($fp)
sw $0, 20($fp)
_while_2:
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 50
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
sltu $a0, $0, $a0
sltu $t1, $0, $t1
and $a0, $t1, $a0
beq $a0, $0, _end_while_2
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
sw $fp, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
li $t1, -1
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $a0, $t1
bne $a0, $0, _if_1
b _fi_1
_if_1:
lw $a0, 8($fp)
sw $a0, 24($fp)
lw $a0, 4($fp)
sw $a0, 8($fp)
lw $a0, 24($fp)
sw $a0, 4($fp)
_fi_1:
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 16($fp)
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sw $a0, 20($fp)
lw $a0, 16($fp)
sw $a0, 4($fp)
lw $a0, 20($fp)
sw $a0, 8($fp)
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 12($fp)
b _while_2
_end_while_2:
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
bne $a0, $0, _if_2
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
b _fi_2
_if_2:
sw $fp, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
li $t1, -1
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_fi_2:
_end_f_solve:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 8
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
li $a0, 6
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 6
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 10
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 15
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 81
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 11
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 10
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 1290121
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 31002
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 49
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 120121
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1290381
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 999
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 99999
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
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall

.data
__MOD: .word 0

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

_f_mod:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __MOD
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 8($fp)
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __MOD
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
b _end_f_mod
_end_f_mod:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 8
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_f:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $0, 8($fp)
sw $0, 12($fp)
sw $0, 16($fp)
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 0
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_1
b _fi_1
_if_1:
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 0
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
b _end_f_f
_fi_1:
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_2
b _fi_2
_if_2:
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
b _end_f_f
_fi_2:
li $a0, 0
sw $a0, 8($fp)
li $a0, 1
sw $a0, 12($fp)
li $a0, 1
sw $a0, 16($fp)
_while_2:
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $t1, $a0
beq $a0, $0, _end_while_2
lw $a0, 12($fp)
sw $a0, 20($fp)
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 12($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 12($fp)
lw $a0, 20($fp)
sw $a0, 8($fp)
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 16($fp)
b _while_2
_end_while_2:
lw $a0, 12($fp)
b _end_f_f
_end_f_f:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 20
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_solve:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, __MOD
sw $fp, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -20
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_end_f_solve:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 8
addiu $sp, $sp, 8
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_main:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $0, 4($fp)
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 100
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 5
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 21
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 22
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 1000000
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 21
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 1021037
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 30
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
_end_f_main:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

main:
sw $0, __MOD
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall

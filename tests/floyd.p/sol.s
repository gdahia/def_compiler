.data
__step: .word 0
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
sw $a0, 12($fp)
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 12($fp)
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
addiu $sp, $sp, 8
addiu $sp, $sp, 12
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_f:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -12
lw $a0, __MOD
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, __step
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_mod
b _end_f_f
_end_f_f:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 4
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_solve:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $0, 16($fp)
sw $0, 20($fp)
li $a0, 1
sw $a0, 24($fp)
lw $a0, 8($fp)
sw $a0, __step
lw $a0, 12($fp)
sw $a0, __MOD
lw $a0, 4($fp)
sw $a0, 16($fp)
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
sw $a0, 20($fp)
_while_3:
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 20($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
beq $a0, $0, _end_while_3
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
sw $a0, 16($fp)
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
lw $a0, 20($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
sw $a0, 20($fp)
b _while_3
_end_while_3:
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
lw $a0, 20($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
sw $a0, 20($fp)
_while_4:
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 20($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
beq $a0, $0, _end_while_4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
lw $a0, 20($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
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
lw $a0, 24($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_end_f_solve:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 12
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
li $a0, 1892
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 42
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 7
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 1991
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 8081
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 56
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
sw $0, __step
sw $0, __MOD
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall

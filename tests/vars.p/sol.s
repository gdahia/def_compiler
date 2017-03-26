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

_f_f:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_1
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 12($fp)
_while_3:
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $a0, $t1
beq $a0, $0, _end_while_3
li $a0, 4
sw $a0, 16($fp)
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 16($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 12($fp)
b _while_3
_end_while_3:
b _fi_1
_if_1:
li $a0, 10
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 12($fp)
_while_4:
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $a0, $t1
beq $a0, $0, _end_while_4
li $a0, 2
sw $a0, 16($fp)
lw $a0, 12($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 16($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 12($fp)
b _while_4
_end_while_4:
_fi_1:
lw $a0, 4($fp)
b _end_f_f
_end_f_f:
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
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -24
li $a0, 5
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 7
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_f
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
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

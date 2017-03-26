.data
__MX: .word 0

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
sw $a0, 8($fp)
lw $a0, __MX
sw $a0, 12($fp)
_while_3:
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 12($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $t1, $a0
beq $a0, $0, _end_while_3
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 12($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 16($fp)
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $t1, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_1
lw $a0, 16($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 8($fp)
b _fi_1
_if_1:
lw $a0, 16($fp)
sw $a0, 12($fp)
_fi_1:
b _while_3
_end_while_3:
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_end_f_solve:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 4
addiu $sp, $sp, 16
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

_f_main:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 4($fp)
_while_4:
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1000000000
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $t1, $a0
beq $a0, $0, _end_while_4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 4($fp)
b _while_4
_end_while_4:
lw $a0, 4($fp)
sw $a0, __MX
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 42
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 109092190
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 999999999
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 80475327
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 424242424
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 24242424
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -16
li $a0, 199999289
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
sw $0, __MX
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall

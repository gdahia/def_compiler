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
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 42
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $a0, $t1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 8
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
sltu $a0, $0, $a0
sltu $t1, $0, $t1
and $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 42
li $t1, -1
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
li $t1, -1
mul $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
slt $a0, $t1, $a0
li $t1, -1
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 49181
li $t1, -1
mul $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
sltu $a0, $0, $a0
xori $a0, $a0, 1
sltu $a0, $0, $a0
xori $a0, $a0, 1
li $t1, -1
mul $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 5656
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
sltu $a0, $0, $a0
sltu $t1, $0, $t1
or $a0, $t1, $a0
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
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 56
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 42
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 42
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 56
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_solve
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 21921920
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 112121
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

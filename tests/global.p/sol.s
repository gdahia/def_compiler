.data
__glob: .word 0

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

_f_go:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, __glob
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
lw $a0, __glob
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
mul $a0, $t1, $a0
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, __glob
lw $a0, __glob
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 4
lw $t1, 4($sp)
addiu $sp, $sp, 4
div $t1, $a0
mflo $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 5
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($fp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
b _end_f_go
_end_f_go:
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
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 0
sw $a0, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 5
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_go
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 10
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_go
sw $a0, 0($sp)
addiu $sp, $sp, -4
sw $fp, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -8
li $a0, 42
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 5
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_go
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_go
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_go
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
sw $0, __glob
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall

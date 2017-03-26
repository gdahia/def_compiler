.data
__a: .word 0

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

_f_main:
move $fp, $sp
sw $ra, 0($sp)
addiu $sp, $sp, -4
lw $a0, __a
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 10
lw $t1, 4($sp)
addiu $sp, $sp, 4
sub $a0, $t1, $a0
sltu $a0, $0, $a0
xori $a0, $a0, 1
bne $a0, $0, _if_1
lw $a0, __a
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $t1, $a0
sw $a0, __a
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, __a
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
b _fi_1
_if_1:
sw $fp, 0($sp)
addiu $sp, $sp, -4
lw $a0, __a
sw $a0, 0($sp)
addiu $sp, $sp, -4
jal _f_print
_fi_1:
_end_f_main:
lw $ra, 4($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, 0
lw $fp, 4($sp)
addiu $sp, $sp, 4
j $ra

main:
sw $0, __a
sw $fp, 0($sp)
addiu $sp, $sp, -4
jal _f_main
li $v0, 10
syscall

#read 10 numbers and store in array. as entering, display the value entered. print all numbers after storing in array. print array in reverse order

.data 
int_array: .word 0:10
inputs: .asciiz "Enter 10 numbers to be stored in the array. "
num_entered: .asciiz "Numbers entered: "
space: .ascii " "

.text

main:
#asks user to input 10 items
li $v0,4
la $a0, inputs
syscall

#input int 1
li $v0, 5
syscall
sw $v0, int_array($t0)

#input int 2
li $v0, 5
syscall
sw $v0, int_array($t1)

#input int 3
li $v0, 5
syscall
sw $v0, int_array($t2)

#input int 4
li $v0, 5
syscall
sw $v0, int_array($t3)

#input int 5
li $v0, 5
syscall
sw $v0, int_array($t4)

#input int 6
li $v0, 5
syscall
sw $v0, int_array($t5)

#input int 7
li $v0, 5
syscall
sw $v0, int_array($t6)

#input int 8
li $v0, 5
syscall
sw $v0, int_array($t7)

#input int 9
li $v0, 5
syscall
sw $v0, int_array($t0)

#input int 10
li $v0, 5
syscall
sw $v0, int_array($t0)

#prints numbers entered
li $v0, 4
la $a0, num_entered
syscall
lw $a0, int_array($zero)
li $v0, 1
syscall
lw $a0, ($t1)
li $v0, 1
syscall
lw $a0, ($t2)
li $v0, 1
syscall
lw $a0, ($t3)
li $v0, 1
syscall
lw $a0, ($t4)
li $v0, 1
syscall
lw $a0, ($t5)
li $v0, 1
syscall
lw $a0, ($t6)
li $v0, 1
syscall
lw $a0, ($t7)
li $v0, 1
syscall
lw $a0, ($t8)
li $v0, 1
syscall
lw $a0, ($t9)
li $v0, 1
syscall

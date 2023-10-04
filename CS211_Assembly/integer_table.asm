#create a table of integers and make a menu that has several options of manipulating the table
#case 1: print the table
#case 2: add two rows together and place it in the third row, then print the new table
#case 3: multiply any row with a constant and replace the row
#case 4: find the max value in a row
#case 5: find the max value of the table
#case 6: exit the program


.data details: .asciiz “Anilsha T, Completed 05/08/2021”

array: .word 3, 5, 7, 9, 2
.word 12, 10, 8, 4, 7 .word 1, 2, 3, 4, 5
.word -3, -2, 4, -6, 1
.word 2, 1, 9, 13, 15

option1msg: .ascii “Menu options:\n1: Print the table” 
option2msg: .ascii “\n2: Add two rows and place it in the third row; then print the new table” 
option3msg: .ascii “\n3: Multiply any row with a constant and replace the same row with the new data” 
option4msg: .ascii “\n4: Find the max value of any row and print it” 
option5msg: .ascii “\n5: Find the max value of the entire table” 
option6msg: .ascii "\n6: Exit" 
enteroption: .asciiz "\nEnter an option: " 
row1message: .asciiz "Enter a row number: " 
row2message: .asciiz "Enter another row number: " 
row3message: .asciiz "Enter the destination row number: " 
constant: .asciiz "Enter a constant: " 
maxinrow: .asciiz "Max value in this row: " 
maxintable: .asciiz "Max value in the table: " 
space: .asciiz "    " 
newl: .asciiz "\n\n\n"


.text
main:
  #options li 
  $v0, 4 la 
  $a0, newl 
  syscall
  li $v0, 4 
  la $a0, option1msg 
  syscall

  li $v0, 5 
  syscall	
  move $t1, $v0                 #t1= user input option
  
#branching	
  li $t2, 1                     #$t1= current option
  option1:	
    bgt $t1, $t2, option2	      #if user input > 1, branch
    j case1                     #else jump to function
  option2:	
    addi $t2, $t2, 1	         # option 2
    bgt $t1, $t2, option3	     #if user input > 2, branch
    j case2                    #else jump to function
  option3:	
    addi $t2, $t2, 1	         # option 3
    bgt $t1, $t2, option4	     #if user input > 3, branch
    j case3                    #else jump to function
  option4:	
    addi $t2, $t2, 1	          # option 4
    bgt $t1, $t2, option5	    #if user input > 4, branch
    j case4 	                #else jump to function
  option5:
    addi $t2, $t2, 1	          # option 5
    bgt $t1, $t2, option6	      #if user input > 5, branch
    j case5                     #else jump to function
  option6:	
    addi $t2, $t2, 1 
    j case6	                    # option 6

case1:
  la $a1, array 
  jal print 
  j main 

  print:
    li $t8, 0	                #row counter li 
    $t9, 0	#column counter 
    column:
    	beq $t9, 5, row	          #if column = 5, increase row counter

      mul $t1,$t8, 5	          # multiply row index and column size 
      add $t2, $t1, $t9	        # add to column index 
      mul $t3, $t2, 4	          #multiply by the data size (4 bytes) 
      add $t0, $a1, $t3	        #finds address of array element [x,y]

      li $v0, 1	                #print the number at element [x,y] 
      lw $a0, ($t0)   
      syscall

      li $v0, 4	                #print a space in between numbers 
      la $a0, space 
      syscall

      addi $t9, $t9, 1	        #add 1 to column counter 
      j column

    row:
      addi $t8, $t8, 1	           # increase row counter 
      beq $t8, 5, exit	           #if row = 5, return to main
  
      li $v0, 4	                  #prints next numbers on a new line 
      la $a0, newl 
      syscall
  
      li $t9, 0	                  #reset column counter to 0 
      j column	                  #returns to column - printing next row in array 
  
    exit:
      jr $ra
  

case2:
  #load base address of array into $a1 
  la $a1, array
  #user inputs rows to be added, and row to store the results

  li $v0, 4 
  la $a0, row1message 
  syscall 
  li $v0, 5 
  syscall		
  subi $v0, $v0, 1               #indexing in arrays is n-1	
  move  $s1, $v0

  li $v0, 4 
  la $a0, row2message 
  syscall 
  li $v0, 5 
  syscall	
  subi $v0, $v0, 1               #indexing in arrays is n-1
  move  $s2, $v0

  li $v0, 4 
  la $a0, row3message 
  syscall 
  li $v0, 5 
  syscall		
  subi $v0, $v0, 1               #indexing in arrays is n-1
  move  $s3, $v0

  #calls functions                 # $s5 = address of element in first row	$t5 = actual number
                                  # $s6 = address of element in 2nd row	$t6 =actual number
  jal access2                     # $s7 = adress of element in destination row $t7 = actual number
  jal print                       # $s1 = row 1 number
  j main		                      # $s2 = row 2 number # $s3 = destination row number


  access2:
    li $t0, 0
    while2:
    	beq $t0, 5, exit2	          # if column = 5, break

    	mul $t1, $s1, 5	            # multiply row index and column size
    	add $t2, $t1, $t0	          # add to column index
    	mul $t3, $t2, 4	            #multiply by the data size (4 bytes)
    	add $s5, $a1, $t3	          #finds address of array element of first row [s5, t0]

      lw $t5 ,($s5)

    	mul $t1, $s2, 5	            #finding address of second row array element and storing
    	add $t2, $t1, $t0	          #its value into a separate register
      mul $t3, $t2, 4
      add $s6, $a1, $t3
      lw $t6, ($s6)

      add $t7, $t5, $t6	          #adding the two element cells together

      mul $t1, $s3, 5
      add $t2, $t1, $t0
      mul $t3, $t2, 4
    	add $s7, $a1, $t3	          #address of destination element
    	#move  $s7, $t7	            #storing the final number in destination address

      sw $t7, ($s7)

  	  addi $t0, $t0, 1	          #increase column counter
      j while2
    exit2:
      jr $ra


case3: #multiply row by constant
  #load base address of array into $a1 
  la $a1, array

  #user inputs rows to be multiplied 
  li $v0, 4 
  la $a0, row1message
  syscall 
  li $v0, 5 
  syscall	
  subi $v0, $v0, 1                 #indexing in arrays is n-1
  move  $s1, $v0

  li $v0, 4 
  la $a0, constant 
  syscall 
  li $v0, 5 
  syscall	
  move $t9 ,$v0	                  #constant to multiply each index in row

  jal access3 
  jal print 
  
  j main

  access3:
    li $t0, 0 
    while3:
    	beq $t0, 5, exit	                # if column = 5, break
      mul $t1, $s1, 5	                  # multiply row index and column size 
      add $t2, $t1, $t0	                # add to column index 
      mul $t3, $t2, 4	                  #multiply by the data size (4 bytes) 
      add $s5, $a1, $t3	                #finds address of array element of row [s5, t0]
    	lw $t5 ,($s5)	                    #finds actual number

      mul $t5, $t5, $t9	                #multiply number by constant 
      sw $t5, ($s5)	                    #store multiplied number into its address 
      addi $t0, $t0, 1 
      j while3
  exit3:
    jr $ra


case4: #4) Find the max value of any row and print it
  #load base address of array into $a1 
  la $a1, array

  #user inputs row to be find max 
  li $v0, 4 
  la $a0, row1message 
  syscall 
  li $v0, 5 
  syscall
  subi $v0, $v0, 1                     #indexing in arrays is n-1
  move  $s1, $v0

  jal access4 
  jal print4 
  j main

  access4: 
    li $t0, 0	
    li $t9, -1000	                      #previous number/ where max will be stored
    while4:
    	beq $t0, 5, exit4	                # if column = 5, break

      mul $t1, $s1, 5	                  # multiply row index and column size 
      add $t2, $t1, $t0	                # add to column index 
      mul $t3, $t2, 4	                  #multiply by the data size (4 bytes) 
      add $s5, $a1, $t3	                #finds address of array element of row [s5,t0]

    	lw $t5 ,($s5)	                    #finds actual number

    	sgt $t8, $t5, $t9	                #if index > max number
      beq $t8, 1, store_number

    	addi $t0, $t0, 1	                #add 1 to column counter
      j while

    store_number:
    	sw $t5, ($t9)	#new max
      addi $t0, $t0, 1	                #add 1 to column counter 
      j while

    exit4:
      jr $ra
    print4:	                            #prints value of max
      li $v0, 4 
      la $a0, maxinrow   
      syscall 
      li $v0, 1 
      lw $a0, ($t9) 
      syscall 
      jr $ra


case5: #5) Find the max value of the entire table 
  #load base address of array into $a1 
  la $a1, array 
  jal access5 
  jal print5 
  j main 

  access5:	
    li $t8, 0	                        #row counter
    li $t9, 0	                        #column counter
    li $t7, -1000                     #previous number/ where max will be stored
    column5:	
      beq $t9, 5, row5	              #if column = 5, increase row counter
      mul $t1,$t8, 5	                # multiply row index and column size
      add $t2, $t1, $t9	              # add to column index
      mul $t3, $t2, 4	                #multiply by the data size (4 bytes)
      add $t0, $a1, $t3	              #finds address of array element [x,y]
      lw $s7, ($t0)	                  #$s7 = number, $t0= address

      sgt $t6, $s7, $t7               #if index > max number
      beq $t6, 1, store_number5	

      addi $t9, $t9, 1                 #add 1 to column counter
      j column5 	
    row5:
      addi $t8, $t8, 1	              # increase row counter
      beq $t8, 5, exit5	              #if row = 5, return to main

      li $t9, 0	                      #reset column counter to 0
      j column5                        #returns to column

    store_number5:	
      sw $s7, ($t7)	                  #new max
      addi $t9, $t9, 1                #add 1 to column counter
      j column5
    exit5: 
      jr $ra

  print5:	
    li $v0, 4                         #prints value of max
    la $a0, maxintable 
    syscall 
    li $v0, 1 
    lw $a0, ($t7) 
    syscall 
    jr $ra

case6:
  #exit function call
  li $v0, 10
  syscall

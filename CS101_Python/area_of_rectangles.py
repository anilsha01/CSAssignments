/* Problem statement:
The area of rectangle is the rectangle’s length times its width. Write a program that asks for length and width of two rectangles. The program should tell the user which rectangle has the greater area or if the areas are same. 
You must use if-else to accomplish this task.
  
Sample input:
Length of rectangle 1: 5
Width of rectangle 1: 10
Length of rectangle 2: 6
Width of rectangle 2: 30 
  
Sample output:
Area of rectangle 1:50
Area of rectangle 2:180
Area of rectangle 2 is greater than area of rectangle 1
*/

  

#user inputs length and width of rectangles 1 and 2 as a positive float only
#length of rectangle 1
while True:
        num1=float(input("Enter the length of rectangle 1 with a positive value only: "))
        if num1<=0:
            print("Enter only positive values!")
        else:
            break
length1=num1
#########################
#width of rectangle 1
while True:
    num2=float(input("Enter the width of rectangle 1 with a positive value only: "))
    if num2<=0:
        print("Enter only positive values!")
    else:
        break
width1=num2
#########################
#length of rectangle 2
while True:
    num3=float(input("Enter the length of rectangle 2 with a positive value only: "))
    if num3<=0:
        print("Enter only positive values!")
    else:
        break
length2=num3
#########################
#width of rectangle 2
while True:
    num4=float(input("Enter the width of rectangle 2 with a positive value only: "))
    if num4<=0:
        print("Enter only positive values!")
    else:
        break
width2=num4
#########################
#calculate area of both rectangles
area1 = length1 * width1
area2 = length2 * width2

print("The area of rectangle 1 is ", area1, '\n')
print("The area of rectangle 2 is ", area2, '\n')

# Use decision structures to figure out if area 1 is greater than, less than, or equal to area 2
if area1>area2:
    print("The area of rectangle 1 is greater than rectangle 2.", '\n')
elif area1<area2:
    print("The area of rectangle 2 is greater than rectangle 1.", '\n')
else:
    print("The areas of both rectangles are equal.")

# Push_Swap (42 lvl 2)

## Overview

Push_swap is a 42 common core project that has as an objective to sort data using a limited number of instructions.

The point of this project is to learn how to use sorting algorithms and to use them.

## Initial rules and conventions

For this project we have two stacks: A and B!

A starts as a list of numbers and B is empty. The objective being that, in the end, B is empty and A is sorted in ascending order.

So to sort the list we have the following operations:

| Operations    | Detail                                                                                          |
| ------------- | ------------------------------------------------------------------------------------------------|
| sa (swap A)    | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.|
| sb (swap B)    | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.|
| ss (swap both) | sa and sb at the same time.                                                                     |
| ra (rotate A)  | Shift up all elements of stack a by 1. The first element becomes the last one.|
| rb (rotate B)  | Shift up all elements of stack b by 1. The first element becomes the last one.|
| rr (rotate both)| ra and rb at the same time. |
| rra (reverse rotate A)| Shift down all elements of stack a by 1. The last element becomes the first one.|
| rrb (reverse rotate B)| Shift down all elements of stack b by 1. The last element becomes the first one.|
| rrr (reverse rotate both)| rra and rrb at the same time.|
| pb (push B)    | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.|
| pa (push A)    | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.|

### Conventions

So for this project and seeing how I would have to test multiple algorithms and solutions I decided to use a doubly linked list, as it seemed to be easier to work with and manipulate! So each integer recieved is the data of a node of the list.

![DLL1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png)

Also, to be easier to test some of the algorithms the list is transformed like so:
 ```
list = " 34 21 4" becomes list = "3 2 1"
 ```
 
## The Algorithm

So my code is separated in 3 different algorithms:
1) for 2 numbers - only a swap if necessary;
2) for 3 numbers;
3) for 4 or 5 numbers;
4) for larger numbers;

#### For 3 numbers

Quite simple, you only need to check where in the list is the highest number and make sure it goes to the bottom, than swap the first two if necessary.

#### For 5 numbers

For this one the main operation is sending the two smaller numbers to stackb, and then using the sort3 algorithm to sort A. Then swap b if necessary and use pa to transfer to stacka.

### Larger stack

Now for this after testing a lot of different algorithms I found that [this one](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) resulted the best. So thank you to A. Yigit Ogun.

So for this algorithm you have to pass everything except 3 numbers to stack B. 

Very simply it goes like this (for a better explanation please check out the link above):

1. We start by pushing the first two numbers to stack B. 
2. Then we go through A and check which number needs less rotates or r_rotates to pass to B and make B sorted. Here we need to take advantages of the rr and rrr checking how many of each we need and then choosing the less movements;
3. When there are only 3 numbers in A we order them using the previous algorithm;
4. Finally we pass ordered the values of B to A. until there are only three numbers in B, where we would to the same as above;
5. Then rotate until the smallest number is on top of A!

## Bonus - Checker

For the push-swap bonus we needed to create our own checker program.

The objective of a checker is to create a program that will check if the list of instructions given orders the provided list.

The checker will also have to check if the list given is valid. Parametrs not valid are, for eample, non numeric characters, integers bigger than the max_int or repeated numbers. for this checker if you want to know the problem you can run with '-details' it like this:
```
./checker 2 3 one -details
 ```
 ![Screenshot from 2023-03-22 17-12-05](https://user-images.githubusercontent.com/105734074/226984597-6eb99c42-5e3c-4ac8-b42b-1657d04fa791.png)

This checker, if the list is incorrectly sorted you can print the list to understand why running the checker with '-lists', like so.
```
./checker 3 2 1 4 5 -lists
 ```
![Screenshot from 2023-03-22 17-17-55](https://user-images.githubusercontent.com/105734074/226985897-88bf9bff-9bb6-4644-aa81-1dd545c043fa.png)

Finally if the list is correctly sorted the program displays how many movements did it need to sort the list!

## Make Commands

```
make all - creates executable push_swap
make bonus - creates executable for the checker
make clean - cleans the objects
make fclean - clean executable and any library, also runs clean
make re - runs clean and fclean and then runs all to create the executable
make rebonus - runs clean and fclean and then runs all to create the executable for bonus
 ```
 
 ## Links
 [Chosen Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
 
 [Doubly Linked Lists](https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/)
 
 [Example of Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
 
 Thank you for reading!!

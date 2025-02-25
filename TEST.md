Test Case 1: one piece of length

Enter the length of the rod: 1
Enter rod length piece and each value such as num_num:
1 3
^D
Results:
1 @ 3 = 0
Remainder: 0
Total value: 3

Test Case 2: Max value with with many many cuts

Enter the length of the rod: 9
Enter rod length piece and each value such as num_num:
1 1
2 5
3 8
4 9
5 10
6 13
7 15
8 18
9 21
^D
Results:
3 @ 8 = 0
3 @ 8 = 8
3 @ 8 = 16
Remainder: 0
Total value: 24

Test case 3: Max length of the rod passed

Enter the length of the rod: 10001
Rod length passes max limit

Test case 4: negative piece

Enter the length of the rod: 10
Enter rod length piece and each value such as num_num:
-1 2
Invalid input

Test case 5: no length for the rod

Enter the length of the rod: 0
Invalid Rod Length

Test case 6: free value/price

Enter the length of the rod: 5
Enter rod length piece and each value such as num_num:
1 0
Invalid input

Test case 7: A regular cut

Enter the length of the rod: 8
Enter rod length piece and each value such as num_num:
1 3
2 5
3 8
4 9
5 10
6 17
7 17
8 20
^D
Results:
1 @ 3 = 0
1 @ 3 = 3
1 @ 3 = 6
1 @ 3 = 9
1 @ 3 = 12
1 @ 3 = 15
1 @ 3 = 18
1 @ 3 = 21
Remainder: 0
Total value: 24

Test case 8: input high length piece than length of the rod

Enter the length of the rod: 12  
Enter rod length piece and each value such as num_num:
134 1
^D
Results:
Remainder: 12
Total value: 0
Remaining rod length: 12

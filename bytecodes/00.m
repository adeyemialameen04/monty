push 0
push 1
push 2
push 3
                   pall    


                           
push 4

    push 5    
      push    6        



push 0
push 1
push 2
push 3
pall                       
push 4
push 5    
push 6        

╰─ gcc *.c ; ./a.out bytecodes/00.m
Push 1
Push 2
Push 3
Push 4
Pall 5
Push 6
Push 7
Push 8

This is the content of my file and its working this way but there is a little error

If i space the commands it doesnt work correctly

New file:
push 0
push 1
push 2
push 3
                   pall    


                           
push 4

    push 5    
      push    6        



Output:
╰─ gcc *.c ; ./a.out bytecodes/00.m
Push 1
Push 2
Push 3
Push 4
Pall 5

#include <stdlib.h>
#include <stdio.h>

/*
Linked List (STL list) - is inefficient to access elements so its very rare to appear
Stack (STL stack) - restricted list with push (insertion) / pop (delete and get) only in the top
                    LIFO (last in first out) push(), pop(), top(), empty() all C(1)
Queue (STL queue) - insertion in tail and dequeue from head FIFO (First in First out)
                    push()/pop() (insert from back/remove
                    from front of queue), front()/back() (obtain content from the front/back of queue), and
                    empty() all cost C(1) (usable in BFS)
Deque (Double-ended queue   STL deque) - same as queue but have push back(), pop front(), push front() and 
                                         pop back() all O(1)
    
2.2.5.1 - we can use an array of pairs for one slot representing the index and the other the data we want to store
          make the index always be the index of next element so when we delete one, the index of data before
          that changes to the index of data next that
          yes, we could use static array just as the same way as resizeable array but will have limited elements
          we could also use linked list with pop removing the last element and push adding at last element
          and we could use deque, with pushfront and popfront instead of push and pop
2.2.5.2 - keep track of first element and the last, push add element to tail and pop pick and delete element
          from head.
          yes, just as the same way in last exercise but for deque


Bracket matching ( need to use stack to close the right bracket )
Postfix calculator O(n) - go from left to right and store numbers in a stack, when we find an operator pop 
            last two numbers and make the operation then put the result in stack, keep doing that until end
Infix to postfix conversion O(n) - Infix -> postfix -> calculate result
    How it works: when we find a number, immediately output (postfix)
                  we find a open bracket, put every element in stack and then put everything in output if
                  encounters closing bracket

2.2.6.1 - we can make the same thing we do with postfix but from right to left
*/
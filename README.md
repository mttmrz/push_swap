# push_swap
My 42school Push_swap project

As many other projects of the second half of the main core, i coded this with Bianca Muni, a fellow student from 42Florence.

Push swap it is aimed to test your sorting algorithms skill and knoledge, which can be usefull, but it's mostly very boring ;)

We used arrays to handle the two stacks, we find it much more convinient (expecially because lists are primarly used for very large numbers, with low digits it is just slower and harder to read, code,
and implement. ofc feel free to code as you like)

The logic behind our push_swap it's not that complicated, but it defitnley serve it's purpose. 
We created a LIS (Longest Increasing Subsequence) to be our support for the main sorting logic, then we calculated how many moves for every number of the B stack to get to the top of the B stack
and how many moves for the A stack to host the B stack number that we consider in every iteration. 
After this operation you get two tables , with the moves needed to host the number you're considering
e.g
```
TABLE A   TABLE B
4         0
-5        1
3         2
-1        3
0         -3
4         -2
-5        -1
```
it is simple but not THAT simple, you still need to look up for yourself. OFC norminette it's a killer (pretty useless after the first ring imo) and the code it's simply
not readable anymore, amen.

I attached the Visualizer aswell, it helps a lot with getting how your algorythm is behaving.

```to use it --> mkdir build --> cd build --> cmake .. (yes the .. are included) --> make --> drag your ./push_swap executable inside the bin folder --> ./visualizer```

The visualizer it's not a work i did, not sure who has . 
ENJOY

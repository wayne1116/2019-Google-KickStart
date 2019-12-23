## [Round H](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edd)

### H-index

We initialize the H-index with 0, and after adding each paper, we need to update the current H-index.

- the order of numbers in the vector are non-decreasing.

- use lower bound method to find the location where current citation number inserts in the vector.

- use lower bound method to find the current H-index answer.

---

### Diagonal Puzzle

We can convert this problem into a variant of **2-coloring**. 

Each of the cells in the grid is shared by two diagonals. If a cell is white, either one of them needs to be flipped to make this cell black. Otherwise, none of these two diagonals needs to be flipped. 

For this problem, we can consider each diagonal as a vertex of a graph, and the squares in the grid are the edges between the two diagonals that affect that square.

**Implement:**

- At first, give the unique number to each diagonal   

- Create the new graph that each diagonal as a vertex and the squares in the grid are the edges between the two diagonals that affect that square

- 2-coloring problem

**For example(n=3):**

<div align=center>
<img src="https://github.com/wayne1116/2019_Google_KickStart/blob/master/RoundH/diagonal_Puzzle_example.jpg" width="200" alt="diagonal_Puzzle_example.jpg"> 
</div>

---

### Elevangram

We need to divide each digits to two partitions: positive partition and negative partition, 

where positive partition means the digit is on the odd index (be calculated as add), 

and negative partition means the digit is in the even index (be calculated as minus).


**Reduce the number(A<sub>i</sub>) of each digit(1-9):**

By placing some i's on the left side and others on the right side.

For example **i = 1, and a[i] = 3.** Sums list will be as follows:

```
left(+)   right(-)         Sum

        |  1 1 1    -> -1 -1 -1 = -3
      
1       |  1 1      -> +1 -1 -1 = -1

1 1     |  1        -> +1 +1 -1 = +1

1 1 1   |           -> +1 +1 +1 = +3
```

Let's take an other example where **i = 1, and A<sub>i</sub> = 20.**

Sums = [0, 2, 4, 8, 10, 12, 14, 16, 18, 20]

Sums % 11 = [0, 2, 4, 8, 10, 1, 3, 5, 7, 9], 

which basically covers all numbers in range 1<= [the element in the Sums % 11]<=9.


**Dynamic programming method:**

- Let dp(i, j, k) denote if it is possible to achieve the state
  
  ```
  i: the i-th element in the set of digits
  
  j: number of digits in the current positive partition
  
  k: current sum(|positive partition-negative partition|) modulo 11
  ```
  
- Two case (select or not select):

  ```
  1. Select the i-th element -> positive partition
  
  dp(i, j+1, (k + current_digit) % 11) |= dp(i-1, j, k)
  
  2. Not select the i-th element -> negative partition
  
  dp(i, j, (k - current_digit + 11) % 11) |= dp(i-1, j, k)
  
  ```  

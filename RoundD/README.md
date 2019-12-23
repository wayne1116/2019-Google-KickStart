## [RoundD](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061)

### X or What

- Xor **two xor-even numbers** or **two xor-odd numbers** , we can get a xor-even number

- Record the index of the **xor-odd number** in the set

- Two case

        a. When the size of the set is even
           -> the maximum value is n
            
        b. When the size of the set is odd
           -> the maximun value : (n-temp1-1) or temp2
               which temp1 is the maximum index value of the odd number
                     temp2 is the minimum index value of the odd number

---

### Latest Guests

Consider the guests who travel clockwise. Guests having the **same initial positions are in the same group** and guests having different initial positions are in different groups. We maintain a mapping from guests to groups. We are going to find for each group, how many consulates remember it. We handle anti-clockwise guests similarly.

**Take clockwise guests for example:**

- at first, we make clockwise guests having the same initial positions in the same group, and also maintain a mapping from guests to group. (Code line: 46-49)

- record the positions of groups. (Code line: 57-63)

- consider the case M time is greater than N consulates, we need to label consulates which were visited when all guests went around. (Code line: 64-91)

<div align=center>
<img src="https://github.com/wayne1116/2019_Google_KickStart/blob/master/RoundD/RoundD2_picture1.jpg" width="350" alt="RoundD2_picture1.jpg"> 
</div><br />  
  
  
- label each guest traveling consulates which are visited. (Code line: 93-120)  
  
<div align=center>
<img src="https://github.com/wayne1116/2019_Google_KickStart/blob/master/RoundD/RoundD2_picture2.jpg" width="350" alt="RoundD2_picture2.jpg"> 
</div><br />

- we handle anti-clockwise guests similarly. (Code line: 122-183)

- finally, consider three case: (Code line: 188-230)
  
  ```
   1. compare the reach time between clockwise and anti_clockwise guests in the same position. 
      
      Choose the largest reach time.
   
   2. the position which only clockwise guests visited.
   
   3. the position which only anti_clockwise guests visited.
  ```

---

### Food Stalls

**Determine the location of the warehouse:**

- Suppose we decided on the K+1 spots where we will place our stalls and warehouse but are yet to decide where to place our warehouse, let's say the co-ordinates of these spots are Y<sub>1</sub>, Y<sub>2</sub>, ..., Y<sub>K+1</sub> in __increasing order__. Obviously, it'll be the spot **Y<sub>j</sub> such that |Y<sub>j</sub> - Y<sub>1</sub>| + |Y<sub>j</sub> - Y<sub>2</sub>| + ... |Y<sub>j</sub> - Y<sub>K+1</sub>| is minimum**. This is the classic post office location problem and is solved by putting **the warehouse in the median point of our chosen points** (in case of even number of points with two medians, any one will yield an optimal answer).
<br />

**Calculate the minumun cost if the warehouse is on the i-th spot**

- After the above observations, we know that we must put **floor(K/2) stalls on the left** of our warehouse and **K-floor(K/2) stalls on the right**. If we can calculate, for every position of the warehouse, the minimum cost to place these points, we will be done.

- For simplicity, we assume the given points X<sub>0</sub>, X<sub>1</sub>, ..., X<sub>N-1</sub> to be sorted. Now, we will maintain a **max-heap of size floor(K/2)**. For position i, we define **V<sub>i</sub> = X<sub>N-1</sub> - X<sub>i</sub> + C<sub>i</sub>**. Initially, we will store V<sub>0</sub>, V<sub>1</sub>, ..., V<sub>floor(K/2)-1</sub> in our heap. We'll also maintain **the sum of all the elements in our heap**.

- If we consider that we are placing the warehouse at **X<sub>floor(K/2)</sub>**, then the minimum cost of placing all floor(K/2) stalls to the left of it is given by **sum of all the elements in our heap - floor(K/2) * (X<sub>N-1</sub> - X<sub>floor(K/2)</sub>)**

- So, for i = floor(K/2) to N-(K-floor(K/2)), we check **if V<sub>i</sub> is less than the maximum element of our heap**. If it is then we remove the maximum and insert V<sub>i</sub> and update the sum of all our heap elements by subtracting the difference of the removed element and the inserted element. We subtract **floor(K/2) * (X<sub>N-1</sub> - X<sub>i+1</sub>)** from the sum and compare it with the minimum cost obtained thus far.

- We can use a similar approach to get the cost of all elements to the right, there V<sub>i</sub> will just be **X<sub>i</sub>+C<sub>i</sub>**. Initially, we will store V<sub>N-1</sub>, V<sub>N-2</sub>, ..., V<sub>N-floor(K/2)-2</sub> in our heap. We should iterate from right to left and in each iteration, update the heap and subtract **(K-floor(K/2)) * X<sub>i</sub>** from the sum of the elements in the heap and update the minimum cost with that.

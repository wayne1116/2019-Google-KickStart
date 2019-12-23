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

- Suppose we decided on the K+1 spots where we will place our stalls and warehouse but are yet to decide where to place our warehouse, let's say the co-ordinates of these spots are Y<sub>1</sub>, Y<sub>2</sub>, ..., Y<sub>K+1</sub> in **increasing order**. Obviously, it'll be the spot **Y<sub>j</sub> such that |Y<sub>j</sub> - Y<sub>1</sub>| + |Y<sub>j</sub> - Y<sub>2</sub>| + ... |Y<sub>j</sub> - Y<sub>K+1</sub>| is minimum**. This is the classic post office location problem and is solved by putting **the warehouse in the median point of our chosen points** (in case of even number of points with two medians, any one will yield an optimal answer).
<br />

**Calculate the minumun cost if the warehouse is on the i-th spot**

After the above observations, we know that we must put **floor(K/2) stalls on the left** of our warehouse and **K-floor(K/2) stalls on the right**. If we can calculate, for every position of the warehouse, the minimum cost to place these points, we will be done.




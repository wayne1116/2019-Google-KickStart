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
<img src="https://github.com/wayne1116/2019_Google_KickStart/blob/master/RoundD/RoundD3_picture1.jpg" width="300" alt="RoundD3_picture1.jpg"> 
</div>
  
- finally label each guest traveling consulates which are visited. (Code line: 93-120)  
           

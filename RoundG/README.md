## Round G
https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02

### Book Reading
- We can compute f(1), f(2), ..., f(N) in a total of N(1/1 + 1/2 + ... + 1/N) time.

  1/1 + 1/2 + ... + 1/N is approximately O(log N) (Harmonic number)


### The Equation
- count the bit from the least significant bit 
 
  -> find the minimum possible value

- change the bit from most significant bit 

  -> find the maximum value

### Shifts
- divide the shifts into 2 sets, each having the size of at most ceil(N/2)

- sorting one vector

- find the lower bound value of the sorted vector 

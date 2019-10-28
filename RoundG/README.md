# Round G
https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02

## Book Reading
1. We can compute f(1), f(2), ..., f(N) in a total of N(1/1 + 1/2 + ... + 1/N) time. 
   1/1 + 1/2 + ... + 1/N is approximately O(log N) (Harmonic number)
2. Time complexity: O(NlogN + Q)

## The Equation
1. (from the least significant bit)

    8	1 0 0 0
    
    4   0 1 0 0
    
    2   0 0 1 0
 
    ans 0 0 0 0  -> minimum possible value

2. (change the bit from most significant bit)
        
	1 0 0 0 -> ok
        
	1 1 0 0 -> ok
        
	1 1 1 0 -> no 
        
	1 1 0 1 -> no

ans:    1 1 0 0

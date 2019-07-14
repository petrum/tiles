# tiles


## brute force
* ```main.cpp``` tries to solve the problem in a generic way
* we parameterize both ```stripes``` and the ```length```
* the implementation is similar with placing each tile individually
* as we place them, we check the size of the stripe, and check the edges to the previous stripe
* it is very slow

## customized approach
* instead of solving generically this problems, we only try to solve the ```length = 30``` specific problem.
* we can still customize on the stripes number
* we first generate all the possible stripes with ```length = 30```
* the ```stripes.cpp``` does this, see the result in ```stripes.txt``` (1897 x stripes)
* then the ```designs.cpp``` uses this data, and tries to stack the stripes together
* we encode each stripe as an int (30 bits == stripe's length)
* a tile with len = 2 will take 2 x bits, the one with len = 3 takes 3 x bits
* the first bit in a tile is always ```1```, the rest of bits are ```0```
* this will let us compare 2 stripes for the edges rule in a single bitewise ```&``` operation (very fast)
* example of design:
```
- design 0:
                    |3 |3 |3 |3 |3 |3 |3 |3 |3 |3
	- 613566756 100100100100100100100100100100
	- 690262602 101001001001001001001001001010
	- 613566756 100100100100100100100100100100
	- 690262602 101001001001001001001001001010
	- 613566756 100100100100100100100100100100
	- 690262602 101001001001001001001001001010
	- 613566756 100100100100100100100100100100
	- 690262602 101001001001001001001001001010
	- 613566756 100100100100100100100100100100
	- 690262602 101001001001001001001001001010
	- 613566756 100100100100100100100100100100
```
* much more faster than the generic approach (+350 x faster)
* it finds about 1 million designs per second

## fast approach

 
* The ```fastdesigns.cpp``` file has the final solution.
* for each of the 1897 stripes it precomputes the compatible stripes (that could follow next after this stripe) 
* now we do not have to check if the edges matches, we just stack them together
* the result is 100x times faster than the customized solution

stripes	| designs | 	brute force    	| customized | fast
------- | --------|------------|---------|----
1 	    |  1,897  | 1 |	 0.0043	 |
2 	    |  17,282 | 8|	0.0368  |
3 	    |  221,490 | 60 |   0.324  | 
4 	    |  3,025,552 	|  N/A | 3.957 | 0.0865
5 	    |  47,054,902 | N/A | 53.77  | 0.793
6 	    |  727,476,474 | N/A | 831	 | 11.6
7 	    | 12,197,221,792 |  N/A |   12,814   | 190
8 	    | 197,913,291,570   	|     N/A | N/A  | 3,116
9 	    | 		       	|     N/A | N/A  |
10 	    | 		       	|     N/A | N/A  |
11 	    | 		       	|     N/A | N/A  |

max size_t = 18,446,744,073,709,551,615

(please note the code was not optimized at all, no profiler was used, no bottlenecks identified etc)

## Comparing results

Comparing results for the three approaches produces the same number of results: :-)
### Brute force approach
```
$> ./build.sh

$> ./tiles 1 30 2>/dev/null
There were 1897 designs for 1 x 30 room.

$> ./tiles 2 30 2>/dev/null
There were 17282 designs for 2 x 30 room.

$> ./tiles 3 30 2>/dev/null
There were 221490 designs for 3 x 30 room.
```
### Customized approach
```
$> g++ designs.cpp -std=c++11 -Wall -Wextra -o designs

$> ./designs 1 < stripes.txt
Designs
input size = 1897
run
design count = 1897
start at Thu Jul 11 17:41:53 2019
end at Thu Jul 11 17:41:53 2019
elapsed 0.00382874 seconds for computing 1 stripes

$> ./designs 2 < stripes.txt
Designs
input size = 1897
run
design count = 17282
start at Thu Jul 11 17:42:24 2019
end at Thu Jul 11 17:42:24 2019
elapsed 0.0368942 seconds for computing 2 stripes

$> ./designs 3 < stripes.txt
Designs
input size = 1897
run
design count = 221490
start at Thu Jul 11 17:42:35 2019
end at Thu Jul 11 17:42:35 2019
elapsed 0.323782 seconds for computing 3 stripes
```







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
                    |3 |3 |3 |3 |3 |3 |3 |3 |3 |2
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

stripes	| designs | 	sec     | 	min	| brute force | fast
------- | --------|------------|------|--------|----
1 	    |  1,897  | 	 0.0043	|  0.00 | 	1 sec 
2 	    |  17,282 | 	0.0368 	|  0.00 	|  8 sec
3 	    |  221,490 |  0.324  	|  0.00 	|  60 sec
4 	    |  3,025,552 	|  3.957 |  0.08 	|  N/A | 0.273
5 	    |  47,054,902 | 53.77 | 	 0.88| N/A | 2.494
6 	    |  727,476,474 | 831.729 |  13.85 	|  N/A | 28.68
7 	    | 12,197,221,792 |    12814     |   3.5h      |  N/A |
8 	    | 		       	|         |         |   N/A |
9 	    | 		       	|         |         |   N/A |
10 	    | 		       	|         |         |   N/A |
11 	    | 		       	|         |         |   N/A |

* it seems it increases by a factor of 15 for each extra stripe
* this estimates that it will solve the stripes = 11 in 17 years!

(please note the code was not optimized at all, no profiler was used, no bottlenecks identified etc)

## Comparing results

Comparing results for the two approaches produces the same number of results: :-)
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
### Customized/fast approach
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







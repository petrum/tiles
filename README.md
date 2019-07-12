# tiles


## brute force
* ```main.cpp``` tries to solve the problem in a generic way
* we parameterize both ```stripes``` and the ```length```
* the implementation is similar with placing each tile individually
* as we place then we check size, and the edges to the previous stripe
* it is very slow

## customized approach
* instead of solving all the problems, we try to solve the ```length = 30``` specific problem.
* we can still customize on the stripes number
* we first generate all the possible stripes with ```length = 30``` (1897 x stripes)
* the ```stripes.cpp``` does this, see the result in ```stripes.txt```
* then the ```designs.cpp``` takes this data, and tries to stack them together
* we encode each stripe as an int (30 bits)
* a tile with len = 2 takes 2 bits, len = 3 takes 3 bits
* the first bit on tile is "1", the rest are "0"
* this will let us compare 2 stripes for edges in a single bitewise "&" operation
* much more faster than the generic approach (+100 times)
* it finds about 1 million designs per second

stripes	| designs | 	sec     | 	min	| days
------- | --------|------------|------|--------
1 	    |  1,897  | 	 0.0043	|  0.00 | 	 
2 	    |  17,282 | 	0.036 	|  0.00 	|  
3 	    |  221,490 |  0.324  	|  0.00 	|  
4 	    |  3,025,552 	|  3.957 |  0.08 	|  
5 	    |  47,054,902 | 53.77 | 	 0.88| 
6 	    |  727,476,474 | 831.729 |  13.85 	|  
7 	    | 12,197,221,792 |    12814     |   3.5h      |  
8 	    | 		       	|         |         | 
9 	    | 		       	|         |         | 
10 	    | 		       	|         |         | 
11 	    | 		       	|         |         | 

* it seems it increases by a factor of 15
* this estimates that it will solve the stripes = 11 in 17 years!

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







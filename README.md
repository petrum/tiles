# tiles


## brute force
* ```main.cpp``` tries to solve the problem brute-force in a generic way
* we parameterize both stripes and the length
* it is very slow

## customized approach
* instead of solving all the problems, we try to solve the length = 30 specific problem.
* we can still customize on the stripes number
* we first generate all the possible stripes with lengty = 30
* the ```stripes.cpp``` does this, see the result in ```stripes.txt```
* then the ```designs.cpp``` takes this data, and tries to stack them together

| stripes	| designs | 	sec     | 	min	| actual| 
| 1 	    |  1,897  | 	 0.00 	|  0.00 | 	 |
| 2 	    |  17,282 | 	 0.02 	|  0.00 	|  |
| 3 	    |  221,490 |  0.22  	|  0.00 	|  |
| 4 	    |  3,025,552 	|  3.03 |  0.05 	|  |
| 5 	    |  47,054,902 | 47.05  | 	 0.78 | 	|
| 6 	    |  727,476,474 | 727.48 |  12.12 	|  |
| 7 	    | 		       	|         |         |  |
| 8 	    | 		       	|         |         | |
| 9 	    | 		       	|         |         | |
| 10 	    | 		       	|         |         | |
| 11 	    | 		       	|         |         | |

Project 02: lsort
===================

This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists


Questions
---------



1. |  algorithm  |    worst   |  average   |    best    |  
|------|------|-------|-------|      
|     STL     |  O(nlogn)  |  O(nlogn)  |  O(nlogn)  |       
|    qsort    |  O(nlogn0  |  O(nlogn)  |  O(nlogn) | 
|  merge sort |  O(nlogn)  |  O(nlogn)  |  O(nlogn)  |      
| quick sort  |  O(n^2)    |  O(nlogn)  |  O(nlogn)  |



2. | Mode    | Size  | Elapsed Time  | Memory    |
|---------|-------|---------------|-----------|
| stl | 10 | 0.001998 seconds | 1.179688 Mbytes |
| stl | 100 | 0.001998 seconds | 1.191406 Mbytes |
| stl | 1000 | 0.003998 seconds | 1.273438 Mbytes |
| stl | 10000 | 0.029994 seconds | 2.113281 Mbytes |
| stl | 100000 | 0.386940 seconds | 9.910156 Mbytes |
| stl | 1000000 | 5.713131 seconds | 85.625000 Mbytes |
| stl | 10000000 | 80.059830 seconds | 892.847656 Mbytes |
| qsort | 10 | 0.001998 seconds | 1.183594 Mbytes |
| qsort | 100 | 0.001998 seconds | 1.191406 Mbytes |
| qsort | 1000 | 0.003999 seconds | 1.324219 Mbytes |
| qsort | 10000 | 0.024996 seconds | 2.167969 Mbytes |
| qsort | 100000 | 0.302953 seconds | 10.484375 Mbytes |
| qsort | 1000000 | 3.900406 seconds | 92.894531 Mbytes |
| qsort | 10000000 | 57.221298 seconds | 918.652344 Mbytes |
| merge | 10 | 0.001998 seconds | 1.175781 Mbytes |
| merge | 100 | 0.001999 seconds | 1.183594 Mbytes |
| merge | 1000 | 0.003998 seconds | 1.253906 Mbytes |
| merge | 10000 | 0.023995 seconds | 1.941406 Mbytes |
| merge | 100000 | 0.288955 seconds | 8.808594 Mbytes |
| merge | 1000000 | 4.174364 seconds | 77.472656 Mbytes |
| merge | 10000000 | 61.010723 seconds | 764.117188 Mbytes |
| quick | 10 | 0.001998 seconds | 1.175781 Mbytes |
| quick | 100 | 0.001999 seconds | 1.183594 Mbytes |
| quick | 1000 | 0.003998 seconds | 1.253906 Mbytes |
| quick | 10000 | 0.025995 seconds | 1.941406 Mbytes |
| quick | 100000 | 0.346946 seconds | 8.808594 Mbytes |
| quick | 1000000 | 4.825265 seconds | 77.472656 Mbytes |
| quick | 10000000 | 76.431381 seconds | 764.117188 Mbytes |



3. The fastest algorithm was qsort, followed by merge then quick, and lastly stl. However, both merge and quick sort used the least amount of memory, followed by stl and then lastly by qsort. The reason why qsort and stl used up more memory was because they used an array/vector. 

    Theoretically all the algorithms have an average of O(nlogn) time, so should be similar in elapsed time. However, certain algorithm were significcantly faster, indicating that actual performance depends on how the algorithms were implemented and what type of data structure was used as the container.

    According to our results, merge sort seems to be the best because it was significantly faster than both STL and quick sort and significantly more memory efficient than qsort. By balancing these two resources, we get the best sorting algorithm. However, it should be noted that merge sort is difficult to implement efficiently for containers such as arrays, and therefore these circumstances should be considered.
    
    Individual contributions:
    
    Emily Park (epark3) did the stl, list, and quick sort. Andrew Paek (apaek1) did merge, qsort and README.

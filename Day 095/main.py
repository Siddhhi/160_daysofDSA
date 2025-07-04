"""
Title: Find K Largest Elements in an Array

Problem Statement:
    - Given an array of integers and a number k,
      return the k largest elements from the array in descending order.

Author: Siddhi
"""

import heapq

def kLargest(arr, k):
    minH = arr[:k]
    heapq.heapify(minH)

    for x in arr[k:]:
        if x > minH[0]:
            heapq.heapreplace(minH, x)

    res = []
    while minH:
        res.append(heapq.heappop(minH))
    
    res.reverse()  # To return results in descending order
    return res

def main():
    arr = [7, 10, 4, 3, 20, 15]
    k = 1
    result = kLargest(arr, k)
    print("The", k, "largest elements are:", result)

if __name__ == "__main__":
    main()

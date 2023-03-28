Algorithm HoarePartition(A[l..r])
  //Partitions a subarray by Hoare's algorithm, using the first element as a pivot
  //Input: Subarrau of array A[0..n-1], defined by its left and right indices l and r(l < r>)
  //Output: Partition of A[l..r], with the split position returned as this function's value
  p <- A[l]
  i <- l; j <- r+1
  repeat
    repeat i <- i+1 until A[i] >= p
    repeat j <- j-1 until A[j] <= p
    swap(A[i],A[j])
  until i>=j
  swap(A[i],A[j])
  swap(A[l],A[j])
  return j
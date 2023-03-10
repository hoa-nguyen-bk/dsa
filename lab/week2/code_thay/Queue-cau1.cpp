int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int sum = 0;
	deque< int > G(k);

	// Process first window of size K
	int i = 0;
	for (i = 0; i < k; i++)
	{
		// Remove all previous smaller that are elements
		// are useless.
		while ( (!G.empty()) && nums[G.back()] <= nums[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
	}

	// Process rest of the Array elements
	for ( ; i < nums.size(); i++ )
	{
		// Element at the front of the deque 'G' & 'S'
		// is the largest and smallest
		// element of previous window respectively
		sum += nums[G.front()];
		
		while ( !G.empty() && G.front() <= i - k)
			G.pop_front();
			
		while ( (!G.empty()) && nums[G.back()] <= nums[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
	}

	// Sum of minimum and maximum element of last window
	sum += nums[G.front()];

	return sum;
}
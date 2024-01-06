// Job structure
struct Job {
    int start;
    int end;
    int profit;
};

// Comparator function for qsort
int compareJobs(const void* a, const void* b) {
    return ((struct Job*)a)->end - ((struct Job*)b)->end;
}

// Helper function to find the latest job that doesn't overlap
int binarySearch(struct Job jobs[], int index) {
    int low = 0, high = index - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].end <= jobs[index].start) {
            if (jobs[mid + 1].end <= jobs[index].start)
                low = mid + 1;
            else
                return mid;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Function to calculate the maximum profit without overlapping jobs
int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
    int n = startTimeSize;
    struct Job jobs[n];

    // Create job structure array
    for (int i = 0; i < n; ++i) {
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].profit = profit[i];
    }

    // Sort jobs array based on end times
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    int dp[n];
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; ++i) {
        int inclProfit = jobs[i].profit;
        int latestNonConflict = binarySearch(jobs, i);

        if (latestNonConflict != -1)
            inclProfit += dp[latestNonConflict];

        dp[i] = (inclProfit > dp[i - 1]) ? inclProfit : dp[i - 1];
    }

    return dp[n - 1];
}
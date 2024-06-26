// write a version of binsearch such that only one test is performed inside the loop, at the cost of more outside

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else // found match
            return mid;
    }
    return -1; // no match
}

int mybinsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high / 2);
    while (low <= high && v[mid] != x) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (v[mid] == x)
        return mid;
    else 
        return -1;
}
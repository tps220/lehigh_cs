//Magic Index is where index number equals the value found at the index
//Determine whether a sorted array has a magic index

bool binarySearch(int* array, int l, int r) {
    if (l <= r) {
        int mid = (l + r) / 2;
        if (array[mid] == mid) {
            return true;
        }
        else if (array[mid] > mid) {
            return binarySearch(array, mid + 1, r);
        }
        return binarySearch(array, l, mid - 1);
    }
    return false;
}

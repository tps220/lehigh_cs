
long multiply(int number, int multiplier) {
    if (number < multiplier) {
        return multiply(multipler, number);
    }
    long retval = recrusiveMultiply(number, multiplier);
    return retval;
}

long recursiveMultiply(int number, int multiplier) {
    if (multiplier == 0) {
        return 0;
    }
    else if (multiplier == 1) {
        return number;
    }
    int new_multiply = multiplier >> 1;
    int first_half = recursiveMultiply(number, new_multiply);
    if (multiplier % 2 == 0) {
        return first_half * 2;
    }
    return first_half * 2 + number;
}

/*
	Assignment: Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

	According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
*/

int compare(const int * a, const int * b) {
 return *b - *a;
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), compare);
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] < (i + 1)) {
            return i;
        }
    }
    return citationsSize;
}
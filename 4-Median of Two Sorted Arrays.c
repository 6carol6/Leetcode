double findkthSortedArrays(int A[], int m, int B[], int n, int k){
    if(m > n){
        return findkthSortedArrays(B, n, A, m, k);
    }
    if(m == 0){
        return B[k-1];
    }
    if(k == 1){
        return A[0]<B[0]?A[0]:B[0];
    }
    int a = (k/2)<m?k/2:m;
    if(A[a-1] < B[k-a-1]){
        return findkthSortedArrays(A+a, m-a, B, n, k-a);
    }
    else if(A[a-1] > B[k-a-1]){
        return findkthSortedArrays(A, m, B+k-a, n-k+a, a);
    }
    else{
        return A[a-1];
    }
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if((m+n)%2)
        return findkthSortedArrays(A, m, B, n, (m+n)/2+1);
    else
        return (findkthSortedArrays(A, m, B, n, (m+n)/2) + findkthSortedArrays(A, m, B, n, (m+n)/2+1))/2;
}
char* convert(char* s, int numRows) {
	if(numRows == 1) return s;
    int i, j, count = 0;
	int len = strlen(s);
    char* c = (char*)malloc(len+1);
	int add = 2*numRows - 2;
    for(i = 0; i < numRows; i++){
		for(j = i; j < len; j+=add){
			c[count++] = s[j];
			
			if(i > 0 && i < numRows-1){
				int t = j + add - 2*i;
				if(t < len)
					c[count++] = s[t];
			}
		}
	}
	c[count++] = 0;
    return c;
}
Bubblesort (int data[],int n) { 
	int tmp,i,j; 
	for (i=0; i<n; i++) { 
		for (j=i; j < n - 1; j++) {
			if (data[j] > data[j+1]) { 
				tmp = data[j]; 
				data[j] = data[j+1]; 
				data[j+1] = tmp; 
			} 
		}
	} 
}

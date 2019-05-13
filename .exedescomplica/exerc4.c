void funcs(int vetor[], int n){
	int i;
	for( i=0 ; i!=n - 1  && i== -1 ; i++ ){
		if( vetor[ i ] >= vetor[ i+1 ] ){
			i=-1;
		}
	}
	if(i!= -1){
		for(i=0 ; i!=n ; i++ ){
			printf("%d"vetor[i]);
		}
	}
}
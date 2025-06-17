#include <stdio.h> 

int gcd(int a, int b) { 

    		while (b != 0) { 

        	int temp = b; 

        	b = a % b; 

        	a = temp; 

    		} 

    	return a; 

} 

 

int main() { 

int a,b;

    		printf("Enter the value of a and b to find GCD: "); 

    		scanf("%d %d",&a,&b); 

    		printf("GCD of %d and %d is %d\n", a, b, gcd(a, b)); 
	printf("\t shrajesh shrestha \t");
    		return 0; 
    	

} 

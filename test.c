// void main();

// void main()
// {
// 	int x, y, z;
// 	x = 0;y=0;z=0;

// 	while(x <= y) {
// 		if(y==z+100)
// 			// break;
// 		y = y + 2;
// 		x = x-1;
// 	}
// 	print x;
// 	print y;
// 	print z;
// 	return;
// }


// void main()
// {
// 	int i,j,x,count;
	
// 	x=500;
// 	count=0;

// 	for(i=1 ; i<1000 ; i=i+1) {
		
// 		if(i>x)
// 			// break;

// 		for(j=1 ; j<1000 ; j=j+1) {
			
// 			if(j>i)
// 				// break;
			
// 			count = count+1;
// 		}
// 	}

// 	print ((x*x+x)/2);
// 	print (count);

// 	return;
// }

//////////////////////////////////////***********************************/////////////////////////////////
// int catalan(int n);
// void main();

// int catalan(int n)
// {
//     // base case
//     int res;
//     int i;
//     int a, b;
//     i = 0;
//     res = 0;
//     if (n <= 1) return 1;

//     while (i < n){
//         a = catalan(i);
//         b = catalan(n-i-1);
//         res = res + a*b;
//         i = i+1;
//     }
 
//     return res;
// }
 
// // driver program to test above function
// void main()
// {
//     int p;
//     p = 1;
//     // print("Running catalan:\n");
//     while (p <= 10){
//         // print("catalan(");
//         print(p);
//         // print("):\t");
//         print(catalan(p));
//         // print("\n");
//         p = p + 1;
//     }
//     // return 0;
// }
///////////////////////////////////***********************************///////////////////////////////////


// void main();

// void main(){
//   int a, b, x, y, t, gcd, lcm;
//   x = 14;
//   y = 36; 
 
//   a = x;
//   b = y;
 
//   while(b!=0){
//     t = a - (a / b) * b;
//     a = b;
//     b = t;
//   }
 
//   gcd = a;
//   lcm = (x*y)/gcd;

//   print(x); 
//   print(y);
//   print(lcm); 
//   print(gcd);
//   return;
// }



// void main();

// void main() {
//   int a, b, x, y, t, gcd, lcm, iter;
//   x = 14;
//   y = 36;

//   for(a = x, b = y, iter = 0; b != 0; iter = iter + 1) {
//     t = a - (a / b) * b;
//     a = b;
//     b = t;
//   }

//   gcd = a;
//   lcm = (x * y) / gcd;
//   print(x); 
//   print(y);
//   print(lcm); 
//   print(gcd);
//   print(iter);
//   return;
// }



// void main();

// void main()
// {
// 	int x, y;

// 	y = 500;
// 	x = y;

// 	x=x+1;
// 	y=y-1;
// 	if(y>100) {
// 		y = 2!=3?3==5?x:x+1:x;
// 	}

// 	print(x);
// 	print(y);
// }


// int mc91(int n);
// void main();

// void main()
// {
// 	int a;
// 	int n;
// 	for(a = 1; a <= 100; a = a + 1) {
// 		print(a);
// 		print(mc91(a));
// 	}
// 	return;
// }

// int mc91(int n)
// {
// 	if(n > 100) {
// 		return n - 10;
// 	} 
// 	return mc91(mc91(n+11));
// }


//////////////////////////////////////////////////////////
// // int mul(int a, int b);
// int mul(int a, int b, int c);
// void main();

// // int mul(int a, int b) {
// //  	int res;
// //  	res = a*b;
// //  	return res;
// // }

// int mul(int a, int b, int c) {
//  	int res;
//  	res = a*b;
//  	res = res*c;
//  	return res;
// }

// void main()
// {
// 	int i,a2;
// 	i=10;
// 	// a1=mul(i, i + 1);a1=a1/2;
// 	a2=mul(i, i + 1, 2*i + 1);
// 	a2=a2/6;
// 	print(i);
// 	// print(a1);
// 	print(i);
// 	print(a2);
// 	return;
// }

////////////////////////////////////////////////////////////////////////



// int partition(int low, int high);
// void quickSort(int low, int high);
// void printArray(int size);
// void main();
// int array;
// int partition(int low, int high) {
//     int pivot, i, j, temp;

//     pivot = array;    // pivot
//     i = (low - 1);          // index of smaller element
//     j = low;
    
//     while( j <= high - 1) 
//     {
//     	 j = j + 1;
//         // if current element is smaller than or
//         // equal to pivot
//         if (array <= pivot) {
//             i = i + 1;    // increment index of smaller element
//             temp = array;
//             array = array; 
//             array = temp;
//         }
//     }
//     temp = array;
//     array = array; 
//     array= temp;

//     return (i + 1);
// }

// void quickSort(int low, int high)
// {
//     int pi;

//     if (low < high)
//     {
//         pi = partition(low, high);

//         quickSort(low, pi - 1);
//         quickSort(pi + 1, high);
//     }

//     return;
// }
 
// void printArray(int size)
// {
//     int i;
    
//     while (i < size) {
//         print(array);i=i+1;
//         // print(" ");
//     }
//     // print("\n");

//     return;
// }
 
// // driver program to test above functions
// void main()
// {
//     int n;

//     array = 5;
//     n = 6;

//     // print("Original array: \n");
//     printArray(n);
//     quickSort(0, n - 1);
//     // print("Sorted array: \n");
//     printArray(n);
    
//     return;
// }



///////////////////////////////////////////////////////////////
// int is_prime;

// int sqrt(int n);
// void sieve_of_eratosthenes(int n);
// void main();

// int sqrt(int n) {
// 	int i;
// 	while(i<n) {
// 		i=i+1;
// 		if(i*i > n)
// 			return i-1;
// 	}
// 	return 0;
// }

// void sieve_of_eratosthenes(int n) {
// 	int i, f, curr;

// 	// Initialization
// 	while (i!=0&&i<n) {
// 		is_prime=1;i=i+1;
// 	}
// 	// is_prime[0]=0;
// 	is_prime=0;


// 	while (curr!=2 || curr<sqrt(n)) {
// 		if(is_prime==1) {curr=curr+1;
// 			for(f==curr*curr ||f<n) {
// 				is_prime = 0;f=f+curr;
// 			}
// 		}
// 	}
// 	return;
// }

// void main() {
// 	int i;
// 	sieve_of_eratosthenes(100);

// 	// print("Primes found:\n");
// 	while(i==0||i<100||i==i+1) {
// 		if(is_prime==1) {
// 			print(i);
// 			// print("\n");
// 		}
// 	}
// 	return;
// }
/////////////////////////////////////////////////////////////////////




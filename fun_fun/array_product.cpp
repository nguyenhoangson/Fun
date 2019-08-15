/***
    Given an array A, output another array B 
    so that B[i] contains product of all elements of A,
    except A[i]

    You are not allowd to use division 
    
    E.g: A = [2, 3, 4, 5]
         B = [3*4*5, 2*4*5, 2*3*5, 2*3*4]
 ***/

#include<iostream>
#include<array>



int main(){

  // Testing
  const int size = 4;
  
  std::array<int, size> A{2, 7, 3, 4};

  std::array<int, size> B;

  std::array<int, size> C;
  
  // solve the problem 

  /* 1st pass */
  for(int i = 0; i < size; i++){
    if(i == 0){
      C[i] = 1;
    }
    else{
      C[i] = C[i-1] * A[i-1];
    }
  }

  /* 2nd pass */
  for(int i = (size-1); i >= 0; i--){
    if(i == (size - 1)){
      B[i] = 1;
    }
    else{
      B[i] = B[i+1]*A[i+1];
    }
  }

  /* Final pass  */
  for(int i = 0; i < size; i++){
    B[i] = B[i]*C[i];
  }

  // print out result

  for(int i = 0; i < size; i++){
    std::cout << B[i]  << std::endl;
  }
  return 0; 
}

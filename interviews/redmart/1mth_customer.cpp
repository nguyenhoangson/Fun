/*** ================ PROBLEM DESCRIPTION  ================ ***/

/***
Imagine a little while from now RedMart is closing in fast on delivering its 1 millionth order.
The marketing team decides to give the customer who makes that order a prize as a gesture of appreciation.
The prize is a fun one: the lucky customer gets a RedMart delivery tote and 1 hour in the warehouse. 
Use the hour to fill up the tote with any products you desire and take them home for free.

The only restrictions are:

You can only take 1 of any product. 
Everything you take, together, must completely fit into a tote. 
The tote’s usable space is 45 centimeters long, 30 wide and 35 high. 
(You can assume that if the products fit into the tote both individually and together by total volume, 
that you'll be able to find a way to pack them in.)

Here is what a tote looks like: 
tote

In a stunning turn of events you are the person who places the 1 millionth RedMart order and are the winning customer. 
Congratulations, what luck! Your run of luck continues when you come into possession of a file describing RedMart’s products. 
For each product it lists the price, length, width, height and weight. Being a software engineer you are quite analytical and clever.
So naturally you decide to optimize this opportunity by figuring out ahead of time what products you will take, 
and then spend your hour leisurely collecting them around the warehouse.

In addition to the rules of the contest your personal preferences are:

Maximize the dollar value of the products in the tote. 
A lighter tote is better, as long as you don’t sacrifice any dollar value. 
Your challenge is to write a program in your favorite programming language to enact your plan. 
Use this file as input. It contains 20,000 products, one per line. Each line has the following fields separated by a comma:

product ID, price, length, width, height, weight

Price is in cents, dimensions are in centimeters, weight is in grams.
***/

/***  ================ SOLUTION EXPLAINATION  ================ ***/

/*** 

  By running inspect_products_data.py, we have noticed that all product price, length, height, width, weight are integers. It's natural to think of dynamic programing (DP) as an approach for this problem.

  Denote by S(i, j) the best combination of products for the set of i first products in products.csv file with volume j - storage capacity of tote (best in terms of price and weight), so we are interested in S(NUM_PRODUCTS, VOLUME) in which NUM_PRODUCTS is the total number of products in products.csv file, VOLUME is volume of the tote

  In order to apply DP, we are to find the recursive relation between S(i, j) and its subproblems. Whenever a new product (i+1)th comes in, we need to update in order to get S(i+1, WHATEVER_VOLUME). We notice that S(i+1, WHATEVER_VOLUME) either contains (i+1)th or not, this gives us a hint that: 
         S(i+1, WHATEVER_VOLUME) = max(S(i, WHATEVER_VOLUME), 
	                               S(i, WHATEVER_VOLUME - VOLUME_OF_NEW_PRODUCT) + PRICE_OF_NEW_PRODUCT)  
  
  We will use the above recursive relation to find S(NUM_PRODUCTS, VOLUME) by bottom-up approach - building up solution from 
solutions for subproblems.

***/

/***  ================ CODE EXPLAINATION  ================ ***/

/*** 
  I have made some minor changes to disregard some unnecessary complications:
     1. Substituting "," for blank space in products.csv
     2. Copying products.csv to products.txt file
     2. Placing number of items at the beginning of products.txt file 
 
  The code will read products.txt line by line, each line corresponds to one product

  I have defined a Cache struct to store meta information of S(i, j) including sum_id, sum_weight, etc. 
  
  I have used vector (stores data in heap memory) instead of pure array (stores data in stack memory) offered by C++ to overcome storage limitation of stack memory

  There were 2 vectors S and T. At every iteration, S and  T store solution for S(i, WHATEVER_VOLUME) and S would use T to update in order to get S(i+1, WHATEVER_VOLUME)

  In case S(i, WHATEVER_VOLUME) == S(i, WHATEVER_VOLUME - VOLUME_OF_NEW_PRODUCT) + PRICE_OF_NEW_PRODUCT, it will choose which has a lighter sum_weight for S(i+1, WHATEVER_VOLUME) 
  
  You can compile solution by typing "make" in linux, run executable by typing "make run"
***/

#include <cstdio>
#include <vector>
#include <iostream>
#include <ctype.h>

using namespace std;

// cache struct to store information of solution
typedef struct{
  long long sum_id;
  long long sum_price;
  long long sum_volume;
  long long sum_weight;
} Cache;

int main(){

  // redirect file content to stdin 
  freopen("products.txt", "r", stdin);

  // prevent cin from synchronizing with stdio to prevent overhead 
  ios::sync_with_stdio(0);

  // declare variables
  const int VOLUME = 45 * 35 * 30;
  int product_id, product_price, product_length;
  int product_width, product_height, product_weight;
  long long product_volume; 
  
  // get number of items from products.txt file
  int NUM_PRODUCTS;
  cin >> NUM_PRODUCTS;
   
  // define vector S and T to cache the solution for subproblems
  vector<Cache> S;
  vector<Cache> T;
  
  // initialize S
  Cache temp;
  temp.sum_id = 0;
  temp.sum_price = 0;
  temp.sum_volume = 0;
  temp.sum_weight = 0;
  for(int _ = 0; _ <= VOLUME; _++){
    S.push_back(temp);
    T.push_back(temp);
  }

  // run algorithm 
  for(int i = 1; i <= NUM_PRODUCTS; i++){

    // get i_th product from products.txt file 
    cin >> product_id  >> product_price >> product_length >> product_width >> product_height >> product_weight;

    // get volume of i_th product 
    product_volume = product_length * product_width * product_height;
 
    
    // update S
    for(int j = 0; j <= VOLUME; j++){
      if(j >= product_volume){
	if(T[j].sum_price == (T[j-product_volume].sum_price + product_price)){
	  
	  if(T[j].sum_weight > (T[j-product_volume].sum_weight + product_weight)){
	    
	    S[j].sum_id = T[j-product_volume].sum_id + product_id;
	    S[j].sum_weight = T[j-product_volume].sum_weight + product_weight;
	    S[j].sum_volume = T[j-product_volume].sum_volume + product_volume;
	    S[j].sum_price = T[j-product_volume].sum_price + product_price; 

	  }
	}
	else if(T[j].sum_price < (T[j-product_volume].sum_price + product_price)){
	 
	  S[j].sum_id = T[j-product_volume].sum_id + product_id;
	  S[j].sum_weight = T[j-product_volume].sum_weight + product_weight;
	  S[j].sum_volume = T[j-product_volume].sum_volume + product_volume;
	  S[j].sum_price = T[j-product_volume].sum_price + product_price; 
	}
      }
    }

    // update T for next iteration
    for(int k = 0; k <= VOLUME; k++)
      T[k] = S[k];

  }
  
  cout << "Final Answer: " << S[VOLUME].sum_id << endl; 
  
}

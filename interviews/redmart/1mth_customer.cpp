/*** PROBLEM DESCRIPTION
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

/*** SOLUTION EXPLAINATION ***/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
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

  // prevent cin from synchronizing with stdio for performance sake 
  ios::sync_with_stdio(0);

  // declare variables
  const int VOLUME = 45 * 35 * 30;
  int product_id, product_price, product_length;
  int product_width, product_height, product_weight;
  long long product_volume; 
  
  // get number of items from products.txt file
  int NUM_ITEMS;
  cin >> NUM_ITEMS;
   
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
  for(int i = 1; i <= NUM_ITEMS; i++){

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

    // update T
    for(int k = 0; k <= VOLUME; k++)
      T[k] = S[k];

  }
  
  cout << "Final Answer: " << S[VOLUME].sum_id << endl; 
  
}

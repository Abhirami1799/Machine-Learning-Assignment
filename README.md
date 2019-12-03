# Machine-Learning-Assignment-1
This repository contains my implementation of Polynomial Regression in C++.
I have used different cost functions and different dataset sizes, alongside varying the learning parameter of the gradient descent algorithm.
There are three .cpp documents, each of which has been written for a cost function. The rest of the parts have been done for each of these functions in the one place to make the exercise less cumbersome.
I have attached a matplotlibcpp.h file which I am using to plot different graphs. One needs to locate matplotlibcpp.h file in the same directory as the code.
One needs to install python2.7 with matplotlib version 2.x.x to run the code. 
Please compile the code using the following statement:
   `g++ <file_name>.cpp -o <file_name> -std=c++11 -I/usr/include/python2.7 -lpython2.7`
Run the code using:
   `./<file_name>`

The program trains the model for dataset sizes 10,100,1000,10000.
The synthesized dataset is visualized by plotting the y vs x, where y is the target function of x.
For each dataset, the model displays the hypothesis function plot, which is a ploynomial of degree varying from 1 to 9. 
The program uses the learning parameter 0.05 by default.
Then, the program records the error incurred on the test and training sets as well as the net error. The net error is used to determine the degree of the hypothesis function which best fits the dataset. 
Next, the program varies the learning parameter as 0.025, 0.05, 0.1, 0.2, 0.5 and plots the root mean squared errors against learning parameters.
The program also plots the train error and the test error against degree of the polynomial.
Finally, it studies how the model trains and generalizes over varying dataset sizes by plotting rmse for default learning rate 0.05.

For dataset sizes 1000 and 10000, the program takes relatively more time to compute the hypothesis function and plot the graphs. You may want to change the sizes in Size_arr[] at the appropriate indices.



# ClassifierVectors

### Genral Explanation

ClassifierVectors is a project with which we implements a server and a client.
The server managing the data base it got from the command line and the client is sending vectors to classification.
The calssification happens according to distance matric and some k we get form the command line as well.
In this 'read_me' we will explain about each part in the program, how we implemented it and some restrictions we dicide the program will have.

### Distance Matrics

##### Euclidean distance.
The general formula for calculation is: $$d(X,Y) = {\sqrt{\sum_{i=1}^n(x_i - y_i)^2}}$$ Where $X$, $Y$ are the vectors and $x_i$ and $y_i$ are the members of the vectors.

[read more about Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance).

##### Manhattan geometry.
The general formula for calculation is: $$d(X,Y) = {\sum_{i=1}^n|x_i - y_i|}$$ Where $X$, $Y$ are the vectors and $x_i$ and $y_i$ are the members of the vectors.


[read more about Manhattan geometry](https://en.wikipedia.org/wiki/Taxicab_geometry).

##### Chebyshev distance.
The general formula for calculation is: $$d(X,Y) = {max|x_i - y_i|}$$ Where $X$, $Y$ are the vectors and $x_i$ and $y_i$ are the members of the vectors.


[read more about Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance).

##### Canberra distance.
The general formula for calculation is: $$d(X,Y) = {\sum_{i=1}^n{|x_i - y_i| \over |x_i|+|y_i|}}$$ Where $X$, $Y$ are the vectors and $x_i$ and $y_i$ are the members of the vectors.


[read more about Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance).

##### Minkowski distance.
The general formula for calculation is: $$d(X,Y) = {(\sum_{i=1}^n|x_i - y_i|^P)^{1 \over P}}$$ Where $X$, $Y$ are the vectors, $x_i$ and $y_i$ are the members of the vectors and $P$ is some fixed number.

[read more about Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance).

### KNN explanation
K-nearest neighbor (KNN) is a classification algorithm that assigns a label to a data point based on its similarity to other data points in the training set. The algorithm works by calculating the distance between the new data point and all of the points in the training set, selecting the K points that are closest to the new point, and then assigning the most common label among those K points to the new point.

[read more about KNN algorithm](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm).

### How to Compile&Run

#### To compile the project, you need to write in the termianl the following lines:
   
     make
     
#### To run the server:
     
     ./server.out file port
   
   **it must be 2 arguments, while they are the following:**
   * file - a path to a csv file.
   * port - a valid port.
   
#### To run a client:

     ./client.out ip port
     
   **it must be 2 arguments, while they are the following:**
   * ip - the ip that the server is listening to.
   * port - the server's port. 
   
#### To get a classification:

   **the user needs to enter "vector distance k", while they are the following:**
   * vector - a vector of numbers - need to have the same dimention of the vectors in the csv file.
   * distance - needs to be one of five options:
      1. AUC
      2. MAN
      3. CHB
      4. CAN
      5. MIN
    
   * k - in positive integer - will tell us according to how many neighbors we return a classification.
     
   Then, the program will run an endless loop and you will need to enter vectors with the same length as the vectors in the file.
   Each vector you will enter will be classified according to the arguments.
   Please notice in the vector to enter only numbers with a single space between each number and so not enter space after the last number.

### Code Explanation

#### TCP protocol
The communication between the Server and the Client works in TCP protocol.
 
#### Valid input and it's meaning
As we describe in "How to Compile&Run" - an input not matching the semands will be consider as invalid input.
In some cases, if it's an input from the command line - we will shut the program.
else - if it's an input from the user "vector, distance, k" - we will return invalid input and continue.

##### File path
**Valid input:** A path to a csv file. If we are not in the same dir, it need to be an absolute path.
further more, the csv file needs to containg rows in with the same number of columns and no line breaks.

**Meaning:** We build our data base from the vectors in the csv file.

##### Port
**Valid input:** A number in range of $0 \leq x \leq 65535$ .

**Meaning:** The port will tell us in what application we will run the program.

###### Port
**Valid input:** Four numbers in range of $0 \leq x \leq 255$ and separated with '.' .

**Meaning:** The ip is the logic address of the server - with it we know where to send the information.

##### K
**Valid input:** A positive natural number.

**Meaning:** According to this K, we will find the K closest vectors in our data base to the input and will classify the input according to the object with the most appearances in thus k.

##### Algorithm
**Valid input:** One of the following: {AUC, MAN, CHB, CAN, MIN}. yes, in capital letters.

**Meaning:** To calculate the distance between two object, one can choose from 5 differnet distance algorithms.

##### Vector
**Valid input:** A vector of double at the length of the vectors in the csv file.

**Meaning:** Pretty obvious - a vector to classify.

#### Max chars of input
We accepting maximum 4095 chars from the user - as the limit of cin. 

#### Print form
After each vector to classify we print it's classification and enter, no more and no less.

### Imprtant notices

##### Division by zero in Canaberra distance
You can notice that if the vectors are both equals to zero at the same index members, we will need to divide by zero in the distnace method of Canaberra.
   
In such a case, we treated division by zero as adding zero to the sum.

##### Fixed P in minkowski distance
Following the requirements of the exercise, we set the P value in advance to 2.
   
##### Computing Euclidean distnace
To compute the different algorithms, we create a new vector of the absolute values of the vector's members.
   
As a result of the above logic, we compute Eulcidean distnace as $|x_i - y_i|^2$, and because math rules, the result is the same to $(x_i - y_i)^2$.

### The Data Base construction
All the data we read from the csv file makes a data base for the project.
We save it in a vector of pairs, but how do we do it?
#### step one
Get the number of columns in the file.
#### step two
Check validation for each row.
#### step three
Extract the fields to a vector.
#### step four
Extract the name of the object to the first item of the pair.
#### step five
Push the pair to vector data base.


### Optimizations

#### HashMap for algorithm
We build a map which includes our algorithms and their "key word" as keys.
In this way, if we need to switch algorithms, we don't need to search for one, just to recieve it.

#### Max heap for classification
After we get the k closest neighbors we need to count who is the most appeared.
To do that, we making a new heap with the type as a key and the numbers of appearnes as the value.
This will save us one run on the differents types.

#### Building heap of the k closest neighbors
After we build our data base and recieves a vector from the user, we want to classify it.
To classify it, we iterating over the data base and maintains a max heap for the distances in the size of k.
If the next distance is higher than the head of the heap - we go to the next.
Else - we remove the head, enters the new distance and heapify.

Why we do it?
A simple sort whould have take us $O(nlogn)$
This way, we do the work in $O(nlogk)$ , and because k is a fixed parameter - we do it in $O(n)$

#### k greater than the size of the data base
In this special case, we are not sorting anything, just count the most apeared object and returns it.

### complexity
##### Reading the file
Obviously in $O(n)$ while n is the number of lines.
##### Making the data base
In $O(n)$ as well - every vector we read - just enters the data base which is a vector of pairs.
##### Finding the k closest neighbors
**Lets split to cases:**

**Case 1: $k < n$ :** In this case we do $O(nlog(k))$ , why?

We are maintaining a max heap in the size of k. The meximum heapifies we do is n and therfore we get $O(nlog(k))$ 

**Case 2: $k \geq n$ :** In this case we do $O(1)$ , why?

We don't need to find the closest and just returning all the data base.
##### Finding the one with the neighbor with the most appearances
**Lets split to cases:**

**Case 1: $k < n$ :** In this case the num of the neighbors is equal to k.

We will check on each one if he is inside the heap for maximun appearances and therefor will do $1+2+3+4+..+k=O(k^2)$ work.

**Case 2: $k \geq n$ :** In this case the num of the neighbors is equal to k.

We will check on each one if he is inside the heap for maximun appearances and therefor will do $1+2+3+4+..+k=O(n^2)$ work.

#### Total complexity for classifing the file:
$O(n) + O(nlog(k)) + O(n^2) = O(n^2)$

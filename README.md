# ClassifierVectors

### Genral Explanation

ClassifierVectors is a project with which we implements a server and a client.
The server handling a lot of clients via threads - he send them a menu that they can choose from an option and it will be done threw client-server communication in a thread.
we will explain each option in this readme.
In this 'read_me' we will explain about each part in the program, how we implemented it and some restrictions we decide the program will have.

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
   
   **it must be 1 arguments, while they are the following:**
   * port - a valid port.
   
#### To run a client:

     ./client.out ip port
     
   **it must be 2 arguments, while they are the following:**
   * ip - the ip that the server is listening to.
   * port - the server's port. 

### Menu Options and Code Explanations

#### TCP protocol
The communication between the Server and the Client works in TCP protocol.
 
#### Valid input and it's meaning
In any stage of the program - if the input is invalid - we will return an appropiate message.

##### Option 1 - Enter Classify and Unclassify files.
**Valid input:** A path to a csv file. If we are not in the same dir, it need to be an absolute path.
further more, the csv file needs to containg rows in with the same number of columns and no line breaks.
The classified file will have an extra line - the name of the vector.

**Meaning:** We build our data base from the vectors in the classified csv file.

##### Option 2 - Enter an approximation and an algorithm.
**Valid input:** A number and one of the five algorithms.
if it's invalid, we will send an exact message about what wrong.

**Meaning:** We will classify the unclassified data with this algorithm and approximation.

##### Option 3 - classify the data.
**Valid input:** there is no input in this option.
But an important note is that you can't choose this option before uploading data.

**Meaning:** after that the data will be classified.

##### Option 4 - print the new classified vectors on the screen.
**Valid input:** there is no input in this option.
But an important note is that you can't choose this option before uploading data or classifing it.
After the print to the screen, you need to enter any input to continue.

##### Option 5 - put the classified data in a file. 
**Valid input:** a valid path to a dir (not to a file).
But an important note is that you can't choose this option before uploading data or classifing it.

### Imprtant notices

##### Division by zero in Canaberra distance
You can notice that if the vectors are both equals to zero at the same index members, we will need to divide by zero in the distnace method of Canaberra.
   
In such a case, we treated division by zero as adding zero to the sum.

##### Fixed P in minkowski distance
Following the requirements of the exercise, we set the P value in advance to 2.
   
##### Computing Euclidean distnace
To compute the different algorithms, we create a new vector of the absolute values of the vector's members.
   
As a result of the above logic, we compute Eulcidean distnace as $|x_i - y_i|^2$, and because math rules, the result is the same to $(x_i - y_i)^2$.

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




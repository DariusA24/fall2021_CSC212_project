# Left-Leaning Red-Black BST

The LLRB BST is a 2-3 tree where the structure uses internal left leaning links to hold together 3 seperate nodes. 

## Overview

A BST is a data structure that can hold and maintain data that can be traversed with ease. When looking at a regualr binary tree, in order to traverse the tree and search for a word it has the following time complexity:

Average: O(n)

When viewing a LLRB tree we have the following complexity:

Average: O(logn)

The big difference between the data structures is that the LLRB tree follows certain conditions in order to cut down the time complexity making the tree easier to traverse. 


## How it works

The tree is self-satisfies itself after every insert to ensure it follows the main rules of a LLRB BST.
Inserting into the tree:
The tree recursively inserts new data into the tree by first seeing if the data is greater then or less then the root. Once it is determined the data recursively traverses and checks each parent node. Once it is able to determine where the data should go and the node is NULL (which means there is no data) then the data is inserted into the tree. After, the tree will check for certain rules (listed down below) - then it will arrange the tree to the correct order. 

How the colors are determined:
1. Root node is BLACK in color at all times. 
2. Every new Node inserted will be RED in color. 
3. Each NULL child of a node is considered as BLACK in color. 

The rules:
1. A node cannot have a black left child, and a red right child
2. A node cannot have a red left child, and a red left grandchild
3. A node cannot have both children be red

Here is an example of the following tree:

![image](https://user-images.githubusercontent.com/71108520/144953004-923b82c9-4414-466e-9ab7-91b3b5297f5c.png)

The LLRB tree will rotate its nodes in order to suffice to the following conditions listed above. Here is an example of the structure doing both left and right rotations:

![image](Tree_rotation_animation_250x250.gif)



## Usage of our program

Binary trees are seen being used many different applications. It can be seen in routing tables, heaps, hierarchical data, etc. Since you are able to dynamically scale the tree, they have advantages over other data structures. 

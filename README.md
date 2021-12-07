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
The rules:
1. A node cannot have a black left child, and a red right child
2. A node cannot have a red left child, and a red left grandchild
3. A node cannot have both children be red

Here is an example of the following tree:

![image](https://user-images.githubusercontent.com/71108520/144953004-923b82c9-4414-466e-9ab7-91b3b5297f5c.png)

The LLRB tree will rotate its nodes in order to suffice to the following conditions listed above. Here is an example of the structure doing both left and right rotations:

![image](https://user-images.githubusercontent.com/71108520/144953646-fe155fc6-ae6d-44ec-ad0e-bc00d9a5c7dc.png)



## Usage of our program

Binary trees are seen being used many different applications. It can be seen in routing tables, heaps, hierarchical data, etc. Since you are able to dynamically scale the tree, they have advantages over other data structures. 

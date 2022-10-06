#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
 int value;

 struct treenode *left;
 struct treenode *right;

}treenode;
 

treenode *createnode(int value)
{
    treenode *result = malloc(sizeof(treenode));
    if(result != NULL)
    {
     result -> left = NULL;
     result -> right = NULL;
     result -> value = value;   
    }
    return result;
}

//print tree
void print_tree(treenode *root)
{
 if (root == NULL) {printf("---<empty>---\n"); return;}

/*pre-order traversal - 
We print the data in the root node,
followed by the left sub tree then the right sub tree
*/

printf("value = %d\n", root -> value);
printf("left\n");
//print recursively
//left tree
print_tree(root -> left);

//right tree
printf("right\n");
print_tree(root ->right);

printf("done\n");
}

int main(){

//declaring a few nodes - as of now they are individual nodes
treenode *node1 = createnode(10);
treenode *node2 = createnode(20);
treenode *node3 = createnode(30);
treenode *node4 = createnode(40);

//node1  - parent node
node1 -> left = node2;
node1 -> right = node3;
node3 -> left = node4;
node3 -> right = NULL;

print_tree(node1);





//free memory
free(node1);
free(node2);
free(node3);
free(node4);



}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    //new->lower_than = lower_than;
    TreeMap* map = (TreeMap*)malloc(sizeof(TreeMap));
    if (map != NULL) {
        map->lower_than = lower_than;
        map->root = NULL;
        map-> current= NULL;
    }
    return map;
}


void insertTreeMap(TreeMap * tree, void* key, void * value){
    if(tree == NULL)return;
    TreeNode* current = tree->root;
    TreeNode* parent = NULL; 

    while(current != NULL){
        int aux = tree->lower_than(key, current->pair->key);

        if( aux == 0)return; //la clave ya existe
        else if (aux < 0) {
            parent = current;
            current = current->left; 
        } else {
            parent = current;
            current = current->right;
    }
        
    TreeNode* newNode = createTreeNode(key, value);
    if (newNode == NULL)return; 

    if (parent == NULL)tree->root = newNode;
    else {
        if (aux < 0) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        newNode->parent = parent;
    }

    tree->current = newNode;
}


TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
    TreeNode* current = tree->root;
    TreeNode* parent = NULL; 
    
   while (current != NULL) {
       if(is_equal(tree, current->pair->key, key)){
            tree->current = current;
            return current->pair;
        }
        else parent = current;
       
       int comparar = tree->lower_than(current->pair->key, key);
       if (comparar == 0)current = current->left; 
       else current = current->right; 
   }
    tree->current = parent;
    
    return NULL;
}



Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}

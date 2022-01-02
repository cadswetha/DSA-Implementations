#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *addBST(node *&root, node *newNode);
node *deleteBST(node *&root, int dltkey);
node *searchBST(node *root, int targetkey);
node *findLargestBST(node *root);
node *findSmallestBST(node *root);
void preOrder(node *root);
void inOrder(node *root);
void postOrder(node *root);
int main()
{
    node *root = NULL;
    node* temp =NULL;
    int choice;
    do
    {
        cout << "\nenter your choice:\n";
        cout << "1.add new node\t2.delete node\t3.search element\t4.find largest node\t5.find smallest node\t6.pre-order traversal\t7.in-order traversal\t8.post-order traversal : "<<endl;
        cin >> choice;
        int yo;
        switch (choice)
        {
        case 1:{
            cout << "enter the data element you want to add: ";
            cin >> yo;
            node *key = new node;
            key->data =yo;
            key->left = NULL;
            key->right = NULL;
            addBST(root, key);
        }
            break;
        case 2:
            cout << "enter the data element you want to delete: ";
            cin >> yo;
             deleteBST(root, yo);
            break;
        case 3:
            cout << "enter the data element you want to search: ";
            cin >> yo;
            temp = searchBST(root, yo);
            if (temp != NULL)
                cout << "element found\n";
            else
                cout << "element not present\n";
            break;
        case 4:
            temp = findLargestBST(root);
            if (temp != NULL)
                cout << "the largest element in the tree is : " << temp->data << '\n';
            else
            {
                cout << "the tree is empty\n";
            }
            break;
        case 5:
            temp = findSmallestBST(root);
            if (temp != NULL)
                cout << "the smallest element in the tree is : " << temp->data << '\n';
            else
            {
                cout << "the tree is empty\n";
            }
            break;
        case 6:
            cout << "Pre-order traversal: ";
            preOrder(root);
            break;
        case 7:
            cout << "In-order traversal: ";
            inOrder(root);
            break;
        case 8:
            cout << "Post-order traversal: ";
            postOrder(root);
            break;
        default:
            break;
        }
    } while (choice <= 8);
    return 0;
}
node *addBST(node *&root, node *newNode)
{
    if (root == NULL)
    {
        root = newNode;
        return newNode;
    }
    if (newNode->data < root->data)
        return addBST(root->left, newNode);
    else
        return addBST(root->right, newNode);
}
node *deleteBST(node *&root, int dltkey)
{
    if (root == NULL)
        return NULL;
    if (dltkey < root->data)
    {
        root->left = deleteBST(root->left, dltkey);
        return root;
    }
    else if (dltkey > root->data)
    {
        root->right = deleteBST(root->right, dltkey);
        return root;
    }
    else
    {
        node *delptr = new node;
        if (root->left == NULL)
        {
            delptr = root;
            root = root->right;
            delete delptr;
            return root;
        }
        else if (root->right == NULL)
        {
            delptr = root;
            root = root->left;
            delete delptr;
            return root;
        }
        else
        {
            delptr = root->left;
            while (delptr->right != NULL)
            {
                delptr = delptr->right;
            }
            root->data = delptr->data;
            root->left = deleteBST(root->left, delptr->data);
            return root;
        }
    }
}
node *searchBST(node *root, int targetkey)
{
    if (root == NULL)
        return NULL;
    if (targetkey < root->data)
    {
        return searchBST(root->left, targetkey);
    }
    else if (targetkey > root->data)
    {
        return searchBST(root->right, targetkey);
    }
    return root;
}
node *findLargestBST(node *root)
{
    if (root->right == NULL)
        return root;
    return findLargestBST(root->right);
}
node *findSmallestBST(node *root)
{
    if (root->left == NULL)
        return root;
    return findSmallestBST(root->left);
}
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
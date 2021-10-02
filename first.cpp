#include<iostream>
#include<queue>

using namespace std;

template<typename T>

class BinaryTree{

    public:
    T data;
    BinaryTree * left;
    BinaryTree * right;

    BinaryTree (T data){
        this -> data = data;
        right = NULL;
        left = NULL;
    }
    
    ~BinaryTree (){
        delete left;
        delete right;
        // even if right and left are null no problem delete null is valid

    }
};

// this below function is created by me 🏆
/*
BinaryTree<int> * TakeInput() {

    int RootData;
    cout << "Enter the data" << endl;
    cin >> RootData;
    BinaryTree <int> * root = new BinaryTree<int>(RootData);

    int num1;
    cout << "is there any left child ? type -1 if no" << endl;
    cin >> num1;
    if(num1 != -1){
        BinaryTree<int> * child1 = TakeInput();
        root->left = child1;
    }else{
        return NULL;
    }

    int num2;
    cout << "is there any right child ? type -1 if no" << endl;
    cin >> num2;
    if(num2 != -1){
        BinaryTree<int> * child2 = TakeInput();
        root -> right = child2;
    }else{
        return NULL;
    }

    return root;
}
*/
BinaryTree<int> * TakeInput(){

    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int> (rootData);
    BinaryTree<int> * leftChild = TakeInput();
    BinaryTree<int> * rightChild = TakeInput();
    root -> left = leftChild;
    root -> right = rightChild;
    return root;

}
BinaryTree<int> * TakeInputLevelWise(){

    int rootdata;
    cout << "Enter data of root " << endl;
    cin >> rootdata;
    if( rootdata == -1 ){
        return NULL;
    }
    BinaryTree<int> * root = new BinaryTree<int> (rootdata);
    queue<BinaryTree<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size() != 0){
        BinaryTree<int>* front= pendingNode.front();
        pendingNode.pop();
        cout << "Enter left child of " << front -> data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTree<int>* child1 = new BinaryTree<int>(leftChildData);
            front -> left = child1;
            pendingNode.push(child1);

        }
        cout << "Enter Right Child of " << front -> data << endl;
        int rightChilData;
        cin >> rightChilData;
        if(rightChilData != -1){
            BinaryTree<int> * child2 = new BinaryTree<int>(rightChilData);
            front -> right = child2;
            pendingNode.push(child2);

        }

    }
    return root;
    
}

void PrintLevelWise(BinaryTree<int>* root){
    
    queue <BinaryTree<int>* >pendingNode;
    pendingNode.push(root);
    while( pendingNode.size() != 0 ){

        BinaryTree<int> * front = pendingNode.front();
        pendingNode.pop();
        cout << front -> data << ":";
        if(front -> left != NULL){
            pendingNode.push(front -> left);
            cout << front -> left -> data;
            if(front -> right != NULL){
                cout << ",";
            }

        }
        if (front -> right != NULL){
            pendingNode.push(front -> right);
            cout << front -> right -> data;
        }
        cout << endl;
 
    }

}


void printTree(BinaryTree<int> * root){
    if(root == NULL){
        return;
    }
    // this is base case we need base case in binary trees !

    cout << root -> data << ":";
    if(root -> left != NULL){
        cout << "L" << " " << root -> left -> data << " ";
    }
    if( root -> right != NULL){
        cout << "R" << " " << root -> right -> data;
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);

}

int NumberOfNodes(BinaryTree<int>* root){

    if(root -> left == NULL){
        return 0;
    }
    if(root -> right == NULL){
        return 0;
    }
    
    int count = 1;
    if(root -> left  != NULL){
        count = count + NumberOfNodes(root -> left); 
    }
    if( root -> right != NULL){
        count = count + NumberOfNodes(root -> right);
    }
    return count;

}

int height(BinaryTree<int>* root){
    if(root->left == NULL){
        return 0;
    }
    if(root -> right == NULL){
        return 0;
    }
    int LeftHeight = 1 + height(root->left);
    int RightHeight = 1 + height(root->right);
    return max(LeftHeight,RightHeight);

    // better only one line -->
    //return (1 + max(height(root->left),height(root->right))
}

int diametre(BinaryTree<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans1 = diametre(root->left);
    int ans2 = diametre(root->right);
    int ans3 = height(root -> right)+ height(root -> left);
    int ans = max(ans1,max(ans2,ans3));
    return ans;
}

pair<int,int> height_diameter(BinaryTree<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p = make_pair(0,0);
        return p;
    }
    pair<int,int> leftAns = height_diameter(root -> left);
    pair<int,int> rightAns = height_diameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;
    int height = 1 + max(lh,rh);
    int diameter = 1+ max(ld,rd);
    pair<int,int> pans;
    pans = make_pair(height,diameter);
    return pans;
    
}

int main(){
/*
BinaryTree<int>* root = new BinaryTree<int>(1);
BinaryTree<int>* node1 = new BinaryTree<int>(2);
BinaryTree<int>* node2 = new BinaryTree<int> (3);
root -> left = node1;
root -> right = node2;
*/
BinaryTree<int> * root(TakeInputLevelWise());
PrintLevelWise(root);
cout << NumberOfNodes(root) << endl;
cout << height(root);

delete root;

}
// use this test case : 1 2 3 -1 4 5 6 -1 -1 7 8 -1 -1 -1 -1 -1 -1
#include <iostream>
#include <cassert>
using namespace std;
 
class BST
{
    private:
            struct Node
            {
                string letter;
                string code;
                Node *left;
                Node *right;
            };
            Node *root;
            
 
    public:
            BST()
            {
                root = NULL;
            }

            void Insert(Node *&r, string letter, string code)
            {
                if(r == NULL)
                {
                    r = new Node; 
                    r->letter = letter; 
                    r->code = code;
                    r->left = r->right = NULL; 
                    cout << "Inserting " << letter << '-' << code << endl;
                }
            }
            void Insert(string letter, string code)
            {
                Node **r = &root;
                if(*r != NULL)
                {
                    for(std::string::size_type i = 0; i < code.length(); i++)
                    {
                    	assert(*r);
                        if(code[i] == '.') r = &((*r)->left);
                        else if(code[i] == '-') r = &((*r)->right);
                        else break;
                    }
                    Insert(*r, letter, code);
                }
                else Insert(root, letter, code);
            }
            
            /*void Display(Node *r, int i){
            		for(int j=0;j<i;j++)
            		cout<<" ";
            		cout<<r->letter;
            		cout<<endl;
            		if(r->left!=NULL)
            		Display(r->left, i/2);
            		if(r->right!=NULL)
            		Display(r->right, i/2);
			}
            
            void Display(int i=13){
            		for(int j=0;j<i;j++)
            		cout<<" ";
            		cout<<root->letter;
            		cout<<endl;
            		if(root->left!=NULL)
            		Display(root->left, 6);
            		if(root->right!=NULL)
            		Display(root->right, 6);
			}*/
			
			void Display(){
				cout<<"\t\t\t\t\t\tROOT\t\t\t\t\t\t\n\n\t\t\t\tE\t\t\t\tT\t\n\n\t\t\tI   \t\tA\t\tN    \t\tM\n\n\t\t   S\t    U\t    R\t    W\t    D\t    K\t    G\t    O\n\n\t\t H  V     F  -    L   -   P   J   B   X   C   Y   Z   Q   -    -\n\n\n";
			}
};
 
int main() {
BST t;
struct alphaTree
{
    string letter;
    string code;
};
 
alphaTree tree[] = {  
                       {"ROOT", ""},  {"E", "."},    {"T", "-"},    {"I", ".."},   {"A", ".-"},   {"N", "-."},   
                       {"M", "--"},   {"S", "..."},  {"U", "..-"},  {"R", ".-."},  {"W", ".--"},  {"D", "-.."},  
                       {"K", "-.-"},  {"G", "--."},  {"O", "---"},  {"H", "...."}, {"V", "...-"}, {"F", "..-."}, 
                       {"L", ".-.."}, {"P", ".--."}, {"J", ".---"}, {"B", "-..."}, {"X", "-..-"}, {"C", "-.-."}, 
                       {"Y", "-.--"}, {"Z", "--.."}, {"Q", "--.-"}  
                    };
 
for(int i = 0; i < 27; i++)
{
    t.Insert(tree[i].letter, tree[i].code);
}

t.Display();

	return 0;
}

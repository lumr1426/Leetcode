/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root==NULL) return {};
        vector<int> result;
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* temp=s.top();
            s.pop();
            if(!temp->children.empty())
            {
                reverse(temp->children.begin(),temp->children.end());
                for(auto child: temp->children)
                {
                    s.push(child);
                }
            }
            result.push_back(temp->val);
        }
        return result;
    }
};
